void checkVaccume(){
  //our vacc check stuff
  if(digitalRead(debugKey)){
    atVaccume = true;
  }else{
    atVaccume = false;
  }
}

void getVaccMeasure(){
  chamberVaccume = 000.0;
}
