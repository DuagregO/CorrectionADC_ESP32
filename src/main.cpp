#include <Arduino.h>
#include <MonADC.h>

#define Vin 32

MonADC adc32(Vin);

int Nreel;
float Ncorrige,Vmes;

void setup()
{
  Serial.begin(115200);
  delay(1000);
}

void loop()
{
  Nreel = analogRead(Vin);
  Ncorrige = adc32.correction(Nreel);
  Vmes = Ncorrige*3.3/4095;

  Serial.print("Nreel = " + String(Nreel)+" -- ");
  Serial.print("Ncorrige = " + String(Ncorrige)+" -- ");
  Serial.println("Vmes = " + String(Vmes)+" -- ");
  delay(1000);
}

