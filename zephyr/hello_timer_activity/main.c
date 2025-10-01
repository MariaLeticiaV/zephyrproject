#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>


LOG_MODULE_REGISTER(HELLO_TIMER_APP, CONFIG_LOG_DEFAULT_LEVEL);

#define REPETITION_INTERVAL_MS CONFIG_HELLO_TIMER_INTERVAL_MS

struct k_timer hello_timer;

void hello_timer_handler(struct k_timer *timer_id)
{

    LOG_ERR("--- Nivel ERROR: Hello World (intervalo: %d ms) ---", REPETITION_INTERVAL_MS);

    LOG_INF("Nivel INFO: Hello World. Checagem periodica.");

    LOG_DBG("Nivel DEBUG: Timer disparado. Tempo de execucao: %lld", k_uptime_get());
}

void main(void)
{
    k_timer_init(&hello_timer, hello_timer_handler, NULL);

    LOG_INF("Iniciando o Hello World Periodico...");
    LOG_INF("Timer configurado para repetir a cada %d ms.", REPETITION_INTERVAL_MS);

    k_timer_start(&hello_timer, K_MSEC(REPETITION_INTERVAL_MS), K_MSEC(REPETITION_INTERVAL_MS));
}
