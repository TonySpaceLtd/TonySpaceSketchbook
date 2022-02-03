
#include "TonySpace_GPS.h"


#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	TONY_GPS TonyGPS;
#endif

TONY_GPS::TONY_GPS()
{
	
}
void TONY_GPS::setSlot(uint8_t slot)
{
	switch(slot)
	{
		case  SLOT1 :
			pin_force_on = AIO0;
			pin_RX = IO0;
			pin_TX = -1;
			break;
		case  SLOT2 :
			pin_force_on = AIO2;
			pin_RX = IO2;
			pin_TX = -1;
			break;
		case  SLOT3 :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT4 :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT5 :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT6 :
			pin_force_on = AIO10;
			pin_RX = IO10;
			pin_TX = -1;
			break;
		case  SLOT1_U :
			pin_force_on = AIO1;
			pin_RX = IO1;
			pin_TX = -1;
			break;
		case  SLOT2_U :
			pin_force_on = AIO3;
			pin_RX = IO3;
			pin_TX = -1;
			break;
		case  SLOT3_U :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT4_U :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT5_U :
			Serial.println("Please use GPS Module only SLOT1 , SLOT2 , SLOT6");
			break;
		case  SLOT6_U :
			pin_force_on = AIO11;
			pin_RX = IO11;
			pin_TX = -1;
			break;
	}
	Tony.pinMode(pin_force_on, OUTPUT);
}
void TONY_GPS::begin(unsigned long baud)
{
	ser_gps.begin(baud,SWSERIAL_8N1, pin_RX, pin_TX, false, 95);
}
