 #include "latch-cd4099B.h"

// there will still be two usefull pin for other uses
// D8 and D0
int outPin=0;
int pinState=HIGH;

// *** remember that latch driver uses ****
// *** D5 ==> write disable pin for first latch
// *** D6 ==> write disable pin for second latch (not used if only one latch is used; 
//            specified by the false parameter in the constructor.
// *** D7 ==> as the data pin for both latches
// *** D1 ==> address pins A0 for both latches
// *** D2 ==> address pins A1 for both latches
// *** D4 ==> address pins A2 for both latches
LatchCD4099BDriver latch(true);
void setup() {
     Serial.begin(115200);
     while (!Serial) 
     {
         ; // wait for serial port to connect. Needed for native USB port only
     }
     Serial.flush();
     Serial.println("");

    latch.enableSerialMonitor =true; 
    latch.begin();

    
     
}
void loop() {
    delay(1000);
   latch.setPin(outPin, pinState);
   outPin++;
   if(outPin==16)
   {
         outPin=0;
         if(pinState==HIGH)
         {
              pinState=LOW;                
         }
         else
         {
              pinState=HIGH;
         }
   }    
}
/*
void setup() {
     Serial.begin(115200);
     while (!Serial) 
     {
         ; // wait for serial port to connect. Needed for native USB port only
     }
     Serial.flush();
     Serial.println("");

 //    latch.begin();
    //writeDisableLatch0 = D5;
    pinMode(writeDisableLatch0,OUTPUT);
   
   // dataPin  = D7;  // data pin
    pinMode(dataPin,OUTPUT);

    // addressPins0 = D1;
    // addressPins1 = D2;
    // addressPins2 = D4;  //Address pins A0, A1, A2
    pinMode(addressPins0,OUTPUT);
    pinMode(addressPins1,OUTPUT);
    pinMode(addressPins2,OUTPUT);

    // just set to hold previous state
    // disable the outputs: 
    digitalWrite(writeDisableLatch0, HIGH);
    
}


void loop() {
    delay(1000);
    //turn pin 0 on
    digitalWrite(dataPin,HIGH);
    digitalWrite(writeDisableLatch0, LOW);
    digitalWrite(writeDisableLatch0, HIGH);
    delay(1000);
    //turn pin 2 on
    digitalWrite(dataPin,HIGH);
    digitalWrite(addressPins1,HIGH);
    digitalWrite(writeDisableLatch0, LOW);
    digitalWrite(writeDisableLatch0, HIGH);
    delay(1000);
    //turn pin 4 on
    digitalWrite(dataPin,HIGH);
    digitalWrite(addressPins1,LOW);
    digitalWrite(addressPins2,HIGH);
    digitalWrite(writeDisableLatch0, LOW);
    digitalWrite(writeDisableLatch0, HIGH);
    delay(1000);
    
}
*/



