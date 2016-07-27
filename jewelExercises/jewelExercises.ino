#include <Adafruit_NeoPixel.h>

#define ARDUINO_PIN_NUMBER 6
#define NUM_PIXELS_IN_JEWEL 7

// initialize neopixel jewel
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(NUM_PIXELS_IN_JEWEL, ARDUINO_PIN_NUMBER, NEO_GRB + NEO_KHZ800);

// colors
uint32_t RED = jewel.Color(255, 0, 0);
uint32_t GREEN = jewel.Color(0, 255, 0);
uint32_t BLUE = jewel.Color(0, 0, 255);
uint32_t PINK = jewel.Color(236, 79, 100);
uint32_t CREAM = jewel.Color(246, 216, 180);
uint32_t PURPLE = jewel.Color(91, 44, 86);
uint32_t YELLOW = jewel.Color(255, 255, 0);
uint32_t SKY_BLUE = jewel.Color(0, 255, 251);
uint32_t SEA_GREEN = jewel.Color(110, 255, 148);
uint32_t WHITE = jewel.Color(255, 255, 255);
uint32_t ORANGE = jewel.Color(255, 165, 0);
uint32_t INDIGO = jewel.Color(75, 0, 130);
uint32_t VIOLET = jewel.Color(238, 130, 238);

// pixel state
uint32_t ALL_OFF[7] = {0, 0, 0, 0, 0, 0, 0};
uint32_t RAINBOW[7] = {VIOLET, RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO};

void setup() {
  jewel.begin();
  jewel.setBrightness(10);
  jewel.show(); // Initialize all pixels to 'off'
}

void loop() {
//    drawCircle(RED, 150);
  //  drawCircle(BLUE, 150);
  //  drawCircle(GREEN, 150);

//    circlingPixel(WHITE, 75);

//    wave(SEA_GREEN, 150);
  //  wave(GREEN, 150);
  //  wave(BLUE, 150);
    
    heartbeat(PINK, 600);
    heartbeat(PINK, 500);
    heartbeat(PINK, 400);
    heartbeat(PINK, 300);
    heartbeat(PINK, 200);
    heartbeat(PINK, 200);
    heartbeat(PINK, 100);
    heartbeat(PINK, 50);
    heartbeat(PINK, 50);

  //glitterRing(RED, 100, 5);
  //centerBlink(GREEN, 50);
  
//    fireworks(PURPLE);
    rainbowFireworks(100);
     delay(400);
  //  fireworks(GREEN);
  //  fireworks(BLUE);

//  tricolorWave(400);

//  drawRainbowCircle(200);

//  travelingRainbow(80);
}

// --------------------------------------------------------------------------------------------
// Blink a certain color around the outside of the jewel
void drawCircle(uint32_t color, uint8_t wait) {
  for (uint8_t pixelInd = 1; pixelInd < NUM_PIXELS_IN_JEWEL; pixelInd++) {
    jewel.setPixelColor(pixelInd, color);
    jewel.show();
    delay(wait);
  }
}

void circlingPixel(uint32_t color, uint8_t wait) {
  for (uint8_t pixelInd = 1; pixelInd < NUM_PIXELS_IN_JEWEL; pixelInd++) {
    uint32_t pixelColors[7] = {0, 0, 0, 0, 0, 0, 0};
    pixelColors[pixelInd] = color;
    setColors(pixelColors, wait);
  }
}

// --------------------------------------------------------------------------------------------
// Rainbow stuff!
void drawRainbowCircle(uint8_t wait) {
  setColors(RAINBOW, wait);
}

void travelingRainbow(long wait) {
  for (uint8_t rotateAmt = 0; rotateAmt < NUM_PIXELS_IN_JEWEL; rotateAmt++) {
    for (uint8_t pixelInd = 0; pixelInd < NUM_PIXELS_IN_JEWEL; pixelInd++) {
      jewel.setPixelColor(pixelInd, RAINBOW[(pixelInd + rotateAmt) % NUM_PIXELS_IN_JEWEL]);
    }
    jewel.show();
    delay(wait);
  }
}

