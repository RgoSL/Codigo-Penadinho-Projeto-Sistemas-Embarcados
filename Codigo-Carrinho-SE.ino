//Sensor Infra

// (Definição dos Pins)

int IRpin = 8;  
int ledpin = 9;  
int valorLido = 0;  //Váriavel de Leitura

void setup(){
  Serial.begin(9600); 
  pinMode(IRpin, INPUT);  
  pinMode(ledpin, OUTPUT);  
}

void loop() {
  valorLido = digitalRead(IRpin); 
  if (valorLido == LOW) {  
    digitalWrite(ledpin,HIGH);  
  }
  else { 
    digitalWrite(ledpin,LOW);
  }
  delay(100); 
}


// Motores

void setup()
{
  Serial.begin(9600);

  //Entradas dos Pinos

  //Motor I
  pinMode(5, OUTPUT); // Saída -
  pinMode(0, OUTPUT); // Saída +

  //Motor II
  pinMode(4, OUTPUT); // Saída -
  pinMode(2, OUTPUT); // Saída +
}

void loop()
{

    //Motor I
  analogWrite(5, 1024); 
  digitalWrite(0, HIGH); 

    //Motor II
  analogWrite(4, 1024); 
  digitalWrite(2, HIGH); 

  delay(2000);

//Para Girar em Outro Sentido

  //Motor I
  analogWrite(5, 1024); 
  digitalWrite(0, LOW); 

  //Motor II
  analogWrite(4, 1024); 
  digitalWrite(2, LOW); 

  delay(2000);
}


//Unificação

// (Entradas à Definir)
const int pinSensor = ; // (Valor da Entrada com o Sensor)
const int motorLeft = ;  // (Valor do Motor da Esquerda)
const int motorRight = ; // (Valor do Motor da Direita)

int sensorValue = 0;

// Espaço Limite Para a Detecção
const int lineThreshold = 500; 

void setup() {
  
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);

  pinMode(pinSensor, INPUT);
}

void loop() {
  sensorValue = analogRead(pinSensor);

  if (sensorValue > lineThreshold) {
    // Boot no Motor ao Detectar uma Linha
    digitalWrite(motorLeft, HIGH);
    digitalWrite(motorRight, HIGH);
  } else {
    // Alterna Entre as Rodas Para Procurar uma Linha
    digitalWrite(motorLeft, HIGH);
    digitalWrite(motorRight, LOW);
  }

  delay(300);
}
