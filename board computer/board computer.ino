int pisc_esq = 26;
int pisc_direi = 27;
int ligar_ing = 28;
int ligar_farol = 29;
int ligar_carro = 31;
int ligar_alerta = 32;
int chave;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pisc_esq, OUTPUT);
  pinMode(pisc_direi, OUTPUT);
  pinMode(ligar_ing, OUTPUT);
  pinMode(ligar_farol, OUTPUT);
  pinMode(ligar_carro, INPUT);
  pinMode(ligar_alerta, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char leitura = Serial.read();
  
  chave  = digitalRead(ligar_carro);
  if(chave == HIGH )
  {
    digitalWrite(pisc_esq, HIGH);
    digitalWrite(pisc_direi, HIGH);
    delay(1000);
    digitalWrite(pisc_esq, LOW);
    digitalWrite(pisc_direi, LOW);
    delay(1000);
  }
  
  if(chave == LOW)
  {
    digitalWrite(pisc_esq, LOW);
    digitalWrite(pisc_direi, LOW);
  }
}
