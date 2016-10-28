#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// set pin numbers:
const int buttonPinR = 13;     // the number of the pushbutton pin
const int buttonPinL = 2;     // the number of the pushbutton pin
const int ledPin =  LED_BUILTIN;      // the number of the LED pin

// variables will change:
int buttonStateR = 0;         // variable for reading the pushbutton status
int buttonStateL = 0;
int setpoint = 20;
int mult = 10;

void setup() {
  drawSetup();
  pinMode(buttonPinR, INPUT);
  pinMode(buttonPinL, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateR = digitalRead(buttonPinR);
  buttonStateL = digitalRead(buttonPinL);
  if (buttonStateR == HIGH) setSetpointUP();
  if (buttonStateL == HIGH) setSetpointDOWN(); 
  draw();
}

void drawSetup(){
  display.begin();
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(2);
  display.clearDisplay();
}

void draw(){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(setpoint);
  display.display();
  delay(120);
}


void setSetpointUP(){
    setpoint = setpoint + mult;
}

void setSetpointDOWN(){
    setpoint = setpoint - mult;
}



