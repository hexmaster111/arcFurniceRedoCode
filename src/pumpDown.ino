int pumpDownSteps[] = {1,2,1,2,3};
int currentStep = 0;

void startPumpDown(){
    if (currentStep==0){
      PumpLoop();
    }else if(currentStep==1){

    }else if(currentStep==2){

    }else if(currentStep==3){

    }else if(currentStep==4){

    }else if(currentStep==5){
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

void PumpLoop(){
  if ((!atVaccume)&&(!estop)){
    relayControl(VaccumePin, true);
    relayControl(PumpCutoutPin, true);
    eStopCheck();
    checkVaccume();
    PumpLoop();
  }else{
    relayControl(VaccumePin, false);
    relayControl(PumpCutoutPin, false);
    loop();
  }
}
