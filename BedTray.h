#ifndef __BEDTRAY_H__
#define __BEDTRAY_H__

#include <RotaryEncoder.h>
#include "Button.h"
#include "AbstractLight.h"

class BedTray {
  
  private:
    AbstractLight* trayLight;
    AbstractLight* mainLight;

    RotaryEncoder* encoder;
    Button* encoderButton;
    
    Button* button;

    long encoderPositionOld;

  public:
    BedTray(RotaryEncoder* encoder, Button* encoderButton, Button* button, AbstractLight* trayLight, AbstractLight* mainLight);

    void loop(void);
};

#endif
