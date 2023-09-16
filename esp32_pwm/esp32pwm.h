#pragma once
#include "Arduino.h"


class esp_pwm{
private:
	int _pin;
	int _frequency;
	int _channel;
	int _pwm_resolution;
	int _cycle;
public:
	void setup(const int pin, const int channel);
	void write(int duty_cycle);
};