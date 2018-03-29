
void eStopMessage(){
  if (StopPrintedflag == 0){
    Serial.println("Estop Pressed!");
    StopPrintedflag = 1;
  }
}



void resetVars(){
  StopPrintedflag = 0;
}
