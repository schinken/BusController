#ifndef __FADER_H__
#define __FADER_H__

#include "AbstractLight.h"
#include <DMXSerial.h>

class Fader final {

  private:
    AbstractLight* light;
    
    bool finished;
    
    float step;
    float current;
    float target;
    
  public:    
    Fader(AbstractLight* light);
    
    void fadeTo(float target, float speed);
    void tick(void);
};

#endif
