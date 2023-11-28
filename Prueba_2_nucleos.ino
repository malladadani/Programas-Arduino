/*
 * Programa para trabajar con dos nucleos
 */

TaskHandle_t Task1;   // Creamos dos variables, de la clase 
TaskHandle_t Task2;   // "TaskHandle_t", para cada una de las tareas

// Declaracion de variables y constantes

int a = 0;
const int _IN4 = 12;
const int _IN3 = 14;
int duty = 0;


// Función que se va a ejecutar en el nucleo 0

void Tarea_Nucleo_0(void *pvParameters)
{
  // Lo metemos dentro de un while(1), para que 
  // se ejecute de manera infinita
  
  while(1)
  {
    
    digitalWrite(_IN3, duty);
    Serial.print(duty);
    Serial.print("\n");
    delay(20);

  }

}


// Funcion que se va a ejecutar en el nucleo 1

void Tarea_Nucleo_1(void *pvParameters)
{

  while(1)
  {
    duty = 0;

    delay(5000);

    duty = 200; 

    delay(5000);

  }
}


// Configuramos los nucleos

void configurar_Nucleos()
{
  
  Serial.begin(115200);
  xTaskCreatePinnedToCore(
    Tarea_Nucleo_0, 
    "Task1",
    10000,
    NULL,
    0,
    &Task1,
    0);


  xTaskCreatePinnedToCore(
    Tarea_Nucleo_1,
    "Task2",
    10000,
    NULL,
    1,
    &Task2,
    1);
}


void setup() {
  // put your setup code here, to run once:
  configurar_Nucleos();
  
  pinMode(_IN4, OUTPUT);
  pinMode(_IN3, OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
}
