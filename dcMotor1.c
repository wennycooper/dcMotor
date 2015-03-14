#include <wiringPi.h>
#include <softPwm.h>

#define RANGE	100
#define PIN0	0
#define INITIAL_VALUE 0

int i;

int main()
{
  wiringPiSetup();

  // initialize left motor (0:pwm, 2:dir & 3:F)
  softPwmCreate(0, INITIAL_VALUE, RANGE);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  // initialize right motor (4:pwm, 5:dir & 6:F)
  softPwmCreate(4, INITIAL_VALUE, RANGE);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);


// to forward (come to me), drive pin 0&5 to some power
// to backward (leave  me), drive pin 2&4 to some power


// forward
  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);
  softPwmWrite(0, 1);
  softPwmWrite(4, 1);
  delay(5000);

// backward
  digitalWrite(2, LOW);
  digitalWrite(5, HIGH);
  softPwmWrite(0, 1);
  softPwmWrite(4, 1);
  delay(5000);

// stop
  softPwmWrite(0, 0);
  softPwmWrite(4, 0);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);

  delay(1000);

}

