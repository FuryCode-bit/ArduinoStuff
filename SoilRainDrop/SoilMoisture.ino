#define ANALOG_SOLO 34 // ESP32 pin GPIO34 (ADC0) that connects to AOUT pin of moisture sensor
#define THRESHOLD 2800

#define A0_PIN 27  // ESP32's pin GPIO27 that provides the power to the rain sensor
#define D0_PIN 13     // ESP32's pin GPIO13 connected to DO pin of the rain sensor

void setup() {
  Serial.begin(9600);
  
  // initialize the Arduino's pin as an input
  pinMode(A0_PIN, OUTPUT);  
  pinMode(D0_PIN, INPUT);

}

void loop() {
  digitalWrite(A0_PIN, HIGH);  
  delay(10);

  int rain_state = digitalRead(D0_PIN);

  digitalWrite(A0_PIN, LOW);

  int value = analogRead(ANALOG_SOLO);

  if (value > THRESHOLD)
    Serial.print("The soil is DRY (");
  else
    Serial.print("The soil is WET (");

  Serial.print(value);
  Serial.println(")");


  int rainAnalogVal = analogRead(A0_PIN);

  if (rain_state == HIGH)
    Serial.print("The rain is NOT detected (");
  else
    Serial.print("The rain is detected (");

  Serial.print(rainAnalogVal);
  Serial.println(")");

  // pause for 1 sec to avoid reading sensors frequently to prolong the sensor lifetime
  delay(1000);
}