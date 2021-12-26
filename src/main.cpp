// Main headers
#include "main.h"
#include "EmbUI.h"
#include "uistrings.h"   // non-localized text-strings
#include <hc12.h> // Библиотека для работы с модулем HC-12


/**
 * построение интерфейса осуществляется в файлах 'interface.*'
 *
 */
const uint8_t LED_PIN=LED_BUILTIN_L2;
const bool LED_LEVEL=HIGH;

TaskHandle_t blink;

void blinkTask(void *pvParam){
  pinMode(LED_PIN,OUTPUT);
  //digitalWrite(LED_PIN, ! LED_LEVEL);
  while(true){
    digitalWrite(LED_PIN, ! LED_LEVEL);
    vTaskDelay(pdMS_TO_TICKS(25));
    digitalWrite(LED_PIN, ! LED_LEVEL);
    vTaskDelay(pdMS_TO_TICKS(1000-25));
  }
}




//HardwareSerial HC12Serial(2);   // Declare SoftwareSerial for HC12
//HC12 hc12(&HC12Serial, 5, 38400);  // Declare HC12: SWSerial address, SET pin, (optional: baud rate)


// MAIN Setup
void setup() {
  Serial.begin(BAUD_RATE); //Выставляем скорость для общения с часами 
  Serial.println();
  Serial2.begin(38400); // Выставляем скорость для общения с НС12
  Serial2.println();


  // Start EmbUI framework
  embui.begin();
 if (xTaskCreate(blinkTask, "blink", 1024, NULL, 1, &blink)!=pdPASS)
 {
   Serial.println("Error creating blink Task");
   Serial.flush();
   esp_deep_sleep_start();
 }
  
  // restore LED state from configuration
 // digitalWrite( LED_BUILTIN_L1, !embui.param(FPSTR(V_LED_L1)).toInt() );
 // digitalWrite( LED_BUILTIN_L2, !embui.param(FPSTR(V_LED_L2)).toInt() );



}



// MAIN loop
void loop() {

  embui.handle();

// Тут будем считатывать данные с Юарт и передавать куда нужно. не написано ещё 
vTaskDelay(pdMS_TO_TICKS(5000));
if (eTaskGetState(blink)== eSuspended){ vTaskResume(blink);}
else {vTaskSuspend(blink);}



}