

  int ledPin1 =  12;      // the number of the LED pin
  int ledState1 = LOW;             // ledState used to set the LED
  unsigned long previousMillis1 = 0;        // will store last time LED was updated
  long OnTime1 = 1;           // milliseconds of on-time
  long OffTime1 = 2000;          // milliseconds of off-time




void checkRelays(){ //turn on and off pins directly according to v 1 relay wireing schmatic
  if (debugMode){

      // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();

  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;  // Turn it off
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(ledPin1, ledState1);  // Update the actual LED
    relayControl(22, true);
    relayControl(23, true);
    relayControl(24, true);
    relayControl(25, true);
    relayControl(26, true);
    relayControl(27, true);
    relayControl(28, true);
    relayControl(29, true);
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;  // turn it on
    previousMillis1 = currentMillis;   // Remember the time
    digitalWrite(ledPin1, ledState1);	  // Update the actual LED
    relayControl(22, false);
    relayControl(23, false);
    relayControl(24, false);
    relayControl(25, false);
    relayControl(26, false);
    relayControl(27, false);
    relayControl(28, false);
    relayControl(29, false);
    }
  }
}
