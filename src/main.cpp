 

#include "Arduino.h"
 
#define SERIAL_OUT Serial 
 
// Agafia SG0+ board has a built-in LED on pin PC13
// LED1 is on pin PF0 and LED2 is on pin PF1

#define LED_F0 PF0  // User LED pin for STM32F4 boards 
#define LED_F1 PF1  // User LED pin for STM32F4 boards
 
void setup()
{
  SERIAL_OUT.begin(115200);
  while (!SERIAL_OUT);  //  wait for SERIAL_OUT port to connect. Needed for Leonardo only

  pinMode(LED_BUILTIN, OUTPUT);  // initialize LED_BUILTIN pin as an output
  SERIAL_OUT.println("Hello World Blink!");

  pinMode(LED_F0, OUTPUT);  // initialize LED_F0 pin as an output
  pinMode(LED_F1, OUTPUT);  // initialize LED_F1 pin as an output
 
}


void loop()
{
  digitalWrite(LED_F1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);     
  digitalWrite(LED_F0, HIGH) ;        // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(300);                       // wait for a second 
  digitalWrite(LED_F0, LOW);         // turn the LED off by making the voltage LOW
  digitalWrite(LED_F1, HIGH);         // turn the LED off by making the voltage LOW
  delay(300);                       // wait for a second
}


  