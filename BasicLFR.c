/*
The ground pins of the H Bridge are connected together.
While assigning pins 2,3,12,13 check the directions in which the motors are moving and then assign the pins accordingly.
*/

int x;
int leftsensorValue = 0;
int rightsensorValue = 0;
int leftdcforward = 13;
int leftdcbackward = 12;
int rightdcforward = 3;
int rightdcbackward = 2;


void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  
  Serial.begin(9600);

}

void loop()
{
  leftsensorValue = analogRead(A0);
  rightsensorValue = analogRead(A1);
  
  if(leftsensorValue >x && rightsensorValue >x) // Move Forward on line
	{
    // For finding X, you need to calibrate the sensors accordingly as the readings by the IR Sensors are not always accurate.
    // For black regions, the IR sensors will show readings near to 0,as some light can get reflected if the surface is shiny. 
		digitalWrite(leftdcforward, HIGH);
		digitalWrite(leftdcbackward, LOW);
		digitalWrite(rightdcforward, HIGH);
		digitalWrite(rightdcbackward, LOW);
	}
  else if(leftsensorValue >x && rightsensorValue <=x) // Turn in a Clockwise manner by rotationg Left side motor in forward and right one in backward direction
	{
		digitalWrite(leftdcforward, HIGH);
		digitalWrite(leftdcbackward, LOW);
		digitalWrite(rightdcforward, LOW);
		digitalWrite(rightdcbackward, HIGH);
	}
  else if(leftsensorValue <=x && rightsensorValue >x) // Turn in an Anticlockwise manner by rotating Right side motor in forward and left one in backward direction
	{
		digitalWrite(leftdcforward, LOW);
		digitalWrite(leftdcbackward, HIGH);
		digitalWrite(rightdcforward, HIGH);
		digitalWrite(rightdcbackward, LOW);
	}

}
