// a great tutorial this code is from is here
//http://www.ladyada.net/learn/arduino/lesson4.html
//it's a bit old... 

*
 * Math is fun!
 */

#include "math.h"               // include the Math Library

int a = 3;
int b = 4;
int h;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Lets calculate a hypoteneuse");

  Serial.print("a = ");
  Serial.println(a);

  Serial.print("b = ");
  Serial.println(b);
  
  h = sqrt( a*a + b*b );
  
  Serial.print("h = ");
  Serial.println(h);
}

void loop()                // we need this to be here even though its empty
{
}
    
