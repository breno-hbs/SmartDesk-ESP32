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

## 🔧 Componentes usados
- ESP32  
- Sensor DHT22 (temperatura e umidade)  
- Sensor LDR (luminosidade)  
- 3 LEDs (verde, amarelo e vermelho)  
- Resistores

---

## 🖥️ Simulação
🔗 **Projeto no Wokwi:** [Clique aqui](https://wokwi.com/projects/SEU-LINK-AQUI)

---

## 👨‍💻 Autor
**Breno Henrique Bortoloti — RMXXXXXX**  
Disciplina: **Edge Computing & Computer Systems**  
FIAP — 2º semestre de 2025
