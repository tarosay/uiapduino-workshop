/**
 * MousePractice
 *
 * ボード:   HID ProMicro CH32V003 KBD+Mouse
 * バージョン: V1.4 + WebHID (EP3)
 *
 * 使い方:
 *   mouse.html の「UIAPduino で実行」ボタンを押すと
 *   buf[1] にステップ番号（1〜4）が入って届く。
 *
 * 注意:
 *   マウスは相対移動なので、実行前にブラウザ上の START 円の中心へ
 *   実マウスでカーソルを置いてから実行する。
 */

#include <WebHID.h>
#include <Mouse.h>
#include <math.h>

#define LED_BUILTIN 2

static const int STEP_WAIT_MS = 8;

void releaseAllMouse() {
  Mouse.release(MOUSE_LEFT);
  Mouse.release(MOUSE_RIGHT);
  Mouse.release(MOUSE_MIDDLE);
  delay(20);
}

void practice1() {
  digitalWrite(LED_BUILTIN, HIGH);
  const int sx = 93;
  const int sy = 314;
  const int bx = 543;
  const int by = 110;

  Mouse.moveLarge(bx - sx, by - sy, 0, 60);
  delay(50);
  Mouse.click(MOUSE_LEFT);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  WebHID.begin();
  Mouse.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  releaseAllMouse();
  delay(1000);
}

void loop() {
  uint8_t buf[16];
  uint8_t len = WebHID.recv(buf, sizeof(buf));

  if (len > 0) {
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(1000);
    //digitalWrite(LED_BUILTIN, LOW);

    releaseAllMouse();
    delay(300);

    switch (buf[1]) {
      case 1:
        practice1();
        break;

      case 2:
        //practice2();
        break;

      case 3:
        //practice3();
        break;

      case 4:
        //practice4();
        break;
    }

    releaseAllMouse();
    delay(150);
  }
}
