void displayWaterTemp(int col){
  lcd.setCursor(0,col);
  lcd.print("WATERTEMP:");
  lcd.setCursor(11,col);
  lcd.print(waterTemp);
  lcd.setCursor(19,col);
  lcd.print("F");
}

void displayCrusableTemp(int col){
  lcd.setCursor(0,col);
  lcd.print("CRUSABLETEMP:");
  lcd.setCursor(14,col);
  lcd.print(crucableTemp);
  lcd.setCursor(19,col);
  lcd.print("F");
}

void displayVaccume(int col){
  lcd.setCursor(0,col);
  lcd.print("VACCUM:");
  lcd.setCursor(8,col);
  lcd.print(chamberVaccume);
  lcd.setCursor(16,col);
  lcd.print("InHg");
}

void displayTheCurrentStepNumber(int col){
  lcd.setCursor(0,col);
  lcd.print("Current Step:");
  lcd.setCursor(14,col);
  lcd.print(currentStep);
}
void displayTheCurrentStep(int col){
  lcd.setCursor(0,col);
    if (currentStep==0){
      lcd.print("WAITING TO START... ");
    }else if(currentStep==1){
      lcd.print("PUMPING DOWN        ");
    }else if(currentStep==2){
      lcd.print("ARGON INPUT         ");
      lcd.setCursor(12,col);
      lcd.print(endtime - starttime);
    }else if(currentStep==3){
      lcd.print("PUMPING DOWN        ");
    }else if(currentStep==4){
      lcd.print("WAITING FOR IN      ");
    }else if(currentStep==5){
      lcd.print("WELDING             ");
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
  lcd.print("3/2018");
  delay(3000);
  lcd.clear();
}

void statusBar(int col){
  if (digitalRead(waterPumpPin)){
    lcd.setCursor(6,col);
    lcd.print("WPUMP|");
  } else {
    lcd.setCursor(6,3);
    lcd.print("     |");
  }

  if (digitalRead(VaccumePin)){
    lcd.setCursor(12,col);
    lcd.print("VPUMP|");
  } else {
    lcd.setCursor(12,col);
    lcd.print("     |");
  }

  if (estop){
    lcd.setCursor(0,col);
    lcd.print("ESTOP|");
  }else{
    lcd.setCursor(0,col);
    lcd.print("     |");
  }

  if (welderOn){
    lcd.setCursor(18,col);
    lcd.print("WE");
  }else{
    lcd.setCursor(18,col);
    lcd.print("   ");
  }

  if (debugMode){
    lcd.setCursor(18,col);
    lcd.print("BG");
  }else{
    lcd.setCursor(18,col);
    lcd.print("  ");
  }
}



// void eStopDisplay(){
//   if (estop){
//     lcd.setCursor(0,3);
//     lcd.print("ESTOP|");
//   }else{
//     lcd.setCursor(0,3);
//     lcd.print("     |");
//   }
// }
