# SmartDesk – Estação Inteligente de Bem-Estar no Trabalho (ESP32 / Wokwi)

## Descrição
O **SmartDesk** é uma estação simples com ESP32 que monitora temperatura, umidade e iluminação do local de trabalho. Quando o ambiente não está favorável, o dispositivo acende um LED vermelho e pode enviar alertas (versão com rede). Projeto feito para a disciplina Edge Computing & Computer Systems.

---

## Autor
- **Nome:** Breno Henrique Bortoloti Santos
- **RM:** RM562856

- **Nome:** Pedro Henrique dos Santos
- **RM:** RM564188

- **Nome:** Pedro Cunha Coutinho
- **RM:** RM562191

---

## Componentes usados (simulados)
- ESP32
- DHT22 (sensor de temperatura e umidade)
- LDR (fotoresistor)
- LEDs: verde (D25), amarelo (D26), vermelho (D27)

---

## Como testar no Wokwi
1. Abra o link do Wokwi: (veja `edge/wokwi_link.txt`)  
2. Clique em **Start Simulation**.  
3. Abra o Serial Monitor e observe as leituras; veja os LEDs mudarem conforme as condições.

Link da simulação: https://wokwi.com/projects/447462756615539713

---

## Arquivos relevantes
- `edge/smartdesk.ino` — código (versão para simulação)
- `edge/smartdesk_mqtt.ino` — (versão com Wi-Fi/MQTT, para hardware real)
- `edge/wokwi_link.txt` — link da simulação
- `images/` — screenshots do circuito e do monitor serial
- `ppt/` — slides para o vídeo
- `video/` — link do vídeo no YouTube (inserir após envio)

---

## Tópicos MQTT (usado somente na versão com rede)
- `smartdesk/data` — dados periódicos (payload JSON)
- `smartdesk/alerts` — alertas de pausa

---

## Observações
Código e documentação feitos para demonstrar como IoT pode ajudar no bem-estar dos profissionais em home office e espaços híbridos.

---
