#ifndef __FUNC
#define __FUNC

extern int pass[4];
extern int input[4];
extern int flagAste;
extern int inputCNT;

void generalInit(void);
int readSW(int status);
void judgeNum(int SWnum);
void checkPass(void);
void DriveMotor(int dig);

#endif /*__FUNC*/