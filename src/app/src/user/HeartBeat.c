/********************************************************************
//��Ȩ˵��	:Shenzhen E-EYE Co. Ltd., Copyright 2009- All Rights Reserved.
//�ļ�����	:heartbeat.c		
//����		:������������������·����
//�汾��	:V0.1
//������	:dxl
//����ʱ��	:2009.12
//�޸���	:
//�޸�ʱ��	:
//�޸ļ�Ҫ˵��	:
//��ע		:
***********************************************************************/ 

//********************************ͷ�ļ�************************************
#include "stm32f2xx.h"
#include "stm32f2xx_lib.h"
#include "include.h"
//********************************�Զ�����������****************************

//********************************�궨��************************************

//********************************ȫ�ֱ���**********************************
u8 OneHourDelayTimeCountEnableFlag = 0;
u32 OneHourDelayTimeCount = 0;
//********************************�ⲿ����**********************************
extern u8	BlindReportFlag;//ä���ϱ���־��1ΪҪ���ϱ������ϱ���0Ϊ��Ҫ��
extern u8    LawlessAccAlarmEnableFlag;//�Ƿ���𱨾�ʹ�ܱ�־��Ĭ��ʹ�ܣ��յ��˹�ȷ�ϱ�����ʹ��,��Ҫ�������ʹ��
extern u8	SpeedFlag;//�ٶ�����,dxl,2015.5.11,0x00:�ֶ�����,0x01:�ֶ�GPS,0x02:�Զ�����,0x03:�Զ�GPS
//********************************���ر���**********************************
static u32	HeartbeatTimeSpace = 0;//������ʱ����
static u32	Link1HeartbeatCount = 0;//����1����ʱ�����
static u32  Link2HeartbeatCount = 0;//����2����ʱ�����
//********************************��������**********************************

/*********************************************************************
//��������	:Heartbeat_TimeTask(void)
//����		:ÿ��һ���������һ��������
//����		:
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
FunctionalState  HeartBeat_TimeTask(void)
{

	//������1
	Link1HeartbeatCount++;
    Link2HeartbeatCount++;
    
	if((Link1HeartbeatCount >= HeartbeatTimeSpace)&&(HeartbeatTimeSpace > 0))
	{
		//������0
		Link1HeartbeatCount = 0;
	    RadioProtocol_TerminalHeartbeat(CHANNEL_DATA_1);
	}
        
    if((Link2HeartbeatCount >= HeartbeatTimeSpace)&&(HeartbeatTimeSpace > 0))
	{
		//������0
		Link2HeartbeatCount = 0;
	    RadioProtocol_TerminalHeartbeat(CHANNEL_DATA_2);
	}  
    return ENABLE;
}

/*********************************************************************
//��������	:HeartBeat_UpdatePram(void)
//����		:����������ʱ����
//����		:�޲���
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void HeartBeat_UpdatePram(void)
{
	u8	Buffer[5] = {0};
	u8	PramLen;
	PramLen = EepromPram_ReadPram(E2_TERMINAL_HEARTBEAT_ID,Buffer);
	if(E2_TERMINAL_HEARTBEAT_LEN == PramLen)
	{	
		HeartbeatTimeSpace = 0;
		HeartbeatTimeSpace |= Buffer[0] << 24;
		HeartbeatTimeSpace |= Buffer[1] << 16;
		HeartbeatTimeSpace |= Buffer[2] << 8;
		HeartbeatTimeSpace |= Buffer[3];
	}
	else
	{
		HeartbeatTimeSpace = 60;//Ĭ��ֵ,ʵ��Ӧ��ʹ��
	}   
}
/*********************************************************************
//��������	:Heartbeat_ClrHeartbeatCount(u8 channel)
//����		:�������HeartbeatCount
//����		:�޲���
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void Heartbeat_ClrHeartbeatCount(u8 channel)
{
    if(CHANNEL_DATA_1 == channel)
    {
        Link1HeartbeatCount = 0;  
    }
    else if(CHANNEL_DATA_2 == channel)
    {
        Link2HeartbeatCount = 0;
    }   
}

