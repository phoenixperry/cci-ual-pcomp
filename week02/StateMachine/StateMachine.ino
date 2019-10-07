
//these are basic types 
//a nice reference to their max number and size is herehttps://learn.adafruit.com/arduino-to-circuitpython/working-with-numbers

//these are just for exmaple 
int x = 10; 
float num = 10.0; 
char c = 'c'; 

//these are in the below code 
String name = "tom"; 
bool state1 = true; 
bool state2 = false; 
int btn = 8;

void setup() {

  pinMode(btn, INPUT_PULLUP); //this is a way to do a button w/out a pull up or pull down resistor 
 Serial.begin(9600); //this is the number of bits per second the serial port sends 
}

void loop() {
  //this is what is called a very basic STATE MACHINE 
  state1 = digitalRead(btn); //state 1 gets set by the button to 0 or 1, true or false. 
  //Serial.println(state1); 
  
  //if the state is true, 1, or anything above 1     
   if(state1){ 
      digitalWrite(13, HIGH);  //write the LED on the arduino board to turn on 
      Serial.println(name); //print the name variable to the console 
   } 
   //if the date is false 
   else{
      digitalWrite(13, LOW); //write the LED on the arduino board to turn off   
    }
}
