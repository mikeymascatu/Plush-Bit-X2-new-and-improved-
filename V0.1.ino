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
}

void loop() {

  delay(2000);
}
