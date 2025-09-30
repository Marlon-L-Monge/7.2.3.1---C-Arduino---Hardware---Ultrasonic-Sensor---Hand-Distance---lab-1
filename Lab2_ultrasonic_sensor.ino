const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;

long ultrasonic_distance()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2 ;
  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {

  distance = ultrasonic_distance();

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance > 4)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("STOP!!");
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  } 
}