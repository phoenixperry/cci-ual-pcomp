#include <LiquidCrystal.h>
#define backLight 13
#define ledcount 24
// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int sensorValue = 0;
int sensorValueOld = -1;

/*
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
*/
byte smiley[8] = {
  B00000,
  B01010,
  B10101,
  B10001,
  B10001,
  B01010,
  B00100,
  B00000
};

int sh = 7;                    
int st = 8;                       
int ds = 9;
int daten[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup(){
  pinMode(backLight, OUTPUT);
  pinMode(sh, OUTPUT);            
  pinMode(st, OUTPUT);            
  pinMode(ds, OUTPUT); 
  pinMode(A0, INPUT);

  digitalWrite(backLight, HIGH);
  
  lcd.begin(16,2);              
  lcd.clear();            
  lcd.setCursor(0,0);     
  lcd.print("Value ");    
  lcd.createChar(0, smiley);  
  lcd.setCursor(15, 1); 
  lcd.write(byte(0));
}

void loop(){
  sensorValue = round(map(analogRead(A0),0,1023,0,(ledcount + 1)));
  
  if(sensorValueOld != sensorValue){
    sensorValueOld = sensorValue;
    lcd.setCursor(0,1);
    
    if(sensorValue <   10){lcd.print(" ");}  
    if(sensorValue <  100){lcd.print(" ");} 
    lcd.print(sensorValue);
  
     //Set values
    for (int i = 0; i < ledcount; i ++){                                              
      daten[(ledcount - 1 - i)] = (sensorValue > i);
    }
    
    //Send values to shift register
    digitalWrite(st, 0);    
    for (int i = 0; i < ledcount; i ++){                                              
     digitalWrite(ds, 0);     
     digitalWrite(sh, 0);
     digitalWrite(ds, daten[i]);
     delay(20); 
     digitalWrite(sh, 1); 
     delay(20);           
    }
    digitalWrite(st, 1);    
  }

  delay(20);   
}
