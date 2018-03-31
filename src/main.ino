#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address



const int versionNumber = 2;

const int estopPin = 32;
const int eStopResetPin = 33;

const int debugKey = 38;


const int waterPumpPin = 22;
const int ArgonPin = 23;
const int VaccumePin = 24;
const int WelderPin = 25;
const int TankVentPin = 26;
const int PumpCutoutPin = 27;
const int arcStartPin = 29;
const int aux = 28;

const int statusLED = 13;

float waterTemp = 000.0; //degf
float crucableTemp = 000.0; //degf
float chamberVaccume = 000.0; //mtor



bool estop = true;//Start Estoped
bool StopPrintedflag = false;

bool debugMode = true; //switch this after wireing and testing

bool atVaccume;

void setup() {
  Serial.begin(9600);
  lcdSetUp();
  pinSetup();
  Serial.print("------ Stared version: ");
  Serial.print(versionNumber);
  Serial.println(" ------");
  initMessage();


}

void loop() {
    checkResetEstop();
    eStopCheck();  // This function WORKS!!!
    startPumpDown(); //called when we want to start pumping down, here for debug
    //checkRelays();
    //startPumpDown();
}
