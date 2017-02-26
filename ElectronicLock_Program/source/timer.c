#include <stm32f0xx.h>
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_tim.h"
#include "stm32f0xx_rcc.h"
#include "timer.h"

void TIM3_Init(uint32_t period, uint32_t prescaler)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM3_TimeBase;
	TIM3_TimeBase.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM3_TimeBase.TIM_CounterMode = TIM_CounterMode_Up;
	TIM3_TimeBase.TIM_Period = period-1;
	TIM3_TimeBase.TIM_Prescaler = prescaler-1;
	TIM3_TimeBase.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM3_TimeBase);
}

void TIM3CH1_PWMConfig(int pulse) //TODO: èâä˙âªÇ∆ï™äÑÇ∑ÇÈ
{
	TIM_OCInitTypeDef TIM3_PWMConfig;
	TIM3_PWMConfig.TIM_OCMode = TIM_OCMode_PWM1;
	TIM3_PWMConfig.TIM_OutputState = TIM_OutputState_Enable;
	TIM3_PWMConfig.TIM_OCNPolarity = TIM_OCPolarity_High;
	TIM3_PWMConfig.TIM_Pulse = pulse-1;

	TIM_OC1Init(TIM3, &TIM3_PWMConfig);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);


	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	GPIO_InitTypeDef TIM3_CH1_Config;
	TIM3_CH1_Config.GPIO_OType = GPIO_OType_PP;
	TIM3_CH1_Config.GPIO_Mode = GPIO_Mode_AF;
	TIM3_CH1_Config.GPIO_Pin = GPIO_Pin_4;
	TIM3_CH1_Config.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOB, &TIM3_CH1_Config);

	TIM3_CH1_Config.GPIO_OType = GPIO_OType_PP;
	TIM3_CH1_Config.GPIO_Mode = GPIO_Mode_IN;
	TIM3_CH1_Config.GPIO_PuPd = GPIO_PuPd_DOWN;
	TIM3_CH1_Config.GPIO_Pin = GPIO_Pin_5;
	TIM3_CH1_Config.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOB, &TIM3_CH1_Config);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_1);
}

void TIM14_Init(uint32_t period, uint32_t prescaler)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);

	TIM_TimeBaseInitTypeDef TIM14_TimeBase;
	TIM14_TimeBase.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM14_TimeBase.TIM_CounterMode = TIM_CounterMode_Down;
	TIM14_TimeBase.TIM_Period = period-1;
	TIM14_TimeBase.TIM_Prescaler = prescaler-1;
	TIM14_TimeBase.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM14, &TIM14_TimeBase);

	TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
	TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);
	NVIC_SetPriority(TIM14_IRQn, 0);

	TIM_Cmd(TIM14, ENABLE);
}



