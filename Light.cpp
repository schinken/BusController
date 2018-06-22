#include "Light.h"

Light::Light(uint8_t channel) {
  this->channel = channel;
  this->value = 0;
}

void Light::setBrightness(uint8_t value) {
  this->value = constrain(value, 0, 255);
  DMXSerial.write(this->channel, this->value);
}

uint8_t Light::getBrightness(void) {
  return this->value;
}

void Light::setRelativeBrightness(int16_t value) {
  int16_t tmp = this->value;
  tmp += value;

  this->setBrightness(tmp);
}

