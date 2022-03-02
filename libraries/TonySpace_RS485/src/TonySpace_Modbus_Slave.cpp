#include"TonySpace_MODBUS_SLAVE.h"
uint8_t *data_temp;

void reciveTask( void * parameter );
bool createMenory(uint16_t size);


void callback_(Modbus_Reuest request){ }

Tony_Modbus_Slave::Tony_Modbus_Slave()
{
	myID =1;
	callback = callback_;
}
void Tony_Modbus_Slave::setSlot(uint8_t slot)
{
	ser485.setSlot(slot);
}
void Tony_Modbus_Slave::begin(unsigned long baud,uint32_t config )
{
	ser485.begin(baud,config);
	//xTaskCreate(reciveTask,"reciveTask",10000,(void*)this,4,NULL);
	
	xTaskCreatePinnedToCore(reciveTask,"httpsTask",10000,this,taskPriority,&task_recv,taskCore);        
}
bool Tony_Modbus_Slave::waitData(unsigned long time)
{
	uint16_t data[2];
	unsigned long pv = millis();
	do{
		if(ser485.available())
			return true;
	}
	while((millis()-pv)<time);
	return false;
}
uint16_t Tony_Modbus_Slave::calCRC(uint8_t *data,size_t length)
{
	uint16_t crc = 0xFFFF;
	
	 for (size_t position = 0; position < length; position++)
    {
        uint8_t d = data[position]&0xFF;
        crc ^= d;
        for (uint8_t i = 8; i != 0; i--)
        {   
			if ((crc & 0x0001) != 0) 
			{
                crc >>= 1;
                crc ^= 0xA001;
            }
            else          
                crc >>= 1;
        }
    }
	return crc;
}	

void Tony_Modbus_Slave::processCommand(uint8_t *data,uint16_t len)
{
	/*
	uint8_t slaveID;
	uint8_t function;
	uint16_t address;
	uint16_t number;
	uint16_t numberReg;
	uint8_t numberByte;
	uint16_t *data;
	*/
	
	Modbus_Reuest request;
	if(data[1] <= Preset_Single_Register )
	{
		request.slaveID = data[0];
		request.function = data[1];
		request.address = (data[2]<<8|data[3]);
		request.number = (data[4]<<8|data[5]);
		(*callback)(request);
		
	}
	if(data[1] == Force_Multiple_Coils )
	{
		request.slaveID = data[0];
		request.function = data[1];
		request.address = (data[2]<<8|data[3]);
		request.numberReg = (data[4]<<8|data[5]);
		request.numberByte = data[6];
		request.data = data+7;
		(*callback)(request);
	}
	if(data[1] == Preset_Multiple_Registers )
	{
		request.slaveID = data[0];
		request.function = data[1];
		request.address = (data[2]<<8|data[3]);
		request.numberReg = (data[4]<<8|data[5]);
		request.numberByte = data[6];
		
		for(uint16_t i=7;i<len-2;i+=2)
		{
			uint8_t b = data[i];
			data[i] = data[i+1];
			data[i+1] = b;
		}
		request.data = data+7;
		
		(*callback)(request);
	}
	
	
}
void Tony_Modbus_Slave::response(Modbus_Reuest req,void *data,uint16_t len)
{
	uint16_t bufSize;
	uint16_t realSize;
	size_t cnt=0;
		
	if((req.function == Read_Coil_Status)||(req.function == Read_Input_Status))
	{
		uint8_t *buf = (uint8_t*)data;
		realSize = req.number/8;
		if(req.number%8>0)
			realSize+=1;
		bufSize = realSize+5;
		
		createMenory(bufSize);
		
		data_temp[cnt++] = req.slaveID;
		data_temp[cnt++] = req.function;
		data_temp[cnt++] = realSize;
		for(uint16_t i=0;i<realSize;i++)
		{
			data_temp[cnt++] = buf[i];
		}
		uint16_t crc = calCRC(data_temp,cnt);
		data_temp[cnt++] = crc&0x00FF;
		data_temp[cnt++] = crc>>8;
		ser485.write(data_temp,cnt);
	}
	if((req.function == Read_Holding_Register)||(req.function == Read_Input_Register))
	{
		uint16_t *buf = (uint16_t*)data;
		realSize = req.number*2;
		bufSize = realSize+5;
		createMenory(bufSize);
		data_temp[cnt++] = req.slaveID;
		data_temp[cnt++] = req.function;
		data_temp[cnt++] = realSize;
		
		for(uint16_t i=0;i<req.number;i++)
		{
			data_temp[cnt++] = buf[i]>>8;
			data_temp[cnt++] = buf[i]&0x00FF;
		}
		
		uint16_t crc = calCRC(data_temp,cnt);
		data_temp[cnt++] = crc&0x00FF;
		data_temp[cnt++] = crc>>8;
		ser485.write(data_temp,cnt);
		
	}
	if((req.function == Force_Single_Coil)||(req.function == Preset_Single_Register))
	{
		ser485.write(data_temp,8);
	}
	if((req.function == Preset_Multiple_Registers)||(req.function == Force_Multiple_Coils))
	{
		bufSize = 8;
		createMenory(bufSize);
		data_temp[cnt++] = req.slaveID;
		data_temp[cnt++] = req.function;
		data_temp[cnt++] = req.address >>8;
		data_temp[cnt++] = req.address &0x00FF;
		data_temp[cnt++] = req.numberReg >> 8;
		data_temp[cnt++] = req.numberReg &0x00FF;
		uint16_t crc = calCRC(data_temp,cnt);
		data_temp[cnt++] = crc&0x00FF;
		data_temp[cnt++] = crc>>8;
		ser485.write(data_temp,cnt);
		
	}
	
	
	
}









