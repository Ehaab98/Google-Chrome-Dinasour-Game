




void __vector_1(void)          __attribute__((signal));
void __vector_2(void)          __attribute__((signal));
void __vector_3(void)          __attribute__((signal));

#define MCUCR       *((u8*)0x55)
#define GICR        *((u8*)0x5B)
#define MCUCSR      *((u8*)0x54)


#define INT0 6
#define INT1 7
#define INT2 5
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3
#define ISC20  6


#define Falling_Edge 0
#define Rising_Edge 1
#define Low_Level 2
#define On_Change 3



