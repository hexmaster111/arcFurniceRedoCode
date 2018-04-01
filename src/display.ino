void statusDisplay(){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("WTEMP:");lcd.setCursor(0,7); lcd.print(waterTemp);
  lcd.setCursor(1,1);
  lcd.print("CTEMP:");lcd.setCursor(1,7); lcd.print(crucableTemp);
  lcd.setCursor(2,1);
  lcd.print("VACCU:");lcd.setCursor(2,7); lcd.print(chamberVaccume);
  lcd.setCursor(3,9);
  if (debugMode){
    lcd.clear();
    lcd.print("DEBUGMODE ON");
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
