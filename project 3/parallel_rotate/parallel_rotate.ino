#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>

Servo myservo;  // create servo object to control a servo
static int taskCore = 0;  // the core that we want our other code to run on 
String address= "http://134.122.113.13/uni/running";
const char *ssid_Router     = "Barnard Guest"; //Enter the router name
const char *password_Router = ""; //Enter the router password

bool buttonPressed = false; 

void coreTask( void * pvParameters ){
//    run only 
    String taskMessage = "Task running on core "; 
      runMotor();
}

int posVal = 0;    // variable to store the servo position
int stopVal = 0;   // varibale to store the servo end position 
int servoPin = 13; // Servo motor pin

// Connect the port of the stepper motor driver
int outPorts[] = {33, 27, 26, 25};

/** Flag if task should run */
bool tasksEnabled = false;

void setup() {
  Serial.begin(9600);
  delay(1000);

//  wifi setup

  WiFi.begin(ssid_Router, password_Router);
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup End");
  
  // servo set up 
  myservo.setPeriodHertz(50);           // standard 50 hz servo
  myservo.attach(servoPin, 500, 2500);  // attaches the servo on servoPin to the servo object
  
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }

  Serial.print("Starting to create task on core ");
  Serial.println(taskCore);

  xTaskCreatePinnedToCore(
                    coreTask,   /* Function to implement the task */
                    "coreTask", /* Name of the task */
                    10000,      /* Stack size in words */
                    NULL,       /* Task input parameter */
                    0,          /* Priority of the task */
                    NULL,       /* Task handle. */
                    taskCore);  /* Core where the task should run */
 
  Serial.println("Task created...");
}

void runMotor(){
  while(true){
    Serial.println(buttonPressed);
    if (buttonPressed == true){
      for (posVal = 0; posVal <= 180; posVal += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(posVal);       // tell servo to go to position in variable 'pos'
        delay(15);                   // waits 15ms for the servo to reach the position
      }
      for (posVal = 180; posVal >= 0; posVal -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(posVal);       // tell servo to go to position in variable 'pos'
        delay(15);                   // waits 15ms for the servo to reach the position
      }
  }
  }
}

void loop() {
  Serial.println("entering loop");
  Serial.println(WiFi.status());
  if((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(address);
 
    int httpCode = http.GET(); // start connection and send HTTP header
    Serial.print("httpCode: ");
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK) { 
        String response = http.getString();
        if (response.equals("false")) {
             buttonPressed = false; 
            // Do not run sculpture, perhaps sleep for a couple seconds
            Serial.println("sculpture should not run");
        }
        else if(response.equals("true")) {
             buttonPressed = true; 
            // Run sculpture
              Serial.println("Starting main loop...");
             //  in here run the code for stepper motor 
            // Rotate a full turn
            moveSteps(true, 32 * 64, 3);
            delay(500);
            // Rotate a full turn towards another direction
            moveSteps(false, 32 * 64, 3);
            delay(500);
        }
        Serial.println("Response was: " + response);
    } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
    delay(500); // sleep for half of a second
  }
}

//Suggestion: the motor turns precisely when the ms range is between 3 and 20
void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(constrain(ms,3,20));        // Control the speed
  }
}

void moveOneStep(bool dir) {
  // Define a variable, use four low bit to indicate the state of port
  static byte out = 0x01;
  // Decide the shift direction according to the rotation direction
  if (dir) {  // ring shift left
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {      // ring shift right
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // Output singal to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}
