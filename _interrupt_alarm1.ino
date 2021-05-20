#define ledR 8
#define ledG 7
#define ledY 12
int interrCount = 0;

void setup() 
{
  pinMode( ledR,OUTPUT );
  pinMode( ledG,OUTPUT );
  pinMode( ledY,OUTPUT );
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite( ledR,0 );
  digitalWrite( ledG,0 );
  digitalWrite( ledY,0 );
  
  attachInterrupt(0, interruptChange, RISING );
}

void loop() {
  interrCount++;
  
  digitalWrite( ledR,1 );
  digitalWrite( ledG,0 );
  delay(300);
  digitalWrite( ledR,0 );
  digitalWrite( ledG,1 );
  delay(300);
  
  
  if ( interrCount == 10 ) 
  {
    interrCount = 0;
    digitalWrite( ledY,0 );
  }
   if (digitalRead(A0) == 1) {
    for (interrCount = 0; interrCount < 1000; ++interrCount) {
  
      tone(2, 165, 1000); // play tone 40 (E3 = 165 Hz)
      delay(150); 
      noTone(2);
      tone(3, 523, 1000); // play tone 60 (C5 = 523 Hz)
      delay(150); 
      noTone(3);
      delay(100); 
    }
   }
}

void interruptChange() 
{
  digitalWrite( ledY,1 );
  digitalWrite (ledG,0);
}
