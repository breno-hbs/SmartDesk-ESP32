/*
  Projeto: SmartDesk — Monitoramento de Ambiente de Trabalho
  Descrição: Monitora temperatura, umidade e luminosidade, acendendo LEDs
              para indicar se o ambiente está confortável, de atenção ou ruim.
  Integrantes: 
    - Breno Henrique Bortoloti (RM562856)
    - Pedro Cunha Coutinho (RM562191)
    - Pedro Henrique dos Santos (RM564188)
  Disciplina: Edge Computing & Computer Systems — FIAP 2025
*/

#include <DHT.h>

// Definindo os pinos dos componentes
#define PINO_DHT 15
#define TIPO_DHT DHT22
#define PINO_LDR 34
#define LED_VERDE 25
#define LED_AMARELO 26
#define LED_VERMELHO 27

// Criando o sensor DHT
DHT sensorDHT(PINO_DHT, TIPO_DHT);

void setup() {
  Serial.begin(115200); // Inicia o monitor serial
  sensorDHT.begin(); // Inicia o sensor de temperatura e umidade

  // Define os pinos dos LEDs como saída
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  Serial.println("Sistema SmartDesk iniciado!");
}

void loop() {
  // Lê os dados do sensor DHT
  float temperatura = sensorDHT.readTemperature();
  float umidade = sensorDHT.readHumidity();
  int luz = analogRead(PINO_LDR);

  // Mostra os dados no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C | Umidade: ");
  Serial.print(umidade);
  Serial.print("% | Luz: ");
  Serial.println(luz);

  // Lógica para acender os LEDs de acordo com as condições do ambiente
  if (temperatura > 26 || umidade < 40 || luz < 500) {
    // Ambiente ruim
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
  } 
  else if (temperatura > 23 || luz < 800) {
    // Ambiente mais ou menos
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
  } 
  else {
    // Ambiente ideal
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  }

  delay(2000); // Espera 2 segundos antes de fazer nova leitura
}


