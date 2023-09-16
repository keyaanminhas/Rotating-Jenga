#ifndef JENGA_H

#define JENGA_H

#include "Arduino.h"

#define EASY_SPEED 40
#define MEDIUM_SPEED 50
#define HARD_SPEED 70


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
	int _current_speed;
	bool _toggle = false;

public:
	void Jenga(mode m, const int m1, const int m2, const int m3en);
	void Jenga(const int m1, const int m2, const int m3en);
	void Jenga_setup();
	void Jenga_loop();
	void set_mode(mode);
}

#endif