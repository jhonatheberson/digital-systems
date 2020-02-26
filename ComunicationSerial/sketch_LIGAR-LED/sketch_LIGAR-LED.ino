int led = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char leitura = Serial.read();

  if(leitura == '1')
  {
    digitalWrite(led, HIGH);
  }
  
  if(leitura == '0')
  {
    digitalWrite(led, LOW);
  }
}
