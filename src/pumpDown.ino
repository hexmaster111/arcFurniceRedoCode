void startPumpDown(){
  eStopCheck();// make sure we are SAFE
  relayControl(PumpCutoutPin, true);
  
}



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
