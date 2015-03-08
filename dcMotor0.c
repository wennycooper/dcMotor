#include <wiringPi.h>
#include <softPwm.h>

#define RANGE	100
#define PIN0	0
#define INITIAL_VALUE 0
#define MIN_POWER  25

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


// to come to me, drive pin 0&5 to some power
// to leave   me, drive pin 2&4 to some power


//  softPwmWrite(0, 100);
//  softPwmWrite(5, 100);
//  delay(5000);

  softPwmWrite(2, 50);
  softPwmWrite(4, 50);
  delay(5000);

  softPwmWrite(2, MIN_POWER);
  softPwmWrite(4, MIN_POWER);
  delay(5000);

  softPwmWrite(2, 0);
  softPwmWrite(4, 0);
  delay(1000);

}

