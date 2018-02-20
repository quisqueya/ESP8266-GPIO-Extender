#include "multiplexer-CD74HC4067-16-lines.h"

MultiAnalogDigitalRead multiread;

void setup() {
  // put your setup code here, to run once:
     Serial.begin(115200);
     while (!Serial) 
     {
         ; // wait for serial port to connect. Needed for native USB port only
     }
     Serial.flush();
     Serial.println("");

    multiread.enableSerialMonitor =true; 
    multiread.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    
    Serial.println("ready to read digital pin 0 in 3 seconds");
    delay(3000);
    int val=multiread.readDigital(0);
    Serial.print("read digital pin 0 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 1 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(1);
    Serial.print("read digital pin 1 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 2 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(2);
    Serial.print("read digital pin 2 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 3 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(3);
    Serial.print("read digital pin 3 value=");
    Serial.println(val);
    //------------------------------------
     Serial.println("ready to read digital pin 4 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(4);
    Serial.print("read digital pin 4 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 5 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(5);
    Serial.print("read digital pin 5 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 6 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(6);
    Serial.print("read digital pin 6 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 7 in 3 seconds");
    delay(3000);
    val=multiread.readDigital(7);
    Serial.print("read digital pin 7 value=");
    Serial.println(val);
    //------------------------------------
    //=================================================================
    Serial.println("ready to read digital pin 0 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(0);
    Serial.print("read analog pin 0 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 1 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(1);
    Serial.print("read analog pin 1 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 2 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(2);
    Serial.print("read analog pin 2 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 3 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(3);
    Serial.print("read analog pin 3 value=");
    Serial.println(val);
    //------------------------------------
     Serial.println("ready to read digital pin 4 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(4);
    Serial.print("read analog pin 4 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 5 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(5);
    Serial.print("read analog pin 5 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 6 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(6);
    Serial.print("read analog pin 6 value=");
    Serial.println(val);
    //------------------------------------
    Serial.println("ready to read digital pin 7 in 3 seconds");
    delay(3000);
    val=multiread.readAnalog(7);
    Serial.print("read analog pin 7 value=");
    Serial.println(val);
    //------------------------------------
}
