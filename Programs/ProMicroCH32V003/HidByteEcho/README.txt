HidByteEcho for UIAPduino Pro Micro CH32V003

使い方:
1. Arduino IDE で HidByteEcho.ino を開く
2. ボードに UIAPduino Pro Micro CH32V003 を選ぶ
3. 通常どおりコンパイル/書き込みする
4. 起動後に WebLink-USBUnstable の t タブで接続し、送った文字がそのまま返るか確認する

構成:
- HidByteEcho.ino        : スケッチ本体
- ch32fun.h             : ch32fun 由来ヘッダ
- funconfig.h           : ch32fun / rv003usb 設定
- usb_config.h          : USB descriptor / pin 設定
- src/uiapusb.*         : 最小API
- src/rv003usb/*        : USB本体ソース
- src/lib/*             : rv003usb 依存ヘッダ

注記:
- .a は使っていません
- ソースのまま Arduino IDE でビルドする前提です
