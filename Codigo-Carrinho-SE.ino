//Sensor Infra

int IRpin = 8;  //Atribui o pino 8 a variável IRpin
int ledpin = 9;  //Atribui o pino 9 a variável ledpin
int valorLido = 0;  //Variável responsável por armazenar o estado do infravermelho (LOW/HIGH)

void setup(){
  Serial.begin(9600);  //Inicializa a comunicação serial, com velocidade de comunicação de 9600
  pinMode(IRpin, INPUT);  //IRpin definido como entrada
  pinMode(ledpin, OUTPUT);  //ledpin definido como saída
}

void loop() {
  valorLido = digitalRead(IRpin);  //Armazena o valor digital de IRpin em valorLido
  if (valorLido == LOW) {   //Se valor lido for igual a LOW
    Serial.println("Linha Detectada");    //Escreve na serial "Linha Detectada"
    digitalWrite(ledpin,HIGH);  //Liga o LED
  }
  else { 
    Serial.println("Linha NAO Detectada"); //Escreve na serial "Linha não detectada"
    digitalWrite(ledpin,LOW);   //Desliga o LED
  }
  delay(100);  //Intervalo de 100 milissegundos
}

// Motores


void setup()
{
  Serial.begin(9600);

  //Define os pinos de controle do motor como saida
  //Motor 1
  pinMode(5, OUTPUT); // saída A-
  pinMode(0, OUTPUT); // saída A+

  //Motor 2
  pinMode(4, OUTPUT); // saída B-
  pinMode(2, OUTPUT); // saída B+
}

void loop()
{
  //Gira os motores no sentido horario

  //Aciona motor 1
  analogWrite(5, 1024); 
  digitalWrite(0, HIGH); 

  //Aciona motor 2
  analogWrite(4, 1024); 
  digitalWrite(2, HIGH); 

  //Aguarda 2 segundos
  delay(2000);

  //Gira os motores no sentido anti-horario

  //Aciona motor 1
  analogWrite(5, 1024); 
  digitalWrite(0, LOW); 

  //Aciona motor 2
  analogWrite(4, 1024); 
  digitalWrite(2, LOW); 

  //Aguarda 2 segundos e reinicia o processo
  delay(2000);
}


//Unificação

// Definição de pinos
const int pinSensor = A0; // Sensor conectado no pino analógico A0
const int motorLeft = 5;  // Motor esquerdo conectado no pino digital 5
const int motorRight = 6; // Motor direito conectado no pino digital 6

// Variável para armazenar leitura do sensor
int sensorValue = 0;

// Limite para detecção de linha
const int lineThreshold = 500; 

void setup() {
  // Configura os pinos dos motores como saída
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);

  // Configura o pino do sensor como entrada
  pinMode(pinSensor, INPUT);
}

void loop() {
  // Lê o valor do sensor
  sensorValue = analogRead(pinSensor);

  // Verifica se o sensor detecta a linha
  if (sensorValue > lineThreshold) {
    // Linha detectada: ativa os motores
    digitalWrite(motorLeft, HIGH);
    digitalWrite(motorRight, HIGH);
  } else {
    // Linha não detectada: desliga os motores
    digitalWrite(motorLeft, HIGH);
    digitalWrite(motorRight, LOW);
  }

  // Aguarda um pequeno intervalo para leitura estável
  delay(100);
}
