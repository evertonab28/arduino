/*
 * Codigo adaptado do forum oficial do Arduino
 * O código original está disponível em:
 * https://forum.arduino.cc/index.php?topic=336012.0
 *
 */

int pino_po = A0; //Pino analógico A0 onde conectaremos o pino Po do módulo

void setup() {
  Serial.begin(9600);
  }

void loop() {
  //A variável 'medida' irá receber a leitura do pino analógico A0
  int medida = analogRead(pino_po);
  Serial.print("Medida: ");
  Serial.print(medida);
  Serial.print(" ");

  //Conversão da leitura analógica de 0 a 1024 para uma tensão de 0 a 5 V
  double tensao = 5 / 1024.0 * medida;
  Serial.print("Tensão: ");
  Serial.print(tensao, 3);
  Serial.print(" ");

  float pH = 7 + ((2.5 - tensao) / 0.18);
  Serial.print("pH: ");
  Serial.print(pH, 3);

  Serial.println("");
  delay(2000);
}
