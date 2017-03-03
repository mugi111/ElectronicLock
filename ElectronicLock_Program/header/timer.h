#ifndef __TIMER__
#define __TIMER__
#include "stm32f0xx_tim.h"

void TIM3_Init(uint32_t period, uint32_t prescaler);
void TIM3CH1_PWMInit();
void TIM3CH1_PWMConfig(int pulse);
void TIM14_Init(uint32_t period, uint32_t prescaler);

#endif /*__TIMER__*/

