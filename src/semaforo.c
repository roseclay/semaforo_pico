#include "semaforo.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

volatile int estado_semaforo = 0;

// Callback para temporizador periódico (Semáforo)
bool repetir_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, estado_semaforo == 0);
    gpio_put(LED_AMARELO, estado_semaforo == 1);
    gpio_put(LED_VERDE, estado_semaforo == 2);
    estado_semaforo = (estado_semaforo + 1) % 3;
    return true;
}

// Inicializa os LEDs do semáforo
void inicializar_semaforo() {
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
}

// Inicia o funcionamento do semáforo
void iniciar_semaforo() {
    static struct repeating_timer timer;
    add_repeating_timer_ms(3000, repetir_timer_callback, NULL, &timer);
}
