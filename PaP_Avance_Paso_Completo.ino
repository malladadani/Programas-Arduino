/*
  Programa para controlar motores Paso a Paso con avance de paso completo --> L298N y ESP32
*/

// Definición de constantes

#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

// Definición de variables
int estado = 0; // Controla el paso que da
float Tm = 0.1; // Delay entre paso y paso


void setup() {
  // put your setup code here, to run once:

  // Configuramos puertos
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  // Configuramos los baudios de salida
  Serial.begin(9600);

  // Inicializamos el paso en 1
  estado = 1;
}

// Bucle infinito
void loop() {
  // put your main code here, to run repeatedly:
  // Switch case para los estados
  switch(estado){
    case(1):
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);

      Serial.println("Estado 1");
      estado = 2;
      delay(Tm);
    break;

    case(2):
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);

      Serial.println("Estado 2");
      estado = 3;
      delay(Tm);
    break;

    case(3):
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);

      Serial.println("Estado 3");
      estado = 4;
      delay(Tm);
    break;

    case(4):
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);

      Serial.println("Estado 4");
      estado = 1;
      delay(Tm);
    break;
  }
}
