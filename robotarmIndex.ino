/** Arduino code used for Robot Arm competition in Science Olympiad
* __________________________Notes _________________________________
* Use 5V for potentiometers
* Use 9V ideally for Servos/Motors
* For the breadboard, 1 side for 5V and the other for 9V, both grounds go into the 9V side
* When looking at potentiometer from the front (turn wheel facing towards you)
  left plug is positive(+), middle plug is value(a), and right plug is negative/ground(-)
* !!! Note, too much voltage can fry the breadboard or melt the wire !!!
* Plug Analog into the potentiometer, and use the corresponding potPin value for output to Motors
* For type of potentiometer, the Bs are better than the As due to free space on the As
*/

// imported library for the servo/motors
#include <Servo.h>

// servo can be used for whichever motor, the servos below were used for mine
Servo servo1; // base rotator servo
Servo servo2; // left shoulder veritcal servo
Servo servo3; // right shoulder vertical servo
Servo servo4; // elbow vertical servo
Servo servo5; // wrist vertical servo
Servo servo6; // wrist rotator servo
Servo servo7; // hand servo

int potPin1 = 0;
int potPin2 = 1;
int potPin3 = 2;    // select the input pin for the potentiometer
int potPin4 = 3;
int potPin5 = 4;
int potPin6 = 5;
int potPin7 = 6;

int valA, oldValA = 0;       // variable to store the value coming from the sensor
int valB, oldValB = 0;
int valC, oldValC = 0;
int valD, oldValD = 0;
int valE, oldValE = 0;
int valF, oldValF = 0;
int valG, oldValG = 0;

// initial function to initialize values
void setup() {
  // setup the pin the servo data signal is on to output to servo/motor
  // value corresponds to the pin on the other side of the Analog to output
  servo1.attach(2);           
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);   
  servo7.attach(8);
}
// loops forever until reset button is pressed or unplugged from power source
void loop() {
  /* HOW THE BELOW CODE WORKS!!
  * val = analogRead(#) <-- value is read from potentiometer based off A# and stored into the val variable
  * val = map(val, 0, 1023, 0, 180) <-- new value is stored based off originally written value from potentiometer
    that returns a value of 0-1023, and is converted to a 0-180 degree scale, can be converted to a 360 degree value.
  * servo#.write(va) <-- value is written to pin based off number and output to the servo/motor on the previously mentioned scale.
  */
  
  valA = analogRead(potPin1);
  valA = map(valA, 0, 1023, 0, 180);
  servo1.write(valA);

  valB = analogRead(potPin2);
  valB = map(valB, 0, 1023, 0, 180);
  servo2.write(valB);
  
  valC = analogRead(potPin3);
  valC = map(valC, 0, 1023, 0, 180);
  servo3.write(valC);
  
  valD = analogRead(potPin4);
  valD = map(valD, 0, 1023, 0, 180);
  servo4.write(valD);

  valE = analogRead(potPin5);
  valE = map(valE, 0, 1023, 0, 180);
  servo5.write(valE);
  
  valF = analogRead(potPin6);
  valF = map(valF, 0, 1023, 0, 180);
  servo6.write(valF);
  
  valG = analogRead(potPin7);
  valG = map(valG, 0, 1023, 0, 180);
  servo7.write(valG);
  
  delay(15);                        // delay of 15 ms for the servo to catch up

  // used to check for output based off potentiometer
  // Serial.println("Servo 1: " + String(valA) + ", Servo 2: " + String(valB) + ", Servo 3: " + String(valC) + ", Servo 4: " + String(valD) + ", Servo 5: " + String(valE));
}
