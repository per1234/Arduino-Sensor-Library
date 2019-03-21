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
    int *prevStates;
    int threshold;
    int noReadings = 0;
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
