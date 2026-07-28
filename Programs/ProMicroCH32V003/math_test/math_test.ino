#include <WebHID.h>
#include <Mouse.h>
#include <math.h>

void setup() {
  for (int i = 0; i < 10; i++) {
    volatile float a = sin(i * DEG_TO_RAD);
  }
}

void loop() {
}