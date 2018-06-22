#include "Bedside.h"

Bedside::Bedside(
  RotaryEncoder* encoder, Bounce* encoderButton, Bounce* button1, Bounce* button2, Bounce* button3, AbstractLight* trayLight, AbstractLight* mainLight) :
  encoder(encoder), encoderButton(encoderButton),
  button1(button1), button2(button2), button3(button3),
  trayLight(trayLight), mainLight(mainLight)
{ 
  this->mainFader = new Fader(mainLight);
}

void Bedside::loop(void) {
  this->encoder->tick();


  if (this->button1->fell()) {
    if (this->mainLight->getBrightness() > 10) {
      this->mainFader->fadeTo(0, 0.1);
    } else {
      this->mainFader->fadeTo(255, 0.1);
    }
  }

  AbstractLight* light = this->trayLight;
  if (this->encoderButton->read() == LOW) {
    light = this->mainLight;
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

  this->mainFader->tick();
}

