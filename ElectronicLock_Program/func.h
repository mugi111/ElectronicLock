#ifndef __FUNC
#define __FUNC

extern int pass[4];
extern int input[4];
extern int flagAste;
extern int inputCNT;

void SW_GPIO_Init(void);
void SW_EXTI_Init(void);
void OPSwitching(int status);
int readSW(int status);
void checkPass(void);
void judgeNum(int SWnum);
void DriveMotor(int dig);

#endif /*__FUNC*/
