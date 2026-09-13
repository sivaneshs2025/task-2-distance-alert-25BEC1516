
const int trigPin = 5;  //GPIO 5    (FOR SENSOR)
const int echoPin = 18; //GPIO 18      (FOR SENSOR)
const int alertPin = 2;  //GPIO 2 (LED OR A BUZZER)


const int thresholdDistance = 20; //threshold in centimeters.

void setup() {
  
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertPin, OUTPUT);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 0 && distance <= thresholdDistance) {
    digitalWrite(alertPin, HIGH);
  } else {
    digitalWrite(alertPin, LOW);   
  }
  delay(200);
}

