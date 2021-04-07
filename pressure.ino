#include <Wire.h>
int address = 40;

void setup() {
  Serial.begin (9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(2);
  int pressure = read_pressure(address);
  Serial.print("Sensor: ");
  Serial.print(pressure);
  Serial.println();
  delay(100);
}

int read_pressure(int address) {
  //start the communication with IC with the address xx
  Wire.beginTransmission(address);
  //send a bit and ask for register zero
  Wire.write(0);
  //end transmission
  Wire.endTransmission();
  //request 1 byte from address xx
  Wire.requestFrom(address, 1);
  //wait for response
  while(Wire.available() == 0);
  //put the pressure in variable c
  int c = Wire.read();
  return c;
}
