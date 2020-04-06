#include "stm32f10x.h"
#include "do.h"
#include "key.h"

#define RELAY_CLOSE_SECOND      30 /* 继电器闭合时间，单位：秒 */

volatile uint32_t systick_count = 0;
uint32_t relay_tick = 0;

void key_scan(void);

int main(void)
{
    key_init();
    do_init();
    SysTick_Config(SystemCoreClock / 1000);
    do_set(ALL, do_open);
    
    while (1) {
        key_scan();

        if (key[1].state == key_pressing) { /* 按钮2闭合 */
            if (key_clicked(0)) { /* 按钮1按过 */
                if (do_state(RELAY) == do_open) {
                    relay_tick = systick_count;
                }
                do_triggle(ALL);
            }
            if (systick_count - relay_tick > RELAY_CLOSE_SECOND * 1000 ) { /* 到时 */
                relay_tick = systick_count;
                do_set(ALL, do_open);
            }
        }
        else {
            do_set(ALL, do_open);
        }
    }

    return 0;
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    ++systick_count;
}

void key_scan(void)
{
    static uint32_t key_tick = 0;
    if (systick_count - key_tick > 50) { // 50ms检测一次按键
        key_tick = systick_count;
        key_read();
    }
}
