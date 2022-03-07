/*
This is an example how to use Touch Intrrerupts and read touch values
*/

int threshold = 40;

void setup() {
  Serial.begin(115200);
  // button
  pinMode(13, INPUT_PULLUP);
  // SW from joystick 
  pinMode(25, INPUT_PULLUP);

}


void loop(){
  // button
  Serial.println(digitalRead(13));
  delay(500); 
  // potentiometer 
  Serial.println(analogRead(12));
  delay(500); 
  // SW
  Serial.println(digitalRead(25));
  delay(500); 
   // potentiometer VRY 
  Serial.println(analogRead(27));
  delay(500); 
   // potentiometer VRX
  Serial.println(analogRead(26));
  delay(500); 




 
}
