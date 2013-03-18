#include <RCSwitch.h>
int value;

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
   value = mySwitch.getReceivedValue();
   if(value>0){

    if(mySwitch.getReceivedBitlength() == 10 && value != 0)
    {
      Serial.print("H = ");
      Serial.println(value);
    }
    if(mySwitch.getReceivedBitlength() == 11 && value != 0)
    {
      Serial.print("V = ");
      Serial.println(value);
    }
   }
}
   
