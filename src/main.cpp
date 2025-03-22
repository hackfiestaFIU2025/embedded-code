#include <Arduino.h>

#define output 15
#define lowMinus 2
#define lowPlus 4

void setup(){
  Serial.begin(115200);
  Serial.print("EKG demo");
  pinMode(lowMinus, INPUT);
  pinMode(lowPlus, INPUT);
}

void loop(){
  if((digitalRead(lowMinus) == 1)||(digitalRead(lowPlus) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      float volt = analogRead(output) * (3.3 / 4095.0);
      Serial.print(volt, 4);
      Serial.println();
  }
  //Wait for a bit to keep serial data from saturating
  delay(50);

}