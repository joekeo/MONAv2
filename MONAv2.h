#ifndef MONAv2_H
#define MONAv2_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//activate debugging mode
#define MONA_DEBUG 0 //1 on;0 off

//Mona Pin configurations
//Mona motor configuation
#define RmotorSpeed 5
#define LmotorSpeed 6
#define RmotorDir 10
#define LmotorDir 9
#define FW 1
#define BW 0

//Mona encoders
#define RmotorEncoder 3
#define LmotorEncoder 2

//Mona IR configuration
#define IRenable 4
#define proxRight 7
#define proxFRight 0
#define proxFront 1
#define proxFLeft 2
#define proxLeft 3

//bottom LED`
#define frontLED 12

//Mona Battery
#define batterySample 6

void initEncoders(void); //begin the encoder interupt routine
void Rencoder(void); //interrupt routine to add the new tick
void Lencoder(void); //interrupt routine to add the new tick


class MONA{
public:
  MONA();

  void initProxSensor(void); //start the proximity sensor IR
  void stopProxSensor(void); //stop the proximity sensor IR
  void readAllSensors(int16_t *proxSensors); //retrreive all the proximity sensor data in one pointer
  //TODO: READ SEPARATE PROXIMITY SENSORS

  void initMotors(void);
  void RmotSpeed(uint8_t pwm = 0,boolean dir = FW); //Set Right motor speed and direction
  void LmotSpeed(uint8_t pwm = 0,boolean dir = FW); //Set Left motor speed and direction

  void resetRencoder(void); //reset the tick cound for the right encoder
  void resetLencoder(void); //reset the tick count for the left encoder
  void resetencoders(void); //reset both encoders' tick counts
  void readEncoders(int32_t *encoders); //read both encoders

  void readBattery(int16_t battery);
  //TODO: COUNT HTE REVS AND ESTIMATE THE RPMS AND VELOCITY OF THE ROBOT
};

#endif //  MONA_H
