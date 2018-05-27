// Lista 2.5: software para tratar bouncy buttons

// Declara variáveis
const int led = 9;
const int botao = 2;
boolean botaoAnterior = LOW;
boolean botaoAtual = LOW;
boolean ledLigado = false;

// Configuração inicial:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

// Função para debouncing do botão
boolean debounce(boolean ultimo) {
  boolean atual = digitalRead(botao);
  if (ultimo != atual) {
    delay(5);
    atual = digitalRead(botao);
  }
  return atual;
}

// Loop principal
void loop() {
  botaoAtual = debounce(botaoAnterior);
  if (botaoAnterior == LOW && botaoAtual == HIGH) {
    ledLigado = !ledLigado;
  }
  botaoAnterior = botaoAtual;
  digitalWrite(led, ledLigado);
}

