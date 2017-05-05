#define ENA 9
#define ENB 10
#define ENC 11

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define IN5 6
#define IN6 7

byte a = 0;
byte b = 0;
byte dir;
  
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENC, OUTPUT);

  Serial.begin(9600);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(ENC, LOW);
}

void loop()
{
  MoveF();
}

void MoveF(void)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  delay(1000);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  delay(5000);
}

void MoveB(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  for(int i = 0; i < 1000; i++)
  {
    analogWrite(ENA, i*(.25));
    Serial.println(dir);
    delay(10);
  }
  for(int i = 100; i > 0; i--)
  {
    analogWrite(ENA, i*(2.5));
    Serial.println(dir);
    delay(10);
  }
}

