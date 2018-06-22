#ifndef __BEDSIDE_H__
#define __BEDSIDE_H__

#include <RotaryEncoder.h>
#include <Bounce2.h>
#include "AbstractLight.h"

class Bedside {
  
  private:
    AbstractLight* trayLight;
    AbstractLight* mainLight;

    RotaryEncoder* encoder;
    Bounce* encoderButton;
    
    Bounce* button;

    long encoderPositionOld;

  public:
    Bedside(RotaryEncoder* encoder, Bounce* encoderButton, Bounce* button, AbstractLight* trayLight, AbstractLight* mainLight);

    void loop(void);
};

#endif
