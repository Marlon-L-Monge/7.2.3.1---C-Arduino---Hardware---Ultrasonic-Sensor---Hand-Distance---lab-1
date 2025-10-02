const int trigPin = 11;
const int echoPin = 12;
int duration;
int distance;
bool object_detected = false;


int ultrasonic_distance()
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

bool if_true(int d)
{
  return d <= 325;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {

  distance = ultrasonic_distance();
  object_detected = if_true(distance);

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(object_detected == false)
  {   
   Serial.println("Waiting To Detect An Object");
  }
  else
  {
    Serial.println("Object Detected & present");
    digitalWrite(LED_BUILTIN, LOW);
  }
    delay(200);
  distance = ultrasonic_distance();

  if(if_true(distance) == false)
  {
    Serial.println("Detetcted object is gone");
    digitalWrite(LED_BUILTIN,LOW);
  }
  delay(200);
}