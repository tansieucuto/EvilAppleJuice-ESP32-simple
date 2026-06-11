# EvilAppleJuice-ESP32-Modified

A streamlined, modifications-focused fork of the original EvilAppleJuice-ESP32 project.

## Credits
Original logic and design by [ckcr4lyf](https://github.com/ckcr4lyf/EvilAppleJuice-ESP32). Go check out and star their original repository for the core implementation.

## What I actually changed (The Technical Realness)
* **Replaced Setup Packets with Action Packets:** Completely removed the old Apple Setup proximity packets (0x04) because newer iOS updates heavily filter or completely ignore them. Replaced them entirely with dynamic Action packets to maintain reliable device processing.
* **Streamlined the Main Loop:** Removed the external peripheral features including the `led.hpp` library, the `stateTable` configurations, and the physical BOOT button polling routines. This focuses all hardware resources strictly on the loop execution, achieving a clean O(1) time complexity per cycle.
* **Removed Preferences Persistence:** Removed the `Preferences.h` flash-writing routine that originally triggered on every state change, preventing potential timing jitter and reducing unnecessary write wear on the microcontroller's internal storage.
* **Enforced Hard 20ms Bleed:** Un-commented the `setMinInterval(0x20)` and `setMaxInterval(0x20)` configuration lines. This forces the ESP32 hardware transceiver to maintain an advertising packet density interval of exactly 20ms, conforming to the peak density standards outlined in Apple's Technical Q&A QA1931.
* **Direct Randomized Boot:** The firmware boots directly into the fully randomized loop. Source MAC addresses, transmit power levels, and advertisement structural types (IND, SCAN_IND, NONCONN_IND) cycle instantaneously on every execution.

## How to use
1. Clone this repo.
2. Open it in VS Code with PlatformIO.
3. Configure your own `platformio.ini` file to match whatever specific ESP32 board you are using.
4. Build and flash it to your board.
5. Plug it into power and let it run.

## Absolute Disclaimer for Dumbasses
oi oi oi
This project is strictly for educational purposes, RF hardware testing, and security research in a controlled lab environment. If you take this device into public malls, coffee shops, or airports to harass people and end up getting your ass arrested or sued by local authorities, you are entirely on your own. I don't give a fuck, and I am absolutely not responsible for your stupid, illegal actions. Don't be a script kiddie. Use your brain cells :333
