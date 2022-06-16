// Main headers
#include "main.h"
#include "EmbUI.h"
#include "uistrings.h"   // non-localized text-strings
#include "radio.h"
#include "FS.h"
#include <LITTLEFS.h>
/**
 * построение интерфейса осуществляется в файлах 'interface.*'
 *
 */


//#define RXD2 16	//(RX2)
//#define TXD2 17	//(TX2)

//radio_data1 rd; // Структура данных для MSG ID = 1 . Простые данные от часов
radio_data1 rd;
void rx_radio_filter(radio_frame * msg);





// MAIN Setup
void setup() {
  Serial.begin(BAUD_RATE); //Выставляем скорость для общения с часами 
  //Serial.println();
  
  //Serial2.begin(BAUD_RATE2); // Выставляем скорость для общения с НС12
  //Serial2.println();




  // Start EmbUI framework
  embui.begin();
 
  

}



// MAIN loop
void loop() {

  embui.handle();

// Тут будем считатывать данные с Юарт и передавать куда нужно. не написано ещё 
radio_pool();
//Serial2.println("Test_Serial2_HS12");
  // while (Serial.available()) 
  // {        
  //   // If HC-12 has data 
  //   // По идее бы радио обмен нужно реализовать как отдельную задачу.
  
  // }

}

void rx_radio_filter(radio_frame * msg)
{
// uint8_t *bf = (uint8_t *)msg;
if (msg->msgid == 1)
{
  radio_data1 *rd1 = ( radio_data1 *)msg->data;
  memcpy(&rd,rd1,sizeof(radio_data1));
  //rd=msg->data;
 //rd=(radio_data1*)msg->data;
 //rd->ds_error
}
// Отправляем в HC12, то что пришло по UART от часов. 
//Serial2.write(bf,msg->len+7);
//Serial2.write((uint8_t *)msg,msg->len+7);



}