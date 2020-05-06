#include <Servo.h>
Servo myservo;
const int ch2 = 4;
const int ch4 = 2;
int ch2pwm,mapch2pwm;
const int front = 5;
const int rev = 6;
const int speed = 10;
void setup() {
// put your setup code here, to run once:
//pinMode(ch2,INPUT);
pinMode(front,OUTPUT);
pinMode(rev,OUTPUT);
Serial.begin(9600);
}

void loop() {
    mapch2pwm = map(pulseIn(ch2,HIGH),993,1986,0,254);
     Serial.print("input val :");
     Serial.println(mapch2pwm);
    if (mapch2pwm>120 && mapch2pwm<130)
    {
        stop();
    }
    
    if(mapch2pwm>130 && mapch2pwm<254 )
    {
      backward(map(pulseIn(ch2,HIGH),994,1986,0,254));
    }
    if(mapch2pwm<120 && mapch2pwm>0)
    {
      forward(map(pulseIn(ch2,HIGH),994,1986,0,254));
    }
}
void forward(int sp)
{
    digitalWrite(front,HIGH);
    digitalWrite(rev,LOW);
    int i = map(sp,120,0,0,254);
    analogWrite(speed,i);
    myservo.write(map(pulseIn(ch4,HIGH),994,1986,50,120));
    Serial.println("servo angle :");
     Serial.println(map(pulseIn(ch4,HIGH),994,1986,50,120));
    Serial.print("Forwars with sped :");
    Serial.println(i);
}
void backward(int sp)
{
    digitalWrite(front,LOW);
    digitalWrite(rev,HIGH);
    int i = map(sp,130,254,0,254);
    analogWrite(speed,i);
     myservo.write(map(pulseIn(ch4,HIGH),994,1986,50,120));
     Serial.println("servo angle :");
     Serial.println(map(pulseIn(ch4,HIGH),994,1986,50,120));
    Serial.print("Backward with sped :");
    Serial.println(i);
}
void stop()
{
    digitalWrite(front,LOW);
    digitalWrite(rev,LOW);
     myservo.write(map(pulseIn(ch4,HIGH),994,1986,50,120));
     Serial.println("servo angle :");
     Serial.println(map(pulseIn(ch4,HIGH),994,1986,50,120));
    Serial.println("stop");
}
