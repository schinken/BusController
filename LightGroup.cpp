#include "LightGroup.h"

LightGroup::LightGroup() {
  for (uint8_t i = 0; i < MAX_LIGHTS; i++) {
    this->lights[i] = NULL;
  }
}

void LightGroup::addLight(AbstractLight* light) {
  for (uint8_t i = 0; i < MAX_LIGHTS; i++) {
    if (this->lights[i] == NULL) {
      this->lights[i] = light;
      return;
    }
  }
}

void LightGroup::setBrightness(uint8_t value) {
  for (uint8_t i = 0; i < MAX_LIGHTS; i++) {
    if (this->lights[i]) {
      this->lights[i]->setBrightness(value);
    }
  }
}

uint8_t LightGroup::getBrightness(void) {
  uint8_t brightest = 0;
  
  for (uint8_t i = 0; i < MAX_LIGHTS; i++) {
    if (this->lights[i]) {
      brightest = max(brightest, this->lights[i]->getBrightness());
    }
  }

  return brightest;
}

void LightGroup::setRelativeBrightness(int16_t value) {
  for (uint8_t i = 0; i < MAX_LIGHTS; i++) {
    if (this->lights[i]) {
      this->lights[i]->setRelativeBrightness(value);
    }
  }
}

