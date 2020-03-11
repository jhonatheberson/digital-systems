int pisc_esq = 26;
int pisc_direi = 27;
int ligar_ing = 28;
int ligar_farol = 29;
int ligar_carro = 31;
int ligar_alerta = 32;
int ingni = A0;
int combust = A2;
int veloc = A1;
int chave;
int alerta;
int ingnicao;
int velocidade;
int combustivel;
int contIg = 0;

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
  ingnicao = analogRead(ingni);
  
  
  
  alerta  = digitalRead(ligar_alerta);
  chave  = digitalRead(ligar_carro);
  if(ingnicao < 10)
  {
    contIg = 0;
    digitalWrite(ligar_farol, LOW);
    digitalWrite(ligar_ing, LOW);
    digitalWrite(pisc_esq, LOW);
    digitalWrite(pisc_direi, LOW);
  }
  if(ingnicao > 300 && ingnicao < 500){
      //digitalWrite(ligar_farol, HIGH);
      contIg = 0;
      if(leitura == '0'){
        digitalWrite(ligar_farol, LOW);
        delay(2000);
      }
      if(leitura == '1'){
        digitalWrite(ligar_farol, HIGH);
      }
      if(leitura == '2'){
          digitalWrite(pisc_esq, HIGH);
          delay(1000);
          digitalWrite(pisc_esq, LOW);
          delay(1000);
          digitalWrite(pisc_esq, HIGH);
          delay(1000);
          digitalWrite(pisc_esq, LOW);
          delay(1000);
          digitalWrite(pisc_esq, HIGH);
          delay(1000);
          digitalWrite(pisc_esq, LOW);
          delay(1000);
          digitalWrite(pisc_esq, HIGH);
          delay(1000);
          digitalWrite(pisc_esq, LOW);
          delay(1000);
      }
      if(leitura == '3'){
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
      }
      combustivel = analogRead(combust);
      Serial.write(combustivel);
  
  }
  if(ingnicao > 600 && ingnicao < 800)
  {
      if(contIg < 1){
        digitalWrite(ligar_ing, HIGH);
        delay(2000);
        digitalWrite(ligar_ing, LOW);

        contIg = 1;
      }
    if(leitura == '0'){
        digitalWrite(ligar_farol, LOW);
      }
    if(leitura == '1'){
        digitalWrite(ligar_farol, HIGH);
      }
    if(leitura == '2'){
        digitalWrite(pisc_esq, HIGH);
        delay(1000);
        digitalWrite(pisc_esq, LOW);
        delay(1000);
        digitalWrite(pisc_esq, HIGH);
        delay(1000);
        digitalWrite(pisc_esq, LOW);
        delay(1000);
        digitalWrite(pisc_esq, HIGH);
        delay(1000);
        digitalWrite(pisc_esq, LOW);
        delay(1000);
        digitalWrite(pisc_esq, HIGH);
        delay(1000);
        digitalWrite(pisc_esq, LOW);
        delay(1000);
    }
    if(leitura == '3'){
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
        digitalWrite(pisc_direi, HIGH);
        delay(1000);
        digitalWrite(pisc_direi, LOW);
        delay(1000);
    }
    combustivel = analogRead(combust);
    velocidade = analogRead(veloc);
    delay(100);
    Serial.write(combustivel);
    Serial.write(velocidade);
    Serial.write(ingnicao); 
//    Serial.println();
//    Serial.print("Combustivel: ");
//    Serial.println(combustivel);
//    Serial.print("Velocidade: ");
//    Serial.println(velocidade);
//    Serial.println(ingnicao);
//    
  }
  if(ingnicao > 900)
  {
    contIg = 0;
    digitalWrite(pisc_esq, HIGH);
    digitalWrite(pisc_direi, HIGH);
    digitalWrite(ligar_farol, HIGH);
    delay(1000);
    digitalWrite(pisc_esq, LOW);
    digitalWrite(pisc_direi, LOW);
    delay(1000);
  }
}
