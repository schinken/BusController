#ifndef __LIGHTGROUP_H__
#define __LIGHTGROUP_H__

#include <Arduino.h>
#include "AbstractLight.h"

#define MAX_LIGHTS 16

class LightGroup final : public virtual AbstractLight {

  private:
    AbstractLight* lights[MAX_LIGHTS];
    int8_t size;
    
  public:
    LightGroup();
    
    void addLight(AbstractLight* light);
    
    void setBrightness(uint8_t value);
    uint8_t getBrightness(void);

    void setRelativeBrightness(int16_t value);
};

#endif
