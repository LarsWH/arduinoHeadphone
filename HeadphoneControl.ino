

//#include <Arduino.h>

#define MY_LED 9
#define MY_RELAY1 7
#define MY_RELAY2 8
#define MY_IN A0
#define SAMPLE_DELAY 1000
#define SETTLE_DELAY 10

void setup() {
  Serial.begin(115200);
  Serial.println("-------- Hello ---------");
  pinMode(MY_LED, OUTPUT);
  pinMode(MY_RELAY1, OUTPUT);
  pinMode(MY_RELAY2, OUTPUT);
  digitalWrite(MY_LED, HIGH);
}

void loop() {

  bool empty = lightDetected();
  if (empty) {
    relayOn(false);
  } else {
    relayOn(true);
  }
  delay(SAMPLE_DELAY);

}

bool lightDetected() {
  digitalWrite(MY_LED, HIGH);
  delay(SETTLE_DELAY);
  int a = analogRead(MY_IN); 
  Serial.print(a);
  digitalWrite(MY_LED, LOW);
  if (a > 200) {
    Serial.println("-------- HP removed ---------");
    return true;
  }
  Serial.println("-------- HP present ---------");
  return false;
}

void relayOn(bool on) {
  if (on) {
    Serial.println("-------- Speakers ---------");
    digitalWrite(MY_RELAY1, HIGH);
    delay(SETTLE_DELAY*5);
    digitalWrite(MY_RELAY2, HIGH);
  } else {
    Serial.println("-------- Headphones ---------");
    digitalWrite(MY_RELAY1, LOW);
    delay(SETTLE_DELAY*5);
    digitalWrite(MY_RELAY2, LOW);
  }
}