void reciveTask( void * parameter )
{
	uint8_t fn[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x0F,0x10};
	Tony_Modbus_Slave *slave = (Tony_Modbus_Slave*) parameter;
    bool flag=false;
	uint8_t func=0;
	uint16_t cnt=0;
	uint16_t rx_length=0;
	//			   id fn	
	// 000241-Tx: 01  01 00 00 00 0A BC 0D
	
	while(1)
	{
		while(slave->ser485.available())
		{
			uint8_t c = slave->ser485.read();
			if(flag == false)
			{
				if(c == slave->myID)
				{
					Serial.println("My Command");
					if(slave->waitData(10))
					{
						func = slave->ser485.peek();
						for(uint8_t i=0;i<8;i++)
						{
							if(func==fn[i])
							{
								flag = true;
								cnt=0;
								if(func <= Preset_Single_Register )
								{
									
									rx_length = 8;
									createMenory(rx_length);
								}
								if((func == Preset_Multiple_Registers )||(func == Force_Multiple_Coils ))
								{
							
									rx_length = 256;
									createMenory(rx_length);
								}
							}
						}
						
					}
				}
			}
			if(flag)
			{
				data_temp[cnt++] = c;
				if(cnt >= rx_length)
				{
					
					uint16_t 	crc_rx = data_temp[cnt-1]<<8;
								crc_rx |= data_temp[cnt-2]&0x00FF;
					uint16_t 	crc = slave->calCRC(data_temp,(cnt-2));
					if(crc_rx == crc)
					{
						Serial.println("Data Ok");
						//slave->*callback(buff[0],buff[1],buff[2]<<8|buff[3],buff+4,(rx_length-4-2)/2);
						slave->processCommand(data_temp,cnt);
						
						
					}
					flag = false;
					cnt=0;
				}
				if((func == Preset_Multiple_Registers )||(func == Force_Multiple_Coils ))
				{
					if(cnt>6)
					{
						rx_length = data_temp[6]+9; 
					}
				}
			}
			
			//Serial.print(slave->ser485.read(),HEX);
			//Serial.print(" ");
		}
		vTaskDelay(pdMS_TO_TICKS( 10 ) );
	}
	
	vTaskDelete( NULL );
 
}
bool createMenory(uint16_t size)
{
	if(data_temp!=NULL)
		free(data_temp);
	if(psramFound())
	{
		data_temp = (uint8_t *)ps_calloc(size, sizeof(uint8_t) );		
	}
	else
	{
		data_temp = (uint8_t *)calloc(size, sizeof(uint8_t) );
	}
	if(data_temp==NULL)
	{
		Serial.println("Memory Fail");
		return (false);
	}
	return (true);
}






