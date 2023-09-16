#include "esp32pwm.h"


void esp_pwm::setup(const int pin, const int channel)
{
	_pin = pin;
	_frequency = 5000;
	_channel = channel;
	_pwm_resolution = 8;
	ledcAttachPin(pin, channel);
	ledcSetup(channel, 5000, 8);
}


void esp_pwm::write(int duty_cycle)
{
	_cycle = duty_cycle;
	ledcWrite(_channel, duty_cycle);
}