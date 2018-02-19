
#include "multiplexer-CD74HC4067-16-lines.h"
#include "latch-cd4099B.h"

// *** remember that multiplexer driver uses ****
// *** A0 ==> Signal line
// *** D8 ==> Signal line
// *** D1 ==> address pins S0 select line 0
// *** D2 ==> address pins S1 select line 1
// *** D4 ==> address pins S2 select line 2
// *** D0 ==> address pins S3 select line 3
MultiAnalogDigitalRead multiread;

// *** remember that latch driver uses ****
// *** D5 ==> write disable pin for first latch
// *** D6 ==> write disable pin for second latch (not used if only one latch is used; 
//            specified by the false parameter in the constructor.
// *** D7 ==> as the data pin for both latches
// *** D1 ==> address pins A0 for both latches
// *** D2 ==> address pins A1 for both latches
// *** D4 ==> address pins A2 for both latches

LatchCD4099BDriver latch(true); 
//  true -> indicates we are using two latches to make it 16 digital output pins.
//  false -> indicates we are using only one latch to make it 8 digital output pins.

void setup() {
  // put your setup code here, to run once:
     Serial.begin(115200);
     while (!Serial) 
     {
         ; // wait for serial port to connect. Needed for native USB port only
     }
     Serial.println("");

    multiread.enableSerialMonitor =true; 
    multiread.begin();  

    latch.enableSerialMonitor =true; 
    latch.begin();
}
int oldValue=0;
void loop() {
  // put your main code here, to run repeatedly:
  if(oldValue==LOW)
  {
      oldValue=HIGH;
  }
  else
  {
       oldValue=LOW;
  }
  latch.setPin(0, oldValue);
  delay(1000);

  latch.setPin(1, oldValue);
  delay(1000);
   
  latch.setPin(2, oldValue);
  delay(1000);
 
  latch.setPin(3, oldValue);
  delay(1000);
}
