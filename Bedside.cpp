#include "Bedside.h"

Bedside::Bedside(RotaryEncoder* encoder, Bounce* encoderButton, Bounce* button1, Bounce* button2, Bounce* button3) :
  encoder(encoder), encoderButton(encoderButton), button1(button1), button2(button2), button3(button3)
{ 
}

void Bedside::setTrayLight(AbstractLight* light) {
  this->tray = light;
}

void Bedside::setMainLight(AbstractLight* light) {
  this->main = light;
}

void Bedside::loop(void) {
  this->encoder->tick();


  if (this->button1->fell()) {
    if (this->main->getBrightness() > 10) {
      this->main->setBrightness(0);
    } else {
      this->main->setBrightness(255);
    }
  }

  AbstractLight* light = this->tray;
  if (this->encoderButton->read() == LOW) {
    light = this->main;
  }


  long newPosition = this->encoder->getPosition();
  if (newPosition > this->encoderPositionOld) {
      light->setRelativeBrightness(+8);
  } else if (newPosition < this->encoderPositionOld) {
      light->setRelativeBrightness(-8);
  }

  this->encoderPositionOld = newPosition;

  this->encoderButton->update();
  
  this->button1->update();
  this->button2->update();
  this->button3->update();
}

