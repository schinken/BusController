#include "LightGroup.h"

LightGroup::LightGroup() {
  this->size = 0;
}

void LightGroup::addLight(AbstractLight* light) {
  this->lights[this->size] = light;
  this->size++;
}

void LightGroup::setBrightness(uint8_t value) {
  for (uint8_t i = 0; i < this->size; i++) {
    this->lights[i]->setBrightness(value);
  }
}

uint8_t LightGroup::getBrightness(void) {
  uint8_t brightest = 0;
  
  for (uint8_t i = 0; i < this->size; i++) {
    brightest = max(brightest, this->lights[i]->getBrightness());
  }

  return brightest;
}

void LightGroup::setRelativeBrightness(int16_t value) {
  for (uint8_t i = 0; i < this->size; i++) {
    this->lights[i]->setRelativeBrightness(value);
  }
}

