#include <Adafruit_NeoPixel.h>

#define ARDUINO_PIN_NUMBER 6
#define NUM_JEWEL_PIXELS 7

// initialize neopixel jewel object
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(NUM_JEWEL_PIXELS, ARDUINO_PIN_NUMBER, NEO_GRB + NEO_KHZ800);

// colors 
const uint32_t RED = jewel.Color(255, 0, 0);
const uint32_t GREEN = jewel.Color(0, 255, 0);
const uint32_t BLUE = jewel.Color(0, 0, 255);
const uint32_t PINK = jewel.Color(236, 79, 100);
const uint32_t YELLOW = jewel.Color(255, 255, 0);
const uint32_t WHITE = jewel.Color(255, 255, 255);
const uint32_t ORANGE = jewel.Color(255, 165, 0);
const uint32_t PURPLE = jewel.Color(91, 44, 86);
const uint32_t INDIGO = jewel.Color(75, 0, 130);
const uint32_t VIOLET = jewel.Color(238, 130, 238);
const uint32_t OFF = 0;
// add more colors here! 
// use http://www.colorpicker.com/ to find RGB values for a color using a color wheel
// use http://cloford.com/resources/colours/500col.htm to find the RGB values for a color by name

// jewel "frame" states
const uint32_t ALL_OFF[7] = {OFF, OFF, OFF, OFF, OFF, OFF, OFF};
const uint32_t RAINBOW[7] = {VIOLET, RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO};
// add more frame states here!

void setup() {
  jewel.begin();
  jewel.show(); // initialize all pixels to 'off'
}

void loop() {
  // experiment with the brightness value here! 
  // you can also tinker with different brightness values in your animations
  jewel.setBrightness(10);

  // call your animations here!
  
}

// -------------------------------------------------------------------------------------
// I. Warm up

// 1. Turn all pixels the color that was passed in
void setPixelsSingleColor(uint32_t color) {

}

// 2. Make all the pixels blink once 
void allBlink(uint32_t color, long delayTimeInMs) {

}

// -------------------------------------------------------------------------------------
// II. Utility Function

// 1. Display a single frame of an animation (this utility function will be useful for building more complicated animations)
//    - set all of the colors on the neopixel using the colors parameter
//    - pause for the amount of time given by the delayTimeInMs parameter
void setPixelColors(const uint32_t colors[], long delayTimeInMs) {

}

// -------------------------------------------------------------------------------------
// III. Heartbeat

// 1. Display a heart shape with the pixels and make them blink once
void heartBlink(uint32_t color, long delayTimeInMs) {
  
}

// 2. Use the heartBlink() function to simulate a heartbeat 
//    - two beats each lasting a third of the given delay time
//    - pause for the full delay time
void heartbeat(uint32_t color, long delayTimeInMs) {
  
}


// -------------------------------------------------------------------------------------
// IV. Explosion!

// 1. Blink the center pixel to animate the initial part of an explosion
void centerBlink(uint32_t color, long delayTimeInMs) {
  
}

// 2. Make the pixels blink alternately to animate the end of the explosion
//    - blink 3 alternating pixels on the outer ring, once
//    - blink the remaining 3 pixels on the outer ring and the middle pixel, once
void alternateBlink(uint32_t color, long delayTimeInMs) {
  
}

// 3. Use centerBlink() and alternateBlink() to create an explosion animation!
void explosion(uint32_t color) {
  
}


// -------------------------------------------------------------------------------------
// V. Create an exploding heart animation! 

// Use your heartbeat() and explosion() functions in the main execution loop to create
// a heartbeat that increases in tempo until it explodes!


// -------------------------------------------------------------------------------------
// Other things to try

// Tinker with your animations:
// - experiment with changing brightness values during your animations!
// - try modifying the speeds of your animations
// - mix and match different animations in the main execution loop()

// Create your own animations!! Here are some ideas:
// - blink a single pixel all the way around the ring of the jewel
// - do the 'wave': blink 2 adjacent pixels on the outside, then the 3 next to them, and then the 2 on the opposite side.
// - tricolor wave: same as the wave function above, but with 3 colors that wrap after they move through the jewel to the other side.
// - rotate the RAINBOW array (or an array defined with your colors of choice) around the jewel ring (hint: the modulo operator helps!)


