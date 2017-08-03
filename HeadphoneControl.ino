#define MY_LED 9 //LED_BUILTIN
#define MY_RELAY 2
#define MY_IN A7
#define SAMPLE_DELAY 1000
#define SETTLE_DELAY 10

//#define SERIAL_LOG

void setup() {
  #ifdef SERIAL_LOG
  Serial.begin(115200);
  Serial.println("-------- Hello ---------");
  #endif
  pinMode(MY_LED, OUTPUT);
  pinMode(MY_RELAY, OUTPUT);
  digitalWrite(MY_LED, HIGH);
}

void loop() {

  bool emptyHanger = lightDetected();
  if (emptyHanger) {
    relayOn(true);
  } else {
    relayOn(false);
  }
  delay(SAMPLE_DELAY);

}

bool lightDetected() {
  digitalWrite(MY_LED, HIGH);
  delay(SETTLE_DELAY);
  int a = analogRead(MY_IN); 
  #ifdef SERIAL_LOG
  Serial.print(a);
  #endif
  digitalWrite(MY_LED, LOW);
  if (a > 200) {
    #ifdef SERIAL_LOG
    Serial.println("-------- HP removed ---------");
    #endif
    return true;
  }
  #ifdef SERIAL_LOG
  Serial.println("-------- HP present ---------");
  #endif
  return false;
}

void relayOn(bool on) {
  if (on) {
    #ifdef SERIAL_LOG
    Serial.println("-------- Speakers ---------");
    #endif
    digitalWrite(MY_RELAY, HIGH);
  } else {
    #ifdef SERIAL_LOG
    Serial.println("-------- Headphones ---------");
    #endif
    digitalWrite(MY_RELAY, LOW);
  }
}


