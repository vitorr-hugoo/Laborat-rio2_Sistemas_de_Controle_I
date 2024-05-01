// Definição das variáveis medidas ou calculadas pelo código:
double timer; // Variável de cálculo do instante de tempo, em milissegundos.
double delta_t; // Variável de cálculo do tempo, em segundos, de execução do loop.
double VT; // Tensão de armadura do motor.
double ia; // Corrente de armadura do motor.
double dia_dt; // Derivada da corrente de armadura do motor.
double wm; // Velocidade angular do eixo do motor.
double dwm_dt; // Derivada da velocidade angular do eixo do motor.
double n; // Velocidade em RPM do eixo do motor.
double y_t; //resposta do sistema 

// Variáveis para parametrização (ajuste):
double VT_nominal = 150; // Tensão nominal de armadura do motor.
double ia_nominal = 10; // Corrente nominal de armadura do motor.
double n_nominal = 1800; // Velocidade nominal do eixo do motor.
float Ra = 1; // Valor da resistência de armadura.
float La = 0.05; // Valor da indutância de armadura.
float Jm = 0.5; // Valor do momento de inércia do eixo do motor.
float Kce = 0.74272; // Constante de tensão.
float Kt = 0.74272; // Constante de torque.
double pi = 3.141592; // Valor de pi.

#define A1 0 // Defina o pino analógico usado para leitura da tensão.

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial a 9600 bps.
}

void loop() {
  delta_t = (millis() - timer) / 1000.0; // Calcula o tempo, em segundos, de execução do loop.
  timer = millis(); // Mede o instante, em milissegundos, de execução do loop.
  //VT = (float)map(analogRead(A1), 0, 512, 0, VT_nominal); // Variação da tensão de armadura pelo potenciômetro.
  if(analogRead(A1) < 512)
  {
    VT = 50;
  }  
  else {
    VT = 100;
  }

  //-----INÍCIO: Rotina de código do modelo do Motor CC no espaço de estados---
  dia_dt= (-Ra/La)*ia - (Kce/La)*wm + (1/La)*VT;
  ia += dia_dt*delta_t;
  dwm_dt = (Kt/Jm)*ia;
  wm += dwm_dt*delta_t;
  n = (30/pi)*wm;
  

  //-----FIM: Rotina de código do modelo do Motor CC no espaço de estados---

  //RPM motor
  
  /*
  Serial.print("Tempo: ");
  Serial.print(timer / 1000.0); // Print do valor do instante de tempo em segundos.
  Serial.print(", VT: ");
  Serial.print(VT); // Print do valor da tensão de armadura.
  Serial.print(", RPM: ");
  Serial.print(n); // Print do valor da velocidade do eixo do motor.
  Serial.println();
  */

//usado para plotar os valores da tensão VT e do RPM do motor
 Serial.print(VT);
  Serial.print(",");
  Serial.println(n);
  // Atualiza o valor de delta_t no final do loop.
  
}