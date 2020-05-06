int ch1pwm,ch2pwm,ch3pwm,mapch1pwm;
int front = 5;
int rev = 6;
int speed = 10;
void setup() {
// put your setup code here, to run once:
//pinMode(ch1,INPUT);
pinMode(front,OUTPUT);
pinMode(rev,OUTPUT);
Serial.begin(9600);
}

void loop() {
    forward();
    backward();
}
void forward()
{
    digitalWrite(front,HIGH);
    digitalWrite(rev,LOW);
    for(int i = 0;i<=243;i++)
    {
        analogWrite(speed,i);
        delay(100);
    }
}
void backward()
{
    digitalWrite(front,LOW);
    digitalWrite(rev,HIGH);
    for(int i = 0;i<=243;i++)
    {
        analogWrite(speed,i);
        delay(100);
    }
}
