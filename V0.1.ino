#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix microbit;

// Define the display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the reset pin (use -1 if no reset pin is used)
#define OLED_RESET -1

// Initialize the OLED display with I2C address 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


 
int stage = 1;
int mode = 0;
int digit_num = 0;
int buttonA_count = 1;
int buttonB_count = 0;
int buttonA_val = 0;
int buttonB_val = 0;

int ButtonA = 0;
int ButtonB = 0;


void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the display with I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the I2C address for the OLED display
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);

  display.clearDisplay();
  microbit.begin();
  display.display();

  display.clearDisplay();

  // Start sequence
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Plush"));
  display.setCursor(0, 30);
  display.println(F(":Bit"));
  microbit.show(microbit.HEART);

  // Update the display with the new content
  display.display();

  delay(2000);

  display.clearDisplay();
  display.display();


}

void loop() {

  ButtonA = ! digitalRead(PIN_BUTTON_A);
  ButtonB = ! digitalRead(PIN_BUTTON_B);

  if (ButtonB == 1) {
    // turn LED on:
      delay(100);
     if(ButtonB == 1) {
        buttonB_count = buttonB_count + 1;
        Serial.write(buttonB_count);
        display.clearDisplay();  
     }
  }

  if (ButtonA == 1) {
    // turn LED on:
    delay(100);
    if(ButtonA == 1) {
        buttonA_count = buttonA_count + 1;
        Serial.write(buttonA_count);
        display.clearDisplay();  
    }
  }

  if (stage == 1){
    if (buttonB_count % 2 == 0) { //Checks if the toggle var is even 
      // turn LED on:
    display.setCursor(0, 0);
    display.setTextSize(3);
    display.println(F("> Math"));
    display.setCursor(0, 30);
    display.setTextSize(2);
    display.println(F("A to Start"));
    display.setCursor(0, 47);
    display.setTextSize(2);
    display.println(F("B to Move"));
    display.display();
   
  if (buttonA_count % 2 == 0) { //Checks if the toggle var is even 
    // turn LED on:
    
    stage = 2;
    mode = 1;
    delay(10);
    display.clearDisplay();
    display.display();
    delay(10);

  } else {
    // turn LED off:
  } 

  } else {
    // turn LED off:
   display.setCursor(0, 0);
   display.setTextSize(3);
   display.println(F("> Read"));
   display.setCursor(0, 30);
   display.setTextSize(2);
   display.println(F("A to Start"));
   display.setCursor(0, 47);
   display.setTextSize(2);
   display.println(F("B to Move"));
   display.display();
  } 
  if(stage == 2){
    if(mode == 1){
      if (buttonB_count % 2 == 0) {
        display.setCursor(0, 0);
        display.setTextSize(3);
        display.println(F("Single"));
        display.setCursor(0, 30);
        display.setTextSize(2);
        display.println(F("A to Start"));
        display.setCursor(0, 47);
        display.setTextSize(2);
        display.println(F("B to Move"));
        display.display();
      } else {
        display.setCursor(0, 0);
        display.setTextSize(3);
        display.println(F("Double"));
        display.setCursor(0, 30);
        display.setTextSize(2);
        display.println(F("A to Start"));
        display.setCursor(0, 47);
        display.setTextSize(2);
        display.println(F("B to Move"));
        display.display();
      }
    }
  }
  delay(100);
}

}


