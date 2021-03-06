#include <stm32f0xx.h>
#include "stm32f0xx_exti.h"
#include "stm32f0xx_gpio.h"
#include "timer.h"
#include "func.h"
#include<stdio.h>

int row;
int column;

int main(void)
{
	int i, j=0;
	int flag[3];
    int keypad[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int keypad_prev[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    SW_GPIO_Init();
	TIM3_Init(4800, 200);//4800 200
	NVIC_EnableIRQ(TIM3_IRQn);
	TIM3CH1_PWMInit(95);	//d = deg * 0.05 + 0.9 + 520 (us)4680
//
	while(1)
    {
RETURN:
GPIO_WriteBit(GPIOA, GPIO_Pin_5, 1);
		for(i=0;i<3;i++){
			Chenge_Output(i);
			switch(i){
				case 0:
					if	   (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))	keypad[1] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5))	keypad[4] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)) 	keypad[7] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7))	keypad[10] = 1;
					else{
						keypad[1] = -1;
						keypad[4] = -1;
						keypad[7] = -1;
						keypad[10] = -1;

					}
					flag[0] = 1;
					break;
				case 1:
					if	   (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))	keypad[2] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)) 	keypad[5] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6))	keypad[8] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7))	keypad[0] = 1;
					else{
						keypad[2] = -1;
						keypad[5] = -1;
						keypad[8] = -1;
						keypad[0] = -1;
					}
					flag[1] = 1;
					break;
				case 2:
					if	   (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)) 	keypad[3] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5))	keypad[6] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6))	keypad[9] = 1;
					else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) 	keypad[11] = 1;
					else{
						keypad[3] = -1;
						keypad[6] = -1;
						keypad[9] = -1;
						keypad[11] = -1;
					}
					flag[2] = 1;
					break;
				default:
					break;
			}
		}

		if(flag[0]&&flag[1]&&flag[2]){
			for(i=0;i<3;i++)	flag[i] = 0;
			for(i=0;i<12;i++){
				if((keypad_prev[i] != keypad[i])&&(keypad[i] == -1)){
					if(i < 10){
						for (j=0; j<3; j++)	input[j] = input[j+1];
						input[3] = i;
					}else if(i == 10){
						for(j=0;j<4;j++)	input[j] = -1;
					}else if(i == 11){
						GPIO_WriteBit(GPIOA, GPIO_Pin_10,1);
						GPIO_WriteBit(GPIOA, GPIO_Pin_9, 0);
						GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0);
						Check_Pass();
						GPIO_WriteBit(GPIOA, GPIO_Pin_5, 0);

						goto WAIT;
					}
				}
			}
		}
		for (i = 0; i < 12; i++) keypad_prev[i] = keypad[i];
		if(keypad_prev[0]==1){
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[1]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[2]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[3]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[4]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[5]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[6]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[7]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}else if (keypad_prev[8]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 1);
		}else if (keypad_prev[9]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 1);
		}else if (keypad_prev[10]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 1);
		}else if (keypad_prev[11]==1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 1);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 1);
		}else{
			GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);
			GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);
		}
    }

    while(1){
WAIT:
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)){
			TIM3CH1_PWMConfig(95);
			for (i = 0; i < 12; i++)	keypad_prev[i] = -1;
			for(i=0;i<4;i++)	input[i] = -1;
//			GPIO_WriteBit(GPIOA, GPIO_Pin_5, 0);
			goto RETURN;
		}
    }
}



void EXTI4_IRQHandler(void)
{

}

void EXTI5_IRQHandler(void)
{

}

void EXTI6_IRQHandler(void)
{

}
