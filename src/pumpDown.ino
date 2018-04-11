

void runLoop(){
    if(currentStep==1){
      PumpLoop();
    }else if(currentStep==2){
      Serial.println("at step two");
      inputArgon();
    }else if(currentStep==3){
      PumpLoop();
    }else if(currentStep==4){
      waitForKey4();
      Serial.println("waiting for input");
    }else if(currentStep==5){
      tone(buzzer,1000,5000);
      relayControl(WelderPin, true);

      //weld n' go
      //Serial.println("at step five");
  }
}

// pumptovaccume = 1  handles when to stop
// input Argon = 2
// prompt = 3


// //thought spot
// //PumpDown
// open pump cutout
// start pumping
// stop pump @ Vaccume
// close pump cutout
// open argon valve
// wait 2 sec
// close argon valve
// open vaccume PumpCutout
// start pumping
// stop pumping @ vaccume
// close vaccue pump cut out
// //at vaccume and clean
// prompet to start and stop welder and start pumpdown

void arcHit(){
  relayControl(arcStartPin, true);
  delay(50)
  relayControl(arcStartPin, false);
}

void waitForKey4(){
  if(digitalRead(startKey) and (currentStep == 4)){
    currentStep = 5;
  }
}

void PumpLoop(){
  if ((!atVaccume)&&(!estop)){
    relayControl(VaccumePin, true);
    relayControl(PumpCutoutPin, true);
    periotics();
    PumpLoop();
  }else if (atVaccume){
    relayControl(VaccumePin, false);
    relayControl(PumpCutoutPin, false);
    currentStep = currentStep + 1;
  }else{
    relayControl(VaccumePin, false);
    relayControl(PumpCutoutPin, false);
  }
}

void inputArgon(){
  starttime = millis();
  endtime = starttime;
  while (((endtime - starttime) <=argonInputTime) && currentStep == 2){
    relayControl(ArgonPin, true);
    endtime = millis();
    periotics();
  }
  relayControl(ArgonPin, false);
  currentStep = currentStep + 1;
}
