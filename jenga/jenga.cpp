#include "jenga.h"


Jenga::Jenga(mode m, const int m1, const int m2, const int m3en)
	:	_current_mode(m), _m1(m1), _m2(m2), _m3en(m3en)
{
}

Jenga::Jenga(const int m1, const int m2, const int m3en)
	:	_current_mode(MEDIUM), _m1(m1), _m2(m2), _m3en(m3en)
{
}

#ifndef ESP32

void Jenga::Jenga_setup(const int EASYSPEED, const int MEDIUMSPEED, const int HARDSPEED, const int CHANCE){
	randomSeed(analogRead(0));
	EASY_SPEED = EASYSPEED;
	MEDIUM_SPEED = MEDIUMSPEED;
	HARD_SPEED = HARDSPEED;
	CHANCES = CHANCE;
	pinMode(_m1, OUTPUT);
	pinMode(_m2, OUTPUT);
	pinMode(_m3en, OUTPUT);
	digitalWrite(_m1, LOW);
	digitalWrite(_m2, LOW);
	analogWrite(_m3en, 0);
}


void Jenga::Jenga_loop(){
	if (random(0,CHANCES) == 0){
		_toggle = !(_toggle);
	}
	if (_current_mode == EASY){
		analogWrite(_m3en, EASY_SPEED);
		digitalWrite(_m1, HIGH);
	}
	else if (_current_mode == MEDIUM){
		analogWrite(_m3en, MEDIUM_SPEED);
		if (_toggle){
			digitalWrite(_m1, HIGH);
			digitalWrite(_m2, LOW);
		}
		else{
			digitalWrite(_m1, LOW);
			digitalWrite(_m2, HIGH);
		}

	}
	else if (_current_mode == HARD){
		analogWrite(_m3en, HARD_SPEED);
		if (_toggle){
			digitalWrite(_m1, HIGH);
			digitalWrite(_m2, LOW);
		}
		else{
			digitalWrite(_m1, LOW);
			digitalWrite(_m2, HIGH);
		}

	}

}

#else

void Jenga::Jenga_setup(const int EASYSPEED, const int MEDIUMSPEED, const int HARDSPEED, const int CHANCE){
	randomSeed(analogRead(0));
	EASY_SPEED = EASYSPEED;
	MEDIUM_SPEED = MEDIUMSPEED;
	HARD_SPEED = HARDSPEED;
	CHANCES = CHANCE;
	pinMode(_m1, OUTPUT);
	pinMode(_m2, OUTPUT);
	motor.setup(_m3en, 0);
	digitalWrite(_m1, LOW);
	digitalWrite(_m2, LOW);
	motor.write(0);
}

void Jenga::Jenga_loop(){
	if ((random(0,CHANCES) == 0) and (_current_mode != CUSTOM)){
		_toggle = !(_toggle);
	}
	if (_current_mode == EASY){
		motor.write(EASY_SPEED);
		digitalWrite(_m1, HIGH);
	}
	else if (_current_mode == MEDIUM){
		motor.write(MEDIUM_SPEED);
		if (_toggle){
			digitalWrite(_m1, HIGH);
			digitalWrite(_m2, LOW);
		}
		else{
			digitalWrite(_m1, LOW);
			digitalWrite(_m2, HIGH);
		}

	}
	else if (_current_mode == HARD){
		motor.write(HARD_SPEED);
		if (_toggle){
			digitalWrite(_m1, HIGH);
			digitalWrite(_m2, LOW);
		}
		else{
			digitalWrite(_m1, LOW);
			digitalWrite(_m2, HIGH);
		}

	}

}
#endif


void Jenga::set_mode(mode m){
	_current_mode = m;
}

void Jenga::direction(String dir){
	if ((dir == "LEFT") and (_current_mode == CUSTOM)){
		digitalWrite(_m1, HIGH);
		digitalWrite(_m2, LOW);
	}
	else if ((dir == "RIGHT") and (_current_mode == CUSTOM)){
		digitalWrite(_m1, LOW);
		digitalWrite(_m2, HIGH);
	}
}