// --------------------------------------------------------------------------------------------
// Simulate a heartbeat!
void heartbeat(uint32_t color, long wait) {
  heartBlink(color, wait/3);
  heartBlink(0, wait/3);
  heartBlink(color, wait/3);
  heartBlink(0, wait/3);
  delay(wait);
}

void heartBlink(uint32_t color, long wait) {
  // 0, 1, 2, 3, 5, 6
  uint32_t colorsFirst[7] = {color, color, color, color, 0, color, color};
  setColors(colorsFirst, wait);
}

// --------------------------------------------------------------------------------------------
// Do the wave!

void tricolorWave(long wait) {
  // R B G
  uint32_t colorsFirst[7] = {BLUE, RED, RED, BLUE, GREEN, GREEN, BLUE};
  setColors(colorsFirst, wait);

  // G R B
  uint32_t colorsSecond[7] = {RED, GREEN, GREEN, RED, BLUE, BLUE, RED};
  setColors(colorsSecond, wait);

  // B G R
  uint32_t colorsThird[7] = {GREEN, BLUE, BLUE, GREEN, RED, RED, GREEN};
  setColors(colorsThird, wait);
}

// Send a color from one side of the jewel, through the middle, to the other side
void wave(uint32_t color, long wait) {
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

void glitterWave(uint32_t color, long wait) {
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
}

void rainbowFireworks(long wait) {
  for (uint8_t numFlashes = 0; numFlashes < 4; numFlashes++) {
    centerBlink(RAINBOW[0], wait/2);
  }
  for (uint8_t numFlashes = 0; numFlashes < 10; numFlashes++) {
    // every other
    uint32_t colorsFirst[7] = {0, RAINBOW[1], 0, RAINBOW[3], 0, RAINBOW[5], 0};
    setColors(colorsFirst, wait);

    // opposite every other
    uint32_t colorsSecond[7] = {0, 0, RAINBOW[2], 0, RAINBOW[4], 0, RAINBOW[6]};
    setColors(colorsSecond, wait);
  }
  setColors(ALL_OFF, wait);
}

void centerBlink(uint32_t color, long wait) {
  // center on
  uint32_t centerOnly[7] = {color, 0, 0, 0, 0, 0, 0};
  setColors(centerOnly, wait);

  // center off
  setColors(ALL_OFF, wait);
}

void glitterRing(uint32_t color, long wait, uint8_t totalIterations) {
  for (uint8_t numFlashes = 0; numFlashes < totalIterations; numFlashes++) {
    // every other
    uint32_t colorsFirst[7] = {0, color, 0, color, 0, color, 0};
    setColors(colorsFirst, wait);

    // opposite every other
    uint32_t colorsSecond[7] = {0, 0, color, 0, color, 0, color};
    setColors(colorsSecond, wait);
  }
}

void glitterRing2(uint32_t color, long wait, uint8_t totalIterations) {
  for (uint8_t numFlashes = 0; numFlashes < totalIterations; numFlashes++) {
    // every other
    for (int ind = 1; ind < NUM_PIXELS_IN_JEWEL; ind++) {
      // introducing the modulo operator!
      if (ind % 2 == 0) {
        jewel.setPixelColor(ind, color);
      }
    }
    jewel.show();
    delay(wait);

    // the other every other
    for (int ind = 1; ind < NUM_PIXELS_IN_JEWEL; ind++) {
      // introducing the modulo operator!
      if (ind % 2 == 1) {
        jewel.setPixelColor(ind, color);
      }
    }
    jewel.show();
    delay(wait);
  }
}

// --------------------------------------------------------------------------------------------
// Util!

// sets each pixel color on the jewel and waits the specified time
void setColors(uint32_t colors[], long wait) {
  for (uint8_t ind = 0; ind < jewel.numPixels(); ind++) {
    jewel.setPixelColor(ind, colors[ind]);
  }
  jewel.show();
  delay(wait);
}

// blinks the jewel pixel colors for each led set
void sparkleColors(uint32_t colors[], uint8_t wait) {
  // TODO: divvy up wait time and blink those that are on
}



