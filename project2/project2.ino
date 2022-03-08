/*
This is an example how to use Touch Intrrerupts and read touch values
*/
#include <ArduinoJson.h>


int threshold = 40;
DynamicJsonDocument doc(1024);

void setup() {
  Serial.begin(115200);
//  Serial.begin(9600);
  // button
  pinMode(13, INPUT_PULLUP);
  // SW from joystick 
  pinMode(25, INPUT_PULLUP);

}


void loop(){

  // button
  Serial.print("b");
  Serial.println(digitalRead(13));
  delay(10);

// potentiometer 
  Serial.print("p");
  Serial.println(analogRead(12));
  delay(10); 
  
//// SW
//    Serial.print("sw");
//    Serial.println(digitalRead(25));
//    delay(10); 
 
// potentiometer VRY 
      Serial.print("y");
      Serial.println(analogRead(27));
      delay(10); 

//    potentiometer VRX
    Serial.print("x");
    Serial.println(analogRead(26));
    delay(200); 
}
