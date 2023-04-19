#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


#define Led 8
#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN); 
int data[4];
const int Motor1_Ileri = 7;//Sağ Motor
const int Motor1_Geri = 6;
const int Motor1_PWM = 3;

const int Motor2_Ileri = 4;//Sol Motor
const int Motor2_Geri = 2;
const int Motor2_PWM = 5; 
void setup()   
{
  pinMode(Led, OUTPUT);
   pinMode(Motor1_Ileri,OUTPUT);
  pinMode(Motor1_Geri,OUTPUT);
  pinMode(Motor1_PWM,OUTPUT);
  pinMode(Motor2_Ileri,OUTPUT);
  pinMode(Motor2_Geri,OUTPUT);
  pinMode(Motor2_PWM,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {


    
    int y = data[1];
    int x = data[0];
    int buton = data[3];
    radio.read( data, sizeof(data) ); 

    Serial.println(data[0]);Serial.print("\t");
    Serial.println(data[1]);Serial.print("\t");
    Serial.println(data[2]);Serial.print("\t");
    Serial.println(data[3]);Serial.print("\t");

    
     if (buton == 1)
  digitalWrite(Led,HIGH);
  else
  digitalWrite(Led,LOW);
    
    if(y >= 450 && y <= 550) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,0);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,0);
    }
    //soladönüş için düşük devir aralığı
     if(y >= 560 && y <= 900) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,125);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,125);
    }
    //sola dönüş için yüksek devir aralığı
    if(y >= 920 && y <= 1023) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,255);
    }
    //sağa dönüş için yüksek devir aralığı
    if(y >= 0 && y <= 100) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
    //sağa dönüş için düşük devir aralığı
    if(y >= 110 && y <= 450) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,125);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,125);
    }
    //ileri vites için yüksek devir
    if(x >= 0 && x <= 100) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
    //ileri vites için düşük devir
    if(x >= 120 && x <= 440) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,125);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,125);
    }
    //geri vites için düşük devir
    if(x >= 560 && x <= 900) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,125);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,125);
    }
    //geri vites için yüksek devir
    if(x >= 910 && x <= 1023) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,255);
    }
  }
}
