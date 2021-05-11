#include "IRremote.h"

int receiver = 5;
int bulbRelay = 7;
int fanRelay = 6;

IRrecv irrecv(receiver);
decode_results results;

void translateIR(){
  Serial.println(results.value,HEX);
  switch(results.value){
      case 0xFFA25D: 
        Serial.println("POWER ON");
        powerONBulb(); 
      break;
      case 0xFFE21D: 
        Serial.println("POWER OFF"); 
        powerOFFBulb();
       break;
       case 0xFF629D:
        Serial.println("FAN ON");
        powerONFan();
        break;
       case 0xFFA857:
        Serial.println("FAN OFF");
        powerOFFFan();
        break;
      default:
        Serial.println("UNKNOWN KEY");
  }
}

void setup(){
  pinMode(bulbRelay, OUTPUT);
  pinMode(fanRelay, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); //starting the receiver
}
 
void loop(){
  //checking if the IR are received
  if(irrecv.decode(&results)){
    translateIR();
    irrecv.resume();
  }
}

//function to power on a bulb_relay
void powerONBulb(){
  digitalWrite(bulbRelay, HIGH);
}

//function to power off a bulb_relay
void powerOFFBulb(){
  digitalWrite(bulbRelay, LOW);
}

//function to power on a fan_relay
void powerONFan(){
  digitalWrite(fanRelay, HIGH);
}

//function to power off a fan_relay
void powerOFFFan(){
  digitalWrite(fanRelay, LOW);
}
