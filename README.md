# EvilAppleJuice-ESP32-Stripped

A stripped-down, zero-bloat fork of the original EvilAppleJuice-ESP32 spammer. No bells, no whistles, just pure RF blasting.

## Credits
Original logic by ckcr4lyf. Go star their original repo instead of looking at me. 

## What I actually changed (The Technical Realness)
* **Killed the LED and Button Bloat:** Stripped out the entire led.hpp library, stateTable, and the stupid BOOT button polling code. It just wasted CPU cycles and introduced latency. Now the loop runs in pure O(1) time complexity.
* **Removed Preferences Flash Writes:** The original code read and wrote to the internal Flash memory (Preferences.h) every single time you clicked a button. That's a great way to introduce jitter and wear out your flash. Gone.
* **Enforced Hard 20ms Bleed:** Un-commented the setMinInterval(0x20) and setMaxInterval(0x20) functions. This forces the ESP32 hardware to blast advertising packets every 20ms—the absolute maximum density recommended by Apple's own Technical Q&A QA1931. 
* **Pure Randomized Chaos:** It boots straight into full-randomization mode. MAC addresses, Tx power, and advertisement types (IND, SCAN_IND, NONCONN_IND) cycle instantly on every loop iteration without any configuration lag.

## How to use
1. Clone this repo.
2. Open it in VS Code with PlatformIO.
3. Configure your own `platformio.ini` file to match whatever specific ESP32 board you are using.
4. Build and flash it to your board.
5. Plug it into power and let it run.

## Absolute Disclaimer for Dumbasses
This project is strictly for educational purposes, RF hardware testing, and security research in a controlled lab environment. If you take this device into public malls, coffee shops, or airports to harass people and end up getting your ass arrested or sued by local authorities, you are entirely on your own. I don't give a fuck, and I am absolutely not responsible for your stupid, illegal actions. Don't be a script kiddie. Use your brain cells.
