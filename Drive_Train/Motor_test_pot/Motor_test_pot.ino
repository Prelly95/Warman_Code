
#define HALL_1 10  // Hall effects sensor 1
#define HALL_2 11  // Hall effects sensor 2
#define MOTOR 9

int val;    // variable to read the value from the analog pin
int H1;
int H2;

void setup() {
  pinMode(HALL_1, INPUT);
  pinMode(HALL_2, INPUT);
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  SpeedUp();
  SlowDown();
  Serial.println(val);
}


void SpeedUp(void)
{
  val = 0;
  for(int i = 0; i < 255; i++)
  {
    val = i;
    analogWrite(MOTOR, val);
    H1 = digitalRead(HALL_1);
    H2 = digitalRead(HALL_2);
    
    Serial.print("H1:  ");
    Serial.print(H1);
    Serial.print("  H2:  ");
    Serial.println(H1);
    delay(100);
  }
}

void SlowDown(void)
{
  val = 0;
  for(int i = 0; i < 255; i++)
  {
    val = 255-i;
    analogWrite(MOTOR, val);
    
    H1 = digitalRead(HALL_1);
    H2 = digitalRead(HALL_2);
    
    Serial.print("H1:  ");
    Serial.print(H1);
    Serial.print("  H2:  ");
    Serial.println(H1);
    delay(100);
  }
}
