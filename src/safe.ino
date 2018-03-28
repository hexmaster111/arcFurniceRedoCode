void eStopCheck(){
  if(digitalRead(estopPin) or (estop == true)){
    //were not estoped
    //estop = false;
  }else{
    digitalWrite(waterPumpPin , false);
    digitalWrite(ArgonPin     , false);
    digitalWrite(VaccumePin   , false);
    digitalWrite(WelderPin    , false);
    digitalWrite(TankVentPin  , false);
    digitalWrite(PumpCutoutPin, false);
    digitalWrite(arcStartPin  , false);
    digitalWrite(aux          , false);
    estop = true;
    //Serial.println(estop);
  }
}


void resetEstop(){ //To reset the eStop after pressing
  if (estop == true){
    if (digitalRead(!eStopResetPin)){
      estop = false;
      resetVars();
    }
  }
}
