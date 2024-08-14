#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_P = 5;
const int LED_PIN_B = 6;
const int LED_PIN_Y = 7;

const int LED_PIN_A  = 18;

const int BTN_PIN_R= 21;

int main() {
  stdio_init_all();

  // Botao - vermelho
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  
  // definindo os dois leds como saida
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(LED_PIN_P);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);
  gpio_init(LED_PIN_B);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);
  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);
  gpio_init(LED_PIN_A);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_PIN_R)){
      for (int i = 0;i<512;i++){
        gpio_put(LED_PIN_A,1);
        gpio_put(LED_PIN_R,1);
        sleep_ms(10);
        gpio_put(LED_PIN_R,0);

        gpio_put(LED_PIN_P,1);
        sleep_ms(10);
        gpio_put(LED_PIN_P,0);

        gpio_put(LED_PIN_B,1);
        sleep_ms(10);
        gpio_put(LED_PIN_B,0);

        gpio_put(LED_PIN_Y,1);
        sleep_ms(10);
        gpio_put(LED_PIN_Y,0);

      }
      gpio_put(LED_PIN_A,0);
      // gpio_pull_up(BTN_PIN_R);
    
    }
  }
}
