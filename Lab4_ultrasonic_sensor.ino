const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;
bool object_detected = false;
int object_Count = 0;

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
  object_detected = if_true();
 
  if(!object_detected)
  {  
   Serial.println("Waiting To Detect An Object");
  }
   else if (object_detected == true)
   {
     Serial.println("Object Detected & present");
     
     while (object_detected)
     {
       distance = ultrasonic_distance();
       object_detected = if_true();
       delay(100);
     }
     
     Serial.println("Detected object is gone.");
     object_Count++;
     Serial.println(object_Count);
     Serial.println(" Objects detected");
   }
  delay(200);
}
