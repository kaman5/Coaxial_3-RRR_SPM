#include <AccelStepper.h>
//#include <FastAccelStepper.h>

#define STEP_PINA 18
#define DIR_PINA 19

#define STEP_PINB 22
#define DIR_PINB 23

#define STEP_PINC 15
#define DIR_PINC 4

#define MS1_PIN 21
#define MS2_PIN 14

// const float stepsPerRevolution = 200;
// int microstepSetting = 8;
// static int inputs[3];
// int inputString = -1;
// int* velA = new int[2001];
// int* velB = new int[2001];
// int* velC = new int[2001];
// unsigned long lastUpdate = micros();  // keep track of last velocity update
// int ind = 0;
// int c = 0;
// int dt_us = 100000;


AccelStepper stepperA(AccelStepper::DRIVER, STEP_PINA, DIR_PINA);
// AccelStepper stepperB(AccelStepper::DRIVER, STEP_PINB, DIR_PINB);
// AccelStepper stepperC(AccelStepper::DRIVER, STEP_PINC, DIR_PINC);

void setup() {
  Serial.begin(115200);
  // // Serial.setTimeout(10);

  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);

  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, HIGH);  
  stepperA.setSpeed(200);
  stepperA.setMaxSpeed(2000);
  stepperA.setAcceleration(1000);
  // stepperB.setSpeed(200);
  // stepperC.setSpeed(500);
}

void loop() {
  if(Serial.available()) {
    String ink = Serial.readString();
    stepperA.move(ink.toInt());
  }
  stepperA.run();
  // stepperB.runSpeed();
  // stepperC.runSpeed();
  // load in trajectory
  // String inS = "";
  // while(c < 2000) {
  //   if(Serial.available() > 0) {
  //     inS = Serial.readStringUntil('\r');
      
  //     receivePositions(inS);
  //     velA[c] = inputs[0];
  //     velB[c] = inputs[1];
  //     velC[c] = inputs[2];
  //     Serial.println(String(velA[c]));
  //     c++;
      
  //   }
  // }
  // if (ind < 2001 && micros() - lastUpdate >= dt_us) {
  //   stepperA.setSpeed(velA[ind]);
  //   stepperB.setSpeed(velB[ind]);
  //   stepperC.setSpeed(velC[ind]);
  //   Serial.println(ind);
  //   // Serial.print(velA[ind]);
  //   // Serial.print(velB[ind]);
  //   // Serial.println(velC[ind]);

  //   lastUpdate += dt_us;  // schedule next update
  //   ind++;              // move to next point in trajectory
  // }

  //   // Continuously call runSpeed() to generate steps
  // stepperA.runSpeed();
  // stepperB.runSpeed();
  // stepperC.runSpeed();

  
}


// static void receivePositions(String inputString) {
//   int count = 0;
//   int spaceIndex;
//   // String inputString = Serial.readStringUntil('\r');

//   inputs[0] = inputString.substring(0, inputString.indexOf(" ")).toInt();
//   inputString = inputString.substring(inputString.indexOf(" ")+1);
//   while(inputString.substring(0, 1).equals(" ")) {
//     inputString = inputString.substring(1);
//   }
//   inputs[1] = inputString.substring(0, inputString.indexOf(" ")).toInt();
//   inputString = inputString.substring(inputString.indexOf(" ")+1);
//   inputs[2] = inputString.toInt();
  
//   // Serial.print(inputs[0]);
//   // Serial.print(inputs[1]);
//   // Serial.println(inputs[2]);
  
// }
