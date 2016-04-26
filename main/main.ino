int EN1 = 10, IN_A1 = 8, IN_B1 = 9, PWM1 = 3;

void setup() {
  pinMode(IN_A1, OUTPUT);
  pinMode(IN_B1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(PWM1, OUTPUT);
}

void loop() {
  //Kill switch
  digitalWrite(EN1, HIGH);

  //Let motor coast for now
  digitalWrite(IN_A1, LOW);
  digitalWrite(IN_B1, LOW);

  //Don't have the motor turn
  analogWrite(PWM1, 0);
}
