#ifndef __TEST_H
#define __TEST_H

//*********文件包含************
#include "stm32f2xx.h"

//*********宏定义**************


//**********函数声明**********
/*********************************************************************
//函数名称	:Test_GetFlag
//功能		:获得检定状态值
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:0:退出了检定状态;1:当前处于检定状态
*********************************************************************/
u8 Test_GetFlag(void);
/*********************************************************************
//函数名称	:Test_EnterE0
//功能		:E0H,进入或保持检定状态
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:收到检定命令E0时调用此函数
*********************************************************************/
void Test_EnterE0(void);
/*********************************************************************
//函数名称	:Test_EnterE1
//功能		:E1H,进入里程误差测量
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:收到检定命令E1时调用此函数
*********************************************************************/
void Test_EnterE1(void);
/*********************************************************************
//函数名称	:Test_EnterE2
//功能		:E2H,进入脉冲系数误差测量
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:收到检定命令E2时调用此函数
*********************************************************************/
void Test_EnterE2(void);
/*********************************************************************
//函数名称	:Test_EnterE3
//功能		:E3H,进入实时时钟误差测量
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:收到检定命令E3时调用此函数
*********************************************************************/
void Test_EnterE3(void);
/*********************************************************************
//函数名称	:Test_EnterE4
//功能		:E4H,退出检定状态,恢复成正常状态
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:收到检定命令E4时调用此函数
*********************************************************************/
void Test_EnterE4(void);
/*********************************************************************
//函数名称	:Test_ExtiInit
//功能		:外部中断初始化
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
//		:
*********************************************************************/
void Test_ExtiInit(void);
/*********************************************************************
//函数名称	:Test_EnableExtiIsr
//功能		:使能（开）外部中断
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
*********************************************************************/
void Test_EnableExtiIsr(void);
/*********************************************************************
//函数名称	:Pulse_DisableExtiIsr
//功能		:使能（开）外部中断
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
*********************************************************************/
void Test_DisableExtiIsr(void);
/*********************************************************************
//函数名称	:Test_ExtiIsr
//功能		:外部中断
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
//		:
*********************************************************************/
void Test_ExtiIsr(void);
/*********************************************************************
//函数名称	:Test_GpioInit
//功能		:测试引脚初始化为GPIO
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
//		:
*********************************************************************/
void Test_GpioInit(void);
/*********************************************************************
//函数名称	:Test_Tim3Init
//功能		:定时器3初始化,用于输出实时时钟秒信号
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:
//		:
*********************************************************************/
void Test_Tim3Init(void);

#endif
