#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <Bounce2.h>

class Button {
  
  private:
    Bounce* bounce;

  public:
    Button(uint8_t pin);

    bool pressed(void);
    bool released(void);
    bool rose(void);
    bool fell(void);
    
    void update(void);
};

#endif
