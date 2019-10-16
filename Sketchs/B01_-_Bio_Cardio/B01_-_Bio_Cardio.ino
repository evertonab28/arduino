
/*  Getting_BPM_to_Monitor prints the BPM to the Serial Monitor, using the least lines of code and PulseSensor Library.
 *  Getting_BPM_to_Monitor imprime os BPM (batimentos por minuto) no Monitor Serial, utilizando o mínimo de linhas de código e a biblioteca PulseSensor.
 *  
 *  Site do tutorial (em inglês): https://pulsesensor.com/pages/getting-advanced
 *  Tutorial Webpage: https://pulsesensor.com/pages/getting-advanced
 *
--------Use This Sketch To------------------------------------------
--------Utilize este Sketch Para------------------------------------------
1) Displays user's live and changing BPM, Beats Per Minute, in Arduino's native Serial Monitor.
1) Exibir em tempo real os BPM, Batimentos Por Minuto, no Monitor Serial nativo do Arduino.
2) Print: "♥  A HeartBeat Happened !" when a beat is detected, live.
2) Mostra: "♥  Um batimento cardíaco aconteceu!" quando um batimento for detectado, ao vivo.
2) Learn about using a PulseSensor Library "Object".
2) Aprender sobre o uso de um objeto da biblioteca PulseSensor.
4) Blinks LED on PIN 13 with user's Heartbeat.
4) Pisca o LED no PINO 13 conforme o batimento cardíaco do usuário.
--------------------------------------------------------------------*/

/*define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.*/
#define USE_ARDUINO_INTERRUPTS true    // Configura interrupções de baixo nível para um cálculo mais preciso dos BPM
/*#include <PulseSensorPlayground.h>   //Includes the PulseSensorPlayground Library.*/
#include <PulseSensorPlayground.h>     //Inclui a biblioteca PulseSensorPlayground

//  Variables
//Variáveis
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0    |||  FIO LARANJA do sensor de batimentos conectado ao PINO ANALÓGICO 0 do Arduino
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.    ||| O LED próprio da placa Arduino, localizado perto do PINO 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.   |||  Determina qual sinal recebido será contado como um batimento e qual será ignorado.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.   ||| Use o "Getting Started Project" para um ajuste fino do valor limite além da configuração padrão.
                               // Otherwise leave the default "550" value.   |||  Caso contrário, deixe o valor padrão de "550".
                               
PulseSensorPlayground sensorDePulso;  // Creates an instance of the PulseSensorPlayground object called "sensorDePulso"
                                     // Cria um objeto de PulseSensorPlayground chamado sensorDePulso.


void setup() {   

  Serial.begin(9600);          // Configura o Monitor Serial

  // Configure the PulseSensor object, by assigning our variables to it. 
// Configura o objeto Sensor de Pulso, atribuindo nossas variáveis a ele.
  sensorDePulso.analogInput(PulseWire);   
  sensorDePulso.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.   || Pisca automaticamente o LED do Arduino com um batimento cardíaco.
  sensorDePulso.setThreshold(Threshold);   

  // Double-check the "sensorDePulso" object was created and "began" seeing a signal. 
  // Checagem dupla do objeto "sensorDePulso", verificando se ele foi criado e começou a enxergar um sinal.
   if (sensorDePulso.begin()) {
    //Serial.println("We created a sensorDePulso Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
    Serial.println("Criamos um objeto sensorDePulso!");  //Isso é mostrado uma vez no Monitor Serial, quando o Arduino é ligado ou reiniciado.
  }
}



void loop() {

 int meuBPM = sensorDePulso.getBeatsPerMinute();  // Calls function on our sensorDePulso object that returns BPM as an "int".  |||  Chama a função "getBeatsPerMinute" no nosso objeto sensorDePulso, que retorna os BPM como um número inteiro.
                                               // "meuBPM" hold this BPM value now.    |||    "meuBPM" mantém este valor do BPM agora.

if (sensorDePulso.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".  ||| Testa constantemente para verificar se um batimento aconteceu.
 Serial.println("♥  Um Batimento Aconteceu!"); // If test is "true", print a message "a heartbeat happened".  |||  Se o teste for verdadeiro (true), imprime a mensagem "Um Batimento Aconteceu!".
 Serial.print("BPM: ");                        // Print phrase "BPM: "  |||  Imprime a frase "BPM: "
 Serial.println(meuBPM);                        // Print the value inside of meuBPM.    |||   Imprime o valor que foi armazenado na variável meuBPM.
}

  delay(20);                    // considered best practice in a simple sketch.   |||   Definimos um tempo de espera de 20ms para recomeçar o loop, considerada a melhor prática em um sketch simples.

}

  
