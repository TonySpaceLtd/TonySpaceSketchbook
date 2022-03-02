#ifndef TonySpace_MODBUS_SLAVE_h
#define TonySpace_MODBUS_SLAVE_h


#include "Arduino.h"
#include "TonySpace_RS485.h"

#define Read_Coil_Status 			0x01
#define Read_Input_Status 			0x02
#define Read_Holding_Register 		0x03
#define Read_Input_Register 		0x04
#define Force_Single_Coil 			0x05
#define Preset_Single_Register 		0x06
#define Force_Multiple_Coils 		0x0F
#define Preset_Multiple_Registers 	0x10


#define SUCCESS 			1
#define MEMORY_FAIL 		2
#define ADDR_FN_FAIL 		3
#define NO_RESPONSE 		4
#define CRC_ERROR			5

typedef struct MODBUS_SLAVE
{
	uint8_t slaveID;
	uint8_t function;
	uint16_t address;
	uint16_t number;
	uint16_t numberReg;
	uint8_t numberByte;
	uint8_t *data;
}Modbus_Reuest;

class Tony_Modbus_Slave
{
public:
		Tony_Modbus_Slave();
		Tony_RS485 ser485;
		void setSlot(uint8_t slot);
		void begin(unsigned long baud,uint32_t config = SERIAL_8N1);
		void setID(uint8_t id){myID = id;};
		uint8_t myID;
		bool waitData(unsigned long time);
		uint16_t calCRC(uint8_t *data,size_t length);
		void (*callback)(Modbus_Reuest request);
		void processCommand(uint8_t *data,uint16_t len);
		void response(Modbus_Reuest req,void *data,uint16_t len);
private:
		const int taskCore = 0;
		const int taskPriority = 4;
		TaskHandle_t task_recv;
		uint16_t **buf16;

};




























#endif