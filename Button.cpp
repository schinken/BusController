#include "Button.h"

Button::Button(uint8_t pin) {
  pinMode(pin, INPUT_PULLUP);

  this->bounce = new Bounce();
  this->bounce->attach(pin);
  this->bounce->interval(10);
}

bool Button::pressed(void) {
  return (this->bounce->read() == LOW);
}

bool Button::released(void) {
  return (this->bounce->read() == HIGH);
}

bool Button::rose(void) {
  return this->bounce->rose();
}

bool Button::fell(void) {
  return this->bounce->fell();
}

void Button::update(void) {
  this->bounce->update();
}

