const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;
bool object_detected = false;


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

bool if_true()
{
  if (distance > 330)
  {
    return false;
  }
  else
  {
    return true;
  }
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
  object_detected = if_true();
  
  if(object_detected == false)
  {   
   Serial.println("Waiting To Detect An Object");
   distance = ultrasonic_distance();
   object_detected = if_true();
  }
   else if (object_detected == true)
   {
     Serial.println("Object Detected & present");
     distance = ultrasonic_distance();
     object_detected = if_true();
     if(object_detected == false)
     {
      Serial.println("Detected object is gone");
      distance = ultrasonic_distance();
      object_detected = if_true();
     }
   }
  delay(200);
}