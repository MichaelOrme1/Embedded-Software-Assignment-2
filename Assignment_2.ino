#include "Ticker.h"
//int b = 900;
//int c = 17;
//int d = 2500;
//int delay = 2500
int increment_tick();
int tick = 0;
Ticker timer(increment_tick, 1000);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//Used to show what the program is doing
  pinMode(13, OUTPUT);
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
    Task7();//3
    Task8();//3
 }

  if ((tick/2) %10 == 0){
   Task3();//10
  }

  if ((tick/2) %50 == 0){
   Task9();//50
 
  }
}


void Task1(){
   digitalWrite(13,HIGH);//Send HIGH signal, turn LED on
   delayMicroseconds(50);
   digitalWrite(13,LOW);//Send LOW signal, turn LED off
}

void Task2(){
  int BUTTON1state = digitalRead(3);
}

void Task3(){
  
}

void Task4(){
  
}

void Task5(){
  
}


void Task6(){
  int i = 0;
  while( i >1000){
    __asm__ __volatile__ ("nop");
    i++;
  }
}

void Task7(){
  
}

void Task8(){
  
}

void Task9(){
  
}

int increment_tick(){
  tick ++;
   Task4();//0.5
   Task5();//0.5
}
