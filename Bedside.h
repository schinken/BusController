#ifndef __BEDSIDE_H__
#define __BEDSIDE_H__

#include <RotaryEncoder.h>
#include <Bounce2.h>
#include "AbstractLight.h"
#include "Fader.h"

class Bedside {
  
  private:
    AbstractLight* trayLight;
    AbstractLight* mainLight;

    Fader* mainFader;

    RotaryEncoder* encoder;
    Bounce* encoderButton;
    
    Bounce* button1;
    Bounce* button2;
    Bounce* button3;

    long encoderPositionOld;

  public:
    Bedside(RotaryEncoder* encoder, Bounce* encoderButton, Bounce* button1, Bounce* button2, Bounce* button3, AbstractLight* trayLight, AbstractLight* mainLight);

    void loop(void);
};

#endif
