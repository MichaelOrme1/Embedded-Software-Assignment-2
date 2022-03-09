#include "Ticker.h"

int increment_tick();
int tick = 0;
int average_analogue = 0;
int BUTTONstate = 0;
int Frequency = 0;
Ticker timer(increment_tick, 1000);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 timer.update();
 Task1();//0.025

 if ((tick/2) %2 == 0){
  Task2();//2
 }

 if ((tick/2) %1 == 0){
   Task6();//1
 }

 if ((tick/2) %3 == 0){
    Task7and8();//3
   
 }

  if ((tick/2) %10 == 0){
   Task3();//10
  }

  if ((tick/2) %50 == 0){
   Task9();//50
 
  }
}


void Task1(){
   digitalWrite(14,HIGH);//Send HIGH signal, turn LED on
   delayMicroseconds(50);
   digitalWrite(14,LOW);//Send LOW signal, turn LED off
}

void Task2(){
  BUTTONstate = digitalRead(3);
}

void Task3(){
  
}

void Task4and5(){
  int analogue1 = analogRead(A0);
  int analogue2 = analogRead(A0);
  int analogue3 = analogRead(A0);
  int analogue4 = analogRead(A0);

  average_analogue = (analogue1+analogue2+analogue3+analogue4)/4;
}




void Task6(){
  int i = 0;
  while( i >1000){
    __asm__ __volatile__ ("nop");
    i++;
  }
}

void Task7and8(){
  int error_code;
  if (average_analogue > 3300/2){
    error_code = 1;
     digitalWrite(14,HIGH);//Send HIGH signal, turn LED on
  }
else{
    error_code = 0;
    digitalWrite(14,LOW);//Send LOW signal, turn LED off

  
}
}

void Task9(){
  Serial.print(BUTTONstate);
  Serial.print(",");
  Serial.print(average_analogue);
  Serial.print(",");
  Serial.print(Frequency);
    
}

int increment_tick(){
  tick ++;
  Task4and5();
}
