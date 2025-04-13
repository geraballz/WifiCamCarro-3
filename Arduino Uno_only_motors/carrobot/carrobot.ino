     #include <AFMotor.h>
#define light_FR  14    //LED Front Right   pin A0 for Arduino Uno
#define light_FL  15    //LED Front Left    pin A1 for Arduino Uno
#define light_BR  16    //LED Back Right    pin A2 for Arduino Uno
#define light_BL  17    //LED Back Left     pin A3 for Arduino Uno
#define horn_Buzz 18    //Horn Buzzer       pin A4 for Arduino Uno

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int speedCar = 255; // Initial car speed set 0 to 255.
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;

void setup()
{
    pinMode(light_FR, OUTPUT);
    pinMode(light_FL, OUTPUT);
    pinMode(light_BR, OUTPUT);
    pinMode(light_BL, OUTPUT);
    pinMode(horn_Buzz, OUTPUT);

    Serial.begin(115200);
    Stop();
}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
    motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void left()
{
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar - 30);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar - 30);
}
void right()
{
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(speedCar - 30);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar - 30);
  motor4.setSpeed(speedCar);
}

void forwardRight()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
}

void forwardLeft()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void backwardRight()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);
     motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
}
void backwardLeft()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop(){
  while(Serial.available()) {
        char command = Serial.read();
        //Stop();       //Initialize with motors stopped.
        if (lightFront) {digitalWrite(light_FR, HIGH); digitalWrite(light_FL, HIGH);}
        if (!lightFront) {digitalWrite(light_FR, LOW); digitalWrite(light_FL, LOW);}
        if (lightBack) {digitalWrite(light_BR, HIGH); digitalWrite(light_BL, HIGH);}
        if (!lightBack) {digitalWrite(light_BR, LOW); digitalWrite(light_BL, LOW);}
        if (horn) {digitalWrite(horn_Buzz, HIGH);}
        if (!horn) {digitalWrite(horn_Buzz, LOW);}
        switch (command) {
            case 'F':
              forward();
              delay(100);
              Stop();
              break;
            case 'B':
              backward();
              delay(100);
              Stop();
              break;
            case 'L':
              left();
              delay(100);
              Stop();
              break;
            case 'R':
              right();
              delay(100);
              Stop();
              break;
            
            case 'S':Stop();break;
            case '0':speedCar = 125;break;
            case '1':speedCar = 139;break;
            case '2':speedCar = 153;break;
            case '3':speedCar = 167;break;
            case '4':speedCar = 181;break;
            case '5':speedCar = 195;break;
            case '6':speedCar = 209;break;
            case '7':speedCar = 223;break;
            case '8':speedCar = 237;break;
            case '9':speedCar = 245;break;
            case 'q':speedCar = 255;break;
            case 'W':lightFront = true;break;
            case 'w':lightFront = false;break;
            case 'U':lightBack = true;break;
            case 'u':lightBack = false;break;
            case 'V':horn = true;break;
            case 'v':horn = false;break;
            default: Stop();
           }
  }
}
