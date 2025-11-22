#define BLYNK_TEMPLATE_ID "TMPL6HsBDSDgy"
#define BLYNK_TEMPLATE_NAME "cloth drying"
#define BLYNK_AUTH_TOKEN "qH5BZeA1tL98B_5ArF22AUwV4FklMeQ2"
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

char ssid[] = "IOT LAB";         // Your WiFi SSID
char pass[] = "iotlab@507"; 

// Servo motor instances
Servo servo1; // Protects clothes
Servo servo2; // Wipes the rain sensor

// Pin definitions
#define SERVO1_PIN D6
#define SERVO2_PIN D5
#define LDR_PIN D0
#define RAIN_SENSOR_PIN D8
#define RAIN_SENSOR_VCC D7

// Threshold for LDR (adjust based on testing)
const int lightThreshold = 30;

void setup() {
  // Initialize servo motors
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  // Set initial servo positions
  servo1.write(0); // Start at 0 degrees
  servo2.write(0); // Start at 0 degrees

  // Initialize rain sensor power
  pinMode(RAIN_SENSOR_VCC, OUTPUT);
  digitalWrite(RAIN_SENSOR_VCC, HIGH); // Power the rain sensor

  // Initialize serial monitor (optional for debugging)
  Serial.begin(9600);
}

void loop() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connecting to Blynk...");
  
  // Read LDR value
  int ldrValue = analogRead(LDR_PIN);

  // Read rain sensor value
  int rainValue = digitalRead(RAIN_SENSOR_PIN);

  // Debugging information (optional)
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  Serial.print("Rain Detected: ");
  Serial.println(rainValue);


  // Handle servo1 based on conditions
  if (rainValue == LOW) {
    //Blynk.logEvent("rain", "Rain Detected and protect clothes.");
    Blynk.logEvent("rain", "Rain Detected and protect clothes.");


    // If rain is detected, protect clothes
     delay(1000);
    servo1.write(0); // Move to 90 degrees to protect clothes
  } else if (ldrValue >= lightThreshold) {
    //Blynk.logEvent("ldr","It's daytime and no rain, allow clothes to dry.");

    Blynk.logEvent("ldr","It's daytime and no rain, allow clothes to dry.");
    // If it's daytime and no rain, allow clothes to dry
    
    servo1.write(0); // Move to 0 degrees
  } else {
    
    // If it's nighttime, keep clothes protected
    servo1.write(90); // Keep at 90 degrees
  }

  // Handle servo2 for wiping rain sensor
  if (rainValue == LOW) {
    // If rain is detected, move servo2 continuously
    servo2.write(90); // Move to 90 degrees
    delay(300);      // Wait for 1 second
    servo2.write(0);  // Move back to 0 degrees
    delay(300);      // Wait for 1 second
  } else {
    // Stop servo2 movement
    servo2.write(0);
  }
 Blynk.virtualWrite(V0, rainValue);
 Blynk.virtualWrite(V5, ldrValue);
 Blynk.run(); // Run Blynk
  delay(100); // Small delay to stabilize readings
}
