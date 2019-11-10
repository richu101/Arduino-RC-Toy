const int ch1 = 2;
int ch1pwm,ch2pwm,ch3pwm,mapch1pwm;
void setup() {
// put your setup code here, to run once:
pinMode(ch1,INPUT);
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
ch1pwm = pulseIn(ch1,HIGH);
mapch1pwm = map(ch1pwm,994,1981,0,254);
Serial.println(mapch1pwm);
delay(400);
}
