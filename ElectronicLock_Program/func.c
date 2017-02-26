#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_exti.h"
#include "func.h"

int pass[4] = {0, 0, 0, 0};
int input[4] = {-1, -1, -1, -1};
int inputCNT = 0;

void SW_GPIO_Init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	GPIO_InitTypeDef SW_Output;
	SW_Output.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	SW_Output.GPIO_Mode = GPIO_Mode_OUT;
	SW_Output.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Output.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &SW_Output);

	GPIO_InitTypeDef SW_Input;
	SW_Input.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	SW_Input.GPIO_Mode = GPIO_Mode_IN;
	SW_Input.GPIO_PuPd = GPIO_PuPd_DOWN;
	SW_Input.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOB, &SW_Input);

	SW_Output.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5;
	SW_Output.GPIO_Mode = GPIO_Mode_OUT;
	SW_Output.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Output.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &SW_Output);
}

void Check_Pass()
{
	if((pass[0]==input[0])&&(pass[1]==input[1])&&(pass[2]==input[2])&&(pass[3]==input[3])){
		DriveServo(90);
	}
}

void Chenge_Output(int status)
{
	switch(status){
		case 0:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 0);
			break;
		case 1:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 0);
			break;
		case 2:
			GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_10, 1);
			break;
		default:
			break;
	}
}

void DriveServo(int dig)
{

}
