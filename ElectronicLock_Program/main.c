#include <stm32f0xx.h>
#include "timer.h"
#include "func.h"

int status;

int main(void)
{
	SW_GPIO_Init();
	TIM3_Init(4800, 1000);
	TIM3CH1_PWMConfig(1200);
	TIM14_Init(4800, 1000);

	NVIC_EnableIRQ(TIM14_IRQn);

    while(1)
    {
    	OPSwitching(status);
    	readSW(status);
    }
}

void TIM14_IRQHandler(void)
{
	status++;
	if(status==4)	status = 0;

	TIM_ClearITPendingBit(TIM14,  TIM_IT_Update);
}
