void eStopCheck(){
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
    //Serial.println("estop");

  }
}


void checkResetEstop(){ //To reset the eStop after pressing
  if ((estop == true) && (digitalRead(eStopResetPin))){
      estop = false;
      resetVars();
      Serial.println("resetVars");
  }
}
