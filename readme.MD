# contents

* models contain the blender and STL files
* StepperVectorCRT is the firmware for the Arduino Nano
* Pattern is the firmware for the ESP32 drawing the [Lissajous](https://en.wikipedia.org/wiki/Lissajous_curve) pattern
* OsciVector is the ESP32 firmware providing a websocket server that receives line segments to draw
  * Line segments are are binary in 8bit x,y pairs. The line is continous until 255 in x which will start a new line.
