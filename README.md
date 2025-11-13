# 🌡️ SmartDesk — Monitoramento de Ambiente de Trabalho

## 🎯 Objetivo
O projeto **SmartDesk** tem como foco melhorar o bem-estar e a produtividade de pessoas que trabalham em ambientes fechados.  
Ele monitora **temperatura**, **umidade** e **luminosidade**, indicando com LEDs se o ambiente está confortável, precisa de atenção ou está em condição ruim.

---

## ⚙️ Funcionamento
O sistema usa o microcontrolador **ESP32**, o sensor **DHT22** e um **sensor LDR**.

- 🟢 **Verde:** ambiente ideal  
- 🟡 **Amarelo:** ambiente de atenção (pode estar um pouco quente ou escuro)  
- 🔴 **Vermelho:** ambiente ruim (muito quente, seco ou escuro)

As informações são mostradas no **Monitor Serial**, e o circuito foi desenvolvido e testado no **Wokwi**.

---

## 🌐 Conectividade (MQTT/HTTP)

Na versão física (com ESP32 real), o projeto pode enviar as leituras de temperatura, umidade e luminosidade
para um servidor MQTT ou via protocolo HTTP.  
Assim, seria possível monitorar o ambiente em tempo real em um dashboard ou aplicativo web,
integrando o SmartDesk com sistemas de gestão de conforto e produtividade.

---

## 🔧 Componentes usados
- ESP32  
- Sensor DHT22 (temperatura e umidade)  
- Sensor LDR (luminosidade)  
- 3 LEDs (verde, amarelo e vermelho)  
- Resistores

## 📦 Bibliotecas utilizadas
- `DHT.h` — para leitura de temperatura e umidade (sensor DHT22)
- `Adafruit_Sensor.h` — suporte interno da biblioteca DHT

---

## Como testar no Wokwi
1. Abra o link do Wokwi: (veja `edge/wokwi_link.txt`)  
2. Clique em **Start Simulation**.  
3. Abra o Serial Monitor e observe as leituras; veja os LEDs mudarem conforme as condições.

Link da simulação: https://wokwi.com/projects/447462756615539713

---

## Arquivos relevantes
- `edge/smartdesk.ino` — código (versão para simulação)
- `edge/wokwi_link.txt` — link da simulação
- `images/` — screenshots do circuito 
- `ppt/` — slides para o vídeo
- `video/` — link do vídeo no YouTube (inserir após envio)

---

## 👨‍💻 Autor
**Breno Henrique Bortoloti — RM562856**  
**Pedro Cunha Coutinho — RM562191** 
**Pedro Henrique dos Santos — RM564188** 

Disciplina: **Edge Computing & Computer Systems**  
FIAP — 2º semestre de 2025
