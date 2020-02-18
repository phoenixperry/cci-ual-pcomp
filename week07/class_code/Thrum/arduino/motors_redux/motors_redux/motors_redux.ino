#include <Adafruit_NeoPixel.h>

#define N_MOTORS 7
#define BLINK_INTERVAL 60
#define LEDSTRIP 12
#define NUMPIXELS 30

#define MOTOR_1 10
#define MOTOR_2 9
#define MOTOR_3 3 
#define MOTOR_4 6
#define MOTOR_5 5
#define MOTOR_6 4
#define MOTOR_7 21

//#define MOTOR_1 1
//#define MOTOR_2 2
//#define MOTOR_3 3 
//#define MOTOR_4 4
//#define MOTOR_5 5
//#define MOTOR_6 6
//#define MOTOR_7 7

// motor states
#define OFF 0
#define ON 1
#define HALF 2
#define HWSERIAL Serial1
#define localSerial Serial
#define PROTO_ON 0x80
#define PROTO_HALF 0x40
#define PROTO_OFF 0x20
#define MOTOR_FLAG 0x1f

int motorStates[N_MOTORS];

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDSTRIP, NEO_GRB + NEO_KHZ800);
//not sure why these vars exist 
int delayVal = 20;
int numLoops = 5;
void setup() {
  // put your setup code here, to run once:

  HWSERIAL.begin(9600);
  localSerial.begin(9600); 
    pinMode(MOTOR_1, OUTPUT);
    pinMode(MOTOR_2, OUTPUT);
    pinMode(MOTOR_3, OUTPUT);
    pinMode(MOTOR_4, OUTPUT);
    pinMode(MOTOR_5, OUTPUT);
    pinMode(MOTOR_6, OUTPUT);
    pinMode(MOTOR_7, OUTPUT);

    for (int i=0; i < N_MOTORS; i++) {
        motorStates[i] = 0;
    }
    
    pixels.begin();
}

void winAnimation() {
    for (int i=0; i < numLoops; i++) {
        for (int j=0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(255, 255, 255));
            pixels.show();
            delay(delayVal);
        }
    }
}
  

void checkSerial() {
    unsigned char incomingByte;
    int motor;
    
    if (HWSERIAL.available() > 0) {
        incomingByte = HWSERIAL.read();
        HWSERIAL.println(incomingByte); 
        localSerial.println(incomingByte);
        HWSERIAL.print("USB received: ");
        localSerial.print("USB received: ");
        HWSERIAL.println(incomingByte, DEC);
        localSerial.println(incomingByte, DEC);
        // first, check for a win
        if (incomingByte == 0xFF) {
            winAnimation();
            return;
        }
 
        // mask off lower five bits for the motor
        motor = incomingByte & MOTOR_FLAG;
        HWSERIAL.print("MOTOR: ");
        localSerial.print("MOTOR: ");
        HWSERIAL.println(motor);
        localSerial.println(motor); 
        if (incomingByte & PROTO_ON) { //we are looking for 0x80
            HWSERIAL.println("ON");
            localSerial.println("on"); 
            motorStates[motor] = ON;
        } else if (incomingByte & PROTO_HALF) {
            HWSERIAL.println("HALF");
            localSerial.println("HALF"); 
            motorStates[motor] = HALF;
        } else if (incomingByte & PROTO_OFF) {
            HWSERIAL.println("OFF");
            localSerial.println("off"); 
            motorStates[motor] = OFF;
        } else {
            // one of those flags must be set
            HWSERIAL.print("received invalid byte");
        }
       
    }
}
void motorOn(int motor) {
        Serial.print("switch on motor ");
        Serial.println(motor);
     if(motor == 0)digitalWrite(MOTOR_1, HIGH);
     if(motor == 1)digitalWrite(MOTOR_2, HIGH);
     if(motor == 2)digitalWrite(MOTOR_3, HIGH);
     if(motor == 3)digitalWrite(MOTOR_4, HIGH);
     if(motor == 4)digitalWrite(MOTOR_5, HIGH);
     if(motor == 5)digitalWrite(MOTOR_6, HIGH);
     if(motor == 6)digitalWrite(MOTOR_7, HIGH);
}

void motorOff(int motor) {
    //    Serial.print("switch off motor ");
    //    Serial.println(motor);
    //digitalWrite(motor, LOW);
     if(motor == 0)digitalWrite(MOTOR_1, LOW);
     if(motor == 1)digitalWrite(MOTOR_2, LOW);
     if(motor == 2)digitalWrite(MOTOR_3, LOW);
     if(motor == 3)digitalWrite(MOTOR_4, LOW);
     if(motor == 4)digitalWrite(MOTOR_5, LOW);
     if(motor == 5)digitalWrite(MOTOR_6, LOW);
     if(motor == 6)digitalWrite(MOTOR_7, LOW);
}
void blinkMotors() {

    for (int i=0; i < N_MOTORS; i++) {
      
        if (motorStates[i] == ON) {
            // on is on
            motorOn(i);
        } else if (motorStates[i] == HALF) {
            // blink logic
            if ((millis() % BLINK_INTERVAL) < (BLINK_INTERVAL / 2)) {
                motorOn(i);
            } else {
                motorOff(i);
            }
        } else {
            // otherwise it's off
            motorOff(i);
        }
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    checkSerial();
    //digitalWrite(1, HIGH); 
    //digitalWrite(1,HIGH); 
    blinkMotors();
}


