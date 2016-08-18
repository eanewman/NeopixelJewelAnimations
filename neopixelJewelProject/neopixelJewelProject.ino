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
// - find RGB values for a color using a color wheel: http://www.colorpicker.com/
// - find the RGB values for a color by name: http://cloford.com/resources/colours/500col.htm

// jewel "frame" states
uint32_t ALL_OFF[7] = {OFF, OFF, OFF, OFF, OFF, OFF, OFF};
uint32_t RAINBOW[7] = {VIOLET, RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO};
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

  // call your animations here to make them run!
 
  // sample animation: heartbeat getting faster -> explosion!
  heartbeat(RED, 500);
  heartbeat(RED, 400);
  heartbeat(RED, 300);
  heartbeat(RED, 250);
  heartbeat(RED, 200);
  heartbeat(RED, 150);
  heartbeat(RED, 100);
  heartbeat(RED, 50);
  explosion(WHITE);
  setPixelColors(ALL_OFF, 400);
}
// *************************************************************************************

// -------------------------------------------------------------------------------------
// Util

// Display a single frame of an animation (this utility function will be useful 
// for building more complicated animations)
// - set all of the colors on the neopixel using the colors parameter
// - pause for the amount of time given by the delayTimeInMs parameter
void setPixelColors(uint32_t colors[], long delayTimeInMs) {
  for (uint8_t pixelIndex = 0; pixelIndex < NUM_JEWEL_PIXELS; pixelIndex++) {
    jewel.setPixelColor(pixelIndex, colors[pixelIndex]);
  }
  jewel.show();
  delay(delayTimeInMs);
}

// -------------------------------------------------------------------------------------
// Heartbeat

// Display a heart shape with the pixels and make them blink once
// - turn the pixels on, wait
// - turn the pixels off, and wait again
void heartBlink(uint32_t color, long delayTimeInMs) {
  // note: the pixel to turn off varies depending on the orientation of your jewel,
  //       so determine which index the top pixel is and turn that pixel off (it
  //       may take a bit of trial and error).
  uint32_t colorsForHeart[7] = {color, color, OFF, color, color, color, color};
  setPixelColors(colorsForHeart, delayTimeInMs);
  setPixelColors(ALL_OFF, delayTimeInMs);
}

// Use the heartBlink() function to simulate a heartbeat 
//    - two beats each lasting a third of the given delay time
//    - pause for entire given delay time
void heartbeat(uint32_t color, long delayTimeInMs) {
  heartBlink(color, delayTimeInMs/3);
  heartBlink(color, delayTimeInMs/3);
  delay(delayTimeInMs);
}

// -------------------------------------------------------------------------------------
// Explosion

// Blink the center pixel to animate the initial part of an explosion
void centerBlink(uint32_t color, long delayTimeInMs) {
  uint32_t centerOnly[7] = {color, OFF, OFF, OFF, OFF, OFF, OFF};
  setPixelColors(centerOnly, delayTimeInMs);
  setPixelColors(ALL_OFF, delayTimeInMs);
}

// Make the pixels blink alternately to animate the end of the explosion
//    - blink 3 alternating pixels on the outer ring, once
//    - blink the remaining 3 pixels on the outer ring and the middle pixel, once
void alternateBlink(uint32_t color, long delayTimeInMs) {
  uint32_t everyOther[7] = {OFF, color, OFF, color, OFF, color, OFF};
  setPixelColors(everyOther, delayTimeInMs);

  uint32_t theOtherEveryOther[7] = {color, OFF, color, OFF, color, OFF, color};
  setPixelColors(theOtherEveryOther, delayTimeInMs);
}

// Use centerBlink() and alternateBlink() to create an explosion animation
void explosion(uint32_t color) {
  for (uint8_t iteration = 0; iteration < 4; iteration++) {
    centerBlink(color, 60);
  }
 
  for (uint8_t iteration = 0; iteration < 10; iteration++) {
    alternateBlink(color, 100);
  }
}

// -------------------------------------------------------------------------------------
// Wave

// Example function using setPixelColors()
// Sends a color from one side of the jewel, through the middle, to the other side.
void wave(uint32_t color, long delayTimeInMs) {
  // set pixels 1, 2 (one side of jewel)
  uint32_t firstStripeColors[7] = {OFF, color, color, OFF, OFF, OFF, OFF};
  setPixelColors(firstStripeColors, delayTimeInMs);

  // set pixels 0, 3, 6 (middle of jewel)
  uint32_t secondStripeColors[7] = {color, OFF, OFF, color, OFF, OFF, color};
  setPixelColors(secondStripeColors, delayTimeInMs);

  // set pixels 4, 5 (other side of jewel)
  uint32_t thirdStripeColors[7] = {OFF, OFF, OFF, OFF, color, color, OFF};
  setPixelColors(thirdStripeColors, delayTimeInMs);
}

// -------------------------------------------------------------------------------------
// Other things to try!

// Tinker with the animations defined above:
// - mix and match different animations in the main execution loop()
// - experiment with changing brightness values during your animations!
// - try modifying the speeds of your animations

// Create your own animations! Here are some ideas:
// - blink a single pixel all the way around the ring of the jewel
// - tricolor wave: same as the wave function above, but with 3 different colors that wrap after they move through the jewel to the other side
// - rotate the RAINBOW array (or an array defined with your colors of choice) around the jewel ring (hint: use the modulo operator!)
