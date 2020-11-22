/*
 * LCD_Interface.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#include "LIB/ERROR_STATE.h"

/*********************************************/
/*********  Send a Character to LCD  *********/
/*********************************************/
ErrorState LCD_EnuSendData (u8 Copy_U8Data) ;





/*********************************************/
/***********  Send a Command to LCD  *********/
/*********************************************/
ErrorState LCD_EnuSendCommand (u8 Copy_U8Command) ;





/***********************************************/
/***********  Initialization of a LCD  *********/
/***********  LCD Connection Selection *********/
/*********** _8BIT MODE  or _4BIT MODE *********/
/***********************************************/
ErrorState LCD_EnuInit(void) ;






/****************************************************************/
/***********  Set the LCD Cursor Position on the Screen *********/
/****************************************************************/
ErrorState LCD_EnuSetPosition ( u8 Copy_U8RowNumber,u8 Copy_U8ColumnNumber ) ;






/****************************************************************/
/***********  Write a Sentence ( string ) on the Screen *********/
/****************************************************************/
ErrorState LCD_EnuWriteString (u8 * Copy_PU8Name) ;






/*********************************************************************/
/***********  Write a Sentence ( INT Numbers ) on the Screen *********/
/*********************************************************************/
ErrorState LCD_EnuWriteIntNum(s32 Copy_S32IntData) ;






/***********************************************************************/
/***********  Write a Sentence ( Float Numbers ) on the Screen *********/
/***********************************************************************/
ErrorState LCD_EnuWriteFloatNum(f32 Copy_F32IntData) ;






/*******************************************************************/
/***********  Record a Special Character in the LCD CG-RAM *********/
/*******************************************************************/
ErrorState LCD_EnuRecordSpecialChar (u8 Copy_U8PatternMatrix[8],u8 Copy_U8CGRAMPos) ;







/**************************************************************************/
/***********  Write a Special Character on the Screen form CG-RAM *********/
/**************************************************************************/
ErrorState LCD_EnuWriteSpecialChar ( u8 Copy_U8CharPattern ) ;



























#endif /* LCD_INTERFACE_H_ */
