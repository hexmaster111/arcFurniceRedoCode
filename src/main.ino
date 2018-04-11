#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

//TODO ADD A BUZZER BEFORE THE FLYBACK DRIVER KICKES ON

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address

const int versionNumber = 2;

const int estopPin = 32;
const int eStopResetPin = 33;

const int debugKey = 38;

const int startKey = 49;

const int waterPumpPin = 22;
const int ArgonPin = 23;
const int VaccumePin = 24;
const int WelderPin = 25;
const int TankVentPin = 26;
const int PumpCutoutPin = 27;
const int arcStartPin = 29;
const int aux = 28;

const int buzzer = 44;

const int statusLED = 13;

int waterTemp = 0; //degf
int crucableTemp = 0; //degf
float chamberVaccume = 000.0; //mtor

int currentStep = 0; //should be zero,set for debug
int argonInputTime = 2000;//millisec

bool estop = true;//Start Estoped
bool StopPrintedflag = false;
bool welderOn = false;
bool watterPumpRunning;

bool debugMode = true; //switch this after wireing and testing
bool atVaccume;

unsigned long starttime;
unsigned long endtime;

void setup() {
  Serial.begin(9600);
  lcdSetUp();
  pinSetup();
  initMessage();
  tone(buzzer,1000,75);
}

void loop() {
    periotics();
    runLoop();
}

void periotics(){
  checkResetEstop();
  eStopCheck();
  displayStepsmanager();
  eStopCheck();
  checkVaccume();
}
