#ifndef __DO_H
#define __DO_H

/* 使继电器闭合的引脚电平 */
#define DO_CLOSE_VALUE  1
/* 继电器及灯数量 */
#define DO_NUM          2
/* 引脚具体的定义 */
#define DO_PIN_CONFIG  { \
    /* DO1- 继电器 */ \
    RCC_APB2Periph_GPIOC, \
    GPIOC, \
    GPIO_Pin_6, \
    /* DO2 - 灯 */ \
    RCC_APB2Periph_GPIOC, \
    GPIOC, \
    GPIO_Pin_7, \
}

#define ALL             (-1) /* 全部 */
#define RELAY           (0)  /* 继电器 */
#define LED             (1)  /* 灯 */

typedef enum {
    do_close,
    do_open = !do_close
} do_state_t;

void do_init(void);
void do_set(int index, do_state_t state);
void do_triggle(int index);
do_state_t do_state(int index);

#endif /* __DO_H */
