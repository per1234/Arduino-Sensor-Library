//==============================================================
#include "Arduino.h"
#include "Sensor.h"
//==============================================================

Sensor::Sensor(int attachedTo, int prev, int thres) {
  pin = attachedTo;
  prevStates = new int[prev];
  threshold = thres;
  len = prev;
}

//==============================================================
void Sensor::setBaseVal(int newVal){
  baseVal = newVal;
}

//==============================================================
bool Sensor::isTriggeredValue(int newVal){

  //Serial.println("start triggered");
  // enqueue new value
  enqueuePrevStates(newVal);


  // check how many were triggered from prevStates
  int counter;
  if(noReadings < len){
    counter = noReadings;
  }else{
    counter = len;
  }

  int trigg = 0;
  for(int i = 0; i < counter; i++){
    int diff = prevStates[i]- baseVal;
    if(diff > threshold){
      trigg++;
    }
  }


  // if number triggered larger than not triggered, then accepted
  return(trigg > counter/3);

}

//=============================================================

void Sensor::addReading(int val){
  //Serial.println(val);
  enqueuePrevStates(val);
  /*Serial.print('[');
  for(int i = 0; i < len; i++){
    Serial.print(prevStates[i]);
    Serial.print(" ,");
  }
  Serial.println(']');*/
}

//=============================================================
int Sensor::getSmoothReading(){
  int max = len;
  if(noReadings < len){
    max = noReadings;
  }
  int total = 0;
  for(int i = 0; i < max; i++){
    
    total = (total + prevStates[i]);
  }

  Serial.println(total/max);
  return(total/max);
}


//=============================================================
  void Sensor::enqueuePrevStates(int value){

     int last;
     if(noReadings >= len){
        int discard = dequeuePrevStates();
        last = len-1;
     } else{
        last = noReadings;
     }
     prevStates[last] = value;
     noReadings++;
  }

//==============================================================
int Sensor::dequeuePrevStates(){
   int first = prevStates[0];
   for(int i = 1; i < len; i++){
    prevStates[i-1] = prevStates[i];
   }
   prevStates[len-1] = 0;
   return(first);
}

//==============================================================
void Sensor::printSensor(){
  Serial.print("pin: " + String(pin) + " base: " + String(baseVal) + " readings: " + String(noReadings));
}
