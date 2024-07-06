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


 
unsigned int stage = 1;
unsigned int mode = 0;
unsigned int digit_num = 0;
unsigned int buttonA_count = 1;
unsigned int buttonB_count = 0;
unsigned int buttonA_count1 = 1;
unsigned int buttonB_count1 = 0;
unsigned int buttonA_val = 0;
unsigned int buttonB_val = 0;

int math_valA = 0;
int math_valB = 0;
int math_valSum = 0;
int math_valUSR = 0;

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

  math_valA = random(2,9);
  math_valB = random(2,9);
  delay(100);

  if (ButtonB == 1) {
    // turn LED on:
      delay(100);
     if(ButtonB == 1) {
        buttonB_count1 = buttonB_count1 + 1;
        Serial.write(buttonB_count1);
        display.clearDisplay();  
     }
  }

  if (ButtonA == 1) {
    // turn LED on:
    delay(100);
    if(ButtonA == 1) {
        buttonA_count1 = buttonA_count1 + 1;
        Serial.write(buttonA_count1);
        display.clearDisplay();  
    }
  }

  if (stage == 1){
    if (buttonB_count1 % 2 == 0) { //Checks if the toggle var is even 
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
   
  if (buttonA_count1 % 2 == 0) { //Checks if the toggle var is even 
    // turn LED on:
    
    stage = 2;
    mode = 1;
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

      if (ButtonB == 1) {
    // turn LED on:
      delay(100);
     if(ButtonB == 1) {
        math_valUSR = math_valUSR + 1;
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



    if(mode == 1)
    {
      math_valA = random(2,9);
      math_valB = random(2,9);
      math_valSum = math_valA + math_valB;
      Serial.write(math_valSum);
      display.setCursor(0, 0);
      display.setTextSize(3);
      display.println(F("ANSWER:"));
      display.setCursor(0, 30);
      display.setTextSize(2);
      display.println(math_valA);
      display.setCursor(20, 30);
      display.println("+");
      display.setCursor(40, 30);
      display.println(math_valB);
      display.setCursor(60, 30);
      display.println("=");
      display.setCursor(0, 47);
      display.setTextSize(2);
      display.println(math_valSum);
      display.display();
    }
  }
  delay(100);
}

}


