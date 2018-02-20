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
