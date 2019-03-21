# Arduino-Sensor-Library

This library contains the class Sensor, which allows to filter misreadings out.

The Sensor class contains the following public attributes and methods:

| Attributes       |            |   |
| ------------- |-------------| -----|
| pin      | the pin your sensor is attached to | int |
| baseVal    | the base value after calibration      |   int |
| prevStates | all n previous states      |    int* |
| threshold | of when your sensor gets triggered      |    int |
| noReadings | how often your sensor has been read      |    int |


  - constructor
    * Sensor(int attachedTo, int prev, int thres);


| Methods       |  parameters        | type  |
| ------------- |-------------| -----|
| setBaseVal     | int newVal | void |
| isTriggeredValue    | int newVal | bool |
| printSensor |   hhd |    void |


To be continued. 
