#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "func.h"

int pass[4] = {0, 0, 0, 0};
int input[4];
int flagAste = 0;
int inputCNT = 0;

void SW_GPIO_Init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitTypeDef SW_Output;
	SW_Output.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_7;
	SW_Output.GPIO_Mode = GPIO_Mode_OUT;
	SW_Output.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Output.GPIO_Speed = GPIO_Speed_Level_1;
//	SW_Output.GPIO_OType =
	GPIO_Init(GPIOA, &SW_Output);

	GPIO_InitTypeDef debug_led;
	debug_led.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	debug_led.GPIO_Mode = GPIO_Mode_OUT;
	debug_led.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOB, &debug_led);

	GPIO_InitTypeDef SW_Input;
	SW_Input.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	SW_Input.GPIO_Mode = GPIO_Mode_IN;
	SW_Input.GPIO_PuPd = GPIO_PuPd_UP;
	SW_Input.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(GPIOA, &SW_Input);

	GPIO_WriteBit(GPIOA, GPIO_Pin_7, 0);
}

int readSW(int status)
{
	int SWnum = -1;
	switch (status) {
		case 0:
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
			break;

		case 1:
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
			break;

		case 2:
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
			break;

		case 3:
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 1);
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
