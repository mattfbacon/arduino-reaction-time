#define PIN_RED_LED 10
#define PIN_GREEN_LED 11
#define PIN_YELLOW_LED 12
#define PIN_START_BUTTON 9
#define PIN_REACT_BUTTON 8
#define PINa_FLOATING 3

void setup() {
	pinMode(PIN_RED_LED, OUTPUT);
	pinMode(PIN_GREEN_LED, OUTPUT);
	pinMode(PIN_YELLOW_LED, OUTPUT);
	pinMode(PIN_START_BUTTON, INPUT);
	pinMode(PIN_REACT_BUTTON, INPUT);

	Serial.begin(9600);
	while (!Serial) {
		yield();
	}
}

void loop() {
	// use a floating pin to get "random" data
	randomSeed(analogRead(PINa_FLOATING));

	digitalWrite(PIN_GREEN_LED, LOW);
	digitalWrite(PIN_RED_LED, HIGH);
	while (!digitalRead(PIN_START_BUTTON)) {
		yield();
	}
	digitalWrite(PIN_RED_LED, LOW);
	digitalWrite(PIN_YELLOW_LED, HIGH);

	// can be tuned
	delay(random(2000, 5000));

	digitalWrite(PIN_YELLOW_LED, LOW);
	digitalWrite(PIN_GREEN_LED, HIGH);
	unsigned long const before = micros();
	while (!digitalRead(PIN_REACT_BUTTON)) {
		yield();
	}
	unsigned long const reactionTime = micros() - before;

	Serial.print("Reaction time: ");
	Serial.print((float)reactionTime / 1000.0);
	Serial.println(" ms");
}
