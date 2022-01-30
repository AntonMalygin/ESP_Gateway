// Main headers
#include "main.h"
#include "EmbUI.h"
#include "uistrings.h"   // non-localized text-strings
#include <SoftwareSerial.h>
#include <HC12.h> // Библиотека для работы с модулем HC-12


/**
 * построение интерфейса осуществляется в файлах 'interface.*'
 *
 */
const uint8_t LED_PIN=LED_BUILTIN_L2;
const bool LED_LEVEL=HIGH;

#define RXD2 16	//(RX2)
#define TXD2 17	//(TX2)
#define HC12 Serial2  //Hardware serial 2 on the ESP32




// MAIN Setup
void setup() {
  Serial.begin(BAUD_RATE); //Выставляем скорость для общения с часами 
  Serial.println();
  
  Serial2.begin(38400); // Выставляем скорость для общения с НС12
  Serial2.println();
  HC12.begin(38400, SERIAL_8N1, RXD2, TXD2);      // Serial port to HC12



  // Start EmbUI framework
  embui.begin();
 
  

}



// MAIN loop
void loop() {

  embui.handle();

// Тут будем считатывать данные с Юарт и передавать куда нужно. не написано ещё 

  while (HC12.available()) 
  {        
    // If HC-12 has data
    Serial2.write(HC12.read());      // Send the data to Serial monitor
  }
  while (Serial2.available()) 
  {      
    // If we have data from Serial monitor
    HC12.write(Serial2.read());      // Send that data to HC-12
  }



}