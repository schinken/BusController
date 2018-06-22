#include "Fader.h"


Fader::Fader(AbstractLight* light) : light(light), finished(true) {
}

void Fader::fadeTo(float target, float step) {
  this->current = this->light->getBrightness();
  this->target = target;
  
  this->step = step;
  if (target < this->current) {
    this->step *= -1;  
  }
  
  this->finished = false;
}

void Fader::tick(void) {
  if (this->finished) {
    return;
  }

  this->current += this->step;
  if (this->step < 0 && this->current <= this->target) {
    this->current = this->target;
    this->finished = true;
  } else if (this->step > 0 && this->current >= this->target) {
    this->current = this->target;
    this->finished = true;
  }
  
  this->light->setBrightness(this->current);
}

