#include <SparkFun_TB6612.h> //Motor Surucu Kutuphanesi


//////////////////////////// 
// Motor Surucu Pinleri
///////////////////////////
 
#define AIN1 5
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 3
#define PWMB 9
#define STBY 6
#define LOWSPEED 120
#define MIDSPEED 110
#define MAXSPEED 250
#define DELAY 300
#define BACKSPIN 500

const int offsetA = 1;
const int offsetB = 1;

///////////////////////////
// Sag ve Sol Motorlar 
//////////////////////////

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY); //sag motor
Motor motor2 = Motor(BIN2, BIN1, PWMB, offsetB, STBY);  //sol motor


/////////////////////////
//Sensorler
////////////////////////


//int cisimSen;

#define lineR_pin 6   //pinler duzenlenecek
#define lineL_pin 5   
//#define cisimSen_pin 6
int LineL;  //Sol line sensoru
int LineR;  //Sag line sensoru
 
void setup(){

  pinMode(lineR_pin, INPUT);         //Line sensor inputlari
  pinMode(lineL_pin, INPUT);
  //Serial.begin(9600);

}


void loop(){

  sensors();

  if(LineR<300 && LineL<300){
    back(motor1,motor2,LOWSPEED); //Once geri geldi
    delay(DELAY);                   //100ms
    brake(motor1,motor2);         //Sonra durdu
    
    motor1.drive(LOWSPEED);   //Sonra geriye dondu
    motor2.drive(-LOWSPEED); 
    delay(BACKSPIN);
    brake(motor1,motor2);
  
  
  }

  else if(LineR<300&&LineL>300){
    back(motor1,motor2,LOWSPEED); //Once geri geldi
    delay(DELAY);
    left(motor1,motor2,LOWSPEED);
    delay(DELAY);
    brake(motor1,motor2);
  }
  
  else if(LineL<300&&LineR>300){
    back(motor1,motor2,LOWSPEED); //Once geri geldi
    delay(DELAY);
    right(motor1,motor2,LOWSPEED);
    delay(DELAY);
    brake(motor1,motor2);
  }
  
  else{
  
    forward(motor1,motor2,LOWSPEED);
    delay(100);
    brake(motor1,motor2); 
      
  }
 // delay(100);
}

void sensors(){

  LineR = analogRead(lineR_pin);
  LineL = analogRead(lineL_pin);

  Serial.print("\nSol =");
  Serial.print(LineL);
  
  Serial.print("\nSag =\n");
  Serial.print(LineR);

 
}

