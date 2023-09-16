#include "jenga.h"


Jenga::Jenga(mode m, const int m1, const int m2, const int m3en)
	:	_current_mode(m), _m1(m1), _m2(m2), _m3en(m3en)
{
	Jenga_setup();
}

Jenga::Jenga(const int m1, const int m2, const int m3en)
	:	_current_mode(MEDIUM), _m1(m1), _m2(m2), _m3en(m3en)
{
	Jenga_setup();
}

void Jenga::Jenga_setup(){
	randomSeed(analogRead(0));
	pinMode(_m1, OUTPUT);
	pinMode(_m2, OUTPUT);
	pinMode(_m3en, OUTPUT);
	digitalWrite(_m1, LOW);
	digitalWrite(_m2, LOW);
	analogWrite(_m3en, 0);
}

void Jenga::Jenga_loop(){
	if (random(1,16) == 7){
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