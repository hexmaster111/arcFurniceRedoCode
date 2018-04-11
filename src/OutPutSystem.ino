

void relayControl(int pin,bool opp){
  if (!digitalRead(pin) && (opp) && (!estop)){ // if pin low and opp high
      digitalWrite(pin, HIGH); // set the pin high
    }else if (digitalRead(pin) && (!opp)){ // if pin high and opp LOW
      digitalWrite(pin, LOW);     // set pin LOW
  }
}

void relayForTime(int pin, bool opp, int time){
//run a relay for an amount of time

}



void pinSetup(){
  pinMode(estop, INPUT_PULLUP);
  pinMode(waterPumpPin ,OUTPUT);
  pinMode(ArgonPin ,OUTPUT);
  pinMode(VaccumePin ,OUTPUT);
  pinMode(WelderPin ,OUTPUT);
  pinMode(TankVentPin ,OUTPUT);
  pinMode(PumpCutoutPin ,OUTPUT);
  pinMode(arcStartPin ,OUTPUT);
  pinMode(aux, OUTPUT);
  pinMode(statusLED, OUTPUT);
}

void lcdSetUp(){
  Wire.begin();
  Wire.beginTransmission(0x27);
  lcd.begin(20, 4); // initialize the lcd and set size
  lcd.home();lcd.setBacklight(1);
}
