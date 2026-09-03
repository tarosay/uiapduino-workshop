#include <Adafruit_NeoPixel.h>

// WS2812BのDINを接続する端子番号
#define LED_PIN 9

// LEDの個数
#define LED_COUNT 12

// NeoPixelの設定
Adafruit_NeoPixel pixels(
  LED_COUNT,
  LED_PIN,
  NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(50);  // 明るさ 0～255
  pixels.show();
}

void loop() {
  // 赤色を順番に点灯
  for (int i = 0; i < LED_COUNT; i++) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    delay(20);
  }

  // 緑色を順番に点灯
  for (int i = 0; i < LED_COUNT; i++) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(20);
  }

  // 青色を順番に点灯
  for (int i = 0; i < LED_COUNT; i++) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(20);
  }

  for (int i = 10; i < 256; i++) {
    pixels.clear();
    for (int j = 0; j < LED_COUNT; j++) {
      pixels.setPixelColor(j, pixels.Color(i, i, i));
    }
    pixels.show();
    delay(2);
  }
  for (int i = 255; i >= 10; i--) {
    pixels.clear();
    for (int j = 0; j < LED_COUNT; j++) {
      pixels.setPixelColor(j, pixels.Color(i, i, i));
    }
    pixels.show();
    delay(2);
  }
}