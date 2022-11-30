#include <Servo.h>
//pins digital
  int pin1 = 10;
  int pin2 = 9;
  int pin4 = 6; 
  int sound = 0;
  int pin3 = A0;
//ldrs pinsanalogs
  int ldrarriba=A1;
  int ldrizq=A2;
  int ldrabajo=A3;
  int ldrderecha=A4;
//servos
  Servo horizontal;
  Servo vertical;
  Servo ori;
//variables
  int state=1;
  int promarriba=0;
  int promabajo=0;
  int promizq=0;
  int promder=0;
  int arribaizq=0;
  int abajoder=0;
  int abajoizq=0;
  int arribader=0;
  int light = 0;
  int altura=0;
  int rotacion=0;
//funciones
  void move(){
    if (state==1){
      if (promizq>promder){
        rotacion = --rotacion;
        if (rotacion<0){
          rotacion=0;
        }
      }

    }
    else if (promizq<promder){
      rotacion= ++ rotacion;
        if (rotacion>180){
          rotacion=180;
        }
    }
    else if (promizq==promder){
      
    }
        if (promarriba>promabajo){
        altura = --altura;
        if (altura<0){
          altura=0;
        }
      }

    
    else if (promarriba<promabajo){
      altura = ++ altura;
        if (altura>180){
          altura=180;
        }
    }
    else if (promarriba==promabajo){
      
    }
    vertical.write(altura);
    horizontal.write(rotacion);
    delay(100);
    }

  void prom(){
    promarriba=(arribader + arribaizq)/2;
    promabajo=(abajoizq+abajoder)/2;
    promizq=(arribaizq+abajoizq)/2;
    promder=(arribader+abajoder)/2;


    }
  void marvin(){
    if (state==1){
      Serial.println(state);
      arribaizq=analogRead(ldrarriba);
      abajoder=analogRead(ldrabajo);
      abajoizq=analogRead(ldrizq);
      arribader=analogRead(ldrderecha);
      light = (arribaizq + abajoder + abajoizq + arribader)/4;

      }
    }
  void origami(){
    if (light >= 100 && state==1){
      ori.write(90);

    }
    else{
      ori.write(0);
    }
    }
  void onoff(){
    sound = analogRead(pin3);
    Serial.println(sound);
    if (sound<=900) {
      vertical.write(0);
      horizontal.write(90);
      delay(1000);
      vertical.write(90);
      horizontal.write(0);
      delay(1000);
   
    }
    else{
    
    }
    }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  horizontal.attach(pin2);
  vertical.attach(pin1);  
  ori.attach(pin4); 
  } 

void loop() {
  onoff();
  marvin();
  prom();
  origami();
  move();  
  //prints
  if (state==1){
   Serial.print("ARRIBA :  ");
    Serial.println(arribaizq);
     Serial.print("ABAJO :  ");
    Serial.println(abajoder);
     Serial.print("DERECHA :  ");
    Serial.println(promder);
     Serial.print("IZQUIERDA :  ");
    Serial.println(abajoizq);
     Serial.print("ALTURA :  ");
    Serial.println(altura);
     Serial.print("ROTACION :  ");
    Serial.println(rotacion);
    delay(10); 
  }

  }
