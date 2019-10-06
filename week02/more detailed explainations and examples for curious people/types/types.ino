
//https://learn.sparkfun.com/tutorials/digital-logic
//boolean (8 bit) - simple logical true/false
//byte (8 bit) - unsigned number from 0-255
//char (8 bit) - signed number from -128 to 127. The compiler will attempt to interpret this data type as a character in some circumstances, which may yield unexpected results
//unsigned char (8 bit) - same as 'byte'; if this is what you're after, you should use 'byte' instead, for reasons of clarity
//word (16 bit) - unsigned number from 0-65535
//unsigned int (16 bit)- the same as 'word'. Use 'word' instead for clarity and brevity
//int (16 bit) - signed number from -32768 to 32767. This is most commonly what you see used for general purpose variables in Arduino example code provided with the IDE
//unsigned long (32 bit) - unsigned number from 0-4,294,967,295. The most common usage of this is to store the result of the millis() function, which returns the number of milliseconds the current code has been running
//long (32 bit) - signed number from -2,147,483,648 to 2,147,483,647
//float (32 bit) - signed number from -3.4028235E38 to 3.4028235E38. Floating point on the Arduino is not native; the compiler has to jump through hoops to make it work. If you can avoid it, you should. We'll touch on this later.

//https://www.arduino.cc/reference/en/
