const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(HIGH, LOW);
  distance = (duration * 0.034) / 2 ;

  Serial.println("Distance: ");
  Serial.println(distance);
}