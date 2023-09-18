
#define ESP32

#include <jenga.h>
#include <blue.h>

String current;

#define motor_pin_1 18
#define motor_pin_2 19
#define motor_speed_pin 5


Jenga game1(MEDIUM, motor_pin_1 , motor_pin_2, motor_speed_pin); // CHANGE MODE TO EASY MEDIUM OR HARD
Ble32 mytooth;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup");
  mytooth.setup("Mytooth Blue");

  game1.Jenga_setup(190,200,220, 50000);


}

void loop() {
  current = mytooth.read();
  if (current == "69"){
    Serial.println("EASY");
    game1.set_mode(EASY);
  }
  else if (current == "77"){
    Serial.println("MEDIUM");
    game1.set_mode(MEDIUM);
  }
  else if (current == "72"){
    Serial.println("HARD");
    game1.set_mode(HARD);
  }
  else if (current == "80"){
    Serial.println("PVP");
    game1.set_mode(CUSTOM);
  }
  else if (current == "76"){
    Serial.println("LEFT");
    game1.direction("LEFT");
  }
  else if (current == "82"){
    Serial.println("RIGHT");
    game1.direction("RIGHT");
  }
  game1.Jenga_loop();

}
