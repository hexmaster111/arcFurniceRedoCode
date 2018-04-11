
void displayStepsmanager(){
  if ((currentStep == 0) or (currentStep == 4)){
    stepsDisplay();
  }else{
    statusDisplay();
  }
}



void statusDisplay(){
  statusBar(0);
  displayWaterTemp(1);
  displayCrusableTemp(2);
  displayVaccume(3);
}


void stepsDisplay(){
  displayTheCurrentStepNumber(0);
  displayTheCurrentStep(1);
  displayVaccume(2);
  statusBar(3);
}
