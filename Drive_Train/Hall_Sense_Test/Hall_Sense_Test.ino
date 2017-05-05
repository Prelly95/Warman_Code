
#define POT 10  // analog pin used to connect the potentiometer
#define MOTOR 10

int val;    // variable to read the value from the analog pin

void setup() {
  pinMode(POT, INPUT);
//  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  val = digitalRead(POT);
//  val = analogRead(POT);
//  val = map(val, 0, 1024, 0, 255);
//  analogWrite(MOTOR, val);
  Serial.println(val);
}

