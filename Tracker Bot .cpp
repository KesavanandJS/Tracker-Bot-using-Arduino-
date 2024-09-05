#define R_SENSOR 4
#define L_SENSOR 2
#define MOTOR_R1 12
#define MOTOR_R2 13
#define MOTOR_L1 7
#define MOTOR_L2 8

void setup() {
  pinMode(R_SENSOR,INPUT);
  pinMode(L_SENSOR,INPUT);

  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    int right = digitalRead(R_SENSOR);
    int left = digitalRead(L_SENSOR);

    if(right == 0 && left == 0) {
      
        moveStraight();
    }
    
    else if(right == 1 && left == 1){
     stopMotion();
    }
    else if(right == 1) 
    {
      moveLeft();
    }
    else if(left == 1) 
    {
      moveRight();
    }
    
}

void moveStraight() {
  Serial.println("Straight");
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
  digitalWrite(MOTOR_L2, HIGH);
  delay(200);
}

void moveLeft() {
  Serial.println("Left");
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_R2, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  delay(200);
}

void moveRight() {
  Serial.println("Right");
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_L1, HIGH);
  digitalWrite(MOTOR_R2, HIGH);
  digitalWrite(MOTOR_L2, LOW);
  delay(200);
}

void stopMotion() {
  Serial.println("Stop");
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_R2, LOW);
  digitalWrite(MOTOR_L2, LOW);
  delay(200);
}