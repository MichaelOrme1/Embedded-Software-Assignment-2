#include "Ticker.h"

#define Watchdog PD7
#define LED PB5
#define BUTTON PD3
#define ANALOGUE A0
int increment_tick();
int tick = 0;
int average_analogue = 0;
int BUTTONstate = 0;
int Frequency = 0;
Ticker timer(increment_tick, 500);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Watchdog, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
  pinMode(ANALOGUE,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 Task1();//0.025
 timer.update();//Allow timer to count
 

 if ((tick/2) %2 == 0){//Timer every 0.5 seconds divide by 2 to get seconds
  Task2();//2 seconds
 }

 if ((tick/2) %1 == 0){
   Task6();//1 second
 }

 if ((tick/2) %3 == 0){
    Task7and8();//3 seconds
   
 }

  if ((tick/2) %10 == 0){
   Task3();//10 seconds
  }

  if ((tick/2) %50 == 0){
   Task9();//50 seconds
 
  }
}


void Task1(){
   digitalWrite(Watchdog,HIGH);//Send HIGH signal, turn LED on
   delayMicroseconds(50);
   digitalWrite(Watchdog,LOW);//Send LOW signal, turn LED off
}

void Task2(){
  BUTTONstate = digitalRead(BUTTON); //Read button
}

void Task3(){
  
}

void Task4and5(){
  //Get analogue reading 4 times
  int analogue1 = analogRead(ANALOGUE);
  int analogue2 = analogRead(ANALOGUE);
  int analogue3 = analogRead(ANALOGUE);
  int analogue4 = analogRead(ANALOGUE);

  average_analogue = (analogue1+analogue2+analogue3+analogue4)/4;//Get average analogue
}




void Task6(){
  int i = 0;
  while( i >1000){//Do 1000 times
    __asm__ __volatile__ ("nop");
    i++;
  }
}

void Task7and8(){
  int error_code;
  if (average_analogue > 3300/2){
    error_code = 1;
     digitalWrite(LED,HIGH);//Send HIGH signal, turn LED on
  }
else{
    error_code = 0;
    digitalWrite(LED,LOW);//Send LOW signal, turn LED off

  
}
}

void Task9(){
  //CSV
  Serial.print(BUTTONstate);
  Serial.print(",");
  Serial.print(average_analogue);
  Serial.print(",");
  Serial.print(Frequency);
    
}

int increment_tick(){
  tick ++;//Increase tick every 0.5 seconds
  Task4and5();//DO every tick
}
