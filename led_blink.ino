const int LED_PIN = 13;

const unsigned long LED_ON_TIME_MS = 1000;
const unsigned long LED_OFF_TIME_MS = 1000;

bool ledState = LOW;
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  unsigned long interval = ledState
      ? LED_ON_TIME_MS
      : LED_OFF_TIME_MS;

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // Other tasks can run here without delay().
}
