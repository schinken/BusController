#include <DMXSerial.h>
#include <Bounce2.h>
#include "Light.h"
#include "LightGroup.h"
#include "Bedside.h"
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

#define CH_LIGHT_TOP_LEFT 30
#define CH_LIGHT_TOP_RIGHT 29

Bounce* BounceFactory(uint8_t pin) {
  pinMode(pin, INPUT_PULLUP);
    
  Bounce* bounce = new Bounce();
  bounce->attach(pin);
  bounce->interval(50);

  return bounce;
}

Light* lightBedLeft = new Light(23);
Light* lightBedRight = new Light(22);

LightGroup* lightAll = new LightGroup();

Bedside* bedLeft = new Bedside(
  new RotaryEncoder(PIN_BED_L_ROTARY_CLK, PIN_BED_L_ROTARY_DT), BounceFactory(PIN_BED_L_ROTARY_SWITCH),
  BounceFactory(PIN_BED_L_BUTTON_1), BounceFactory(PIN_BED_L_BUTTON_2), BounceFactory(PIN_BED_L_BUTTON_3),
  lightBedLeft, lightAll
);

Bedside* bedRight = new Bedside(
  new RotaryEncoder(PIN_BED_R_ROTARY_CLK, PIN_BED_R_ROTARY_DT), BounceFactory(PIN_BED_R_ROTARY_SWITCH),
  BounceFactory(PIN_BED_R_BUTTON_1), BounceFactory(PIN_BED_R_BUTTON_2), BounceFactory(PIN_BED_R_BUTTON_3),
  lightBedRight, lightAll
);


void setup() {
  DMXSerial.init(DMXController);

  lightAll->addLight(new Light(30));
  lightAll->addLight(new Light(29));
  lightAll->addLight(new Light(28));
  lightAll->addLight(new Light(27));
  lightAll->addLight(new Light(26));
  lightAll->addLight(new Light(25));
  lightAll->addLight(new Light(24));
  lightAll->addLight(lightBedLeft);
  lightAll->addLight(lightBedRight);
}

void loop() {
  bedLeft->loop();
  bedRight->loop();
}
