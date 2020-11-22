#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_



/********************************************/
/**********   EXTI Mode Selection   *********/
/********************************************/
//#define EXTI0_MODE	 LOW_LEVEL
//#define EXTI0_MODE	 ON_CHANGE
#define EXTI0_MODE	 FALLING
//#define EXTI0_MODE	 RISING



//#define EXTI1_MODE	 LOW_LEVEL
//#define EXTI1_MODE	 ON_CHANGE
#define EXTI1_MODE	 FALLING
//#define EXTI1_MODE	 RISING




#define EXTI2_MODE	 FALLING
//#define EXTI2_MODE	 RISING






/********************************************/
/********** INT Channel Selection ***********/
/********************************************/
typedef enum EXTI_Channels
{
	INT0=0 ,
	INT1   ,
	INT2

}EXTI_Channels ;






#endif
