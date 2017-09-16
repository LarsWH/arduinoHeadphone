// Pin definitions
#define IR_TRANSMITTER 9
#define IR_RECEIVER_ANALOG A7
#define AUDIO_RELAY 2

// Control
#define SAMPLE_DELAY 1000
#define SETTLE_DELAY 10
#define ANALOG_VALUE_LIMIT 200

void setup() {
  pinMode(IR_TRANSMITTER, OUTPUT);
  pinMode(AUDIO_RELAY, OUTPUT);
  digitalWrite(IR_TRANSMITTER, HIGH);
}

void loop() {
  bool emptyHanger = lightDetected();
  if (emptyHanger) {
    audioInHeadset(true);
  } else {
    audioInHeadset(false);
  }
  delay(SAMPLE_DELAY);
}


bool lightDetected() {
  digitalWrite(IR_TRANSMITTER, HIGH);
  delay(SETTLE_DELAY);
  int a = analogRead(IR_RECEIVER_ANALOG); 
  digitalWrite(IR_TRANSMITTER, LOW);
  if (a > ANALOG_VALUE_LIMIT) {
    return true;
  }
  return false;
}


void audioInHeadset(bool on) {
  if (on) {
    digitalWrite(AUDIO_RELAY, HIGH);
  } else {
    digitalWrite(AUDIO_RELAY, LOW);
  }
}

