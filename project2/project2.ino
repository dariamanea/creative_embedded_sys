/*
This is an example how to use Touch Intrrerupts and read touch values
*/

int threshold = 40;

void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
}

void loop(){
  Serial.println(digitalRead(13));
  delay(500); 
  Serial.println(analogRead(12));
 
}
