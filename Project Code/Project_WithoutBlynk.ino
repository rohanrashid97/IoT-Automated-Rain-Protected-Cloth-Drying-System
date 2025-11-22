#include <Servo.h>
#include <ESP8266WiFi.h>

// Servo motor instances
Servo servo1;  
Servo servo2;  

// Pin definitions (YOUR UPDATED LIST)
#define DHT_PIN D5
#define SERVO1_PIN D4
#define SERVO2_PIN D2
#define LDR_PIN D0            // You said this is LDR pin — using exactly as given
#define RAIN_SENSOR_PIN D6
#define RAIN_SENSOR_VCC D7

// LDR threshold (adjust after testing)
const int lightThreshold = 300;

// Wiping timing
const unsigned long wipeInterval = 700;
unsigned long lastWipe = 0;
bool wipePos = false;

// Inverted direction → keep same logical angles
void setServo1(int angle) {
  int a = constrain(angle, 0, 180);
  int inverted = 180 - a;
  servo1.write(inverted);
}

void setup() {
  // servo1 custom pulse range
  servo1.attach(SERVO1_PIN, 500, 2400);
  servo2.attach(SERVO2_PIN);

  setServo1(0);
  servo2.write(0);

  // Power rain sensor
  pinMode(RAIN_SENSOR_VCC, OUTPUT);
  digitalWrite(RAIN_SENSOR_VCC, HIGH);

  pinMode(RAIN_SENSOR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {

  // Read sensors
  int ldrValue = analogRead(LDR_PIN);   // Using your chosen pin D0
  int rainValue = digitalRead(RAIN_SENSOR_PIN);  // LOW = rain

  // Debug
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Rain (LOW=Rain): ");
  Serial.println(rainValue);

  bool isDay = (ldrValue <= lightThreshold);
  bool isRain = (rainValue == LOW);

  // --- LOGIC ---
  // Only dry when: DAY & NO RAIN
  if (isDay && !isRain) {
    Serial.println("Day & No Rain → Dry clothes (servo1 = 0)");
    setServo1(0);
    servo2.write(0);
  }
  else {
    Serial.println("Rain OR Night → Protect clothes (servo1 = 180)");
    setServo1(180);

    if (isRain) {
      // continuous servo2 wiping using millis
      unsigned long now = millis();
      if (now - lastWipe >= wipeInterval) {
        lastWipe = now;
        wipePos = !wipePos;
        servo2.write(wipePos ? 90 : 0);
      }
    }
    else {
      // Night but no rain → stop wiping
      servo2.write(0);
    }
  }

  delay(50);
}
