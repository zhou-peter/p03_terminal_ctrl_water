/*--------------------------------------------------------------|
 *| company | 湖南华中苗木云科技有限公司                        |
 *|-------------------------------------------------------------|
 *| date    | 2019-09-20                                        |
 *|-------------------------------------------------------------|
 *| author  | 冯  辉                                            |
 *|-------------------------------------------------------------|
 *| contact | QQ:258820709    email:fenghuibox@qq.com           |
 *|-------------------------------------------------------------*/
 

#ifndef __DRI_IO_LED_H
#define __DRI_IO_LED_H


#include "com_typedef.h"



//---------led 1----------------------------------------------------------
void driLed1Open( void );

void driLed1Close( void );

void driLed1Toggle( void );

//-------------------------------------------------------------------


extern void driIoLedInit( void );







//----------sleep and wakeup---------------------------------------------------------

void driIoLedToSleep( void );


void driIoLedOnWakeup( void );



#endif

