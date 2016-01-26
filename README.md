# P9813

Port of the mbed Seeed RGB LED library for the Grove Chainable RGB LED, which uses the P9813.

**Original mbed library:** https://developer.mbed.org/teams/Seeed/code/Chainable_RGB_LED/

**Seeed Wiki page:** http://www.seeedstudio.com/wiki/index.php?title=Twig_-_Chainable_RGB_LED

## API

### P9813(PinName clk_pin, PinName data_pin, uint32_t number_of_leds)

Constructor for the library

  - `clk_pin` - mbed pin that is connected to the "Clock In" pin
  - `clk_pin` - mbed pin that is connected to the "Data In" pin
  - `number_of_leds` - Number of LEDs chained together

### void setColorRGB(uint32_t led, uint8_t red, uint8_t green, uint8_t blue)

Set the color of an individual LED using RGB values

  - `led` - Index of the LED (starting with `0`)
  - `red` - Intensity of the red LED (`0` - `255`)
  - `green` - Intensity of the green LED (`0` - `255`)
  - `blue` - Intensity of the blue LED (`0` - `255`)

### void setColorHSB(uint32_t led, float hue, float saturation, float brightness)

Set the color of an individual LED using HSB values

  - `led` - Index of the LED (starting with `0`)
  - `hue` - Hue component of the RGB LED (`0.0` - `1.0`)
  - `saturation` - Saturation component of the RGB LED (`0.0` - `1.0`)
  - `brightness` - Brightness component of the RGB LED (`0.0` - `1.0`)

###  void ledsOff()

Turn off all of the LEDs