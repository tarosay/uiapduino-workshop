# -*- coding: utf-8 -*-
"""
uiap-hid-web の docs/sketches から、講習で使うスケッチを
uiapduino-workshop リポジトリへ同期し、配布用 ZIP も作る。

ZIP の中身は Lab ページの「ZIPダウンロード」とまったく同じ構成にする
（<スケッチ名>/ フォルダ + 各ファイル + sketch.yaml）。
"""
import os
import shutil
import zipfile

LAB = r"D:/git/github/uiap-hid-web/docs/sketches"
REPO = r"D:/git/github/uiapduino-workshop"
DST_SRC = os.path.join(REPO, "Sketches")
DST_ZIP = os.path.join(REPO, "Sketches", "zip")

FQBN = "UIAP_HID:ch32v:CH32V003:pnum=V14,usb=%s,opt=oslto"

# (スケッチ名, ファイル一覧, USB 設定, 対応する Lab ページ)
SKETCHES = [
    ("WebHIDTest",       ["WebHIDTest.ino"],                        "kbdweb"),
    ("HidPrint",         ["HidPrint.ino", "Hid.h", "Hid.cpp"],      "kbdweb"),
    ("KeyboardPractice", ["KeyboardPractice.ino"],                  "kbdweb"),
    ("KeyboardSwitch",   ["KeyboardSwitch.ino"],                    "kbdweb"),
    ("MazeSolver",       ["MazeSolver.ino", "MazeHID.h"],           "kbdweb"),
    ("SnakeSolver",      ["SnakeSolver.ino", "SnakeHID.h"],         "webhid"),
    ("SnakeVS",          ["SnakeVS.ino", "SnakeVSHID.h"],           "webhid"),
    ("RockDodge",        ["RockDodge.ino", "RockDodgeHID.h"],       "webhid"),
]

# 講習中に手で打ち込むスケッチ（Lab には無い。リポジトリ側が原本）
LOCAL_SKETCHES = [
    ("Blink", ["Blink.ino"], "kbd"),
    ("A_Key", ["A_Key.ino"], "kbd"),
]


def write_yaml(folder, usb):
    with open(os.path.join(folder, "sketch.yaml"), "w",
              encoding="utf-8", newline="\n") as f:
        f.write("default_fqbn: " + (FQBN % usb) + "\n")


def main():
    os.makedirs(DST_ZIP, exist_ok=True)

    # ── Lab 由来のスケッチを同期 ────────────────────────────────
    for name, files, usb in SKETCHES:
        src = os.path.join(LAB, name)
        dst = os.path.join(DST_SRC, name)
        os.makedirs(dst, exist_ok=True)
        for fn in files:
            shutil.copy2(os.path.join(src, fn), os.path.join(dst, fn))
        write_yaml(dst, usb)
        print("sync : %-18s %s" % (name, " ".join(files)))

    # ── リポジトリ側が原本のスケッチにも sketch.yaml を用意 ──────
    for name, files, usb in LOCAL_SKETCHES:
        dst = os.path.join(DST_SRC, name)
        if os.path.isdir(dst):
            write_yaml(dst, usb)
            print("yaml : %-18s usb=%s" % (name, usb))

    # ── 配布用 ZIP を作る ───────────────────────────────────────
    for name, files, usb in SKETCHES + LOCAL_SKETCHES:
        folder = os.path.join(DST_SRC, name)
        if not os.path.isdir(folder):
            continue
        zip_path = os.path.join(DST_ZIP, name + ".zip")
        with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as z:
            for fn in files + ["sketch.yaml"]:
                p = os.path.join(folder, fn)
                if os.path.exists(p):
                    z.write(p, "%s/%s" % (name, fn))
        print("zip  : %-18s %d bytes" % (name, os.path.getsize(zip_path)))


if __name__ == "__main__":
    main()
