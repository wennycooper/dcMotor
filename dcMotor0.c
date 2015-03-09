#include <wiringPi.h>
#include <softPwm.h>

#define RANGE	100
#define PIN0	0
#define INITIAL_VALUE 0

int i;

int main()
{
  wiringPiSetup();

  // initialize left motor (pin0, 2 & 3)
  softPwmCreate(0, INITIAL_VALUE, RANGE);
  softPwmCreate(2, INITIAL_VALUE, RANGE);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  // initialize right motor (pin4, 5 & 6)
  softPwmCreate(5, INITIAL_VALUE, RANGE);
  softPwmCreate(4, INITIAL_VALUE, RANGE);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);


// to forward (come to me), drive pin 0&5 to some power
// to backward (leave  me), drive pin 2&4 to some power


// forward
  softPwmWrite(0, 0);
  softPwmWrite(5, 0);
  softPwmWrite(2, 100);
  softPwmWrite(4, 100);
  delay(5000);

// backward
  softPwmWrite(0, 100);
  softPwmWrite(5, 100);
  softPwmWrite(2, 0);
  softPwmWrite(4, 0);
  delay(5000);

// stop
  softPwmWrite(0, 0);
  softPwmWrite(5, 0);
  softPwmWrite(2, 0);
  softPwmWrite(4, 0);
  delay(1000);

}

