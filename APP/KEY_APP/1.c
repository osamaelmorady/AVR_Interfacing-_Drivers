/*
 * MAIN.C
 *
 *  Created on: Oct 22, 2020
 *      Author: Osama Elmorady
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include <util/delay.h>




int main(void)
{
u8 x;
KEYPAD_VidInit() ;
LCD_VidInit() ;

LCD_VidSetPosition(0,2) ;

while(1)
{


x=KEYPAD_U8GetKey() ;
if (x=='#') {
}

else {

LCD_VidSendData(x) ;

}


}

return 0;
}
