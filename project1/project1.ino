/*  
 Test the tft.print() viz embedded tft.write() function

 This sketch used font 2, 4, 7
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

#define TFT_GREY 0x5AEB // New colour
char *problems[]={" a nose bruise ", " a hairy carrot ", " dry skin ", " spilling coffee on myself "};
long p;

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  p = random(sizeof(problems)/sizeof(char*));
  
  
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  tft.fillScreen(TFT_BLACK);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_YELLOW,TFT_BLACK);  tft.setTextSize(2);
  // We can now plot text on screen using the "print" class
  int number_of_problems = random(100);
  char problem[] = "arduino documentation";
  tft.print("I got ");  
  tft.print(number_of_problems);  
  tft.println(" problems but "); 
  tft.setTextColor(TFT_ORANGE);
  tft.setTextFont(1);
  tft.println(problems[p]);
  tft.setTextColor(TFT_YELLOW);  tft.setTextSize(3);
  tft.print(" ain't one.");
  
  

  while(1) yield(); // We must yield() to stop a watchdog timeout.
}
