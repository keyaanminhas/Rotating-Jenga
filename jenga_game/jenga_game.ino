#include <jenga.h>
#define ESP32
#define CHANCES 15

Jenga game1(MEDIUM, 18, 19, 5);


void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup");
  game1.Jenga_setup(250,250,200, 50000);

}

void loop() {
  game1.Jenga_loop();
}
