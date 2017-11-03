# P9813

Port of the mbed Seeed RGB LED library for the Grove Chainable RGB LED, which uses the P9813.

**Original mbed library:** https://developer.mbed.org/teams/Seeed/code/Chainable_RGB_LED/

**Seeed Wiki page:** http://wiki.seeed.cc/Grove-Chainable_RGB_LED/

## Example

```c++
#include "mbed.h"
#include "p9813.h"

#define NUM_LEDS 3

P9813 leds(dp6, dp2);
P9813::led_val_t led_data[NUM_LEDS];


int main() {
    leds.clear(NUM_LEDS);
    while(1) {
        // Slowly fade to bright white
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < NUM_LEDS; j++) {
                led_data[j].r = i;
                led_data[j].g = i;
                led_data[j].b = i;
            }

            leds.send(led_data, NUM_LEDS);
            wait(0.02);
        }
    }
}
```
