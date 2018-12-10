/*************************************************************************
*
* Copyright (c) 2008,深圳市伊爱高新技术开发有限公司
* All rights reserved.
*
* 文件名称 : EeyeLib.h
* 功能     : E-EYE 库函数
*
* 当前版本 : 1.0
* 开发者   : zhulin
* 修改时间 : 2008年4月15日
*
* 历史版本 : 
* 开发者   : 
* 完成时间 : 
* 
* 备注 :
*************************************************************************/
#ifndef     _E_EYE_LIB_H_ 
#define     _E_EYE_LIB_H_ 

#include "stm32f2xx.h"

extern const u8 ASC[16];
/********************************************************************
* 名称 : CharCopy
* 功能 : 字符串拷贝
*
* 输入: strDest : 目的 字符串 
*       strSrc  : 源   字符串
* 输出: len : 拷贝的长度
********************************************************************/
u8 CharCopy(const u8 *strSrc, u8  *strDest);

/********************************************************************
* 名称 : CharCmp
* 功能 : 比较2字串，返回0，相等；返回1，不等。
*
* 输入: strDest : 目的 字符串 
*       strSrc  : 源   字符串
		len : 比较字符串的长度
* 输出: 
********************************************************************/
u8 CharCmp(u8  * buff, const u8 * source, u8 length);

/********************************************************************
* 名称 : ClearMem
* 功能 : 复位 存储器区域值
*
* 输入: ptray : 开始地址
*       len   : 长度
* 输出: 无
********************************************************************/
void ClearMem(u8 *ptray, u8 len);

/********************************************************************
* 名称 : CalTel
* 功能 : 计算电话号码个数，"**,**"
*
* 输入: teldat :电话号码列表
*       length :列表数据长度
* 输出: relen  :有效电话号码列表长度
*		telcount:电话号码个数，0无电话，>0电话个数
* 全局变量: 
* 调用函数:
*
* 中断资源:  (没有,不写)
*
* 备注: (修改记录内容、时间)
********************************************************************/
u8 CheckTelFormat(u8  * teldat, u8 length, u8  * relen);
/********************************************************************
* 名称 : CopyLenChar
* 功能 : 拷贝 字符串strSrc前N个字符到字符串strDest里
*
* 输入: ptray : 开始地址
*       len   : 长度
* 输出: 无
********************************************************************/
//void CopyLenChar(u8  *strDest, u8 * strSrc, u8 length);

/********************************************************************
* 名称 : StrLenCompare
* 功能 : 比较 字符串buff 和 字符串source 前 length 个字符
*
* 输入: buff   : 比较的字符串0
*       source : 比较的字符串1
*       length : 比较的长度
* 输出: state  : 0:两个字符串相等;  非0:两个字符串不等;
********************************************************************/
//u8 StrLenCompare(u8  * buff, u8 * source, u8 length);

/********************************************************************
* 名称 : FindStr
* 功能 : 在一个字串中查找相符的字串
*
* 输入: buff   : 
*       source : 
*       length : 
* 输出: state  : 
********************************************************************/
//在一个字串中查找相符的字串
//u8 FindStr(u8  * buff, u8 * source, u8 length);

/********************************************************************
* 名称 : Convert2Asc2Hex
* 功能 : 将2个字节的ASCII码 合成 1个HEX字节
*
* 输入: source : 要转换的 ASCII码数组
*       destin : 转换后的 HEX数组 
*       length : 转换的 ASCII码数组长度
* 输出: 无
********************************************************************/
u8 Convert2Asc2Hex(u8  * source, u8 * destin, u32 length);

/********************************************************************
* 名称 : ConvertDec2Hex
* 功能 : 将 2个字节的10进制数字 转换为 16进制数据
*
* 输入: ch1 : 10进制数据的 10位
*       ch2 : 10进制数据的 个位
* 输出: hexData : 16进制数据
********************************************************************/
u8 ConvertDec2Hex(u8 ch1, u8 ch2);

/********************************************************************
* 名称 : ConvertHex2Asc
* 功能 : 将 1个HEX字节 分解为 2个字节的ASCII码
*
* 输入: source : 
*       destin : 
*       length :
* 输出: 无
********************************************************************/
u32 ConvertHex2Asc(u8 * source, u8 * destin, u32 length);

/********************************************************************
* 名称 : CalCheckSum
* 功能 : 计算 数组的 校验和(异或)
*
* 输入: buff   : 要校验的数组
*       length : 需要校验的数据长度
* 输出: result : 0: 表示校验码正确;  非0:错误
********************************************************************/
u8 CalCheckSum(u8 * buff, u32 length);

/********************************************************************
* 名称 : ConvertAsc2Asc
* 功能 : 
*
* 输入: source : 
*       destin :
*       length : 
* 输出: 无
********************************************************************/
//解析移位超作
void ConvertAsc2Asc(u8  * source, u8  * destin, u8 length);

#endif
