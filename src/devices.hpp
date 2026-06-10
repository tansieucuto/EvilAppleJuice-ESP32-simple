#include <Arduino.h>

enum PacketType { APPLE_AUDIO, APPLE_ACTION };
struct AppleDevice {
  const char* name;
  uint8_t modelId;
  PacketType type;
};

enum DeviceIndex : uint8_t {
  // Audio (31 bytes, ID at index 7)
  AIRPODS = 0,
  POWER_BEATS,
  BEATS_X,
  BEATS_SOLO_3,
  BEATS_STUDIO_3,
  AIRPODS_MAX,
  POWER_BEATS_PRO,
  BEATS_SOLO_PRO,
  AIRPODS_PRO,
  AIRPODS_GEN_2,
  BEATS_FLEX,
  BEATS_STUDIO_BUDS,
  BEATS_FIT_PRO,
  AIRPODS_GEN_3,
  AIRPODS_PRO_GEN_2,
  BEATS_STUDIO_BUDS_PLUS,
  BEATS_STUDIO_PRO,
  AIRPODS_PRO_GEN_2_USB_C,
  BEATS_SOLO_4,
  BEATS_SOLO_BUDS,
  SOFTWARE_UPDATE,
  POWERBEATS_FIT,

  // FUCK APPLE, idk i just use 11 byte and id at index 7
  ACTION_APPLETV_SETUP,
  ACTION_APPLETV_PAIR,
  ACTION_SETUP_NEW_PHONE,
  ACTION_HOMEPOD_SETUP,
  ACTION_APPLETV_HOMEKIT_SETUP,
  ACTION_APPLETV_KEYBOARD_SETUP,
  ACTION_TV_COLOR_BALANCE,
  ACTION_APPLETV_NEW_USER,
  ACTION_APPLETV_CONNECTING_TO_NETWORK,
  ACTION_APPLETV_APPLEID_SETUP,
  ACTION_ESIM_TRANSFER,
  ACTION_HOMEPOD_STEREO_PAIR,
  ACTION_AUDIO_SYNC,
  ACTION_WATCH_COMPANION,
  ACTION_VISION_PRO,

  NUM_DEVICES

};

const AppleDevice ALL_DEVICES[] = {
  // Audio Devices (31 bytes, ID at index 7)
  // These are audio devices: wireless headphones / earbuds
  // It seems these need a shorter range between ESP & iDevice
  {"Airpods", 0x02, APPLE_AUDIO},
  {"Power Beats", 0x03, APPLE_AUDIO},
  {"Beats X", 0x05, APPLE_AUDIO},
  {"Beats Solo 3", 0x06, APPLE_AUDIO},
  {"Beats Studio 3", 0x09, APPLE_AUDIO},
  {"Airpods Max", 0x0a, APPLE_AUDIO},
  {"Power Beats Pro", 0x0b, APPLE_AUDIO},
  {"Beats Solo Pro", 0x0c, APPLE_AUDIO},
  {"Airpods Pro", 0x0e, APPLE_AUDIO},
  {"Airpods Gen 2", 0x0f, APPLE_AUDIO},
  {"Beats Flex", 0x10, APPLE_AUDIO},
  {"Beats Studio Buds", 0x11, APPLE_AUDIO},
  {"Beats Fit Pro", 0x12, APPLE_AUDIO},
  {"Airpods Gen 3", 0x13, APPLE_AUDIO},
  {"Airpods Pro Gen 2", 0x14, APPLE_AUDIO},
  {"Beats Studio Buds Plus", 0x16, APPLE_AUDIO},
  {"Beats Studio Pro", 0x17, APPLE_AUDIO},
  {"Airpods Pro Gen 2 USB-C", 0x24, APPLE_AUDIO},
  {"Beats Solo 4", 0x25, APPLE_AUDIO},
  {"Beats Solo Buds", 0x26, APPLE_AUDIO},
  {"Software update", 0x2e, APPLE_AUDIO},
  {"Powerbeats fit", 0x2f, APPLE_AUDIO},

  //action devices
  {"Action AppleTV Setup", 0x01, APPLE_ACTION},
  {"Action AppleTV Pair", 0x06, APPLE_ACTION},
  {"Action Setup New Phone", 0x09, APPLE_ACTION},
  {"Action Homepod Setup", 0x0b, APPLE_ACTION},
  {"Action AppleTV Homekit Setup", 0x0d, APPLE_ACTION},
  {"Action AppleTV Keyboard Setup", 0x13, APPLE_ACTION},
  {"Action TV Color Balance", 0x1e, APPLE_ACTION},
  {"Action AppleTV New User", 0x20, APPLE_ACTION},
  {"Action AppleTV Connecting to Network", 0x27, APPLE_ACTION},
  {"Action AppleTV AppleID Setup", 0x2b, APPLE_ACTION},
  {"Action eSIM Transfer", 0x02, APPLE_ACTION},
  {"Action Homepod Stereo Pair", 0x0c, APPLE_ACTION},
  {"Action Audio Sync", 0x10, APPLE_ACTION},
  {"Action Watch Companion", 0x1c, APPLE_ACTION},
  {"Action Vision Pro", 0x24, APPLE_ACTION}
};

void generatePacket(const AppleDevice& device, uint8_t* buffer, size_t& outLength);
