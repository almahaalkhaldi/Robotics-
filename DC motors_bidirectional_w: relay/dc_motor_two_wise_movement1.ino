void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(2000);
}