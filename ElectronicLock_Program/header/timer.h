#ifndef __TIMER__
#define __TIMER__

void TIM3_Init(uint32_t period, uint32_t prescaler);
void TIM3CH1_PWMConfig(int pulse);


#endif /*__TIMER__*/
