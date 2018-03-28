#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int estopPin = 32;

const int waterPumpPin = 22;
const int ArgonPin = 23;
const int VaccumePin = 24;
const int WelderPin = 25;
const int TankVentPin = 26;
const int PumpCutoutPin = 27;
const int arcStartPin = 29;
const int aux = 28;

float waterTemp = 000.0; //degf
float crucableTemp = 000.0; //degf
float chamberVaccume = 000.0; //mtor

LiquidCrystal_I2C lcd(0x27,20,4);

bool estop;

bool debugMode = true;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.home();
  lcd.backlight();
  pinSetup();
}

void loop() {
    eStopCheck();  // This function WORKS!!!
    //checkRelays();
}
