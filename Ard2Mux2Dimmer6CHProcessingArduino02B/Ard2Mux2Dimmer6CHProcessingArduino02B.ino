// ARDUINO  -  2 MULTIPLEXORES  -  2 DIMMERS / 6CH
//
// Conxión de 2 Dimmer a través de 2 multiplexores:
//
//  Arduino       Multiplex1    Dimmer1
//     |              |            |          
//    GND ------- GND y EN ------ GND
//    5V ----------- VCC -------- VCC
//    8 ------------ S0 ---------- |          
//    9 ------------ S1 ---------- |          
//    10 ----------- S2 ---------- |
//    11 ----------- S3 ---------- |
//    5 ------------ SIG           |
//    3 ------------------------- SYNC
//    
//    
//    Multiplex1  Dimmer1   
//        |          |      
//        Y0 ------ CH1    
//        Y1 ------ CH2 
//        Y2 ------ CH3 
//        Y3 ------ CH4    
//        Y4 ------ CH5 
//        Y5 ------ CH6 
//    
//    

#include <TimerOne.h>    // Librería para interrupción

const int selectPins[4] = {8, 9, 10, 11}; // Pines de Arduino para todos los multiplexores (compartidos)
const int z1Output = 7; // Conexión a Z/SIG de Multiplexor1


unsigned char CH0; // Salida a Canal 6
unsigned char CH1; // Salida a Canal 1
unsigned char CH2; // Salida a Canal 2
unsigned char CH3; // Salida a Canal 3
unsigned char CH4; // Salida a Canal 4
unsigned char CH5; // Salida a Canal 5
unsigned char CH6; // Salida a Canal 6
unsigned char CH7; // Salida a Canal 1
unsigned char CH8; // Salida a Canal 2
unsigned char CH9; // Salida a Canal 3
unsigned char CH10; // Salida a Canal 4
unsigned char CH11; // Salida a Canal 5
unsigned char CH12; // Salida a Canal 6
unsigned char CH13; // Salida a Canal 3
unsigned char CH14; // Salida a Canal 4
unsigned char CH15; // Salida a Canal 5

unsigned char clock_tick; // variable para Timer1

int trama_longitud = 143; //Número que tendrá la trama
int inicio_de_trama = 255; //Número de control de inicio de trama
int trama_array[143]; //Tamaño del array
int nuevo_byte; //byte leido
int indice_lectura = 0; //celdas del array

void setup() {
  Serial.begin(9600); //Velocidad de comunicación

  //Establecer los pines para multiplexores como salida:
  for (int i=0; i<4; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], LOW);
  }
  //Establecer los pines para Z/SIG de multiplexores como salida:
  pinMode(z1Output, OUTPUT);
  
  //Establece el tiempo de interrupción
  attachInterrupt(1, zero_crosss_int, RISING);
  Timer1.initialize(100); // Temporizador de 100 microsegundos para 50Hz o de 83 para 60Hz;
  Timer1.attachInterrupt( timerIsr ); // Establece la interrupción desde la función
  
  CH0=CH1=CH2=CH3=CH4=CH5=CH6=95; // Bombillas en Off al empezar el programa(95 - FULLY OFF ; 5 - FULLY ON)
  CH7=CH8=CH9=CH10=CH11=CH12=95;
  CH13=CH14=CH15=95;

  while (!Serial) {
    ; // Espera la conexión del puerto
  }
}

