/*
   Programm:          Treppenhausschaltung
   Letzte Änderung:   12.11.20
   Programmierer:     LC
   Version:           1.0
   Bibliothek:        OneButton

   Hardware:      Arduino UNO / Taster 1 an Pin 11 , Taster 2 an Pin 12 / Beide Pull-Down / LED an Pin 6
*/

#include <OneButton.h>

OneButton button1(2, false);             // Taster 1 erstellen und dem Pin 11 zuweisen
OneButton button2(3, false);             // Taster 2 erstellen und dem Pin 12 zuweisen

#define LED 6

bool taster1Gedrueckt = false;
bool taster2Gedrueckt = false;

bool ledZustand = LOW;

void setup()
{
  pinMode(LED, OUTPUT);
  button1.attachClick(Taster1);
  button2.attachClick(Taster2);
}

void loop()
{
  button1.tick();
  button2.tick();
  delay(10);
  if (taster1Gedrueckt == true)
  {
    if (ledZustand == LOW)
    {
      digitalWrite(LED, HIGH);
      ledZustand = HIGH;
    }
    else
    {
      digitalWrite(LED, LOW);
      ledZustand = LOW;
    }
    taster1Gedrueckt = false;
  }
  else if (taster2Gedrueckt == true)
  {
    if (ledZustand == LOW)
    {
      digitalWrite(LED, HIGH);
      ledZustand = HIGH;
    }
    else
    {
      digitalWrite(LED, LOW);
      ledZustand = LOW;
    }
    taster2Gedrueckt = false;
  }
}

void Taster1()
{
  taster1Gedrueckt = !taster1Gedrueckt;
}


void Taster2()
{
  taster2Gedrueckt = !taster2Gedrueckt;
}

