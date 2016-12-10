#include<RFID.h>
#include<SPI.h>

RFID kartokuyucu(10, 9);
byte anakart[5] = {65, 57, 236, 213, 65};
byte paso[5] = {*************};
byte aktarma[5] = {182, 225, 39, 75, 59};
boolean anakartkontrol = false;
boolean pasokontrol = false;
boolean aktarmakontrol = false;
int a = 0;
int b = 0;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  kartokuyucu.init();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  anakartkontrol = false;
  pasokontrol = false;
  aktarmakontrol = false;
  if (kartokuyucu.isCard())
  {
    if (kartokuyucu.readCardSerial())
    {
      for (int i = 0; i < 5; i++)
      {
        if (kartokuyucu.serNum[i] == anakart[i])
        {
          anakartkontrol = true;
        }
        if (kartokuyucu.serNum[i] == paso[i])
        {
          pasokontrol = true;
        }
        if (kartokuyucu.serNum[i] == aktarma[i])
        {
          aktarmakontrol = true;
        }
      }

    }
    if (anakartkontrol == true)
    {
      a = 10;
      b = a % 11;
      if (b == 10)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
      }
    }
    if (aktarmakontrol == true)
    {
      a++;
      b = a % 11;
      if (b == 10)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
      }
      if (b == 8)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
      }
      if (b == 6)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 4)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 2)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 0)
      {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
    }
    if ( pasokontrol == true)
    {
      a -= 2;
      b = a % 11;

      if (b == 10)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
      }
      if (b == 8)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
      }
      if (b == 6)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 4)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 2)
      {
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
      if (b == 0)
      {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }

    }
    Serial.println(a);
    delay(1000);
    kartokuyucu.halt();
  }

}
