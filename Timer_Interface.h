/*************************************************************************************************************************************************************************/
/*************************************************************************************************************************************************************************/
/*********************************************************    Auther: Mohamed Ehab      **********************************************************************************/
/*********************************************************    File: Interface of Interupt    **********************************************************************************/
/*********************************************************    Date:23/9/2022             **********************************************************************************/
/*********************************************************    Version: 1                **********************************************************************************/
/*********************************************************    Desc:                     **********************************************************************************/
/*************************************************************************************************************************************************************************/
/*************************************************************************************************************************************************************************/




#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void Timer_VidInit(void);
void Timer_VidTimerCount(u8 Copy_U8TimerCount);
void Timer_setCallBack(void (*timerptr)( void), u32 Copy_U32DesTime);



#endif
