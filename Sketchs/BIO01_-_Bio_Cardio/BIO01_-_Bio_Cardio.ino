/*  Getting_BPM_to_Monitor imprime os BPM (batimentos por minuto) no Monitor Serial, utilizando o mínimo de linhas de código e a biblioteca PulseSensor.
 *  
 *  Site do tutorial (em inglês): https://pulsesensor.com/pages/getting-advanced 
 *
--------Utilize este Sketch Para------------------------------------------
1) Exibir em tempo real os BPM, Batimentos Por Minuto, no Monitor Serial nativo do Arduino.
2) Mostra: "♥  Um batimento cardíaco aconteceu!" quando um batimento for detectado, ao vivo.
2) Aprender sobre o uso de um objeto da biblioteca PulseSensor.
4) Pisca o LED no PINO 13 conforme o batimento cardíaco do usuário.
--------------------------------------------------------------------*/

#define USE_ARDUINO_INTERRUPTS true    // Configura interrupções de baixo nível para um cálculo mais preciso dos BPM
#include <PulseSensorPlayground.h>     //Inclui a biblioteca PulseSensorPlayground

// Variáveis
const int PulseWire = 0;       // FIO LARANJA do sensor de batimentos conectado ao PINO ANALÓGICO 0 do Arduino
const int LED13 = 13;          // O LED próprio da placa Arduino, localizado perto do PINO 13.
int Threshold = 550;           // Determina qual sinal recebido será contado como um batimento e qual será ignorado.
                               // Use o "Getting Started Project" para um ajuste fino do valor limite além da configuração padrão.
                               // Caso contrário, deixe o valor padrão de "550".
                               
PulseSensorPlayground sensorDePulso;  // Cria um objeto de PulseSensorPlayground chamado sensorDePulso. 
                                     


void setup() {   

  Serial.begin(9600);          // Configura o Monitor Serial
  
// Configura o objeto Sensor de Pulso, atribuindo nossas variáveis a ele.
  sensorDePulso.analogInput(PulseWire);   
  sensorDePulso.blinkOnPulse(LED13);       // Pisca automaticamente o LED do Arduino com um batimento cardíaco.
  sensorDePulso.setThreshold(Threshold);   
  
  // Checagem dupla do objeto "sensorDePulso", verificando se ele foi criado e começou a enxergar um sinal.
   if (sensorDePulso.begin()) {    
    Serial.println("Criamos um objeto sensorDePulso!");  //Isso é mostrado uma vez no Monitor Serial, quando o Arduino é ligado ou reiniciado.
  }
}



void loop() {

 int meuBPM = sensorDePulso.getBeatsPerMinute();  // Chama a função "getBeatsPerMinute" no nosso objeto sensorDePulso, que retorna os BPM como um número inteiro.
                                                  // "meuBPM" mantém este valor do BPM agora.

if (sensorDePulso.sawStartOfBeat()) {            // Testa constantemente para verificar se um batimento aconteceu.
 Serial.println("♥  Um Batimento Aconteceu!");  // Se o teste for verdadeiro (true), imprime a mensagem "Um Batimento Aconteceu!".
 Serial.print("BPM: ");                         // Mostra a frase "BPM: "
 Serial.println(meuBPM);                        // Mostra o valor que foi armazenado na variável meuBPM.
}

  delay(20);     // Definimos um tempo de espera de 20ms para recomeçar o loop, considerada a melhor prática em um sketch simples.

}

  
