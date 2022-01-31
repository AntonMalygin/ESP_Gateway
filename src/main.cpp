// Main headers
#include "main.h"
#include "EmbUI.h"
#include "uistrings.h"   // non-localized text-strings


/**
 * построение интерфейса осуществляется в файлах 'interface.*'
 *
 */


#define RXD2 16	//(RX2)
#define TXD2 17	//(TX2)





// MAIN Setup
void setup() {
  Serial.begin(BAUD_RATE); //Выставляем скорость для общения с часами 
  Serial.println();
  
  Serial2.begin(BAUD_RATE2, SERIAL_8N1, RXD2, TXD2); // Выставляем скорость для общения с НС12
  Serial2.println();




  // Start EmbUI framework
  embui.begin();
 
  

}



// MAIN loop
void loop() {

  embui.handle();

// Тут будем считатывать данные с Юарт и передавать куда нужно. не написано ещё 

  while (Serial2.available()) 
  {        
    // If HC-12 has data
  
  }

}