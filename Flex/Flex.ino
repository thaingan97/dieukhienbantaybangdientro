#include <Servo.h>

Servo ser1, ser2, ser3, ser4, ser5;

int bientro[5], quidoi[5];

void setup(){ // goi chan va dieu khien servo
  ser1.attach(3);
  ser2.attach(5);
  ser3.attach(6);
  ser4.attach(9);
  ser5.attach(10);
}

void loop(){ //doc gia tri analog
  bientro[0]= analogRead(A0);
  bientro[1]= analogRead(A1);
  bientro[2]= analogRead(A2);
  bientro[3]= analogRead(A3);
  bientro[4]= analogRead(A4);
  
  //gioi han gia tri tu 50 toi 900 de giam nhieu
  //vi dieu khien ATmega doc gia tri analog 8 bit: 0 -> 1023
  
  bientro[0] = constrain(bientro[0], 50, 900);
  bientro[1] = constrain(bientro[1], 50, 900);
  bientro[2] = constrain(bientro[2], 50, 900);
  bientro[3] = constrain(bientro[3], 50, 900);
  bientro[4] = constrain(bientro[4], 50, 900);
  
  //qui doi gia tri analog tu 50-900 sang 0-180 do
  
  quidoi[0] = map(bientro[0], 50, 900, 0, 180);
  quidoi[1] = map(bientro[1], 50, 900, 0, 180);
  quidoi[2] = map(bientro[2], 50, 900, 0, 180);
  quidoi[3] = map(bientro[3], 50, 900, 0, 180);
  quidoi[4] = map(bientro[4], 50, 900, 0, 180);
  
  ser1.write(quidoi[0]);
  //Serial.println(quidoi[0]);
  ser2.write(quidoi[1]);
  ser3.write(quidoi[2]);
  ser4.write(quidoi[3]);
  ser5.write(quidoi[4]);
  delay(50);
}