void timerIsr(){
  clock_tick++;
  
  //Esto le indica al dimmer la intensidad por velocidad de pulso
  
  //Según el canal del Dimmer se selecciona la salida Y0 a Y15(selectMuxPin) del multiplexor
  //que corresponda (z1Output o z2Output)
  
  if (CH0==clock_tick){
    selectMuxPin(0);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH1==clock_tick){
    selectMuxPin(1);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH2==clock_tick){
    selectMuxPin(2);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH3==clock_tick){
    selectMuxPin(3);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH4==clock_tick){
    selectMuxPin(4);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH5==clock_tick){
    selectMuxPin(5);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH6==clock_tick){
    selectMuxPin(6);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH7==clock_tick){
    selectMuxPin(7);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH8==clock_tick){
    selectMuxPin(8);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH9==clock_tick){
    selectMuxPin(9);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH10==clock_tick){
    selectMuxPin(10);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH11==clock_tick){
    selectMuxPin(11);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH12==clock_tick){
    selectMuxPin(12);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH13==clock_tick){
    selectMuxPin(13);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH14==clock_tick){
    selectMuxPin(14);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH15==clock_tick){
    selectMuxPin(15);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
}

void zero_crosss_int(){ // function to be fired at the zero crossing to dim the light
  // Every zerocrossing interrupt: For 50Hz (1/2 Cycle) => 10ms ; For 60Hz (1/2 Cycle) => 8.33ms
  // 10ms=10000us , 8.33ms=8330us
  
  clock_tick=0;
}

void loop(){
  while(Serial.available()==0){ //Mientras no lea dato de Serial, espera
    //esperar
    
  }
  
  nuevo_byte = Serial.read(); //Lee el byte 
  if (nuevo_byte == inicio_de_trama) { //Si el byte es el de control
    indice_lectura = 0; //pone el contador a 0

    if(trama_array[0]>=0){
      CH0=trama_array[0];
      CH0=100-CH0;
      if(CH0<5){CH0=5;}
      if(CH0>95){CH0=95;}
    }
    if(trama_array[1]>=0){
      CH1=trama_array[1];
      CH1=100-CH1;
      if(CH1<5){CH1=5;}
      if(CH1>95){CH1=95;}
    }
    if(trama_array[2]>=0){
      CH2=trama_array[2];
      CH2=100-CH2;
      if(CH2<5){CH2=5;}
      if(CH2>95){CH2=95;}
    }
    if(trama_array[3]>=0){
      CH3=trama_array[3];
      CH3=100-CH3;
      if(CH3<5){CH3=5;}
      if(CH3>95){CH3=95;}
    }
    if(trama_array[4]>=0){
      CH4=trama_array[4];
      CH4=100-CH4;
      if(CH4<5){CH4=5;}
      if(CH4>95){CH4=95;}
    }
    if(trama_array[5]>=0){
      CH5=trama_array[5];
      CH5=100-CH5;
      if(CH5<5){CH5=5;}
      if(CH5>95){CH5=95;}
    }
    if(trama_array[6]>=0){
      CH6=trama_array[6];
      CH6=100-CH6;
      if(CH6<5){CH6=5;}
      if(CH6>95){CH6=95;}
    }
    if(trama_array[7]>=0){
      CH7=trama_array[7];
      CH7=100-CH7;
      if(CH7<5){CH7=5;}
      if(CH7>95){CH7=95;}
    }
    if(trama_array[8]>=0){
      CH8=trama_array[8];
      CH8=100-CH8;
      if(CH8<5){CH8=5;}
      if(CH8>95){CH8=95;}
    }
    if(trama_array[9]>=0){
      CH9=trama_array[9];
      CH9=100-CH9;
      if(CH9<5){CH9=5;}
      if(CH9>95){CH9=95;}
    }
    if(trama_array[10]>=0){
      CH10=trama_array[10];
      CH10=100-CH10;
      if(CH10<5){CH10=5;}
      if(CH10>95){CH10=95;}
    }
    if(trama_array[11]>=0){
      CH11=trama_array[11];
      CH11=100-CH11;
      if(CH11<5){CH11=5;}
      if(CH11>95){CH11=95;}
    }
    if(trama_array[12]>=0){
      CH12=trama_array[12];
      CH12=100-CH12;
      if(CH12<5){CH12=5;}
      if(CH12>95){CH12=95;}
    }
    if(trama_array[13]>=0){
      CH13=trama_array[13];
      CH13=100-CH13;
      if(CH13<5){CH13=5;}
      if(CH13>95){CH13=95;}
    }
    if(trama_array[14]>=0){
      CH14=trama_array[14];
      CH14=100-CH14;
      if(CH14<5){CH14=5;}
      if(CH14>95){CH14=95;}
    }
    if(trama_array[15]>=0){
      CH15=trama_array[15];
      CH15=100-CH15;
      if(CH15<5){CH15=5;}
      if(CH15>95){CH15=95;}
    }
    
  }else{
    //Si no es el byte de control, va almacenando los bytes en el array
    if (indice_lectura < trama_longitud) {
      trama_array[indice_lectura] = nuevo_byte;
      indice_lectura++;
    }else{
      //Error
    }
  }
  
}

void selectMuxPin(byte pin)
{
  if (pin > 15) return; // Si el dato es más alto, sale del ámbito
  for (int i=0; i<4; i++)
  {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
