void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(10); // Delay a little bit to improve simulation performance
}