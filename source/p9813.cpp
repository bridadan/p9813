/*
 * Copyright (C) 2013 Seeed Technology Inc.
 * Copyright (C) 2012 Paulo Marques (pjp.marques@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Information about the P9813 protocol obtained from:
 * http://www.seeedstudio.com/wiki/index.php?title=Twig_-_Chainable_RGB_LED
 *
 * HSB to RGB routine adapted from:
 * http://mjijackson.com/2008/02/rgb-to-hsl-and-rgb-to-hsv-color-model-conversion-algorithms-in-javascript
 *
 * This library is ported from Arduino to mbed
 */

#include "p9813/p9813.h"


// --------------------------------------------------------------------------------------

P9813::P9813(PinName clk_pin, PinName data_pin)
:_spi(data_pin, NC, clk_pin, NC) {
}

void P9813::send(led_val_t *leds, unsigned int length) {
    // Send data frame prefix (32x "0")
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);

    // Send color data for each one of the leds
    for (unsigned int i = 0; i < length; i++) {
        sendColor(leds->rgb[i * 3 + 0], leds->rgb[i * 3 + 1], leds->rgb[i * 3 + 2]);
    }

    // Terminate data frame (32x "0")
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
}

void P9813::clear(unsigned int length) {
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);

    for (int i = 0; i < length; i++) {
        sendColor(0, 0, 0);
    }

    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
    sendByte(0x00);
}

void P9813::sendByte(uint8_t b)
{
    // Send one bit at a time, starting with the MSB
    _spi.write(b);
}

void P9813::sendColor(uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t r67 = ~(red & 0xC0) >> 6;;
    uint8_t g67 = ~(green & 0xC0) >> 4;
    uint8_t b67 = ~(blue & 0xC0) >> 2;
    uint8_t verify = 0xC0 | r67 | g67 | b67;

    sendByte(verify);
    sendByte(blue);
    sendByte(green);
    sendByte(red);
}
