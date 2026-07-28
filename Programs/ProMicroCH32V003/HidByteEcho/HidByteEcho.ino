extern "C" {
#include "src/uiapusb.h"
}

static uint8_t buf[64];

void setup() {
  uiapusb_begin();
}

void loop() {
  int n = uiapusb_read(buf, sizeof(buf));
  if (n > 0) {
    uiapusb_write(buf, n);
  }
}
