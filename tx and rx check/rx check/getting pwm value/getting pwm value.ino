const int ch1 = 4;
int ch1pwm,mapch1pwm;
void setup() {
// put your setup code here, to run once:
pinMode(ch1,INPUT);
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
ch1pwm = pulseIn(ch1,HIGH);
Serial.println("channel 1:");
Serial.println(ch1pwm);
mapch1pwm = map(pulseIn(ch1,HIGH),993,1986,0,254);
Serial.println("ch2 map:");
Serial.println(mapch1pwm);
delay(400);
}