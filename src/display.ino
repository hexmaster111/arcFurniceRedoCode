void statusDisplay(){
  lcd.clear();
  eStopDisplay();
  lcd.setCursor(0,1);
  lcd.print("WATERTEMP:");lcd.setCursor(0,11); lcd.print(waterTemp);
  lcd.setCursor(1,1);
  lcd.print("CTEMP:");lcd.setCursor(1,7); lcd.print(crucableTemp);
  lcd.setCursor(2,1);
  lcd.print("VACCU:");lcd.setCursor(2,7); lcd.print(chamberVaccume);
  lcd.setCursor(3,9);

  if (debugMode){
    lcd.setCursor(3,9);
    lcd.print("DEBUG ON");
  }
}


void stepsDisplay(){
  lcd.clear();
  eStopDisplay();
  lcd.setCursor(0,0);
  lcd.println("CURRENT STEP:");
  lcd.setCursor(1,0);
  stepFunction();

}


void eStopDisplay(){
  if (estop){
    lcd.setCursor(3,0);
    lcd.print("ESTOP|");
  }else{
    lcd.setCursor(3,6);
    lcd.print("|");
  }
}

void stepFunction(){
    if (currentStep==0){
      lcd.println("PUMPING DOWN");
    }else if(currentStep==1){
      lcd.println("");
    }else if(currentStep==2){
      lcd.println("");
    }else if(currentStep==3){
      lcd.println("");
    }else if(currentStep==4){
      lcd.println("");
    }else if(currentStep==5){
      lcd.println("");
    }else{
      lcd.println(currentStep);
    }
}


void initMessage(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ARC Control");
  lcd.setCursor(0,1);
  lcd.print("Version:");
  lcd.setCursor(9,1);
  lcd.print(versionNumber);
  lcd.setCursor(9,2);
  lcd.print("THE SHED");
  lcd.setCursor(9,3);
  lcd.print("3/31/18");
  delay(1000);
}
