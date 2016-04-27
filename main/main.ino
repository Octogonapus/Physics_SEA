//Motor driver pins
const int EN1 = 8, IN_A1 = 7, IN_B1 = 4, PWM1 = 3;

//Digital input pins
const int killSwitchButton = 2;

//Analog input pins
const int slidePot = A0;

//Spring constant
const float springK = 26.30;

//Current load
float load = 0;

void setup() {
  Serial.begin(9600);
  
  //Motor driver pins
  pinMode(IN_A1, OUTPUT);
  pinMode(IN_B1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(PWM1, OUTPUT);

  //Digital input pins
  pinMode(killSwitchButton, INPUT);
}

void loop() {
  //Update current load
  load = springK * ((((analogRead(slidePot) / 1023.0) * 5.0) / 2.5) - 1);

  //Write current load to serial output
  Serial.println(load);
  
  //Kill switch
  if (digitalRead(killSwitchButton) == 1)
  {
    digitalWrite(EN1, HIGH);
  }
  else
  {
    digitalWrite(EN1, LOW);
  }

  //Let motor coast for now
  digitalWrite(IN_A1, LOW);
  digitalWrite(IN_B1, LOW);

  //Don't have the motor turn
  analogWrite(PWM1, 0);
}
