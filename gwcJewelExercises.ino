#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);

uint32_t PINK = jewel.Color(236, 79, 100);
uint32_t CREAM = jewel.Color(246, 216, 180);
uint32_t LAVENDER = jewel.Color(174, 113, 208);
uint32_t PURPLE = jewel.Color(91, 44, 86);

uint32_t RED = jewel.Color(255, 0, 0);
uint32_t GREEN = jewel.Color(0, 255, 0);
uint32_t BLUE = jewel.Color(0, 0, 255);

void setup() {
  jewel.begin();
  jewel.setBrightness(80);
  jewel.show(); // Initialize all pixels to 'off'
}

void loop() {
  //  drawCircle(RED, 150);
  //  drawCircle(BLUE, 150);
  //  drawCircle(GREEN, 150);

  //  fireworks(RED);
  //  fireworks(GREEN);
  //  fireworks(BLUE);

  //  wave(RED, 150);
  //  wave(GREEN, 150);
  //  wave(BLUE, 150);

//    heartbeat(PINK, 600);
    heartbeat(PINK, 200);

  //glitterRing(RED, 100, 5);
  //centerBlink(GREEN, 50);
  //circlingPixel(BLUE, 75);

//  tricolorWave(250);
}

// --------------------------------------------------------------------------------------------
// Blink a certain color around the outside of the jewel
void drawCircle(uint32_t color, uint8_t wait) {
  for (uint8_t pixelInd = 1; pixelInd < jewel.numPixels(); pixelInd++) {
    jewel.setPixelColor(pixelInd, color);
    jewel.show();
    delay(wait);
  }
}

void circlingPixel(uint32_t color, uint8_t wait) {
  for (uint8_t pixelInd = 1; pixelInd < jewel.numPixels(); pixelInd++) {
    uint32_t pixelColors[7] = {0, 0, 0, 0, 0, 0, 0};
    pixelColors[pixelInd] = color;
    setColors(pixelColors, wait);
  }
}

// --------------------------------------------------------------------------------------------
// Simulate a heartbeat!
void heartbeat(uint32_t color, uint8_t wait) {
  heartBlink(color, 100);
  heartBlink(0, 100);
  heartBlink(color, 100);
  heartBlink(0, 100);
  delay(wait);
}

void heartBlink(uint32_t color, uint8_t wait) {
  // 0, 1, 2, 3, 5, 6
  uint32_t colorsFirst[7] = {color, color, color, color, 0, color, color};
  setColors(colorsFirst, wait);
}

// --------------------------------------------------------------------------------------------
// Do the wave!

void tricolorWave(uint8_t wait) {
  jewel.setPixelColor(0, BLUE);
  jewel.setPixelColor(1, RED);
  jewel.setPixelColor(2, RED);
  jewel.setPixelColor(3, BLUE);
  jewel.setPixelColor(4, GREEN);
  jewel.setPixelColor(5, GREEN);
  jewel.setPixelColor(6, BLUE);
  jewel.show();
  delay(wait);
  delay(wait);
  
//  jewel.setPixelColor(0, RED);
//  jewel.setPixelColor(1, GREEN);
//  jewel.setPixelColor(2, GREEN);
//  jewel.setPixelColor(3, RED);
//  jewel.setPixelColor(4, BLUE);
//  jewel.setPixelColor(5, BLUE);
//  jewel.setPixelColor(6, RED);
//  jewel.show();
//  delay(wait);
//  delay(wait);
//
//  jewel.setPixelColor(0, GREEN);
//  jewel.setPixelColor(1, BLUE);
//  jewel.setPixelColor(2, GREEN);
//  jewel.setPixelColor(3, GREEN);
//  jewel.setPixelColor(4, RED);
//  jewel.setPixelColor(5, RED);
//  jewel.setPixelColor(6, GREEN);
//  jewel.show();
//  delay(wait);
//  delay(wait);

  
//  // R B G
//  uint32_t colorsFirst[7] = {BLUE, RED, RED, BLUE, GREEN, GREEN, BLUE};
//  setColors(colorsFirst, wait);
//
//  // G R B
//  uint32_t colorsSecond[7] = {RED, GREEN, GREEN, RED, BLUE, BLUE, RED};
//  setColors(colorsSecond, wait);
//
//  // B G R
//  uint32_t colorsThird[7] = {GREEN, BLUE, BLUE, GREEN, RED, RED, GREEN};
//  setColors(colorsThird, wait);
}

// Send a color from one side of the jewel, through the middle, to the other side
void wave(uint32_t color, uint8_t wait) {
  // 1, 2
  uint32_t colorsFirst[7] = {0, color, color, 0, 0, 0, 0};
  setColors(colorsFirst, wait);

  // 0, 3, 6
  uint32_t colorsSecond[7] = {color, 0, 0, color, 0, 0, color};
  setColors(colorsSecond, wait);

  // 4, 5
  uint32_t colorsThird[7] = {0, 0, 0, 0, color, color, 0};
  setColors(colorsThird, wait);
}

void glitterWave(uint32_t color, uint8_t wait) {
  // TODO
}

//void multicolorWave(uint32_t colors[], uint8_t wait) {
//  // get size of colors array
//  uint8_t colorsSizeBytes = sizeof(colors);
//  if (sizeof(colors) <= 0) {
//    return;
//  } 
//  uint8_t colorsElementSizeBytes = sizeof(colors[0]);
//  uint8_t numColors = colorSizeBytes/colorsElementSizeBytes;
//  
//  for (uint8_t colorInd = 0; colorInd<colorsSize; colorInd++) {
//    // 1, 2
//    uint32_t color1 = colors[colorInd];
//    uint32_t colorsFirst[7] = {0, color1, color1, 0, 0, 0, 0};
//    // 0, 3, 6
//    
//    setColors(colorsFirst, wait);
//  }
//}

// --------------------------------------------------------------------------------------------
// Fireworks!

void fireworks(uint32_t color) {
  for (uint8_t numFlashes = 0; numFlashes < 4; numFlashes++) {
    centerBlink(color, 50);
  }
  glitterRing(color, 100, 5);
  jewel.show();
  delay(150);
}

void centerBlink(uint32_t color, uint8_t wait) {
  // center on
  uint32_t centerOnly[7] = {color, 0, 0, 0, 0, 0, 0};
  setColors(centerOnly, wait);

  // center off
  uint32_t allOff[7] = {0, 0, 0, 0, 0, 0, 0};
  setColors(allOff, wait);
}

void glitterRing(uint32_t color, uint8_t wait, uint8_t totalIterations) {
  for (uint8_t numFlashes = 0; numFlashes < totalIterations; numFlashes++) {
    // every other
    uint32_t colorsFirst[7] = {0, color, 0, color, 0, color, 0};
    setColors(colorsFirst, wait);

    // opposite every other
    uint32_t colorsSecond[7] = {0, 0, color, 0, color, 0, color};
    setColors(colorsSecond, wait);
  }
}

// --------------------------------------------------------------------------------------------
// Util!

// sets the jewel pixel colors for each led
void setColors(uint32_t colors[], uint8_t wait) {
  for (uint8_t ind = 0; ind < jewel.numPixels(); ind++) {
    jewel.setPixelColor(ind, colors[ind]);
  }
  jewel.show();
  delay(wait);
}

// blinks the jewel pixel colors for each led set
void sparkleColors(uint32_t colors[], uint8_t wait) {

}



