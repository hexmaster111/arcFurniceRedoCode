



void eStopCheck(){
  statusLight(); //to chaing the statusLED when the estopVar changes
  if(digitalRead(estopPin) or (estop == true)){
    //were not estoped
    //estop = false;
    //Serial.println("notEstoped");
  }else{ //digitalWrite used to force them low, rather then the relay control function
    digitalWrite(waterPumpPin , false);
    digitalWrite(ArgonPin     , false);
    digitalWrite(VaccumePin   , false);
    digitalWrite(WelderPin    , false);
    digitalWrite(TankVentPin  , false);
    digitalWrite(PumpCutoutPin, false);
    digitalWrite(arcStartPin  , false);
    digitalWrite(aux          , false);
    estop = true;
    eStopMessage();
    currentStep = 0;
  }
  debugSafty();
}

void debugSafty(){
  if (debugMode){
    digitalWrite(WelderPin    , false);
    digitalWrite(arcStartPin  , false);
  }
}


void checkResetEstop(){ //To reset the eStop after pressing
  if ((estop == true) && (digitalRead(eStopResetPin)) && (digitalRead(estopPin))){
      estop = false;
      resetVars();
      Serial.println("Estop Reset!");
      tone(buzzer,1000,75);
  }
}



void statusLight(){
  if (estop){
    digitalWrite(statusLED, HIGH);
  }else{
    digitalWrite(statusLED, LOW);
  }
}
