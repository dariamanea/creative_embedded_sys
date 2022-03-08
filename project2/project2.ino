/*
This is an example how to use Touch Intrrerupts and read touch values
*/
#include <ArduinoJson.h>


int threshold = 40;
DynamicJsonDocument doc(1024);

void setup() {
//  Serial.begin(115200);
  Serial.begin(9600);
  // button
  pinMode(13, INPUT_PULLUP);
  // SW from joystick 
  pinMode(25, INPUT_PULLUP);

}


void loop(){
  
//  doc["button"] = digitalRead(13);
  doc["potentiometer"]   = analogRead(12);
  doc["vrx"][0] = analogRead(26);
  doc["vry"][1] = analogRead(27);
  doc["sw"][1] = digitalRead(25);
  serializeJson(doc, Serial);

  delay(1);
  
  // button
//  Serial.print("Button ");
//  Serial.println(digitalRead(13));

//  delay(500); 
  
  // potentiometer 
//  Serial.println(analogRead(12));
//  delay(500); 
  
  // SW
//  Serial.println(digitalRead(25));
//  delay(500); 
  
   // potentiometer VRY 
//  Serial.println(analogRead(27));
//  delay(500); 
  
   // potentiometer VRX
//  Serial.println(analogRead(26));
//  delay(500); 
}
