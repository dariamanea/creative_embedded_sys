#include "Freenove_WS2812_Lib_for_ESP32.h"
#define LEDS_COUNT 144 // The number of led
#define LEDS_PIN 2 // define the pin connected to the Freenove 8 led strip
#define CHANNEL 0 // RMT channel
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
bool close_enough = false; 

//Distance sensor pins
#define echoPin 13 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 15 //attach pin D3 Arduino to pin Trig of HC-SR04


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  //  LEDs
  strip.begin();
//  strip.setBrightness(10);
//Set up the baselevel brightness
  strip.setBrightness(2);
}
void loop() {
  if (close_enough == true){
      for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, 255, 255, 255);
      strip.show();
    }
  }
  else {
//      strip.setLedColorData(2, 255, 255, 255);
      strip.show();
    }
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 50) {
   close_enough = true; 
  }
  else {
      close_enough = false;  
    }
}
