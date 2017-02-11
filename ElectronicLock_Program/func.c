#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_exti.h"
#include "func.h"

int pass[4] = {0, 0, 0, 0};
int input[4] = {-1, -1, -1, -1};
int flagAste = 0;
int inputCNT = 0;

void SW_GPIO_Init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitTypeDef SW_Output;
	SW_Output.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	SW_Output.GPIO_Mode = GPIO_Mode_OUT;
	SW_Output.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Output.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &SW_Output);
}

void SW_EXTI_Init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	GPIO_InitTypeDef SW_Input;
	SW_Input.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	SW_Input.GPIO_Mode = GPIO_Mode_IN;
	SW_Input.GPIO_PuPd = GPIO_PuPd_DOWN;
	SW_Input.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOB, &SW_Input);

	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line4 | EXTI_Line5 | EXTI_Line6;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_EnableIRQ(EXTI4_15_IRQn);
}

void OPSwitching(int status)
{
	switch (status) {
		case 0:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_11, 0);
			break;

		case 1:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_11, 0);
			break;

		case 2:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_11, 0);
			break;

		case 3:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_11, 1);
		default:
			break;
	}
}

void judgeNum(int SWnum)
{
	if((SWnum!=-1)&&(SWnum<10)){
		input[inputCNT] = SWnum;
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, inputCNT%2);
		inputCNT++;
	}else if(SWnum==11){
		flagAste = ~flagAste;
	}else if(SWnum==12){
		checkPass();
	}
}

void checkPass()
{
	if((pass[0]==input[0])&&(pass[1]==input[1])&&(pass[2]==input[2])&&(pass[3]==input[3])){
		DriveMotor(90);
	}else {
		flagAste = 0;
	}
}

void DriveMotor(int dig)
{

}
