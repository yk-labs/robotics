#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


#define CE_PIN  9
#define CSN_PIN 10
#define x_ A0 // x axis
#define y_ A1 //y axis

#define buton 3


const uint64_t pipe = 0xE8E8F0F0E1EL; 
RF24 radio(CE_PIN, CSN_PIN); 
int data[4];  

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
   pinMode(buton, INPUT);
}

void loop()   
{

  data[0] = analogRead(x_);
  data[1] = analogRead(y_);
  data[2] = 111;
  data[3] = digitalRead(buton);
  
  radio.write( data, sizeof(data) ); 
 
//HATA AYIKLAMA (DEBUG)
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  //Serial.print(digitalRead(BUTON));
}
