#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Blynk authentication token
char auth[] = "YourAuthToken";

// Pin assignments
#define MOTOR_PIN D1  // Pin for controlling motor speed

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  delay(1000); // Give time to initialize Serial Monitor

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected");
}

void loop() {
  // Call Blynk's run function
  Blynk.run();
}

// Blynk virtual pin handler
BLYNK_WRITE(V1) {
  // Get the value from the virtual pin
  int motor_speed = param.asInt();
  Serial.print("Received motor speed: ");
  Serial.println(motor_speed);

  // Control the motor speed
  analogWrite(MOTOR_PIN, motor_speed);
  Serial.println("Motor speed updated");
}
