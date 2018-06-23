#include "Bedside.h"

Bedside::Bedside(
  RotaryEncoder* encoder, Button* encoderButton, Button* button, AbstractLight* trayLight, AbstractLight* mainLight) :
  encoder(encoder), encoderButton(encoderButton), button(button),
  trayLight(trayLight), mainLight(mainLight)
{ 
}

void Bedside::loop(void) {
  AbstractLight* light = this->trayLight;
  if (this->encoderButton->pressed()) {
    light = this->mainLight;
  }

  long newPosition = this->encoder->getPosition();
  if (newPosition > this->encoderPositionOld) {
      light->setRelativeBrightness(+8);
  } else if (newPosition < this->encoderPositionOld) {
      light->setRelativeBrightness(-8);
  }

  this->encoderPositionOld = newPosition;

  this->encoder->tick();
  this->encoderButton->update();
  this->button->update();
}

