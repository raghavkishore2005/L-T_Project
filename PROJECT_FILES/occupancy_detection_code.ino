// Pin configuration
const int PIR_OUTDOOR = 2;
const int PIR_INDOOR = 3;
const int LIGHT_PIN = 8;
const int FAN_PIN = 9;

// State
bool roomOccupied = false;
unsigned long lastExitTime = 0;
const unsigned long cooldownTime = 30000; 

// Flags for detecting sequence
bool outdoorTriggered = false;
bool indoorTriggered = false;
unsigned long triggerTime = 0;
const unsigned long triggerWindow = 3000; 

void setup() {
  pinMode(PIR_OUTDOOR, INPUT);
  pinMode(PIR_INDOOR, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int outdoorMotion = digitalRead(PIR_OUTDOOR);
  int indoorMotion = digitalRead(PIR_INDOOR);
  unsigned long currentTime = millis();

  // ENTRY detection: Outdoor PIR triggers first, then Indoor
  if (outdoorMotion == HIGH && !roomOccupied) {
    outdoorTriggered = true;
    triggerTime = currentTime;
  }
  if (outdoorTriggered && indoorMotion == HIGH && (currentTime - triggerTime <= triggerWindow)) {
    roomOccupied = true;
    digitalWrite(LIGHT_PIN, HIGH);
    digitalWrite(FAN_PIN, HIGH);
    Serial.println("Person entered, Light & Fan ON");
    outdoorTriggered = false;
    delay(1000);
  }

  // EXIT detection: Indoor PIR triggers first, then Outdoor
  if (indoorMotion == HIGH && roomOccupied) {
    indoorTriggered = true;
    triggerTime = currentTime;
  }
  if (indoorTriggered && outdoorMotion == HIGH && (currentTime - triggerTime <= triggerWindow)) {
    lastExitTime = currentTime;
    Serial.println("Person exited, Starting cooldown");
    indoorTriggered = false;
    delay(1000);
  }

  // Cooldown logic: Turn off after 30 sec if no one returns
  if (roomOccupied && (currentTime - lastExitTime >= cooldownTime) && lastExitTime != 0) {
    roomOccupied = false;
    digitalWrite(LIGHT_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
    Serial.println("Room now empty, Light & Fan OFF");
    lastExitTime = 0;
  }
}
