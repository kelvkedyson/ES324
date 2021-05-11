/*
  For simulation purposes alone
*/

int bulbRelay = 7, bulbLED = 12, bulbBtn = 4;
int fanRelay = 6, fanLED = 11, fanBtn = 3;
int receiver = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(bulbRelay, OUTPUT);
  pinMode(fanRelay, OUTPUT);
  pinMode(bulbLED, OUTPUT);
  pinMode(fanLED, OUTPUT);
  pinMode(receiver, INPUT);
  pinMode(bulbBtn, INPUT);
  pinMode(fanBtn, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(receiver) == HIGH){
    //do something
    if(digitalRead(bulbBtn) == HIGH && digitalRead(fanBtn) == HIGH){
      //power ON bulb and fan
      powerONBulb();
      powerONFan();
    }else if(digitalRead(bulbBtn) == HIGH && digitalRead(fanBtn) == LOW){
      powerONBulb();
      powerOFFFan();
    }else if(digitalRead(bulbBtn) == LOW && digitalRead(fanBtn) == HIGH){
      powerONFan();
      powerOFFBulb();
    }else{
      powerOFFBulb();
      powerOFFFan();
    }
  }else{
    //power OFF all appliances
    powerOFFBulb();
    powerOFFFan();
  }
  

}

void powerONBulb(){
  digitalWrite(bulbRelay, HIGH);
  digitalWrite(bulbLED, HIGH);
}

void powerOFFBulb(){
  digitalWrite(bulbRelay, LOW);
  digitalWrite(bulbLED, LOW);
}

void powerONFan(){
  digitalWrite(fanRelay, HIGH);
  digitalWrite(fanLED, HIGH);
}

void powerOFFFan(){
  digitalWrite(fanRelay, LOW);
  digitalWrite(fanLED, LOW);
}
