int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};
int numberOfLeds = 7;

int trigPin = 10;
int echoPin = 11;
int travelTime;
int distance;

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  sendSoundWave();                       //Send a sound Wave
  travelTime = pulseIn(echoPin, HIGH);   //Get Travel Time
  distance = travelTime * 0.034 / 2;     //Calculate Distance in cm

  if (distance <= 20) {
    //Turn ON Some LEDs depending on the distance
    int n = map(distance, 0, 20, numberOfLeds, 0);
    for (int i = 0; i < n; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    for (int i = n + 1; i < numberOfLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    
  } else {
    //Turn Off All LEDs
    for (int i = 0; i < numberOfLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(500);
}

void sendSoundWave() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
