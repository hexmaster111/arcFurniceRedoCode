void eStopCheck(){
  if(digitalRead(estopPin)){
    //were not estoped
    estop = false;
  }else{
    digitalWrite(waterPumpPin , false);
    digitalWrite(ArgonPin     , false);
    digitalWrite(VaccumePin   , false);
    digitalWrite(WelderPin    , false);
    digitalWrite(TankVentPin  , false);
    digitalWrite(PumpCutoutPin, false);
    digitalWrite(arcStartPin  , false);
    digitalWrite(aux , false);
    estop = true;
    //Serial.println(estop);
  }
}
