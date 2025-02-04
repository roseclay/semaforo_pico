#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "semaforo.h"
#include "one_shot.h"

#define BOTAO 5

volatile bool botao_habilitado = true;

// Callback para interrupção do botão
void botao_callback(uint gpio, uint32_t events) {
    if (botao_habilitado) {
        botao_habilitado = false;
        iniciar_one_shot();
    }
}

int main() {
    stdio_init_all();
    
    // Inicializa o semáforo
    inicializar_semaforo();

    // Configuração do botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
    gpio_set_irq_edge_rise(BOTAO, true);
    gpio_set_irq_callback(botao_callback);
    irq_set_enabled(IO_IRQ_BANK0, true);

    // Inicia o ciclo do semáforo
    iniciar_semaforo();

    while (true) {
        sleep_ms(1000);
    }
}
