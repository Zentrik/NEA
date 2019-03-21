// Motor 1 pins
int enA = 16; //D0
int a0 = 5;  //D1  
int a1 = 4;  //D2
// Motor 2 pins
int enB = 0; //D3
int a2 = 2;  //D4  
int a3 = 14;  //D5
void motorsOff() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(a0, LOW); 
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
}
void lock() {
  analogWrite(enA, 1023); //set motor speed
  analogWrite(enB, 1023);
  if (Locked) {
      digitalWrite(a0, HIGH); //clockwise spin
      digitalWrite(a1, LOW);
      delay(3000);
      digitalWrite(a2, HIGH);
      digitalWrite(a3, LOW);    
    } else {
      digitalWrite(a0, LOW); //counter clockwise spin
      digitalWrite(a1, HIGH);
      digitalWrite(a2, LOW);
      digitalWrite(a3, HIGH);
    }
  delay(500);
  motorsOff();
}
void setup() {
  pinMode(enA, OUTPUT); // set all motor control pins as outputs
  pinMode(a0, OUTPUT);     
  pinMode(a1, OUTPUT);
  pinMode(enB, OUTPUT); 
  pinMode(a2, OUTPUT);     
  pinMode(a3, OUTPUT);
  motorsOff();
}
void loop() {
  lock()
}
