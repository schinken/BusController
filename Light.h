#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "AbstractLight.h"
#include <DMXSerial.h>

class Light final : public virtual AbstractLight {

  private:
    uint8_t value;
    uint8_t channel;
    
  public:
    Light(uint8_t channel);
    
    void setBrightness(uint8_t value);
    uint8_t getBrightness(void);

    void setRelativeBrightness(int16_t value);
};

#endif
