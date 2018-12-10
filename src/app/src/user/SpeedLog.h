#ifndef	__SPEED_LOG_H
#define	__SPEED_LOG_H

//*************文件包含***************
#include "stm32f2xx_gpio.h"
#include "stm32f2xx.h"
//*************宏定义****************

//************结构体类型******************

//*************函数声明**************
/*********************************************************************
//函数名称	:SpeedLog_TimeTask(void)
//功能		:记录速度异常
//		:
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:50ms秒调度1次
*********************************************************************/
FunctionalState SpeedLog_TimeTask(void);
/*******************************************************************************
* Function Name  : GetSpeedLogStatus
* Description    : 返回当前速度状态
* Input          : None            
* Output         : None
* Return         : None
*******************************************************************************/
u8 GetSpeedLogStatus(void);
#endif
