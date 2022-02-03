
#ifndef TonySpace_GPS_h
#define TonySpace_GPS_h

#include "Arduino.h"
#include <Stream.h>
#include "TonyS_X1.h"
#include <SoftwareSerial.h>


class TONY_GPS : public Stream
{
	public:
		TONY_GPS();
		void setSlot(uint8_t slot);
		void begin(unsigned long baud=9600);
		//Stream Class 
		virtual int read() { return ser_gps.read();};	
		virtual size_t write(uint8_t c){return ser_gps.write(c);};
		virtual int available(){return ser_gps.available();};
		virtual int peek(){return ser_gps.peek();}; 
		virtual void flush(){ser_gps.flush();};
		using Stream::write; // make the other overloads of write visible
		
		
	private:
		SoftwareSerial ser_gps;
		uint8_t pin_RX, 
			pin_TX,
			pin_force_on;
			
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	extern TONY_GPS TonyGPS;
#endif

#endif
















