# Sound Reactive Lights Tutorial

**Materials List**
- Arduino – I'm using the Limited Edition Arduino Uno Mini
- Microphone Sensor
- RGB LED Strip (WS2812B)

## **1. Wire Diagram**

| Mic Sensor  | Arduino  | LED Strip |
| ---------|-------------| ----------|
| +        | 5V          | +         |
| - (GND)  | GND         | - (GND)   |
| A0       | A0          |           |
|          |   5 (digital pin)    | DIN       |

## **2. Install FastLED Library**
This code uses the FastLED library to control LED lights. The library can be installed from the Arduino IDE by going to **Sketch > Include Library > Manage Libraries.** Then search for **FastLED by Daniel Garcia** and click Install.

## **3. Upload Code**
Open the ***sound-reactive-lights.ino*** file and upload the code onto the Arduino board!
