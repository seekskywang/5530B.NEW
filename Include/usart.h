/******************** (C) COPYRIGHT 2014 KUNKIN********************
 * ����    :usart.h
 * ����    :����
 * ����    :
 * �������:
 * Ӳ������:
 * �޸�����:2015-2-5
*******************************************************************/
	

#ifndef _usart_h_
#define _usart_h_
#define USART_REC_LEN  			400*1024 //�����������ֽ��� 55K
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����


extern u16 USART_RX_STA; //?????? 
extern u32 USART_RX_CNT;  //?????? 

extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 


void USART_Configuration(void);//���ڳ�ʼ������
void UART1_Send(void);
static void USART1_NVIC_Config(void);

#endif
