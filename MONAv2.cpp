/***************************************************
  This is a library for the MONA educational mobile robot
  Designed specifically to work with the MONA platform
  ----> http://www.mona.uk
  Written by Jose Espinosa/Farshad Arvin for The University of Manchester.
  TODO:ADDlicense
 ****************************************************/
#include "MONAv2.h"

//variables to store the encoder ticks
volatile double encoderRTicks = 0;
volatile double encoderLTicks = 0;


//variables to store the direction of the motors
volatile boolean dirR = 0;
volatile boolean dirL = 0;

MONA::MONA(){
}

void MONA::initMotors(void){
  pinMode(RmotorDir, OUTPUT);
  pinMode(LmotorDir, OUTPUT);

}


void MONA::RmotSpeed(uint8_t pwm,boolean dir){
  dirR = dir;
  if(dir==0){
    pwm = abs(pwm - 255);
    analogWrite(RmotorSpeed,pwm);
    digitalWrite(RmotorDir,1);
  }
  else{
    analogWrite(RmotorSpeed,pwm);
    digitalWrite(RmotorDir,0);

  }
}

void MONA::LmotSpeed(uint8_t pwm,boolean dir){
  dirL = dir;
  if(dir==0){
    pwm = abs(pwm - 255);
    analogWrite(LmotorSpeed,pwm);
    digitalWrite(LmotorDir,1);
  }
  else{
    analogWrite(LmotorSpeed,pwm);
    digitalWrite(LmotorDir,0);

  }
}

void initEncoders(void){ //begin the encoder pulling routine wi the period in ms
  attachInterrupt(digitalPinToInterrupt(LmotorEncoder), Rencoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RmotorEncoder), Lencoder, CHANGE);
}

void Rencoder(void){ //read the value of the right encoder
 if (dirR>0)
 encoderRTicks = encoderRTicks + 1;
 else
 encoderRTicks = encoderRTicks - 1;
}


void Lencoder(void){ //read the value of the right encoder
 if (dirL>0)
 encoderLTicks = encoderLTicks + 1;
 else
 encoderLTicks = encoderLTicks - 1;
}

void MONA::resetRencoder(void){ //reset the tick cound for the right encoder
  encoderRTicks = 0;
}

void MONA::resetLencoder(void){ //reset the tick cound for the right encoder
  encoderLTicks = 0;
}

void MONA::readEncoders(int32_t *encoders){
  encoders[0] = encoderRTicks;
  encoders[1] = encoderLTicks;

}

void MONA::initProxSensor(void){ //start the proximity sensor IR
  pinMode(IRenable, OUTPUT); //Enabel IR emiters
  digitalWrite(IRenable, HIGH); //Enabel IR emiters
}

void MONA::stopProxSensor(void){ //start the proximity sensor IR
  pinMode(IRenable, LOW); //Disabel IR emiters
}

void MONA::readAllSensors(int16_t *proxSensors){

  proxSensors[0] = analogRead(proxRight);
  proxSensors[1] = analogRead(proxFRight);
  proxSensors[2] = analogRead(proxFront);
  proxSensors[3] = analogRead(proxFLeft);
  proxSensors[4] = analogRead(proxLeft);

}
