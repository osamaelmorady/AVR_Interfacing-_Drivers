/*
 * MAIN.C
 *
 *  Created on: Oct 22, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include <util/delay.h>




int main(void)
{

KEYPAD_VidInit() ;
LCD_VidInit() ;

LCD_VidSetPosition(0,2) ;

while(1)
{

u8 X='\0';
KEYPAD_U8GetKey(&X) ;
if (X=='\0') {
}

else {

LCD_VidSendData(X) ;

}


}

return 0;
}
