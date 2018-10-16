#include "AD7689.h"
#include "GPIO.h"
#include "my_register.h" 
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_rcc.h"

extern struct bitDefine
{
    unsigned bit0: 1;
    unsigned bit1: 1;
    unsigned bit2: 1;
    unsigned bit3: 1;
    unsigned bit4: 1;
    unsigned bit5: 1;
    unsigned bit6: 1;
    unsigned bit7: 1;
} flagA, flagB,flagC,flagD,flagE,flagF,flagG;
// Device operation Macro definition.
#define AD7689_CNV_0			GPIO_ResetBits(GPIOB,GPIO_Pin_6);
#define AD7689_CNV_1			GPIO_SetBits(GPIOB,GPIO_Pin_6);
vu16 AD7689_Buffer[8];
vu16 Ad7689_Fit_Imon[10];
vu16 Ad7689_Fit_Imon1[10];
vu16 Ad7689_Fit_Vmon[10];
void Bubble_sort(vu16 *D_temp,vu8 num);
void AD7689_InitializeSPI2(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  //SPI_InitTypeDef  SPI_InitStructure;
  /*!< SD_SPI_CS_GPIO, SD_SPI_MOSI_GPIO, SD_SPI_MISO_GPIO, SD_SPI_DETECT_GPIO 
       and SD_SPI_SCK_GPIO Periph clock enable 
	// 	 RCC_AHBPeriphClockCmd(FLASH_CS_PIN_SCK|FLASH_SCK_PIN_SCK|FLASH_MISO_PIN_SCK | FLASH_MOSI_PIN_SCK, ENABLE);
  !< SD_SPI Periph clock enable */
	/*RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
	
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//inv
	GPIO_Init(GPIOA, &GPIO_InitStructure);//
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;//PC2~3���ù������	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PB10���ù������	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
	
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource2,GPIO_AF_SPI2); //PC2����Ϊ SPI2
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource3,GPIO_AF_SPI2); //PBC3����Ϊ SPI2
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_SPI2); //PB13����Ϊ SPI2
	AD7689_CNV_1;
	AD7689_Delay();
	AD7689_CNV_0;
	//����ֻ���SPI�ڳ�ʼ��
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;		//����SPI�����ݴ�С:SPI���ͽ���16λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI2, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	
	SPI_Cmd(SPI2, ENABLE);*/ //ʹ��SPI����*/
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//inv
	GPIO_Init(GPIOB, &GPIO_InitStructure);//

	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//sck,
	GPIO_Init(GPIOB, &GPIO_InitStructure);//
	
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//MOSI
	GPIO_Init(GPIOB, &GPIO_InitStructure);//
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//MISO
	GPIO_Init(GPIOB, &GPIO_InitStructure);//
	
	AD7689_CNV_1;
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//MOSI=0
	GPIO_SetBits(GPIOB,GPIO_Pin_3);//SCK=0
}

vu16 SPI_AD7689_Read(vu16 AD7689_CFG, vu16 AD7689_INx)
{
	vu16 AD7689_Config=0;
	vu16 AD7689_Data;
	vu8 i;
	AD7689_Config = AD7689_CFG<<13|AD7689_INCC<<10|AD7689_INx<<7|AD7689_BW<<6|AD7689_REF<<3|AD7689_SEQ<<1|AD7689_RB;//д�����ò���
	AD7689_Config <<=2;
	AD7689_CNV_0;
	AD7689_Delay();
	for(i=0;i<16;i++)
	{
		if(AD7689_Config&0x8000)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_5);//MOSI=1
		}
		else
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);//MOSI=0
		}
		AD7689_Delay();
		GPIO_ResetBits(GPIOB,GPIO_Pin_3);//SCK=0
		AD7689_Delay();
		AD7689_Config <<= 1;
		GPIO_SetBits(GPIOB,GPIO_Pin_3);//SCK=1
		AD7689_Delay();
		AD7689_Data <<=1;
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4))
		{
			AD7689_Data |=1;
		}
	}
	AD7689_Delay(); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_3);//SCK=0
	AD7689_Delay(); 
	AD7689_CNV_1;
	AD7689_Delay(); 
	return AD7689_Data;
}

