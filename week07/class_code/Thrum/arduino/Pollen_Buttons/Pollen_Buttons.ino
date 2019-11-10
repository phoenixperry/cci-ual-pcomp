#define N_SENSORS 6
#define BLINK_INTERVAL 500
//#define HWSERIAL Serial1
#define SWSERIAL Serial

int btnP0 = 2;
int btnP1 = 4;
int btnP2 = 7;
int btnP3 = 8;
int btnP4 = 12;
int btnP5 = 13;

int ledP0 = 3;
int ledP1 = 5;
int ledP2 = 6;
int ledP3 = 9;
int ledP4 = 10;
int ledP5 = 11;

int btns[6] = {btnP0,btnP1, btnP2, btnP3, btnP4, btnP5};
int leds[6] = {ledP0, ledP1, ledP2, ledP3, ledP4, ledP5};
String game_state = "start_sequence";

// blinking or not
int ledStates[6] = {0, 0, 0, 0, 0, 0};
int ledCounter[6] = {0, 0, 0, 0, 0, 0};

//for pulsing
int pulse = 0;
int pulseSpeed = 1;
int delayTime = 50;
void setup() {
  //  HWSERIAL.begin(9600);
    SWSERIAL.begin(9600);
    for (int i=0; i < N_SENSORS; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(btns[i],INPUT_PULLUP);
    }
}

//function to read LEDS
int readBtns(int num){
    int val = digitalRead(num);
    return val;
}
void pulseLeds(){

  for(int i=0; i < N_SENSORS; i++){
    if(pulse > 250 || pulse < 0)
    {
      pulseSpeed = pulseSpeed * -1;
    }
    analogWrite(leds[i],pulse);
    pulse = pulse + pulseSpeed;
    SWSERIAL.println(pulse);
  }
  delay(delayTime);
}
void play_game(){
  // read sensor data and react
  for(int i=0; i < N_SENSORS; i++){
      int btnVal =readBtns(btns[i]);
      SWSERIAL.print("btn_");
      SWSERIAL.print(i);
      SWSERIAL.print(":");
      SWSERIAL.println(!btnVal);

      if(!btnVal == 1)
      {
        analogWrite(leds[i], 0);
        ledStates[i] = 1;
      }else{
        analogWrite(leds[i], 255);
        ledStates[i] = 0;
      }
    }
}
String setGameState(){
  if(Serial.available() > 0) {
    String incomming = Serial.readString();
    if(incomming=="start_sequence"){
      return incomming;
    }
    else if(incomming=="play_game"){
      return incomming;
    }
  }
  if(!Serial.available()){
    return "start_sequence";
  }
}
//void blinkLEDs() {
//    for (int k=0; k<N_SENSORS; k++) {
//        ledCounter[k]++;
//        if (ledStates[k] == 1) {
//            if (ledCounter[k] < BLINK_INTERVAL) {
//                digitalWrite(leds[k], LOW);
//                delay(1);
//            }
//            if (ledCounter[k] > BLINK_INTERVAL && ledCounter[k] < (BLINK_INTERVAL * 2)) {
//                digitalWrite(leds[k], HIGH);
//                delay(1);
//            }
//        } else {
//            digitalWrite(leds[k], LOW);
//        }
//        if (ledCounter[k] > (BLINK_INTERVAL * 2)) {
//            ledCounter[k] = 0;
//        }
//    }
//}


  void loop() {
    //pulseLeds();
    game_state = setGameState();
    if(game_state == "start_sequence") pulseLeds();
    else if (game_state == "play_game") play_game();
}
