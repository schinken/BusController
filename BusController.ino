#include <DMXSerial.h>
#include <Bounce2.h>
#include "Light.h"
#include "LightGroup.h"
#include "Bedside.h"
#include "Fader.h"
#include "RotaryEncoder.h"

#define PIN_BED_L_BUTTON_1 53
#define PIN_BED_L_BUTTON_2 51
#define PIN_BED_L_ROTARY_CLK 49
#define PIN_BED_L_ROTARY_DT 47
#define PIN_BED_L_ROTARY_SWITCH 45
#define PIN_BED_L_BUTTON_3 43

#define PIN_BED_R_BUTTON_1 52
#define PIN_BED_R_BUTTON_2 50
#define PIN_BED_R_ROTARY_CLK 48
#define PIN_BED_R_ROTARY_DT 46
#define PIN_BED_R_ROTARY_SWITCH 44
#define PIN_BED_R_BUTTON_3 42

#define PIN_DOOR_BUTTON_1 40
#define PIN_DOOR_BUTTON_2 38
#define PIN_DOOR_CONTACT 36

#define CH_LIGHT_CEILING_LEFT 30
#define CH_LIGHT_CEILING_RIGHT 29
#define CH_LIGHT_SHELF_TOP 28
#define CH_LIGHT_SHELF_MIDDLE 27
#define CH_LIGHT_SHELF_BOTTOM 26
#define CH_LIGHT_BED_LEFT 25
#define CH_LIGHT_BED_RIGHT 24

Bounce* BounceFactory(uint8_t pin) {
  pinMode(pin, INPUT_PULLUP);
    
  Bounce* bounce = new Bounce();
  bounce->attach(pin);
  bounce->interval(10);

  return bounce;
}

Light* lightBedLeft = new Light(CH_LIGHT_BED_LEFT);
Light* lightBedRight = new Light(CH_LIGHT_BED_RIGHT);

LightGroup* lightAll = new LightGroup();

Fader* mainFader = new Fader(lightAll);

Bounce* doorMainSwitch = BounceFactory(PIN_DOOR_BUTTON_1);
Bounce* leftBedMainSwitch = BounceFactory(PIN_BED_L_BUTTON_1);
Bounce* rightBedMainSwitch = BounceFactory(PIN_BED_R_BUTTON_1);

Bedside* bedLeft = new Bedside(
  new RotaryEncoder(PIN_BED_L_ROTARY_CLK, PIN_BED_L_ROTARY_DT), BounceFactory(PIN_BED_L_ROTARY_SWITCH),
  BounceFactory(PIN_BED_L_BUTTON_3),
  lightBedLeft, lightAll
);

Bedside* bedRight = new Bedside(
  new RotaryEncoder(PIN_BED_R_ROTARY_CLK, PIN_BED_R_ROTARY_DT), BounceFactory(PIN_BED_R_ROTARY_SWITCH),
  BounceFactory(PIN_BED_R_BUTTON_3),
  lightBedRight, lightAll
);

void setup() {
  DMXSerial.init(DMXController);

  lightAll->addLight(new Light(CH_LIGHT_CEILING_LEFT));
  lightAll->addLight(new Light(CH_LIGHT_CEILING_RIGHT));
  lightAll->addLight(new Light(CH_LIGHT_SHELF_TOP));
  lightAll->addLight(new Light(CH_LIGHT_SHELF_MIDDLE));
  lightAll->addLight(new Light(CH_LIGHT_SHELF_BOTTOM));
  lightAll->addLight(lightBedLeft);
  lightAll->addLight(lightBedRight);
}

void loop() {
  
  if (doorMainSwitch->fell() || leftBedMainSwitch->fell() || rightBedMainSwitch->fell()) {
    if (lightAll->getBrightness() > 10) {
      mainFader->fadeTo(0, 0.1);
    } else {
      mainFader->fadeTo(255, 0.1);
    }
  }
  
  bedLeft->loop();
  bedRight->loop();

  doorMainSwitch->update();
  leftBedMainSwitch->update();
  rightBedMainSwitch->update();
  
  mainFader->tick();

}
