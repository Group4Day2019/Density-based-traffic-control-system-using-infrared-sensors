#define ledA1 2
#define ledA2 3
#define ledA3 4

#define ledB1 5
#define ledB2 6
#define ledB3 7

#define ledC1 8
#define ledC2 9
#define ledC3 10

#define ledD1 12
#define ledD2 11
#define ledD3 13

int a1, a2, b1, b2, c1, c2, d1, d2;

void setup(){
  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);

}

void loop(){
  readSensor();
  if (b1==1 && b2==1)
  {
    roadBopen();
  }
  else if (d1==1 && d2==1 && (b1==0 || b2==0))
  {
    roadDopen();
    if (b1==1 && b2==1)
    {
      roadBopen();
    }
  }
  else if (a1==1 && a2==1 && ((d2==0 || b2==0) || (d1==0 || b1==0)))
  {
    roadAopen();
    if (b1==1 && b2==1)
    {
      roadBopen();
    }
    else if (d1==1 && d2==1 && (b1==0 || b2==0))
    {
      roadDopen();
    }
  }
  else if (c1==1 && c2==1 && ((d2==0 || b2==0 || a2==0) || (d1==0 || b1==0 || a1==0)))
  {
    roadCopen();
    if (b1==1 && b2==1)
    {
      roadBopen();
    }
    else if (d1==1 && d2==1 && (b1==0 || b2==0))
    {
      roadDopen();
    }
  }
  else if ((b1==1 && b2==0) && (c1==1 || d1==1 || b1==1) && (c2==1 && d2==1 && b2==1))
  {
    roadBopen();
  }
  else if ((d1==1 && d2==0) && (c1==1 || a1==1) && (b1==0 && b2==0) && (c2==0 && a2==0))
  {
    roadDopen();
  }
  else if ((a1==1 && a2==0) && (c1==1 && c2==0) && (d1==0 && d2==0) && (b1==0 && b2==0))
  {
    roadAopen();
  }
  else if ((c1==1 && c2==0) && (b1==0 || b2==0) && (d1==0 || d2==0) && (a1==0 || a2==0))
  {
    roadCopen();
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  else if ((b1==1 && b2==0) && (c1==0 || c2==0) && (d1==0 || d2==0) && (a1==0 || a2==0))
  {
    roadBopen();
  }
  else if ((d1==1 && d2==0) && (c1==0 || c2==0) && (b1==0 || b2==0) && (a1==0 || a2==0))
  {
    roadDopen();
  }
  else if ((a1==1 && a2==0) && (c1==0 || c2==0) && (d1==0 || d2==0) && (b1==0 || b2==0))
  {
    roadAopen();
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (a1==0 && b1==0 && c1==0 && d1==0)
  {
    roadBopen();
    if (a1==0 && b1==0 && c1==0 && d1==0)
    {
      roadDopen();
    }
    if (a1==0 && b1==0 && c1==0 && d1==0)
    {
      roadAopen();
    }
    if (a1==0 && b1==0 && c1==0 && d1==0)
    {
      roadCopen();
    }
  }
}

void readSensor()
{
  a1 = analogRead(A7);
  a2 = analogRead(A6);
  b1 = analogRead(A4);
  b2 = analogRead(A5);
  c1 = analogRead(A1);
  c2 = analogRead(A0);
  d1 = analogRead(A3);
  d2 = analogRead(A2);

  if (a1<400) a1=1; else a1=0; if (a2<400) a2=1; else a2=0;
  if (b1<400) b1=1; else b1=0; if (b2<400) b2=1; else b2=0;
  if (c1<400) c1=1; else c1=0; if (c2<400) c2=1; else c2=0;
  if (d1<400) d1=1; else d1=0; if (d2<400) d2=1; else d2=0;

  Serial.print(a1);
  Serial.print("\t");
  Serial.print(a2);
  Serial.print("\t");
  Serial.print(b1);
  Serial.print("\t");
  Serial.print(b2);
  Serial.print("\t");
  Serial.print(c1);
  Serial.print("\t");
  Serial.print(c2);
  Serial.print("\t");
  Serial.print(d1);
  Serial.print("\t");
  Serial.print(d2);
  Serial.print("\t");
}

void roadAopen()
{
  digitalWrite(ledA3, LOW);
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledA2, HIGH);
  delay(1000);
  digitalWrite(ledA2, LOW);
  readSensor();
  
}

void roadBopen()
{
  digitalWrite(ledB3, LOW);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopen()
{
  digitalWrite(ledC3, LOW);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopen()
{
  digitalWrite(ledD3, LOW);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  delay(10000);
  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  delay(1000);
  digitalWrite(ledD2, LOW);
  readSensor();
}

/*C:\Users\THEFAM~1\AppData\Local\Temp\arduino_build_13757/Traffic_source_code.ino.hex*/
