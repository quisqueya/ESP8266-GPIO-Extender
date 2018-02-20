# ESP8266-GPIO-Extender
Expands the NodeMCU module GPIO to 16 digital outputs, 8 digital inputs, and 8 analog inputs using two CD4099B latch 8-bit chips to provide 16 digital output pins. These output pins have persistante states, meaning that they keep the state that you assign them indepedant of each other. A CD74HC4067 multiplexer/de-multiplexer breakout module is used to provide 8 digital inputs and 8 analog inputs. The two CD4099B and the CD74HC4067 chips share three of the NodeMCU GPIO (D1, D2, and D3) like kind of a common bus.

------------------------------------------------------------------------------------------------------------

Latch 1 provides digital ouput pins 0 - 7. Connect the latch chip to the ESP8266 NodeMCU as follows:



D5 ==> write disable -> pin 4 on the CD4099B

D7 ==> data -> pin 3 on the CD4099B

D1 ==> address pins A0  -> pin 5  on the CD4099B 

D2 ==> address pins A1  -> pin 6  on the CD4099B

D4 ==> address pins A2  -> pin 7  on the CD4099B



Latch 2 provides digital ouput pins 8 - 15. The second latch chip is optional. Connect the second latch chip to the ESP8266 NodeMCU as follows:



D6 ==> write disable -> pin 4 on the CD4099B

D7 ==> data -> pin 3 on the CD4099B

D1 ==> address pins A0  -> pin 5  on the CD4099B 

D2 ==> address pins A1  -> pin 6  on the CD4099B

D4 ==> address pins A2  -> pin 7  on the CD4099B



The class LatchCD4099BDriver is used to manage the digital output pins. Example code:



#include "latch-cd4099B.h"



LatchCD4099BDriver latch(true); 


//  true -> indicates we are using two latches to make it 16 digital output pins.
//  false -> indicates we are using only one latch to make it 8 digital output pins.



void setup() {
  
  

    //  latch.enableSerialMonitor =true; 
    
    latch.begin();
}
int oldValue=0;
}


void loop() {
      

     // put your main code here, to run repeatedly:
  
     for (int pin=0;pin<16;pin++)
  
     {

          if(oldValue==LOW)
 
          {
   
               oldValue=HIGH;
 
          }
 
          else

          {
   
               oldValue=LOW;

          }
          
          latch.setPin(pin,oldValue);

          delay(1000);
  
      }
 
}
 
==================================================================================================
 

The CD74HC4067 multiplexer/de-multiplexer provides 16 input pins of which eight pins are used for analog inputs, and eight for digital inputs. Connect the de-multiplexer chip CD74HC4067 to the ESP8266 NodeMCU as follows:
 


A0 ==> Signal line on the breakout module

D8 ==> Signal line on the breakout module

D1 ==> select pin S0 

D2 ==> select pin S1 

D4 ==> select pin S2

D0 ==> select pin S3 



Pins C0 - C7 on the CD74HC4067 breakout module are the analog inputs 0 - 7, and pins C8 - C15 are the digital inputs 0 -7.

 The class MultiAnalogDigitalRead is used to manage the digital and analog pins. Example code:



#include "multiplexer-CD74HC4067-16-lines.h"



MultiAnalogDigitalRead multiread;



void setup() {
  
 

     //   multiread.enableSerialMonitor =true; 
    
     multiread.begin();
}


void loop() {
 
     // put your main code here, to run repeatedly:
  
     int val;
  
     for (int pin=0;pin<8;pin++)
  
     {
         
          val = multiread.readAnalog(pin);
 
         //do something with val
         
          delay(1000);
   
     }
   
     for (int pin=0;pin<8;pin++)
  
     {
         
          val = multiread.readDigital(pin);
  
          //do something with val
         
          delay(1000);
   
     }
 
}

See the provided schematic image for wiring the chips and breakout module.
