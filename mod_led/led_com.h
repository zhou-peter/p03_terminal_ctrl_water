/*--------------------------------------------------------------|
 *| company | 湖南华中苗木云科技有限公司                        |
 *|-------------------------------------------------------------|
 *| date    | 2019-09-20                                        |
 *|-------------------------------------------------------------|
 *| author  | 冯  辉                                            |
 *|-------------------------------------------------------------|
 *| contact | QQ:258820709    email:fenghuibox@qq.com           |
 *|-------------------------------------------------------------*/


#ifndef __MOD_LED_COM_H
#define __MOD_LED_COM_H


#include "com_includes.h"

#include "dev.h"


//--------------------------------------------------------------------------

//--------------------------------------------------------------------


typedef enum
{
	LED_BATT_OFF = 0,
	LED_BATT_ON,
}EN_LED_BATT;


//--------------------------------------------------------------------------
//--------------------------------------------------------------------



void _allOff( void );

void _allOn( void );


void _errShow( EN_DEV_STATE s );


void _errShowStop( void );


#endif


