
//UltraSonic
int distanceLimit = 150;
int cm = 0;
int led_pin = 4;
int motionPin= 7;

int LightPin= A0;

//buzzer
int buzzer_pin = 10;
int period = 400;
unsigned long time_now = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
} 

void setup(){
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(motionPin,INPUT_PULLUP);
  
}

void loop(){
    // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.print("Distance: ");
  Serial.println(cm);
  int LDRval= analogRead(A0);
  Serial.print("Light: ");
  Serial.println(LDRval);
  // Motions sensor detecs someting
  
  if (digitalRead(motionPin) == HIGH){
    digitalWrite(led_pin,HIGH);
    tone(buzzer_pin,440,500);
    delay(400);
    tone(buzzer_pin,240,500);
    delay(400);
  }
  
  // Detects Light
  
  else if (LDRval>600){
    digitalWrite(led_pin,HIGH);
    tone(buzzer_pin,440,500);
    // Delay for 400ms
    delay(400);
    tone(buzzer_pin,240,500);
    // Delay for 400ms
    delay(400);
  }else{
    digitalWrite(led_pin,LOW);
    digitalWrite(buzzer_pin,LOW);
  }
  
  // Detect somethin and turn on LEDs
  // Skip Error

  if (cm < distanceLimit && cm != 0 ){
    digitalWrite(led_pin,HIGH);
  }
  if (cm < distanceLimit && cm != 0 ){ 
   tone(buzzer_pin,440,500);
    // Delay for 400ms
    delay(400);
    tone(buzzer_pin,240,500);
    // Delay for 400ms
    delay(400);  
  }
   
  
}
