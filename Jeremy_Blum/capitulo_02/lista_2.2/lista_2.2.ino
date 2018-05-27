// Lista 2.2

// Declara variáveis
const int led = 9;

// Configuração geral
void setup() {
  pinMode(led, OUTPUT);
}

// Loop princiapl
void loop() {
  for (int i = 25; i <= 1000; i = i + 25) {
    digitalWrite(led, HIGH);
    delay(i);
    digitalWrite(led, LOW);
    delay(i);
  }
}

