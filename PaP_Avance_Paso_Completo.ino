#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

int estado = 0;
float Tm = 0.1;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  Serial.begin(9600);
  estado = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
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
