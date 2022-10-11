int trigPIN = 5;
int echoPIN = 6;
int distancetime;
float pingdistance;
float distance;
float DisIncm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
}

void loop() {
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);
  distancetime = pulseIn(echoPIN, HIGH);
  delay(25);
  pingdistance = (765. * 5280. * 12 * distancetime) / (3600. * 1000000.);
  distance = pingdistance / 2;
  DisIncm = distance * 2.54;
  Serial.print("Distance: ");
  Serial.print(DisIncm);
  Serial.println(" cm");
  delay(50);
}
