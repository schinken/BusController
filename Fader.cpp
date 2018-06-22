#include "Fader.h"


Fader::Fader(AbstractLight* light) : light(light), running(false) {
}

void Fader::fadeTo(float target, float step) {
  this->current = this->light->getBrightness();
  this->last = this->current;
  this->target = target;
  
  this->step = step;
  if (target < this->current) {
    this->step *= -1;  
  }
  
  this->running = true;
}

void Fader::tick(void) {
  if (!this->running) {
    return;
  }

  this->current += this->step;

  // Did we reach our target? 
  if ((this->step < 0 && this->current <= this->target) ||
      (this->step > 0 && this->current >= this->target)) {
    this->light->setBrightness(this->target);
    this->running = false;

    return;
  }

  int16_t diff = (int16_t) this->current - (int16_t) this->last;
  if (abs(diff) > 1) {
    this->light->setRelativeBrightness(diff);
    this->last = this->current;
  }
}

