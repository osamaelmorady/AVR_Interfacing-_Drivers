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

#define SIZE   6
#define Not_Pressed  '\0'


void clear_line(u8 num) ;
void free_name(u8 name[SIZE]) ;
u8 name_check(u8 name[SIZE]) ;
u8 pass_check(u8 password[SIZE]) ;




u8 username[SIZE]="15018"  ;
u8 userpassword[SIZE] = "13+89" ;
u8 user[SIZE]={} ;
u8 pass[SIZE]={} ;


u8 key = Not_Pressed ;
u8 trials=3 ;





int main(void)
{

KEYPAD_VidInit() ;
LCD_VidInit() ;
DIO_EnuSetPinDir(PIN16,OUTPUT) ;
DIO_EnuSetPinDir(PIN17,OUTPUT) ;
DIO_EnuSetPinDir(PIN18,OUTPUT) ;


u8 char_num=0 ;u8 k=0 ;
while(1)
{

	LCD_VidSetPosition(0,0) ;
	LCD_VidWriteString("Enter Username :") ;

	key=Not_Pressed;
	KEYPAD_U8GetKey(&key) ;
	if (key==Not_Pressed) { continue ; }

	else
	{

	   if( (key>='0' && key <='9') || (key=='+') || (key=='-')  || (key=='/')|| (key=='*') )
	   	{   LCD_VidSetPosition(1,2+k) ;
	   		user[char_num]=key ;
	   		LCD_VidSendData(key) ;
	   		char_num++;
	   		k++ ;
	   	}

		if (key=='E')
		{
			if (name_check(user) )
			{
				free_name(user) ;
				k=0 ;
				char_num=0 ;
				LCD_VidSendCommand(0x01) ;

				while(trials!=0)
				{
					u8 return_key=0 ;
					LCD_VidSetPosition(0,0) ;
					LCD_VidWriteString("Enter Password") ;

					key=Not_Pressed;
					KEYPAD_U8GetKey(&key) ;

					if( (key>='0' && key <='9') || (key=='+') || (key=='-') || (key=='/')|| (key=='*'))
						   	{   LCD_VidSetPosition(1,2+k) ;
						   		pass[char_num]=key ;
						   		LCD_VidSendData('*') ;
						   		char_num++;
						   		k++ ;
						   	}

					if (key=='E')
							{
								if(pass_check(pass))
									{
										free_name(pass) ;
										LCD_VidSendCommand(0x01) ;
										while(1)
										{
											LCD_VidSetPosition(0,0) ;
											LCD_VidWriteString("Fan   5 6") ;
											LCD_VidSetPosition(1,0) ;
											LCD_VidWriteString("Light 8 9") ;
											key=Not_Pressed;
											KEYPAD_U8GetKey(&key) ;
											return_key=0 ;
											switch(key)
											{
											case '5' :	DIO_EnuSetPinVal(PIN16,HIGH) ;			break ;
											case '6' :	DIO_EnuSetPinVal(PIN16,LOW ) ;			break ;
											case '8' :	DIO_EnuSetPinVal(PIN18,HIGH) ;			break ;
											case '9' :	DIO_EnuSetPinVal(PIN18,LOW ) ;			break ;
											case 'C' :	return_key=1	;				        break ;
											default :break ;
											}

											if(return_key) {break ;}

										}
									}
								else
									{
										free_name(pass) ;
										k=0;
										char_num=0;
										LCD_VidSendCommand(0x01) ;
										LCD_VidSetPosition(0,0) ;
										LCD_VidWriteString("Wrong Password") ;
										_delay_ms(400) ;
										LCD_VidSendCommand(0x01) ;
										trials-=1 ;
											if (trials==0)
											{
												DIO_EnuSetPinVal(PIN17,HIGH) ;
											}
									}
							}
					else if(key=='C' && k>0 )
							{
								pass[char_num]='\0' ;
								char_num-=1 ;
								k-=1 ;
								LCD_VidSetPosition(1,2+k) ;
								LCD_VidSendData(' ') ;

							}

					if(return_key) {LCD_VidSendCommand(0x01) ;   break ;}
				}
			}
			else
			{
				free_name(user) ;
				k=0 ;
				char_num=0 ;
				LCD_VidSendCommand(0x01) ;
				LCD_VidSetPosition(0,0) ;
				LCD_VidWriteString("Wrong username") ;
				_delay_ms(400) ;
			}
		}
		else if(key=='C' && k>0 )
		{
			user[char_num]='\0' ;
			char_num-=1 ;
			k-=1 ;
			LCD_VidSetPosition(1,2+k) ;
			LCD_VidSendData(' ') ;

		}


	}


}

return 0;
}




void clear_line(u8 num)
{
	if( num==0 || num==1 )
	{	LCD_VidSetPosition(num,0) ;
		LCD_VidWriteString("                                ") ;
	}
}


void free_name(u8 name[SIZE])
{
	for (u8 i=0;i<=SIZE;i++)
	{
		name[i]='\0' ;
	}

}



u8 name_check(u8 name[SIZE])
{
	u8 flag=0 ;
	for (u8 i=0;username[i]!='\0';i++)
	{
		if (name[i]!=username[i])
		{
			flag=0 ;
			break ;
		}
		else
		{
			flag=1 ;
		}

	}

	return flag ;

}



u8 pass_check(u8 password[SIZE])
{

	u8 flag=0 ;
		for (u8 i=0;userpassword[i]!='\0';i++)
		{
			if (password[i]!=userpassword[i])
			{
				flag=0 ;
				break ;
			}
			else
			{
				flag=1 ;
			}

		}

		return flag ;

}

