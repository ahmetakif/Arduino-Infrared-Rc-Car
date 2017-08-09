#include <IRremote.h>
#include <Servo.h>

IRrecv irrecv(2);

decode_results results;

Servo steer;

#define POWER 0xE0E040BF
#define BUTTON1 0xE0E020DF
#define BUTTON2 0xE0E0A05F
#define BUTTON3 0xE0E0609F
#define BUTTON4 0xE0E010EF
#define BUTTON5 0xE0E0906F
#define BUTTON6 0xE0E050AF
#define BUTTON7 0xE0E030CF
#define BUTTON8 0xE0E0B04F
#define BUTTON9 0xE0E0708F
#define BUTTON0 0xE0E08877
#define UP 0xE0E006F9
#define LEFT 0xE0E0A659
#define OK 0xE0E016E9
#define RIGHT 0xE0E046B9
#define DOWN 0xE0E08679

const int ff = 4;
const int bb = 5;
const int en = 3;
const int buzzer = 11;

int velocity;
int angle;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(buzzer , OUTPUT);
  pinMode(ff , OUTPUT);
  pinMode(bb , OUTPUT);
  pinMode(en , OUTPUT);
  steer.attach(6);
  digitalWrite(buzzer , LOW);
  digitalWrite(ff , LOW);
  digitalWrite(bb , LOW);
  analogWrite(en , 0);
  angle = 86;
  steer.write(angle);
}

void loop() 
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    Serial.println(velocity);
    if(results.value == OK)
    {
      digitalWrite(buzzer , HIGH);
    }
    if(results.value == BUTTON0)
    {
      velocity = 25;
    }
    if(results.value == BUTTON1)
    {
      velocity = 50;
    }
    if(results.value == BUTTON2)
    {
      velocity = 75;
    }
    if(results.value == BUTTON3)
    {
      velocity = 100;
    }
    if(results.value == BUTTON4)
    {
      velocity = 125;
    }
    if(results.value == BUTTON5)
    {
      velocity = 150;
    }
    if(results.value == BUTTON6)
    {
      velocity = 175;
    }
    if(results.value == BUTTON7)
    {
      velocity = 200;
    }
    if(results.value == BUTTON8)
    {
      velocity = 225;
    }
    if(results.value == BUTTON9)
    {
      velocity = 255;
    }
    if(results.value == UP)
    {
      digitalWrite(ff , HIGH);
      digitalWrite(bb , LOW);
      analogWrite(en , velocity);
    }
    if(results.value == DOWN)
    {
      digitalWrite(bb , HIGH);
      digitalWrite(ff , LOW);
      analogWrite(en , velocity);
    }
    if(results.value == LEFT)
    {
      angle = angle - 1;
    }
    if(results.value == RIGHT)
    {
      angle = angle + 1;
    }
    irrecv.resume();
    steer.write(angle);
    delay(100);
  }
  else
  {
    digitalWrite(buzzer , LOW);
    digitalWrite(ff , LOW);
    digitalWrite(bb , LOW);
  }
  if(angle > 100)
  {
    angle = 100;
  }
  if(angle < 71)
  {
    angle = 71;
  }
}
