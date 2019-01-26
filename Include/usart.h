/******************** (C) COPYRIGHT 2014 KUNKIN********************
 * 名称    :usart.h
 * 作者    :李振
 * 描述    :
 * 软件功能:
 * 硬件外设:
 * 修改日期:2015-2-5
*******************************************************************/
	

#ifndef _usart_h_
#define _usart_h_
#define USART_REC_LEN  			400*1024 //定义最大接收字节数 55K
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收


extern u16 USART_RX_STA; //?????? 
extern u32 USART_RX_CNT;  //?????? 


void USART_Configuration(void);//串口初始化函数
void UART1_Send(void);
static void USART1_NVIC_Config(void);

#endif
