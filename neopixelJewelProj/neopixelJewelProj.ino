#include <Adafruit_NeoPixel.h>

#define ARDUINO_PIN_NUMBER 6
#define NUM_JEWEL_PIXELS 7

// initialize neopixel jewel
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


// *************************************************************************************
// main execution loop -- this is the code that your arduino will run
// *************************************************************************************
void loop() {
  // experiment with the brightness value here! 
  // you can also tinker with different brightness values in your animations
  jewel.setBrightness(10);

  // call your animations here!

}
// *************************************************************************************


// -------------------------------------------------------------------------------------
// I. Warm up

// 1. Turn all pixels on using the color passed in
void setPixelsSingleColor(uint32_t color) {
  
}

// 2. Make all the pixels blink once using allOn()
void allBlink(uint32_t color, long delayTimeInMs) {
  
}

// 3. Display a single frame of an animation (utility function that's useful for building more complicated animations)
//    - set all of the colors on the neopixel using the colors array parameter
//    - pause for the amount of time given by the delayTimeInMs parameter
void setPixelColors(uint32_t colors[], long delayTimeInMs) {
  
}

// 4. Example function using setPixelColors()
// Sends a color from one side of the jewel, through the middle, to the other side.
// Try calling this function in the main execution loop!
void wave(uint32_t color, long wait) {
  // set pixels 1, 2
  uint32_t firstStripeColors[7] = {OFF, color, color, OFF, OFF, OFF, OFF};
  setPixelColors(firstStripeColors, wait);

  // pixels 0, 3, 6
  uint32_t secondStripeColors[7] = {color, OFF, OFF, color, OFF, OFF, color};
  setPixelColors(secondStripeColors, wait);

  // pixels 4, 5
  uint32_t thirdStripeColors[7] = {OFF, OFF, OFF, OFF, color, color, OFF};
  setPixelColors(thirdStripeColors, wait);
}


// -------------------------------------------------------------------------------------
// II. Heartbeat

// 1. Display a heart shape with the pixels and make them blink once
void heartBlink(uint32_t color, long delayTimeInMs) {
  
}

// 2. Use the heartBlink() function to simulate a heartbeat 
//    - two beats each lasting a third of the given delay time
//    - pause
void heartbeat(uint32_t color, long delayTimeInMs) {
  
}


// -------------------------------------------------------------------------------------
// III. Explosion!

// 1. Blink the center pixel to animate the initial part of an explosion
void centerBlink(uint32_t color, long delayTimeInMs) {
  
}

// 2. Make the outer pixels blink alternately to animate the end of the explosion
//    - blink 3 alternating pixels on the outer ring, once
//    - blink the remaining 3 pixels on the outer ring, once
void alternateBlink(uint32_t color, long delayTimeInMs) {
  
}

// 3. Use centerBlink() and alternateBlink() to create an explosion animation!
void explosion(uint32_t color) {
  
}


// -------------------------------------------------------------------------------------
// Other things to try!

// Tinker with your animations
// - experiment with changing brightness values during your animations!
// - try modifying the speeds of your animations
// - mix and match different animations in the main execution loop()

// Create your own animations!! Some ideas:
// - blink a single pixel all the way around the ring of the jewel
// - do the wave! start with any 2 adjacent pixels on the outside, then light up the 3 next to it, then the 2 on the other side
// - tricolor wave: same as the one above, but with 3 colors that wrap after they move through the jewel to the other side
// - rotate the RAINBOW array (or an array defined with your colors of choice) around the jewel ring (hint: the modulo operator helps!)


