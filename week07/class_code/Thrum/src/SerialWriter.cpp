#include "SerialWriter.h"

SerialWriter::SerialWriter() {

}

void SerialWriter::setup() {
    serial = new ofSerial();
    serial->listDevices();
    if(!serial->setup(WRITE_SERIAL_PORT, 9600)) {
        ofLogNotice() << "unable to init serial device";
    }
}

void SerialWriter::update() {
}

void SerialWriter::setMotor(int m, MotorState ms) { //m = index of motor
    unsigned char b = 0; // this is the 8bit bite set to all 0s
    b = MOTOR_MASK & m; // bitwise and operation on the 00000000 from 0001111, which is MOTOR_MASK
    //if the value m is within the mask copy it directly. if it's outside, strip it off. it masks just like a stencil
    if (ms == MotorState::FULL) {
        b |= PROTO_ON; //b equals b bitwise or b = b | PROTO_ON
    } else if (ms == MotorState::HALF) {
        b |= PROTO_HALF;
    } else {
        b |= PROTO_OFF;
    }
    //uncomment this if you want to test for this pattern using a keystroke
     ofLogNotice() << "writing " << b;
    std::cout<<std::bitset<8>(b)<<std::endl; //this is the binary code unmasked
    if(serial->isInitialized()){
        ofLogNotice() << "writing serial data";
        serial->writeByte(b);
    } else {
        ofLogNotice() << "no serial available";
    }
}

void SerialWriter::winAnimation() {
    ofLogNotice() << "sending win animation signal";
    serial->writeByte(0xFF);
}
