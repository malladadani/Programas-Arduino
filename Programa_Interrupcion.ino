/*
  Programa para cambiar el estado de dos led con una interrupción externa
  */

// Definición de constantes
#define SALIDA 15
#define Boton 33

#define LED_1 24
#define LED_2 27

// Variable para el cambio de estado
int cont = 0;

// Configuración
void setup() {
  // put your setup code here, to run once:

  // Configuración de pines
  pinMode(Boton, INPUT);
  pinMode(SALDIA, OUTPUT);

  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);

  // Configuración de baudios salida
  Serial.begin(9600);

  // Configuración de la interrupción, por flanco de bajada
  attachInterrupt(digitalPinToInterrupt(Boton), funcion_interrupcion, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(cont)
  {
    case(0):
      digitalWrite(LED_1, 1);
      digitalWrite(LED_2, 0);
    break;

    case(1):
      digitalWrite(LED_1,0);
      digitalWrite(LED_2,1);
    break;

    case(2):
      digitalWrite(LED_1,1);
      digitalWrite(LED_2,1);
    break;

    default:
      digitalWrite(LED_1,0);
      digitalWrite(LED_2,0);
    break;
  }
}

void funcion_interrupcion()
{
  // Delay para el rebote
  delay(20);
  if(cont == 3)
  {
    cont = 0;
  }  
  else
  {
    cont++;
  }
}
