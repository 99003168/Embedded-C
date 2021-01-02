#include<SPI.h>

volatile boolean received;
volatile int Slave;


void setup()

{
  Serial.begin(9600);
 
pinMode(MISO, OUTPUT);

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  }

ISR (SPI_STC_vect)                        //Inerrrput routine function
{
  Slave = SPDR;         // Value received from master 
  received = true;                        //Sets received as True 
   
}

void loop()
{ if(received)                            
  {
 delay(500);
 Serial.println(Slave);
      switch (Slave)
      {
        case 0:
               Serial.println("Human is absent\n");
               break;
        case 1:
               Serial.println("Human is present\n");
               break;
        case 2:
               Serial.println("Sensor value is less than 512\n");
               break;              
      }
}
}