/************************************************************************/
/* Function Name:	TM7707_TransferByte.								*/
/* Purpose:			Send of recive a byte.								*/
/* Resources:		SPI controler.										*/
/* Params:																*/
/*	@uiTxData:			The byte data will be sent.						*/
/* Return:			The byte data recived.						+		*/
/* Limitation:		None.												*/
/************************************************************************/
vu16 AD7689_TransferByte(vu16 uiTxData)
{
	vu8 uiRxData;
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
	SPI_I2S_SendData(SPI2,uiTxData);
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
	uiRxData = SPI_I2S_ReceiveData(SPI2);
	return uiRxData;
}
/************************************************************************/
/* Function Name:	AD7689_Delay.									*/
/* Purpose:			Wait for device DRDY signal.						*/
/* Resources:		DRDY GPIO pin.										*/
/* Params:			None.												*/
/* Return:			None.												*/
/* Limitation:		None.												*/
/************************************************************************/
void AD7689_Delay(void)
{
	vu16 count ;
  for(count = 1000; count != 0; count--);
}
void AD7689_Delay1(void)
{
	vu16 count ;
  for(count = 3000; count != 0; count--);
}
void AD7689_Scan_CH(void)
{
	static vu8 I_cont,I1_cont,V_cont;
	vu8 i,f;
	vu32 sum1;
	vu16 var_chI,var_chV,var_chV1;
	for(i=0;i<8;i++)
		{
			AD7689_Buffer[i]=SPI_AD7689_Read(1, i);
			AD7689_Delay1();
			var_chI=AD7689_Buffer[3];
			var_chV=AD7689_Buffer[2];
			var_chV1=AD7689_Buffer[4];
		}
	/***************��Դ�����˲�**********************/
	Ad7689_Fit_Imon1[I1_cont++]=var_chI;
	if(I1_cont==8)
	{
		I1_cont=0;
	}
	Bubble_sort( Ad7689_Fit_Imon1,8);//����Ӵ�С
	sum1=0;
	for(f=2;f<6;f++)
	{
		sum1 +=Ad7689_Fit_Imon1[f];
	}
	Imon_value=sum1/4;
	/***************���ص�ѹ�˲�**********************/
	Ad7689_Fit_Vmon[V_cont++]=var_chV;
	if(V_cont==8)
	{
		V_cont=0;
	}
	Bubble_sort( Ad7689_Fit_Vmon,8);//����Ӵ�С
	sum1=0;
	for(f=2;f<6;f++)
	{
		sum1 +=Ad7689_Fit_Vmon[f];
	}
	Vmon1_value=sum1/4;
/***************���ص����˲�**********************/
	Ad7689_Fit_Imon[I_cont++]=var_chV1;
	if(I_cont==8)
	{
		I_cont=0;
	}
	Bubble_sort( Ad7689_Fit_Imon,8);//����Ӵ�С
	sum1=0;
	for(f=2;f<6;f++)
	{
		sum1 +=Ad7689_Fit_Imon[f];
	}
	Imon1_value=sum1/4;
}

/*
ð���������ֵ�ڵ�һλ����Сֵ�����һλ
 */
void Bubble_sort(vu16 *D_temp,vu8 num)
{
	unsigned int _temp;
	unsigned char m,n;
	for(m=0;m<num;m++)
	{
		for(n=m;n<num;n++)
		{
			if(D_temp[n]>D_temp[m])//����ֵ���ڵ�һλ
			{
				_temp = D_temp[m];
				D_temp[m] =D_temp[n];
				D_temp[n]=_temp;		
			}
		}	
	}
}
