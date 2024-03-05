const int trigPin = 9;
const int echoPin = 10;

const int redPin = 5;
const int greenPin = 6;
const int yellowPin = 7;



float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if( distance < 20 ){
    digitalWrite(redPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(greenPin, LOW);
    delayMicroseconds(2);
    digitalWrite(yellowPin, LOW);
    delayMicroseconds(2);
    
  }
  else if(distance >= 20 and distance < 40 ){
    digitalWrite(redPin, LOW);
    delayMicroseconds(2);
    digitalWrite(greenPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(yellowPin, LOW);
    delayMicroseconds(2);
   
  }
  else {
    digitalWrite(redPin, LOW);
    delayMicroseconds(2);
    digitalWrite(greenPin, LOW);
    delayMicroseconds(2);
    digitalWrite(yellowPin, HIGH);
    delayMicroseconds(2);
    
  }
  
  
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
