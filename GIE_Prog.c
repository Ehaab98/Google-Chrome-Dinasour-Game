#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GIE_Private.h"





void GIE_VidEnable(void)
{
    /*GIE Enable*/
    SET_BIT(SREG, GIE);

}


void GIE_VidDisable(void)
{
    /*GIE Disable*/
    CLR_BIT(SREG, GIE);
}
