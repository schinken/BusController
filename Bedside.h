#ifndef __BEDSIDE_H__
#define __BEDSIDE_H__

#include "AbstractLight.h"
#include <RotaryEncoder.h>
#include <Bounce2.h>

class Bedside {
  
  private:
    AbstractLight* tray;
    AbstractLight* main;

    RotaryEncoder* encoder;
    Bounce* encoderButton;
    
    Bounce* button1;
    Bounce* button2;
    Bounce* button3;

    long encoderPositionOld;

  public:
    Bedside(RotaryEncoder* encoder, Bounce* encoderButton, Bounce* button1, Bounce* button2, Bounce* button3);
    void setTrayLight(AbstractLight* light);
    void setMainLight(AbstractLight* light);
    
    void loop(void);
};

#endif
