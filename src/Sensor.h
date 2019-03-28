/*
  Sensor.cpp - Library for Sensor Objects and low-key filtering.
  Created by Nicole Meng, Mar 10 2019.
*/
//========================================================
#ifndef Sensor_h
#define Sensor_h
//========================================================
#include "Arduino.h"
#include "Sensor.h"
//========================================================
class Sensor
{
    //======================================================
  public:
    int pin;
    int baseVal = 0;
    int* prevStates = NULL;
    int threshold;
    int noReadings = 0;
    int len;
    //======================================================
  public:
    Sensor(int attachedTo, int prev, int thres);
    /**
     printSensor: <#Description#>
     */
    void printSensor();

    /**
     setBaseVal: <#Description#>
     @param newVal <#newVal description#>
     */
    void setBaseVal(int newVal);

    /**
     isTriggeredValue: <#Description#>
     @param newVal <#newVal description#>
     @return <#return value description#>
     */
    bool isTriggeredValue(int newVal);

    /**
     addReading: <#Description#>
     @param val <#newVal description#>
     @return <#return value description#>
     */
    void addReading(int val);
    
    /**
     getSmoothReading: <#Description#>
     @return <#return value description#>
     */
    int getSmoothReading();

    //======================================================
  private:
    /**
     enqueuePrevStates: <#Description#>
     @param value <#value description#>
     */
    void enqueuePrevStates(int value);
    /**
     dequeuePrevStates: <#Description#>
     @return <#return value description#>
     */
    int dequeuePrevStates();
};

#endif