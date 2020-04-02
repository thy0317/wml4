#ifndef __KEY_H
#define __KEY_H

#define KEY1_CLK         RCC_APB2Periph_GPIOB
#define KEY1_PORT        GPIOB
#define KEY1_PIN         GPIO_Pin_1

#define KEY2_CLK         RCC_APB2Periph_GPIOB
#define KEY2_PORT        GPIOB
#define KEY2_PIN         GPIO_Pin_2

void key_init(void);
;
#endif /* __KEY_H */
