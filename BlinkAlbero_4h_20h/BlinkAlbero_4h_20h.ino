const int LED_PIN = 13;
const int RELE_1_PIN = 11;
const int RELE_2_PIN = 12;

int ledState = LOW;
int releState = HIGH;

// Generally, you shuould use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;
unsigned long interval = 0;



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELE_1_PIN, OUTPUT);
  //pinMode(RELE_2_PIN, OUTPUT);
  Serial.begin(9600); //inizializza la porta seriale (per il log)
  //Serial.println("Initialized"); //scrive sulla porta seriale (per il log)
}

void loop() {
  unsigned long currentMillis = millis();
  Serial.print(currentMillis - previousMillis); Serial.print("/"); Serial.print(interval);
  Serial.println();
  if (currentMillis - previousMillis >= interval) {

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      releState = LOW;
      interval = getMillisecondiFromOre(4);
    }
    else {
      ledState = LOW;
      releState = HIGH;
      interval = getMillisecondiFromOre(20);
    }

    digitalWrite(LED_PIN, ledState);
    digitalWrite(RELE_1_PIN, releState);
    //digitalWrite(RELE_2_PIN, releState);

    // save the last time you blinked the LED
    previousMillis = currentMillis;
  }
  /*
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELE_2_PIN, LOW);

    // attende 9 ore prima di spegnere (dalle 18.00 alle 03.00)
    for(int i = 0; i < getSecondiFromOre(9); i++){
      delay(1000);
    }

    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELE_2_PIN, HIGH);

    // attende 15 ore prima di riaccendere (dalle 03.00 alle 18.00)
    for(int i = 0; i < getSecondiFromOre(15); i++){
      delay(1000);
    }
  */
}

unsigned long getMillisecondiFromOre(unsigned long ore) {
  return ore * 60 * 60 * 1000;
}


