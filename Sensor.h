/*
  Sensor.cpp - Library for Sensor Objects and low-key filtering.
  Created by Nicole Meng, Mar 10 2019.
*/

#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
#include "Sensor.h"

class Sensor {

   public:
      // attributes
      int pin;
      int baseVal = 0;
      int* prevStates;
      int threshold;
      int noReadings = 0;

      Sensor(int attachedTo, int prev, int thres);

      // methods
      void setBaseVal(int newVal);
      bool isTriggeredValue(int newVal);
      void printSensor();

    private:
      void enqueuePrevStates(int value);
      int dequeuePrevStates();
};


#endif
