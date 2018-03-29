void statusDisplay(){
  if (debugMode){
    lcd.clear();
    lcd.print("DEBUGMODE ON");

  }else{
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("WTEMP:");lcd.setCursor(0,7); lcd.print(waterTemp);
    lcd.setCursor(1,1);
    lcd.print("CTEMP:");lcd.setCursor(1,7); lcd.print(crucableTemp);
    lcd.setCursor(2,1);
    lcd.print("VACCU:");lcd.setCursor(2,7); lcd.print(chamberVaccume);
    lcd.setCursor(3,1);
  }
  //Here we can put other stuff
}
