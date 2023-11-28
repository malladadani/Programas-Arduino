#define SALIDA 15
#define Boton 33

#define LED_1 24
#define LED_2 27

int cont = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Boton, INPUT);
  pinMode(SALDIA, OUTPUT);

  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);

  Serial.begin(9600);

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