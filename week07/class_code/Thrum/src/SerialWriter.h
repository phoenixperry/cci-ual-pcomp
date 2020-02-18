#ifndef _SERIALWRITER
#define _SERIALWRITER

#include "ofMain.h"
#include "Motor.h"

#define PROTO_ON 0x80 //1000 0000
#define PROTO_HALF 0x40 // 0100 0000
#define PROTO_OFF 0x20 //0010 0000
#define MOTOR_MASK 0x1f //0001 1111 

#ifdef TARGET_WIN32
#define WRITE_SERIAL_PORT "WINDOWS SERIAL PORT GOES HERE"
#else
#define WRITE_SERIAL_PORT "/dev/cu.usbserial-AH01D4X4"
#endif

class SerialWriter {
 public:
		SerialWriter();
		void setup();
		void update();
		void setMotor(int, MotorState);
		void winAnimation();
        void closePort();
    
 private:
		ofSerial * serial;
};

#endif
