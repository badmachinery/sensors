#include <Wire.h>

int Q_TRIG = 7;         
int E_TRIG = 8;
int L_TRIG = 2;         
int R_TRIG = 4;

int Q_PIN = A0;
int E_PIN = A1;
int L_PIN = A2;
int R_PIN = A3;


int Q_value = -1;
int E_value = -1;
int L_value = -1;
int R_value = -1;


void prepareSensor(int sensorPin){
  pinMode(sensorPin,OUTPUT);        
  digitalWrite(sensorPin,HIGH);                 
}

void setStateUndoIn(int sensorPin){
  digitalWrite(sensorPin, LOW);
  digitalWrite(sensorPin, HIGH);  
}

void readData(){ 
  setStateUndoIn(Q_TRIG);                
  Q_value = analogRead(Q_PIN); 
  
  setStateUndoIn(E_TRIG);                 
  E_value = analogRead(E_PIN); 
  
  setStateUndoIn(L_TRIG);                 
  L_value = analogRead(L_PIN); 
  
  setStateUndoIn(R_TRIG);                 
  R_value = analogRead(R_PIN); 
  
  Q_value = Q_value <=10 ? -1 : Q_value * 0.718;
  E_value = E_value <=10 ? -1 : E_value * 0.718;
  L_value = L_value <=10 ? -1 : L_value * 0.718;
  R_value = R_value <=10 ? -1 : R_value * 0.718;
}

void sendSonarData(){
  Serial.print("Q");
  Serial.println(Q_value);

  Serial.print("E");
  Serial.println(E_value);
  
  Serial.print("L");
  Serial.println(L_value);
  
  Serial.print("R");
  Serial.println(R_value);
}

void setup(){
  Serial.begin(115200);                  
  Wire.begin();
  prepareSensor(Q_TRIG);
  prepareSensor(E_TRIG);                    
  prepareSensor(L_TRIG);
  prepareSensor(R_TRIG);
  delay(13);
 }
 
void loop(){
  readData();
  sendSonarData();
  delay(13);
} 
