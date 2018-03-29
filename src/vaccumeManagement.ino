void checkVaccume(){
  //our vacc check stuff
  if(digitalRead(debugKey)){
    atVaccume = true;
  }else{
    atVaccume = false;
  }
}
