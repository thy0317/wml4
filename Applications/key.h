#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY_NUM         2

#define KEY_PIN_CONFIG  { \
    /* key1 */ \
    RCC_APB2Periph_GPIOB, \
    GPIOB, \
    GPIO_Pin_2, \
    /* key2 */ \
    RCC_APB2Periph_GPIOB, \
    GPIOB, \
    GPIO_Pin_3, \
}

typedef enum {
    key_no_press,
    key_pressing,
    key_pressed,
    key_click = !key_no_press
} key_state_t;

typedef struct {
    /* 时钟 */
    uint32_t RCC_APB2Periph;
    /* 端口 */
    GPIO_TypeDef *GPIOx;
    /* 引脚 */  
    uint16_t GPIO_Pin;
} key_pin_t;

typedef struct {
    /* 之前状态 */
    key_state_t pre_state;
    /* 当前状态 */
    key_state_t state;
    /* 引脚配置 */
    key_pin_t pin_cfg;
} key_t;

extern key_t key[];

void key_init(void);
void key_read(void);
int key_clicked(uint32_t index);

#endif /* __KEY_H */
