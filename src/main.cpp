// Main headers
#include "main.h"
#include "EmbUI.h"
#include "uistrings.h"   // non-localized text-strings

/**
 * построение интерфейса осуществляется в файлах 'interface.*'
 *
 */

#ifdef USE_FTP
 #include "ftpSrv.h"
#endif

// MAIN Setup
void setup() {
  Serial.begin(BAUD_RATE);

  LOG(printf_P, PSTR("\n\nsetup: free heap  : %d\n"), ESP.getFreeHeap());
#ifdef ESP32
  LOG(printf_P, PSTR("setup: free PSRAM  : %d\n"), ESP.getFreePsram()); // 4194252
#endif

  Serial.println("Starting test...");

  pinMode(LED_BUILTIN_L1, OUTPUT); // we are goning to blink this LED
  pinMode(LED_BUILTIN_L2, OUTPUT); // we are goning to blink this LED

  // Start EmbUI framework
  embui.begin();

  // restore LED state from configuration
  digitalWrite( LED_BUILTIN_L1, !embui.param(FPSTR(V_LED_L1)).toInt() );
  digitalWrite( LED_BUILTIN_L2, !embui.param(FPSTR(V_LED_L2)).toInt() );

  #ifdef USE_FTP
      ftp_setup(); // запуск ftp-сервера
  #endif
}


// MAIN loop
void loop() {
  embui.handle();

#ifdef USE_FTP
  ftp_loop(); // цикл обработки событий фтп-сервера
#endif
}