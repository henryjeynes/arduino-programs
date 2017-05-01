/*
   A simple Arduino-based boost converter.

   This sketch is intended to show how a boost
   converter works, not to be used in an actual
   product. The output will be unstable and may
   cut out with rapid adjustment.
*/

float volts;
float adcVolts;
float vSetValue;
float vSetVoltage;
float setVoltage = 10;
float multiplier = 0.2;
unsigned int adcReading;
unsigned int pwmValue;

#define feedback A0
#define switchPin 5
#define vSet A1

void setup() {
  pinMode(switchPin, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pwmValue = 0;
  //analogWriteResolution(8); //for Cortex-based boards
}

void loop() {
  vSetValue = analogRead(vSet);
  vSetVoltage = (vSetValue * 5) / 1024;
  setVoltage = vSetVoltage / multiplier;

  adcReading = analogRead(feedback);
  adcVolts = (adcReading * 5) / 1024;
  volts = adcVolts / multiplier;

  if (volts > 23.0) {
    digitalWrite(13, LOW);
    analogWrite(switchPin, 0);
    delay(1000);
    digitalWrite(13, HIGH);
  }

  if (pwmValue > 230) {
    pwmValue = 230;
  }
  analogWrite(switchPin, pwmValue);
  if (volts < setVoltage) {
    pwmValue++;
    if (pwmValue > 230) {
      pwmValue = 230;
    }
    analogWrite(switchPin, pwmValue);
  }
  if (volts > setVoltage) {
    pwmValue--;
    analogWrite(switchPin, pwmValue);
  }
}

