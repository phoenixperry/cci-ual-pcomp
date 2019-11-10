#include "SerialReader.h"

SerialReader::SerialReader() {

}

void SerialReader::setup() {
    serial = new ofSerial();
    serial->listDevices();
    if(!serial->setup(READ_SERIAL_PORT, 9600)) {
        ofLogNotice() << "unable to init serial device";
    }
}

int SerialReader::update() {
    int goal = -1;
    bool on;
    if (serial->available()) {
        // get some data here
        unsigned char bytesReturned[7];
        memset(bytesReturned, 0, sizeof(bytesReturned));
        serial->readBytes(bytesReturned, 6);
        cout << bytesReturned <<endl; 
        // the messages from the pollen look like
        // 0:ON or 0:OFF or 3:ON etc.
        // ie, GOAL:STATE
        // we take advantage of the fact that there are < 10 goals,
        // so the 0th char gives us an index
        // and we can just use the 3rd char, 'N' or 'F' to
        // figure out the state
        goal = bytesReturned[0] - '0'; //single character in c is a byte. converting a char to an int
        on = (bytesReturned[3] == 'N');
        ofLogNotice() << goal << ":" << on;
    }
    if (on) {
        return goal;
    } else {
        return -1;
    }
    serial->flush();
}
