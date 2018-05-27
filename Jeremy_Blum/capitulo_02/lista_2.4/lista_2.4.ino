// Lista 2.4: pulldown resistors

// Declara variáveis
const int led = 9;
const int botao = 2;

// Configuração inicial
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

// Loop principal
void loop() {
  if (digitalRead(botao) == LOW) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}

