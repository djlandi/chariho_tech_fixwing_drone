#include<Servo.h> 

Servo esc;//Declare the ESC as a Servo Object
Servo elevator;
Servo rudder;

int x_axis;
int elevator_val;
int y_axis;
int rudder_val;
int input;

void setup() {
  esc.attach(10);           //Attach the ESC to Digital Pin 10
  Serial.begin(9600);      //Begin Reading/Open Serial 
  Serial.begin (9600) ;
  pinMode(A1,INPUT);
  elevator.attach(37);
  pinMode(A2,INPUT);
  rudder.attach(36);
  esc.write(1023);
  delay(10000);
  esc.write(508);
}

void loop() {
  
  x_axiss();
  y_axiss();
  
  input=analogRead(A0);                      //Value of input is analog input on pin A0
  Serial.print("Original Input Value:");      //Serial print the original input value
  Serial.print(input);
  Serial.print(" | ");
  delay(1);
  
  input=map(analogRead(A0), 0, 1023, 0, 180); //Map the input values from the joystick on analog pin 0 to  correspond to max and min values for the servo output: 180 and 0
  Serial.print("Mapped Input Value:");
  Serial.print(input);                      //Serial print the mapped input value
  Serial.print("\n");
  delay(1);                                  //Delay determines your resolution/smoothness and responsiveness of Motor to the movement of Potwntiometer/Joystick.
  esc.write(input);
}

void x_axiss(){
  x_axis=analogRead(A1);
  elevator_val=map(x_axis,0,1023,0,180);
  elevator.write(elevator_val);
}

void y_axiss(){
  y_axis=analogRead(A2);
  rudder_val=map(y_axis,0,1023,0,180);
  rudder.write(rudder_val);
}
