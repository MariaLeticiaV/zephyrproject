#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

// 1. Registra o módulo de log
LOG_MODULE_REGISTER(HELLO_TIMER_APP, CONFIG_LOG_DEFAULT_LEVEL);

// 2. Obtém o valor do Kconfig
#define REPETITION_INTERVAL_MS CONFIG_HELLO_TIMER_INTERVAL_MS

// 3. Estrutura do timer
struct k_timer hello_timer;

// 4. Função de callback que é executada pelo timer
void hello_timer_handler(struct k_timer *timer_id)
{
    // === Etapa: Uso dos diferentes níveis de log ===
    
    // Nível ERROR (Sempre aparece se o log estiver habilitado)
    LOG_ERR("--- Nivel ERROR: Hello World (intervalo: %d ms) ---", REPETITION_INTERVAL_MS);
    
    // Nível INFO (Aparece se CONFIG_LOG_DEFAULT_LEVEL for 3 ou mais)
    LOG_INF("Nivel INFO: Hello World. Checagem periodica.");
    
    // Nível DEBUG (Aparece SOMENTE se CONFIG_LOG_DEFAULT_LEVEL for 4)
    LOG_DBG("Nivel DEBUG: Timer disparado. Tempo de execucao: %lld", k_uptime_get());
}

// 5. Função principal (ponto de entrada do Zephyr)
void main(void)
{
    // 5.1 Inicializa o timer com a função de callback
    k_timer_init(&hello_timer, hello_timer_handler, NULL);

    LOG_INF("Iniciando o Hello World Periodico...");
    LOG_INF("Timer configurado para repetir a cada %d ms.", REPETITION_INTERVAL_MS);

    // 5.2 Inicia o timer de forma periódica
    // O timer dispara a primeira vez após 1 intervalo, e repete a cada 1 intervalo.
    k_timer_start(&hello_timer, K_MSEC(REPETITION_INTERVAL_MS), K_MSEC(REPETITION_INTERVAL_MS));
}