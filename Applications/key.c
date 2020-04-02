#include "stm32f10x.h"
#include "key.h"

uint32_t key_value = 0;

/**
 * @brief   key pin init and operations
 * @{
 */
void key_init(void)
{
    GPIO_InitTypeDef init;
    RCC_APB2PeriphClockCmd(KEY1_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(KEY2_CLK, ENABLE);

    init.GPIO_Pin = KEY1_PIN;
    init.GPIO_Mode = GPIO_Mode_IPU;
    init.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(KEY1_PORT, &init);
    init.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_PORT, &init);
}

static uint8_t read_key(void)
{
    if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == Bit_RESET) {
        key_value |= (1 << 0);
    }
    else {
        key_value &= ~(1 << 0);
    }

    if (GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == Bit_RESET) {
        key_value |= (2 << 0);
    }
    else {
        key_value &= ~(2 << 0);
    }
}


