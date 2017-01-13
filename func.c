#include "stm32f0xx_gpio.h"
#include "stm32f0xx_tim.h"

int pass[4] = {0, 0, 0, 0};
int input[4];
int flagAste = 0;
int inputCNT = 0;

void generalInit()
{
	GPIO_InitTypeDef SW_Output;
	SW_Output.GPIO_Pin = GPIO_Pin_0 || GPIO_Pin_1 || GPIO_Pin_2 || GPIO_Pin_3;
	SW_Output.GPIO_Mode = GPIO_Mode_OUT;
	SW_Output.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Output.GPIO_Speed = GPIO_Speed_Level_1;
//	SW_Output.GPIO_OType =
	GPIO_Init(GPIOA, &SW_Output);

	GPIO_InitTypeDef SW_Input;
	SW_Input.GPIO_Pin = GPIO_Pin_4 || GPIO_Pin_5 || GPIO_Pin_6;
	SW_Input.GPIO_Mode = GPIO_Mode_IN;
	SW_Input.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Input.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &SW_Input);

	GPIO_InitTypeDef DisplayLED;
	DisplayLED.GPIO_Pin = GPIO_Pin_7 || GPIO_Pin_8 || GPIO_Pin_9 || GPIO_Pin_10 || GPIO_Pin_11;
	DisplayLED.GPIO_Mode = GPIO_Mode_OUT;
	DisplayLED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	DisplayLED.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &DisplayLED);

	TIM_TimeBaseInitTypeDef StatusCount;
//	StatusCount.TIM_ClockDivision =
//	StatusCount.TIM_CounterMode =
//	StatusCount.TIM_Period =
//	StatusCount.TIM_Prescaler =
	TIM_TimeBaseStructInit(&StatusCount);

}

int readSW(int status)
{
	int SWnum = -1;
	switch (status) {
		case 0:
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)){
				SWnum = 1;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)){
				SWnum = 2;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)){
				SWnum = 3;
			}
			break;

		case 1:
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)){
				SWnum = 4;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)){
				SWnum = 5;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)){
				SWnum = 6;
			}
			break;

		case 2:
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)){
				SWnum = 7;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)){
				SWnum = 8;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)){
				SWnum = 9;
			}
			break;

		case 3:
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)){
				SWnum = 11;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)){
				SWnum = 0;
			}else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)){
				SWnum = 12;
			}
			break;

		default:
			break;
	}
	return SWnum;
}

void judgeNum(int SWnum)
{
	if((SWnum!=-1)&&(SWnum<10)){
		input[inputCNT] = SWnum;
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
