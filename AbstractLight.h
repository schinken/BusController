#ifndef __ABSTRACT_LIGHT_H__
#define __ABSTRACT_LIGHT_H__

#include <Arduino.h>

class AbstractLight {

  public:
    virtual void setBrightness(uint8_t value) = 0;
    virtual uint8_t getBrightness(void) = 0;

    virtual void setRelativeBrightness(int16_t value) = 0;
};

#endif
