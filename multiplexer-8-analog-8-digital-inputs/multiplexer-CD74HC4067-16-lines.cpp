#include "multiplexer-CD74HC4067-16-lines.h"

bool MultiAnalogDigitalRead::enableSerialMonitor=false;


MultiAnalogDigitalRead::MultiAnalogDigitalRead()
{
     initialized = false;
}
MultiAnalogDigitalRead::~MultiAnalogDigitalRead()
{
  
}


void MultiAnalogDigitalRead::begin()
{
  
   if(enableSerialMonitor)
   {  
        Serial.println("================================================");
        Serial.println("**** staring multi analog/digital inputs Driver class ****");
   }  
   
   // *** selectPin = D0 ==> LOW = analog read select; HIGH = digital read select
   pinMode(selectPin,OUTPUT);
 
   // digitalReadPin  = D8;  // digital data pin
    pinMode(digitalReadPin,INPUT);

    // addressPins0 = D1;
    // addressPins1 = D2;
    // addressPins2 = D4;  //Address pins A0, A1, A2
    pinMode(addressPins0,OUTPUT);
    pinMode(addressPins1,OUTPUT);
    pinMode(addressPins2,OUTPUT);

    initialized=true;
}
int MultiAnalogDigitalRead::readDigital(int pin)
{
     if(pin<0 || pin>7)
     {
           if(enableSerialMonitor)
           {                             
                Serial.print("Invalid pin number ->");
                Serial.println(pin+8);
           }    
           return -1;        
     }        
     setAddress(pin+8);
     int val=digitalRead(digitalReadPin);
     return val;
}
int MultiAnalogDigitalRead::readAnalog(int pin)
{  
     if(pin<0 || pin>7)
     {
           if(enableSerialMonitor)
           {                             
                Serial.print("Invalid pin number ->");
                Serial.println(pin);
           }    
           return -1;        
     }           
     setAddress(pin);  
     int val=analogRead(analogReadPin);
     return val;
}
void MultiAnalogDigitalRead::setAddress(int pinNumber)
{
    if(enableSerialMonitor)
    {                             
        Serial.print("CALLED setAddress(");
        Serial.print(pinNumber);
        Serial.println(")");
    }    
    if(!initialized)
    {
          if(enableSerialMonitor)
          {                             
              Serial.println("*** MultiAnalogDigitalRead Class instance not initialized. Call begin() first to initialize this class. ***");
          }    
          return;
     }
    
    //set address line 0
    int address= pinNumber & 0x01;
    digitalWrite(addressPins0, address);
   
    address= (pinNumber & 0x02) >> 1;
    digitalWrite(addressPins1, address);

    address= (pinNumber & 0x04) >> 2;
    digitalWrite(addressPins2, address);

    address= (pinNumber & 0x08) >> 3;
    digitalWrite(selectPin,address);
}

