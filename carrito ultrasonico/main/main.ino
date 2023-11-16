int int1=8, int2=9, int3=10, int4=11; //int1 e int2 son la derecha, int3 e int4 son izquierda
int ena, enb; //ena es derecha, enb es izquierda
int potencia=0, encendido=0, valorSerial=0;


void setup() {
  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    Serial.print("serial disponible\n");
    valorSerial=Serial.read();
    Serial.print("serial value: ");
    Serial.print(valorSerial);
  }
  
}

void Decision(int valorSerial){
  if(valorSerial=='A' || valorSerial=='D' || valorSrial='I' || valorSerial==0){
    Encender(valorSerial, int1,int2,int3,int4);
  }if(valorSerial>=1 && valorSerial<=1055){
    Potencia(valorSerial,ena, enb);
  }
}

void Potencia(int velocidad, int ena, int enb){
  if(velocidad==1){
    analogWrite(ena, 85);
    analogWrite(enb,85);  
  }else if(velocidad==2){
    analogWrite(ena, 170);
    analogWrite(enb, 170);
  }else if(velocidad==3){
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }else{
    Decision(velocidad);
  }
  
}

void Encender(int encendido, int int1, int int2, int int3, int int4){
  if(encendido=='A'){ //si encendido tiene el valor 1, avanza derecho
    digitalWrite(int1, HIGH);
    digitalWrite(int2, HIGH);
    digitalWrite(int3, HIGH);
    digitalWrite(int4, HIGH);
  }else if(encendido=='D'){ //si encendido tiene valor 2, gira derecha
    digitalWrite(int1, HIGH);
    digitalWrite(int2, HIGH);
    digitalWrite(int3, LOW);
    digitalWrite(int4, LOW);
  }else if(encendid=='I'){
     digitalWrite(int1, LOW);
    digitalWrite(int2, LOW);
    digitalWrite(int3, HIGH);
    digitalWrite(int4, HIGH);
  }else if(encendido==0){
     digitalWrite(int1, LOW);
    digitalWrite(int2, LOW);
    digitalWrite(int3, LOW);
    digitalWrite(int4, LOW);
  }else{
    Decision(encendido);
  }
}