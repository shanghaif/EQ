/*******************************************************************************
 * File Name:			oilwearcalib.h 
 * Function Describe:	
 * Relate Module:		
 * Writer:				joneming
 * Date:				2013-05-25
 * Rewriter:
 * Date:		
 *******************************************************************************/
#ifndef __OILWEARCALIB_H
#define __OILWEARCALIB_H

#define CALIB_OIL_WEAR      //是否使用油耗校准

#define OIL_CALIB_MAX_NUM  25//油耗最大校准点数
//***********************函数声明*****************************

LZM_RET TaskOilPointShow(LZM_MESSAGE *Msg);
/*************************************************************
** 函数名称: TaskCalibOilPointNumber
** 功能描述: 油量标定点数菜单
** 入口参数: 无
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
LZM_RET TaskCalibOilPointNumber(LZM_MESSAGE *Msg);

/*******************************************************************************
** 函数名称: OilWear_GetSubjoinInfoCurOilVal
** 功能描述: 取得当前油量附加信息包(包括附加信息ID、长度、附加信息体)
** 入口参数: 需要保存油量附加信息包的首地址
** 出口参数: 
** 返回参数: 油量附加信息包的总长度
*******************************************************************************/
unsigned char OilWear_GetSubjoinInfoCurOilVal(unsigned char *data);
/*******************************************************************************
** 函数名称: OilWear_GetSubjoinInfoCurOilResVal
** 功能描述: 取得当前油量电阻值附加信息包(包括附加信息ID、长度、附加信息体)
** 入口参数: 需要保存油量电阻值附加信息包的首地址
** 出口参数: 
** 返回参数: 油量电阻值附加信息包的总长度
*******************************************************************************/
unsigned char OilWear_GetSubjoinInfoCurOilResVal(unsigned char *data);
/**************************************************************
*Function: OilWear_UartDataProtocolParse
*Describe: 油耗数据解析
*入口参数: pBuffer数据首地址,Len数据长度
*注意:     24 F1 05 X1 X2 X3 4F FF ,"获得油耗"BSJ协议
           24 F1 05 03 99 02 94 FF ,"获得油耗"国迈GM协议 
**************************************************************/
void OilWear_UartDataProtocolParse(unsigned char *pBuffer,unsigned short Len);
/*************************************************************
** 函数名称: OilWear_UpdatePram
** 功能描述: 读取油量标定参数并计算系数
** 入口参数: 
** 出口参数: 无
** 返回参数: 无
** 全局变量: 无
** 调用模块: 无
*************************************************************/
void OilWear_UpdatePram(void);
/*************************************************************
** 函数名称: OilWear_GetCalibTestValue
** 功能描述: 根据测量值获得实际油量值
** 入口参数: 测量值(放大10倍)
** 出口参数: 无
** 返回参数: 实际油量值(放大10倍)
** 全局变量: 
** 调用模块: 
*************************************************************/	
float OilWear_GetCalibTestValue(unsigned short testVal);
/*************************************************************
** 函数名称: OilWear_SetCalibOilSaveValue
** 功能描述: 把油量标定值保存到结构体中
** 入口参数: index保存编号(从0开始),oilVal:油量值(放大10倍,即单位为0.1L),testVal:测量值(放大10倍)
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
void OilWear_SetCalibOilSaveValue(unsigned char index,unsigned short oilVal,unsigned short testVal);
/*************************************************************
** 函数名称: OilWear_SaveCalibOilParamToFram
** 功能描述：把油量标定参数结构体保存到铁电中
** 入口参数: 无
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
void OilWear_SaveCalibOilParamToFram(void);
/*************************************************************
** 函数名称: OilWear_SetCalibFullOil
** 功能描述: 设置满油量
** 入口参数: fullOil满油量(放大10倍)
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
void OilWear_SetCalibFullOil(unsigned short fullOil);
/*************************************************************
** 函数名称: OilWear_SetCalibPoint
** 功能描述: 设置油量标定点数
** 入口参数: CalibPoint标定点数
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
void OilWear_SetCalibPoint(unsigned char CalibPoint);
/*************************************************************
** 函数名称: OilWear_CalCoefAndC
** 功能描述：计算当前标定系数 
** 入口参数: 无
** 出口参数: 无
** 返回参数: 无
** 全局变量: 
** 调用模块: 
*************************************************************/	
void OilWear_CalCoefAndC(void);
/*************************************************************
** 函数名称: OilWear_DisposeEIExpandProtocol
** 功能描述: 油耗伊爱扩展协议
** 入口参数: pBuffer:消息体内容首地址,BufferLen消息体内容长度
** 出口参数: 
** 返回参数: 
** 全局变量: 无
** 调用模块: 无
*************************************************************/
unsigned char OilWear_DisposeEIExpandProtocol(unsigned char *pBuffer, unsigned short BufferLen);
/*************************************************************
** 函数名称: OilWear_Updata16PINPortPeripheralParam
** 功能描述: 更新16pin接口接的外设参数
** 入口参数: (沿用EGS702的32pin的Pos接口参数ID)
** 出口参数: 
** 返回参数: 
** 全局变量: 无
** 调用模块: 无
*************************************************************/
void OilWear_Updata16PINPortPeripheralParam(void);
/*************************************************************
** 函数名称: OilWear_Get16PINPortInsertBSJOilFlag
** 功能描述: 16pin接口接的外设类型,是否接入博实结油位传感器模块
** 入口参数: 
** 出口参数: 
** 返回参数: 1:接入,0:没有接入
** 全局变量: 无
** 调用模块: 无
*************************************************************/
unsigned char OilWear_Get16PINPortInsertBSJOilFlag(void);
/*************************************************************
** 函数名称: OilWear_Get16PINPortInsertJointechOilFlag
** 功能描述: 16pin接口接的外设类型,是否接入久通机电油位传感器模块
** 入口参数: 
** 出口参数: 
** 返回参数: 1:接入,0:没有接入
** 全局变量: 无
** 调用模块: 无
*************************************************************/
unsigned char OilWear_Get16PINPortInsertJointechOilFlag(void);
#endif//__OILWEARCALIB_H
/*******************************************************************************
 *                             end of module
 *******************************************************************************/

