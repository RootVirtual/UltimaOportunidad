// ARDUINO  -  2 MULTIPLEXORES  -  2 DIMMERS / 6CH
//
// Conxión de 2 Dimmer a través de 2 multiplexores:
// Mismo esquema para 9 multiplexores y 36 Dimmers.
//
//  Arduino       Multiplex1   Multiplex2     Dimmer1    Dimmer2
//     |              |             |            |          |
//    GND ------- GND y EN ---- GND y EN ------ GND ------ GND
//    5V ----------- VCC -------- VCC --------- VCC ------ VCC
//    8 ------------ S0 ---------- S0            |          |
//    9 ------------ S1 ---------- S1            |          |
//    10 ----------- S2 ---------- S2            |          |
//    11 ----------- S3 ---------- S3            |          |
//    5 ------------ SIG            |            |          |
//    6 -------------------------- SIG           |          |
//    3 --------------------------------------- SYNC ---- SYNC
//    
//    
//    Multiplex1  Dimmer1          Multiplex2   Dimmer2
//        |          |                  |          |
//        Y0 ------ CH1                 Y0 ------ CH1
//        Y1 ------ CH2                 Y1 ------ CH2   
//        Y2 ------ CH3                 Y2 ------ CH3
//    
//    

#include <TimerOne.h>    // Librería para interrupción

const int selectPins[4] = {8, 9, 10, 11}; // Pines de Arduino para todos los multiplexores (compartidos)
const int z1Output = 22; // Conexión a Z/SIG de Multiplexor1
const int z2Output = 23; // Conexión a Z/SIG de Multiplexor2
const int z3Output = 24; // Conexión a Z/SIG de Multiplexor3
const int z4Output = 25;
const int z5Output = 26;
const int z6Output = 27;
const int z7Output = 28;
const int z8Output = 29;
const int z9Output = 30;


int numero_canales=143; //Número de canales/Dimmers
unsigned char CH[143]; //Variable para cada Canal

unsigned char clock_tick; // variable para Timer1

int trama_longitud = 143; //Número que tendrá la trama
int inicio_de_trama = 255; //Número de control de inicio de trama
int trama_array[143]; //Tamaño del array
int nuevo_byte; //byte leido
int indice_lectura = 0; //celdas del array

void setup() {
  Serial.begin(9600); //Velocidad de comunicación

  //Establecer los pines para multiplexores como salida:
  for (int i=0; i<4; i++){
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], LOW);
  }
  //Establecer los pines para Z/SIG de cada multiplexor como salida:
  pinMode(z1Output, OUTPUT);
  pinMode(z2Output, OUTPUT);
  pinMode(z3Output, OUTPUT);
  pinMode(z4Output, OUTPUT);
  pinMode(z5Output, OUTPUT);
  pinMode(z6Output, OUTPUT);
  pinMode(z7Output, OUTPUT);
  pinMode(z8Output, OUTPUT);
  pinMode(z9Output, OUTPUT);
  
  
  //Establece el tiempo de interrupción
  attachInterrupt(1, zero_crosss_int, RISING);
  Timer1.initialize(1500); // Temporizador de 100 microsegundos para 50Hz o de 83 para 60Hz;
  Timer1.attachInterrupt( timerIsr ); // Establece la interrupción desde la función
  
  // Bombillas en Off al empezar el programa(95 - FULLY OFF ; 5 - FULLY ON)
  for(int i=0;i<numero_canales;i++){
    CH[i]=5;
  }
  while (!Serial) {
    ; // Espera la conexión del puerto
  }
}

void timerIsr(){
  clock_tick++;
  
  //Esto le indica al dimmer la intensidad por velocidad de pulso
  
  //Según el canal del Dimmer se selecciona la salida Y0 a Y15(selectMuxPin) del multiplexor
  //que corresponda (z1Output, z2Output, z3Output...)

  //------------------------------------------------------------Z1
  if (CH[0]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[1]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[2]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[3]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[4]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[5]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[6]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[7]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[8]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[9]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[10]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[11]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[12]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[13]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[14]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  if (CH[15]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z1Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z1Output, LOW); // triac Off
  }
  

  //------------------------------------------------------------Z2
  if (CH[16]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[17]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[18]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[19]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[20]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[21]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[22]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[23]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[24]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[25]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[26]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[27]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[28]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[29]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[30]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[31]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z2Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }


  
  //------------------------------------------------------------Z3
  if (CH[32]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[33]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[34]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[35]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[36]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[37]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[38]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[39]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[40]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[41]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[42]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[43]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[44]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[45]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z2Output, LOW); // triac Off
  }
  if (CH[46]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }
  if (CH[47]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z3Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z3Output, LOW); // triac Off
  }


  //------------------------------------------------------------Z4
  if (CH[48]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[49]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[50]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[51]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[52]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[53]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[54]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[55]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[56]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[57]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[58]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[59]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[60]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[61]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[62]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }
  if (CH[63]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z4Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z4Output, LOW); // triac Off
  }

  //------------------------------------------------------------Z5
  if (CH[64]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[65]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[66]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[67]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[68]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[69]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[70]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[71]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[72]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[73]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[74]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[75]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[76]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[77]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[78]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }
  if (CH[79]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z5Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z5Output, LOW); // triac Off
  }

  //------------------------------------------------------------Z6
  if (CH[80]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[81]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[82]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[83]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[84]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[85]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[86]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[87]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[88]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[89]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[90]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[91]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[92]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[93]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[94]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }
  if (CH[95]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z6Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z6Output, LOW); // triac Off
  }

  //------------------------------------------------------------Z7
  if (CH[96]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[97]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[98]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[99]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[100]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[101]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[102]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[103]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[104]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[105]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[106]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[107]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[108]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[109]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[110]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }
  if (CH[111]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z7Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z7Output, LOW); // triac Off
  }


  //------------------------------------------------------------Z8
  if (CH[112]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[113]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[114]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[115]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[116]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[117]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[118]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[119]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[120]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[121]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[122]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[123]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[124]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[125]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[126]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }
  if (CH[127]==clock_tick){
    selectMuxPin(15);
    digitalWrite(z8Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z8Output, LOW); // triac Off
  }

  //------------------------------------------------------------Z9
  if (CH[128]==clock_tick){
    selectMuxPin(0);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[129]==clock_tick){
    selectMuxPin(1);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[130]==clock_tick){
    selectMuxPin(2);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[131]==clock_tick){
    selectMuxPin(3);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[132]==clock_tick){
    selectMuxPin(4);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[133]==clock_tick){
    selectMuxPin(5);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[134]==clock_tick){
    selectMuxPin(6);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[135]==clock_tick){
    selectMuxPin(7);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[136]==clock_tick){
    selectMuxPin(8);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[137]==clock_tick){
    selectMuxPin(9);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[138]==clock_tick){
    selectMuxPin(10);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[139]==clock_tick){
    selectMuxPin(11);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[140]==clock_tick){
    selectMuxPin(12);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[141]==clock_tick){
    selectMuxPin(13);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
  }
  if (CH[142]==clock_tick){
    selectMuxPin(14);
    digitalWrite(z9Output, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(z9Output, LOW); // triac Off
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

    //------------------------------------ Z1
    for(int j=0;j<numero_canales;j++){
      if(trama_array[j]>=0){
      CH[j]=trama_array[j];
      }
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
