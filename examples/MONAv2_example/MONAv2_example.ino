#include <MONAv2.h>
//initialise an object calle mona using the MONA structure
MONA mona;

//pointerm to store the encoder data
int32_t encoders[2];
int16_t sensors[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mona.initMotors();
  initEncoders();//start the encoder interrupts
  mona.initProxSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  mona.RmotSpeed(255, FW);
  mona.LmotSpeed(255, FW);
  mona.readEncoders(&encoders[0]);
  mona.readAllSensors(&sensors[0]);
  Serial.print("Proximity Sensors-> Left: ");
  Serial.print(sensors[4]);
  Serial.print(" Front Left: ");
  Serial.print(sensors[3]);
  Serial.print(" Front: ");
  Serial.print(sensors[2]);
  Serial.print(" Front Right: ");
  Serial.print(sensors[1]);
  Serial.print(" Right: ");
  Serial.print(sensors[0]);
  Serial.print("   Encoder values -> Right motor: ");
  Serial.print(encoders[0]);
  Serial.print("    Left motor: ");
  Serial.println(encoders[1]);
  

}
