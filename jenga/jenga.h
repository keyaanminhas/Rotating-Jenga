#ifndef JENGA_H

#define JENGA_H

#include "Arduino.h"



#ifdef ESP32
#include "esp32pwm.h"
#endif


enum mode {
	EASY = 1,
	MEDIUM = 2,
	HARD = 3,
	CUSTOM = 4
};

class Jenga{
private:
	mode _current_mode;
	const int _m1;
	const int _m2;
	const int _m3en;
	int EASY_SPEED;
	int MEDIUM_SPEED;
	int HARD_SPEED;
	int CHANCES;
	int _current_speed;
	bool _toggle = false;
	#ifdef ESP32
	esp_pwm motor;
	#endif

public:
	Jenga(mode m, const int m1, const int m2, const int m3en);
	Jenga(const int m1, const int m2, const int m3en);
	void Jenga_setup(const int EASYSPEED, const int MEDIUMSPEED, const int HARDSPEED, const int CHANCE);
	void Jenga_loop();
	void set_mode(mode);
};

#endif