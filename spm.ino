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

const float stepsPerRevolution = 200;
int microstepSetting = 8;
static int inputs[3];
int inputString = -1;


AccelStepper stepperA(AccelStepper::DRIVER, STEP_PINA, DIR_PINA);
AccelStepper stepperB(AccelStepper::DRIVER, STEP_PINB, DIR_PINB);
AccelStepper stepperC(AccelStepper::DRIVER, STEP_PINC, DIR_PINC);

void setup() {
  Serial.begin(115200);
  // Serial.setTimeout(10);

  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);

  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, HIGH);

  int maxSpeed = 20000;
  int accel = 7000;
  // float desiredRPM = 50;
  // float MaxRPM = 150;

  // float speedStepsPerSec = (microstepSetting * stepsPerRevolution * desiredRPM) / 60.0;
  // float Max_Speed_StepsPerSec = microstepSetting * stepsPerRevolution * MaxRPM / 60;
  stepperA.setMaxSpeed(maxSpeed);
  stepperA.setAcceleration(accel);
  stepperB.setMaxSpeed(maxSpeed);
  stepperB.setAcceleration(accel);
  stepperC.setMaxSpeed(maxSpeed);
  stepperC.setAcceleration(accel);
  // stepper.setAcceleration(50.0);
  
}

void loop() {
  if(Serial.available() > 0) {
    receivePositions();
    stepperA.moveTo(inputs[0]);
    stepperB.moveTo(inputs[1]);
    stepperC.moveTo(inputs[2]);
  }
  // if(Serial.available() > 0) {
  //   //receivePositions();
  //   int count = 0;
  //   int spaceIndex;
  //   inputString = Serial.read();
  //   Serial.println(inputString);
    
  //   // if(count == 2) {
  //   //   count = 0;
  //   //   stepperA.moveTo(inputs[0]);
  //   //   stepperB.moveTo(inputs[1]);
  //   //   stepperC.moveTo(inputs[2]);
      
      
  //   // }
  //   // inputs[count] = inputString;
  //   // count++;
    
  // }
  // else {
  //   Serial.println(inputString);
  // }
  // Serial.print(inputs[0]);
  // Serial.print(" ");
  // Serial.print(inputs[1]);
  // Serial.print(" ");
  // Serial.println(inputs[2]);
  stepperA.run();
  stepperB.run();
  stepperC.run();


  // else if(Serial) {
  //   Serial.println( (String) inputs[0] + " " + (String) inputs[1] + " " + (String) inputs[2]);
  //   delay(500);
  // }
  
}
// stepperA.moveTo(inputs[0]);
//       stepperB.moveTo(inputs[1]);
//       stepperC.moveTo(inputs[2]);
//       dataIndex = 0;
//       Serial.print(inputs[0]);
//       Serial.print(" ");
//       Serial.print(inputs[1]);
//       Serial.print(" ");
//       Serial.println(inputs[2]);

static void receivePositions() {
  int count = 0;
  int spaceIndex;
  String inputString = Serial.readStringUntil('\r');

  // for(int i = 0; i < 3; i++) {
    
  //   if(inputString.indexOf(" ") == -1) {
  //     inputs[2] = inputString.toInt();
  //   }
  //   else {
  //     inputs[i] = inputString.substring(0, inputString.indexOf(" ")+1).toInt();
  //     inputString = inputString.substring(inputString.indexOf(" "));
  //   }
  // }
  inputs[0] = inputString.substring(0, inputString.indexOf(" ")).toInt();
  inputString = inputString.substring(inputString.indexOf(" ")+1);
  while(inputString.substring(0, 1).equals(" ")) {
    inputString = inputString.substring(1);
  }
  inputs[1] = inputString.substring(0, inputString.indexOf(" ")).toInt();
  inputString = inputString.substring(inputString.indexOf(" ")+1);
  inputs[2] = inputString.toInt();
  
  // Serial.print(inputs[0]);
  // Serial.print(inputs[1]);
  // Serial.println(inputs[2]);
  
}
