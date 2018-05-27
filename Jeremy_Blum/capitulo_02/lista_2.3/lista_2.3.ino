// Lista 2.3: Pulse-Width Modulation

// Declara variáveis
const int led = 9;

// Configuração inicial:
void setup() {
  pinMode(led, OUTPUT);
}

// Loop principal
void loop() {
  // Aumenta a luz do led
  for (int i = 0; i <= 255; i = i + 1) {
    analogWrite(led, i);
    delay(10);
  }
  // Diminui a luz do led
  for (int i = 255; i >= 0; i = i - 1) {
    analogWrite(led, i);
    delay(10);
  }
}

