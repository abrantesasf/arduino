// Lista 2.6: controlando LED RGB através do uso de:
//               - Output PWM para pernas RGB do led
//               - Input através de pino digital e botão
//               - Código para debouncing de botão

// Declara variáveis
const int red   = 11;
const int green = 10;
const int blue  =  9;
const int botao =  2;

boolean botaoAnterior = LOW;
boolean botaoAtual    = LOW;

int posicaoNoCiclo = 0;

// Configuração inicial
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
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

// Função para mudar a cor do botão no ciclo (não retorna nada):
void mudaCor(int posicao) {
  if (posicao == 0) {         // APAGADO
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  } else if (posicao == 1) {  // VERMELHO
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  } else if (posicao == 2) {  // VERDE
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  } else if (posicao == 3) {  // AZUL
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  } else if (posicao == 4) {  // PÚRPURA (VERMELHO + AZUL)
    analogWrite(red, 127);
    analogWrite(green, 0);
    analogWrite(blue, 127);
  } else if (posicao == 5) {  // TEAL (AZUL + VERDE)
    analogWrite(red, 0);
    analogWrite(green, 127);
    analogWrite(blue, 127);
  } else if (posicao == 6) {  // LARANJA (VERMELHO + VERDE)
    analogWrite(red, 127);
    analogWrite(green, 127);
    analogWrite(blue, 0);
  } else if (posicao == 7) {  // BRANCO (VERMELHO + AZUL + VERDE)
    analogWrite(red, 85);
    analogWrite(green, 85);
    analogWrite(blue, 85);
  }
}

// Loop principal:
void loop() {
  botaoAtual = debounce(botaoAnterior);
  if (botaoAnterior == LOW && botaoAtual == HIGH) {
    posicaoNoCiclo++;
  }
  botaoAnterior = botaoAtual;
  if (posicaoNoCiclo == 8) {
    posicaoNoCiclo = 0;
  }
  mudaCor(posicaoNoCiclo);
}

