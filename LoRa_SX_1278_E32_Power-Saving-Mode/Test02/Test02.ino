/*
  Demonstrates a way to utilize LaunchPad low power modes with the
  sleep(), sleepSeconds(), suspend() and wakeup() functions in
  Energia. The LaunchPad will blink the red LED 3 times and
  demonstrate sleep() and sleepSeconds().  It then goes into suspend()
  but will wake up and start over again if the button is pushed.
  sleep() and sleepSeconds() use LPM3. suspend() uses LPM4.
*/
void setup()
{
 Serial.begin(19200);
 pinMode(RED_LED, OUTPUT);                  // Make red LED an output
 pinMode(PUSH1, INPUT_PULLUP);              // Make push button input
 attachInterrupt(PUSH1, interrupt, FALLING);// Attach ISR to PUSH1
}

void loop()
{
  // Flash the LED - use sleep and sleepSeconds to save power by going
  // into LPM3
  for (int i = 0; i < 3; i++)           
  {
    //Serial.flush();
    //Serial.println("Suspend!");
    digitalWrite(RED_LED, HIGH);
    delay(200);                        // use sleep for millis
    digitalWrite(RED_LED, LOW);
    delay(1000);                   // use sleepSeconds for seconds
  }
  // Suspend and go into LPM4
  Serial.println("Suspend!");
  delay(200);
  suspend();
}
void interrupt()
{
  wakeup();
  Serial.println("Wake up!");// wake up if button is pushed
}
