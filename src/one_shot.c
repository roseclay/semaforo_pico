#include "one_shot.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

bool one_shot_timer_callback(struct repeating_timer *t) {
    static int fase = 0;
    
    if (fase == 0) {
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 1);
    } else if (fase == 1) {
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
    } else if (fase == 2) {
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
    }
    
    fase++;
    return fase < 3;
}

void iniciar_one_shot() {
    add_alarm_in_ms(3000, (alarm_callback_t)one_shot_timer_callback, NULL, false);
}
