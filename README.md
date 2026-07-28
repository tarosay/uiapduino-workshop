# uiapduino-workshop

**マイコンC言語基礎講座**（2026年7月27日開催）の資料・スケッチ一式です。

UIAPduino（CH32V003 を使った HID 対応マイコンボード、290円）を使って、
C言語の基礎からアルゴリズムまでを体験する講習会の教材をまとめています。

- 🌐 練習ページ: **[UIAPduino WebHID Lab](https://tarosay.github.io/uiap-hid-web/)**
- 💬 アフターフォロー: **[Discord「コンピュータを楽しもう」](https://discord.gg/EF3kAU3XT)**

---

## 講習の流れ

資料は `Documents/マイコンC言語基礎講座.pdf`（全123枚）です。
前半は実機だけで進み、後半はブラウザ（WebHID）と組み合わせて進みます。

| 部 | スライド | 内容 | 学ぶC言語 |
|---|---|---|---|
| — | 1–44 | マイコンとは／部材／ArduinoIDE／Lチカ／キーボードを作る | `#define` `setup()` `loop()` `pinMode` `digitalWrite` `delay` `#include` `if` |
| 第2部 | 45–55 | WebHID とは／Echo Test | 双方向通信の考え方 |
| 第3部 | 56–75 | HID Console／**.h と .cpp の分割** | 変数と型・演算・`for`・配列・`class`・`#ifndef`・`extern` |
| 第4部 | 76–88 | Keyboard Practice 1 / 2 | コメント `//`・**`switch` 文**・`break`・エラーの読み方 |
| 第5部 | 89–102 | Snake Solver | **二次元配列**・**BFS**・参照渡し `&` |
| 第6部 | 103–118 | Snake VS（CPU 5段ラダー） | **ボロノイ**・ミニマックス・RAM の節約 |
| — | 119–123 | 残り時間の挑戦／アフターフォロー | — |

**構成の意図**：文法を先に教えるのではなく、「不便だ」と感じてから道具を渡す順にしています。
たとえば `switch` は、Keyboard Practice 1 でステップごとに書き込み直す面倒を体験してから導入します。

前半で置いた話は後半で回収されます。

- 第3部「RAM は 2048 バイトしかないから型を選ぶ」 → 第6部「`bool` 3枚 768B を `uint8_t` 1枚 256B に」
- 第3部「通信は `.h` に押し込む」 → 第5部 `SnakeHID.h` → 第6部 `SnakeVSHID.h`
- 第4部「`switch` と `break`」 → 第5部 `switch (buf[0])`
- 第5部「BFS 最大空間優先」 → 第6部「それが CPU Lv3。だから Lv4 に勝てない」

---

## 使用する部材

| 品目 | 型番・備考 | 入手先 |
|---|---|---|
| マイコン | UIAPduino（HID ProMicro CH32V003）290円 | https://www.switch-science.com/products/9914 |
| ブレッドボード | EIC-801 | https://akizukidenshi.com/catalog/g/g100315/ |
| マイコン基板用ピンヘッダ | 必要な分を折って使う | https://akizukidenshi.com/catalog/g/g100167/ |
| コネクター付ケーブル（オス-オス） | 一本ずつ切り離して使う | https://akizukidenshi.com/catalog/g/g115869/ |
| USB ケーブル | Type-A → Type-C | https://akizukidenshi.com/catalog/g/g117017/ |
| タクトスイッチ | 押すとオンする | https://akizukidenshi.com/catalog/g/g103649/ |

UIAPduino は足を上にそろえ、まっすぐ縦にブレッドボードへ挿します。
LED は **Pin-2**、タクトスイッチは **GND と Pin-3** につなぎます（押すと Pin-3 が LOW）。

---

## 事前準備

1. Arduino IDE をインストール（手順書は当日配布）
2. ボードパッケージ `UIAP_HID:ch32v` を Board Manager から追加
   （[arduino_core_ch32](https://github.com/tarosay/arduino_core_ch32) 参照）
3. ブラウザは **Chrome または Edge**（WebHID は Firefox・Safari では動きません）

詳細は `Documents/マイコンC言語基礎講座の事前準備など.pdf` にあります。

書き込みは、**UIAPduino のボタンを押しながら USB を挿し、挿したらすぐ離す** → 書き込みボタン、の手順です。

---

## 使用するスケッチ

`Sketches/` にソース、`Sketches/zip/` に配布用 ZIP を置いています。
**ZIP には `sketch.yaml` が入っているので、展開して開けばボード設定が自動で入ります。**

| スケッチ | Tools → USB | 入手方法 | 対応する Lab ページ |
|---|---|---|---|
| `Blink` | Keyboard+Mouse | スケッチ例 → **HID** → Blink | —（Lチカ） |
| `A_Key` | Keyboard+Mouse | 講習中に手で打ち込む | —（キーボードを作る） |
| `WebHIDTest` | Keyboard+Mouse+WebHID | スケッチ例 → **WebHID** → WebHIDTest | [Echo Test](https://tarosay.github.io/uiap-hid-web/echo.html) |
| `HidPrint` | Keyboard+Mouse+WebHID | ページから ZIP ダウンロード | [HID Console](https://tarosay.github.io/uiap-hid-web/hid-console.html) |
| `KeyboardPractice` | Keyboard+Mouse+WebHID | スケッチ例 → **Keyboard** → KeyboardPractice | [Keyboard Practice](https://tarosay.github.io/uiap-hid-web/keyboard.html) |
| `KeyboardSwitch` | Keyboard+Mouse+WebHID | スケッチ例 → **Keyboard** → KeyboardSwitch | [Keyboard Practice 2](https://tarosay.github.io/uiap-hid-web/keyboard2.html) |
| `SnakeSolver` | **WebHID Only** | ページから ZIP ダウンロード | [Snake Solver](https://tarosay.github.io/uiap-hid-web/snake.html) |
| `SnakeVS` | **WebHID Only** | ページから ZIP ダウンロード | [Snake VS](https://tarosay.github.io/uiap-hid-web/snake-vs.html) |
| `RockDodge` | **WebHID Only** | ページから ZIP ダウンロード | [Rock Dodge](https://tarosay.github.io/uiap-hid-web/rock-dodge.html) |
| `MazeSolver` | Keyboard+Mouse+WebHID | ページから ZIP ダウンロード | [Maze Solver](https://tarosay.github.io/uiap-hid-web/maze-solver.html) |

### ⚠️ USB 設定の切り替えに注意

Snake 系（`SnakeSolver` / `SnakeVS` / `RockDodge`）だけ **WebHID Only** です。
`MazeSolver` に移るときは **Keyboard+Mouse+WebHID** に戻す必要があります。
講習中にいちばん詰まりやすいポイントなので、資料でも都度明記しています。

なお `WebHID.h` を使うスケッチを `Keyboard+Mouse`（WebHID なし）でビルドすると、
次のエラーで止まります。設定間違いはここで気づけます。

```
#error "WebHID ライブラリを使うには: Tools > USB > WebHID Only または Keyboard+Mouse+WebHID を選択してください"
```

### ビルド確認済み

全スケッチを arduino-cli で `sketch.yaml` の FQBN のままビルドし、Flash 使用量を確認しています。

| スケッチ | Flash | スケッチ | Flash |
|---|---|---|---|
| `Blink` | 3,936 B (24%) | `SnakeSolver` | 3,744 B (22%) |
| `A_Key` | 5,460 B (33%) | `SnakeVS` | 4,544 B (27%) |
| `WebHIDTest` | 5,928 B (36%) | `RockDodge` | 4,336 B (26%) |
| `HidPrint` | 5,368 B (32%) | `MazeSolver` | 4,100 B (25%) |
| `KeyboardPractice` | 4,712 B (28%) | `KeyboardSwitch` | 5,008 B (30%) |

CH32V003 の Flash 上限は 16,384 バイト、RAM は 2,048 バイトです。

---

## 挑戦課題

講習の残り時間や、持ち帰ってからの課題です。

| 課題 | 目標 |
|---|---|
| **Snake VS** | 配布スケッチは CPU Lv3 と互角、Lv4（ボロノイ）で止まる。ボロノイを実装して Lv4 を倒す |
| **Snake VS 2P** | 2台の UIAPduino を直接対戦させる。ランキングは連勝記録 |
| **Rock Dodge** | セーフティラインに乗るだけではノルマ未達。どこまで稼ぎに出るかの採算判断が勝負 |
| **Maze Solver** | `solveMaze()` に右手法 → DFS → BFS と実装を上げていく |

各ページにヒントが段階的に用意されています（最終段のコードだけは伏せてあります）。

`SnakeVS` と `RockDodge` は `#define PLAYER_NAME` に自分の名前（半角英数12文字まで）を
書き込んで使います。2台で対戦するときは、**必ずお互い違う名前**にしてください。

---

## リポジトリ構成

```
Documents/            公開する資料（PDF・画像）
Sketches/             講習で使うスケッチ一式
  <スケッチ名>/       ソース（各フォルダに sketch.yaml 付き）
  zip/                配布用 ZIP（Lab ページの「ZIPダウンロード」と同じ構成）
  sync_from_lab.py    uiap-hid-web から同期して ZIP を作り直すスクリプト
Programs/
  ProMicroCH32V003/   講習では使わない実験用スケッチ、ピンアサイン図、回路図 PDF
Schematic/            UIAPduino の回路図・基板データ
Private/              非公開（.gitignore 済み。リポジトリには入りません）
```

**資料は PDF で公開しています。** 編集用の pptx は `Private/` に置いてあり、
リポジトリには含まれません。会場・日時などの運営情報、原価を含む部品リスト、
別講座の資料も同じく `Private/` です。

Lab 側のスケッチが更新されたら、`Sketches/sync_from_lab.py` を実行すれば
ソースのコピーと ZIP の作り直しがまとめてできます（`uiap-hid-web` が同じ階層にある前提）。

```bash
python Sketches/sync_from_lab.py
```

---

## 関連リポジトリ

| リポジトリ | 内容 |
|---|---|
| [uiap-hid-web](https://github.com/tarosay/uiap-hid-web) | WebHID Lab（練習ページ本体）。スケッチの原本もここ |
| [arduino_core_ch32](https://github.com/tarosay/arduino_core_ch32) | ボードパッケージ・ライブラリ |

スケッチのソースは **uiap-hid-web が原本**です。
このリポジトリの `Sketches/` は講習日時点のコピーで、
`Sketches/zip/` はそこから作った配布用 ZIP です。

---

## ライセンス

MIT License（`LICENSE` を参照）
