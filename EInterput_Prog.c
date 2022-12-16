#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EInterput_Private.h"
#include "EInterupt_Cfg.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include<avr/interrupt.h>







/************************************INT0 Control************************************/
#ifdef EINT0

static void (*INT0_PFun) (void);

/*INT0 Enable*/
void EInterupt0_VidEnable(void)
{
    SET_BIT(GICR,INT0);
}

/*INT0 Disable*/
void EInterupt0_VidDisable(void)
{
    CLR_BIT(GICR,INT0);
}

/*INT0 ISC*/
void EInt0_VidSenseControl (void)
{
    /*ISC = Falling Edge*/
#if ISC0_Type == Falling_Edge
    SET_BIT(MCUCR,ISC01);
    CLR_BIT(MCUCR,ISC00);

    /*ISC = Rising Edge*/
#elif ISC0_Type == Rising_Edge
    SET_BIT(MCUCR,ISC01);
    SET_BIT(MCUCR,ISC00);

    /*ISC = On Change */
#elif ISC0_Type == On_Change
    CLR_BIT(MCUCR,ISC01);
    SET_BIT(MCUCR,ISC00);

    /*ISC = Low Level*/
#elif ISC0_Type == Low_Level
    CLR_BIT(MCUCR,ISC01);
    CLR_BIT(MCUCR,ISC00);
#endif
}


/*Call Back Setter INT0*/
void INT0_setCallBack(void (*int0ptr)( void))
{
	INT0_PFun = int0ptr;
}

/*ISR for INT0*/
void __vector_1(void)
{
    INT0_PFun();
}
#endif
/*******************************************************************************************/


/************************************INT1 Control************************************/
#ifdef EINT1

static void (*INT1_PFun) (void);

/*INT1 Enable*/
void EInterupt1_VidEnable(void)
{
    SET_BIT(GICR,INT1);
}

/*INT1 Disable*/
void EInterupt1_VidDisable(void)
{
    CLR_BIT(GICR,INT1);
}

/*INT0 ISC*/
void EInt1_VidSenseControl (void)
{
    /*ISC = Falling Edge*/
#if ISC1_Type == Falling_Edge
    SET_BIT(MCUCR,ISC11);
    CLR_BIT(MCUCR,ISC10);

    /*ISC = Rising Edge*/
#elif ISC1_Type == Rising_Edge
    SET_BIT(MCUCR,ISC11);
    SET_BIT(MCUCR,ISC10);

    /*ISC = On Change */
#elif ISC1_Type == On_Change
    CLR_BIT(MCUCR,ISC11);
    SET_BIT(MCUCR,ISC10);

    /*ISC = Low Level*/
#elif ISC1_Type == Low_Level
    CLR_BIT(MCUCR,ISC11);
    CLR_BIT(MCUCR,ISC10);
#endif
}


/*Call Back Setter INT1*/
void INT1_setCallBack(void (*int1ptr)( void))
{
	INT1_PFun = int1ptr;
}

/*ISR for INT1*/
void __vector_2(void)
{
	INT1_PFun();
}
#endif
/*******************************************************************************************/


/************************************INT2 Control************************************/
#ifdef EINT2

static void (*INT2_PFun) (void);

/*INT2 Enable*/
void EInterupt2_VidEnable(void)
{
    SET_BIT(GICR,INT2);
}

/*INT0 Disable*/
void EInterupt2_VidDisable(void)
{
    CLR_BIT(GICR,INT2);
}

/*INT0 ISC*/
void EInt2_VidSenseControl (void)
{
    /*ISC = Falling Edge*/
#if ISC2_Type == Falling_Edge
    CLR_BIT(MCUCSR,ISC20);

    /*ISC = Rising Edge*/
#elif ISC2_Type == Rising_Edge
    SET_BIT(MCUCSR,ISC20);

#endif
}


/*Call Back Setter INT2*/
void INT2_setCallBack(void (*int2ptr)( void))
{
	INT2_PFun = int2ptr;
}

/*ISR for INT2*/
void __vector_3(void)
{
    INT2_PFun();
}
#endif
/*******************************************************************************************/
