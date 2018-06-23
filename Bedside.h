#ifndef __BEDSIDE_H__
#define __BEDSIDE_H__

#include <RotaryEncoder.h>
#include "Button.h"
#include "AbstractLight.h"

class Bedside {
  
  private:
    AbstractLight* trayLight;
    AbstractLight* mainLight;

    RotaryEncoder* encoder;
    Button* encoderButton;
    
    Button* button;

    long encoderPositionOld;

  public:
    Bedside(RotaryEncoder* encoder, Button* encoderButton, Button* button, AbstractLight* trayLight, AbstractLight* mainLight);

    void loop(void);
};

#endif
