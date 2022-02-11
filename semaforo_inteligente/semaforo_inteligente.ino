//Codigo por Sarah Ramos para um semaforo inteligente
//O pedestre passa pelo sensor ultrassonico e o semaforo fecha para atravesar a rua

#include <Ultrasonic.h> // Inclui biblioteca para usar o sensor ultrassônico
Ultrasonic ultrasonic(13,12); // Passa pinos 13 e 12 como emissor e receptor


void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT); //define portas dos leds como saida
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
     
  int dist = ultrasonic.read(CM);
  delay(200);
  Serial.print("DIST.: "); //printa no monitor serial a distancia
  Serial.print(dist);
  Serial.println(" cm.");

  if(dist > 10){
    digitalWrite(5,HIGH);//verde
    digitalWrite(6,LOW);//amarelo 
    digitalWrite(7,LOW);//vermelho
    digitalWrite(8,LOW);//verde pedestre
    digitalWrite(9,HIGH);//vermelho pedestre
  }else{
    digitalWrite(5,LOW);//verde
    digitalWrite(6,HIGH);//amarelo 
    digitalWrite(7,LOW);//vermelho
    digitalWrite(8,LOW);//verde pedestre
    digitalWrite(9,HIGH);//vermelho pedestre
    delay(1000);
    digitalWrite(5,LOW);//verde
    digitalWrite(6,LOW);//amarelo 
    digitalWrite(7,HIGH);//vermelho
    digitalWrite(8,HIGH);//verde pedestre
    digitalWrite(9,LOW);//vermelho pedestre
    delay(5000);
  }
}
