#ifndef __FUNC
#define __FUNC

extern int pass[4];
extern int input[4];
extern int flagAste;
extern int inputCNT;

void SW_GPIO_Init(void);
void Chenge_Output(int status);
void Check_Pass(void);
void DriveServo(int dig);

#endif /*__FUNC*/
