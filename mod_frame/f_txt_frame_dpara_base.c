
#if 1

/*--------------------------------------------------------------|
 *| company | 湖南华中苗木云科技有限公司                        |
 *|-------------------------------------------------------------|
 *| date    | 2019-09-20                                        |
 *|-------------------------------------------------------------|
 *| author  | 冯  辉                                            |
 *|-------------------------------------------------------------|
 *| contact | QQ:258820709    email:fenghuibox@qq.com           |
 *|-------------------------------------------------------------*/
 

#include "com_includes.h"
#include "dri.h"
#include "timer.h"

#include "f_txt_frame_dpara_base.h"
#include "f_txt_frame_data.h"

#include "cfg_base.h"








// ------------- config ver -----------------------------------------
void paraCfgVerSet( u8 *pPara )
{
	u32 configVer;
	
	configVer = byteMergeto32( pPara[0], pPara[1], pPara[2], pPara[3] );

	cfgCfgVerSet( configVer );
}


void paraCfgVerGet( u8 *pPara )
{
	u32 configVer;

	configVer = cfgCfgVerGet();
	
	u32splitToByte( configVer, pPara );
}




u8 para_config_ver_exe( ST_FRAME *pstFrame )
{	
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.config_ver = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		paraCfgVerSet( pstFrame->pBuf + DPACK_OFFSET_PARA );
		
		//gstN2S.config_ver = 1;

		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;
}




// ------------- def -----------------------------------------

void _defTimerCB( void )
{
	driSoftReset();
}

int paraDefSet( u8 *pPara  )
{
	#include "cfg.h"

	configDef();

	timerStart( 200, 1, _defTimerCB );
	
	return TRUE;
}





u8 para_def_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		if( paraDefSet( pstFrame->pBuf + DPACK_OFFSET_PARA ) == FALSE )
			return FALSE;
		
		gstN2S.def = 1;
		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	return FALSE;
}




// ------------- aes switch -----------------------------------------

#include "aes_switch.h"


int paraAesSwitchSet( u8 *pPara  )
{
	if( *pPara == 0 )
	{
		aesSwitchSet( 0 );
	}
	else if( *pPara == 1 )
	{
		aesSwitchSet( 1 );
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}


u8 paraAesSwitchGet( void )
{
	return aesSwitchGet();
}


u8 para_aes_switch_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.aes_switch = 1;
		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		if( paraAesSwitchSet( pstFrame->pBuf + DPACK_OFFSET_PARA ) == FALSE )
			return FALSE;
		
		//gstN2S.aes_switch = 1;
		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	return FALSE;
}




// ------------- aes key -----------------------------------------

#include "aes_key12.h"

u8 paraAesKeySet( u8 *pPara  )
{
	return aesKey12Set( pPara );
}


u8 paraAesKeyGet( u8 *pPara )
{
	aesKey12Get( pPara );
	return TRUE;
}


u8 para_aes_key_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.aes_key = 1;
		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		if( paraAesKeySet( pstFrame->pBuf + DPACK_OFFSET_PARA ) == FALSE )
			return FALSE;
		
		//gstN2S.aes_key = 1;
		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	return FALSE;
}




// ------------- reboot -----------------------------------------

void _rebootTimerCB( void )
{
	driSoftReset();
}


u8 para_reboot_exe( ST_FRAME *pstFrame )
{
	/*if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.aes_key = 1;
		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else */if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		timerStart( 100, 1, _rebootTimerCB );
		
		//gstN2S.reboot = 1;
		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;
}



// ------------- sleep sec  -----------------------------------------
void paraSleepSecSet( u8 *pPara )
{
	u32 temp;
	
	temp = byteMergeto32( pPara[0], pPara[1], pPara[2], pPara[3] );

	cfgSleepSecSet( temp );
}


void paraSleepSecGet( u8 *pPara )
{
	u32 temp;

	temp = cfgSleepSecGet();
	
	u32splitToByte( temp, pPara );
}




u8 para_sleep_sec_exe( ST_FRAME *pstFrame )
{	
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.sleep_sec = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		paraSleepSecSet( pstFrame->pBuf + DPACK_OFFSET_PARA );
		
		//gstN2S.sleep_sec = 1;

		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;
}


// ------------- work sec  -----------------------------------------
void paraWorkSecSet( u8 *pPara )
{
	u32 temp;
	
	temp = byteMergeto32( pPara[0], pPara[1], pPara[2], pPara[3] );

	cfgWorkSecSet( temp );
}


void paraWorkSecGet( u8 *pPara )
{
	u32 temp;

	temp = cfgWorkSecGet();
	
	u32splitToByte( temp, pPara );
}




u8 para_work_sec_exe( ST_FRAME *pstFrame )
{	
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.work_sec = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	else if( pstFrame->action == TXT_FRAME_ACTION_SET )
	{
		paraWorkSecSet( pstFrame->pBuf + DPACK_OFFSET_PARA );
		
		//gstN2S.work_sec = 1;

		//gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;
}




// ------------- ver -----------------------------------------

u8 paraVerGet( void )
{	
	return 17;
}





u8 para_ver_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.ver = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;

	
}


// ------------- dev type -----------------------------------------
EN_DEV_TYPE paraDevTypeGet( void )
{
	return DEV_TYPE_CTRL;
}




u8 para_dev_type_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.dev_type = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;

}


// ------------- Heartbeat -----------------------------------------
u8 para_heartbeat_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.heartbeat = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;

}



// ------------- battery -----------------------------------------
// u16 :  H + L ( *pPara = H   *(pPara+1) = L )
void paraBatteryGet( u8 *pPara )
{
	#include "dev_vbatt.h"
	
	u16 val;
	
	val = devVbattValGet(); 

	u16splitToByteHL( val, pPara );
}


u8 para_battery_exe( ST_FRAME *pstFrame )
{
	if( pstFrame->action == TXT_FRAME_ACTION_GET )
	{
		gstN2S.battery = 1;

		gB1.txtFrameExeOKhaveRspReport = 1;

		return TRUE;
	}
	
	return FALSE;

}






#endif






