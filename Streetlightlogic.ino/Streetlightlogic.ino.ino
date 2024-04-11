const int ledPin1 = 16; // First LED connected to GPIO pin 16
const int ledPin2 = 17; // Second LED connected to GPIO pin 17
const int ledPin3 = 23;
const int ledPin4 = 16;
const int ledPin5 = 17;
const int ledPin6 = 23;
const int motionSensor1 = 19; // First motion sensor connected to GPIO pin 19
const int motionSensor2 = 21; // Second motion sensor connected to GPIO pin 20
const int motionSensor3 = 14;
const int motionSensor4 = 19;
const int motionSensor5 = 21;
const int motionSensor6 = 14;

const int light_sensor1 = 12;
const int light_sensor2 = 26;
const int light_sensor3 = 13;
const int light_sensor4 = 12;
const int light_sensor5 = 27;
const int light_sensor6 = 13;

bool motionDetected1 = false; // Motion detected by first sensor
bool motionDetected2 = false; // Motion detected by second sensor
bool motionDetected3 = false;
bool motionDetected4 = false;
bool motionDetected5 = false;
bool motionDetected6 = false;
unsigned long lastMotionTime = 0; // Time when motion was last detected

// Time interval to wait for the second motion before turning off all LEDs (in milliseconds)
const unsigned long motionTimeout = 5000; // 5 seconds

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(motionSensor1, INPUT);
  pinMode(motionSensor2, INPUT);
  pinMode(motionSensor3, INPUT);
  pinMode(motionSensor4, INPUT);
  pinMode(motionSensor5, INPUT);
  pinMode(motionSensor6, INPUT);
  pinMode(light_sensor1, INPUT);
  pinMode(light_sensor2, INPUT);
  pinMode(light_sensor3, INPUT);
  pinMode(light_sensor4, INPUT);
  pinMode(light_sensor5, INPUT);
  pinMode(light_sensor6, INPUT);

}

void loop() {
  //printse();
  if (analogRead(light_sensor1)  > 500)
  {  // Check motion sensor 1
  
    if (digitalRead(motionSensor1) == HIGH) {
      motionDetected1 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin1, HIGH); // Turn on first LED
    }

    // Check motion sensor 2
    if (digitalRead(motionSensor2) == HIGH) {
      motionDetected2 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin2, HIGH); // Turn on second LED
    }

    // Check motion sensor 3
    if (digitalRead(motionSensor3) == HIGH) {
      motionDetected3 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin3, HIGH); // Turn on second LED
    }

    // Check motion sensor 4
    if (digitalRead(motionSensor4) == HIGH) {
      motionDetected4 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin4, HIGH); // Turn on first LED
    }

    // Check motion sensor 5
    if (digitalRead(motionSensor5) == HIGH) {
      motionDetected5 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin5, HIGH); // Turn on first LED
    }

    // Check motion sensor 6
    if (digitalRead(motionSensor6) == HIGH) {
      motionDetected6 = true;
      lastMotionTime = millis();
      digitalWrite(ledPin6, HIGH); // Turn on first LED
    }

    // Check if motion timeout has elapsed
    if (millis() - lastMotionTime >= motionTimeout) {
      motionDetected1 = false;
      motionDetected2 = false;
      motionDetected3 = false;
      motionDetected4 = false;
      motionDetected5 = false;
      motionDetected6 = false;
      digitalWrite(ledPin1, LOW); // Turn off first LED
      digitalWrite(ledPin2, LOW); // Turn off second LED
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
    }

    // Adjust delay as needed to avoid excessive checking
  }
  delay(5000);
}