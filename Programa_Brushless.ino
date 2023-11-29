/*
 * Programa para controlar el sentido de giro de un motor Brushless con dos driver L298N y un ESP32
 * 
  */

#define ENA 17
#define Fase_U 16
#define ENB 4
#define Fase_V 0
#define ENC 2
#define Fase_W 15


float Tm = 0.01;
int estado = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Avance_Positivo();
  // Avance_Negativo();
}

void Avance_Positivo()
{
  switch(estado)
  {
    case(1):
      Serial.println("Estado 1");
      
      digitalWrite(ENA,1);
      digitalWrite(Fase_U,1);

      digitalWrite(ENB,1);
      digitalWrite(Fase_V,0);

      digitalWrite(ENC,0);
      // Condiciona a que este abierto el puente entero

      delay(Tm);
      estado = 2;      
    break;


    case(2):
      Serial.println("Estado 2");

      digitalWrite(ENA,1);
      digitalWrite(Fase_U,1);

      digitalWrite(ENB,0);
      // Condiciona a que este abierto el puente entero

      digitalWrite(ENC,1);
      digitalWrite(Fase_W,0);

      delay(Tm);
      estado = 3;
    break;


    case(3):
      Serial.println("Estado 3");

      digitalWrite(ENA,0);
      // Condiciona a que este abierto el puente entero

      digitalWrite(ENB,1);
      digitalWrite(Fase_V,1);

      digitalWrite(ENC,1);
      digitalWrite(Fase_W,0);

      delay(Tm);
      estado = 4;
    break;

    case(4):
      Serial.println("Estado 4");

      digitalWrite(ENA,1);
      digitalWrite(Fase_U,0);

      digitalWrite(ENB,1);
      digitalWrite(Fase_V,1);

      digitalWrite(ENC,0);
      // Condiciona a que este abierto el puente entero

      delay(Tm);
      estado = 5;
    break;
      
    case(5):
      Serial.println("Estado 5");

      digitalWrite(ENA,1);
      digitalWrite(Fase_U,0);

      digitalWrite(ENB,0);
      // Condiciona a que este abierto el puente entero

      digitalWrite(ENC,1);
      digitalWrite(Fase_W,1);

      delay(Tm);
      estado = 6;
    break;


    case(6):
      Serial.println("Estado 6");

      digitalWrite(ENA,0);
      // Condiciona a que este abierto el puente entero

      digitalWrite(ENB,1);
      digitalWrite(Fase_V,0);

      digitalWrite(ENC,1);
      digitalWrite(Fase_W,1);

      delay(Tm);
      estado = 1;
    break;
    } // Fin switch
  } // Fin Función Avance_Positivo


  void Avance_Negativo()
  {
    switch(estado)
    {
      case(1):
        Serial.println("Estado 1");

        digitalWrite(ENA,0);
        // Condiciona a que este abierto el puente entero
  
        digitalWrite(ENB,1);
        digitalWrite(Fase_V,0);
  
        digitalWrite(ENC,1);
        digitalWrite(Fase_W,1);
  
        delay(Tm);
        estado = 2;
      break;

      case(2):
        Serial.println("Estado 2");

        digitalWrite(ENA,1);
        digitalWrite(Fase_U,0);
  
        digitalWrite(ENB,0);
        // Condiciona a que este abierto el puente entero
  
        digitalWrite(ENC,1);
        digitalWrite(Fase_W,1);
  
        delay(Tm);
        estado = 3;
      break;

      case(3):
        Serial.println("Estado 3");

        digitalWrite(ENA,1);
        digitalWrite(Fase_U,0);
  
        digitalWrite(ENB,1);
        digitalWrite(Fase_V,1);
  
        digitalWrite(ENC,0);
        // Condiciona a que este abierto el puente entero
  
        delay(Tm);
        estado = 4;
      break;

      case(4):
        Serial.println("Estado 4");

        digitalWrite(ENA,0);
        // Condiciona a que este abierto el puente entero
  
        digitalWrite(ENB,1);
        digitalWrite(Fase_V,1);
  
        digitalWrite(ENC,1);
        digitalWrite(Fase_W,0);
  
        delay(Tm);
        estado = 5;
      break;

      case(5):
        Serial.println("Estado 5");

        digitalWrite(ENA,1);
        digitalWrite(Fase_U,1);
  
        digitalWrite(ENB,0);
        // Condiciona a que este abierto el puente entero
  
        digitalWrite(ENC,1);
        digitalWrite(Fase_W,0);
  
        delay(Tm);
        estado = 6;
      break;

      case(6):
        Serial.println("Estado 6");
      
        digitalWrite(ENA,1);
        digitalWrite(Fase_U,1);
  
        digitalWrite(ENB,1);
        digitalWrite(Fase_V,0);
  
        digitalWrite(ENC,0);
        // Condiciona a que este abierto el puente entero
  
        delay(Tm);
        estado = 1;
      break;
      } // Fin Switch
    } // Fin Función Avance_Negativo()
