#define MOTOR 13

int count;

bool state_A = 0;
bool state_B = 0;

void setup() {
  pinMode(MOTOR, OUTPUT);
  attachInterrupt(0, RISE_A, RISING);
  attachInterrupt(1, RISE_B, RISING);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(MOTOR, HIGH);
  delay(5000);
  digitalWrite(MOTOR, LOW);
  delay(500);
}

void RISE_A()
{
  detachInterrupt(0);
  state_A = 1;
  switch(state_B){
    case 0:
      Serial.println("Moving Forward\t--->");
      break;
    case 1:
      Serial.println("Moving Backward\t<---");
      break;
  }
  attachInterrupt(0, FALL_A, FALLING);
}

void FALL_A()
{
  detachInterrupt(0);
  state_A = 0;
  switch(state_B){
    case 0:
      Serial.println("Moving Backward\t<---");
      break;
    case 1:
      Serial.println("Moving Forward\t--->");
      break;
  }
  attachInterrupt(0, RISE_A, RISING);
}

void RISE_B()
{
  detachInterrupt(1);
  state_B = 1;
  switch(state_A){
    case 0:
      Serial.println("Moving Backward\t<---");
      break;
    case 1:
      Serial.println("Moving Forward\t--->");
      break;
  }
  attachInterrupt(1, FALL_B, FALLING);
}

void FALL_B()
{
  detachInterrupt(1);
  state_B = 0;
  switch(state_A){
    case 0:
      Serial.println("Moving Forward\t--->");
      break;
    case 1:
      Serial.println("Moving Backward\t<---");
      break;
  }
  attachInterrupt(1, RISE_B, RISING);
}

