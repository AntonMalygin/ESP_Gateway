#ifndef UISTRINGS_H
#define UISTRINGS_H

#pragma once

// Set of flash-strings that might be reused multiple times within the code

// General
#if defined ARDUINO_ESP32_DEV  
  static const char T_HEADLINE[] PROGMEM = "ESP32_Gateway";    // имя проекта
#elif defined ARDUINO_ESP32S2_DEV  
  static const char T_HEADLINE[] PROGMEM = "EmbUI ESP32S2 Demo";    // имя проекта
#elif defined ARDUINO_ESP32C3_DEV  
  static const char T_HEADLINE[] PROGMEM = "EmbUI ESP32C3 Demo";    // имя проекта
#else
  static const char T_HEADLINE[] PROGMEM = "EmbUI Demo";    // имя проекта
#endif  

// Our variable names
// static const char V_LED_L2[] PROGMEM = "vLED_L2";
// static const char V_LED_L1[] PROGMEM = "vLED_L1";
// static const char V_VAR1[] PROGMEM = "v1";
// static const char V_VAR2[] PROGMEM = "v2";
// static const char V_VAR3[] PROGMEM = "v3";

// UI blocks
static const char T_DEMO[] PROGMEM = "demo";     // генерация UI-секции "демо"
static const char T_MORE[] PROGMEM = "more";

// UI handlers
static const char T_SET_DEMO[] PROGMEM = "do_demo";     // обработка данных из секции "демо"
static const char T_SET_MORE[] PROGMEM = "do_more";

#endif