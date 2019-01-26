#include "internalflash.h"

/****************************************************************************
* ��    ��: ��ȡ��ַAddress��Ӧ��sector���
* ��ڲ�������ַ
* ���ڲ�����sector���
* ˵    ������
* ���÷�������
****************************************************************************/
uint16_t Flash_GetSector(uint32_t Address)
{
uint16_t sector = 0;
if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
{
sector = FLASH_Sector_0;  
}
else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
{
sector = FLASH_Sector_1;  
}
else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
{
sector = FLASH_Sector_2;  
}
else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
{
sector = FLASH_Sector_3;  
}
else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
{
sector = FLASH_Sector_4;  
}
else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
{
sector = FLASH_Sector_5;  
}
else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
{
sector = FLASH_Sector_6;  
}	
else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
{
sector = FLASH_Sector_7;  
}
else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
{
sector = FLASH_Sector_8;  
}
else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
{
sector = FLASH_Sector_9;  
}
else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
{
sector = FLASH_Sector_10;  
}
else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11))*/
{
sector = FLASH_Sector_11;  
}
return sector;
}

/****************************************************************************
* ��    ��: ����ָ������
* ��ڲ�����SectorNum ������
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_EraseSector(uint16_t SectorNum)
{
FLASH_Unlock(); 
FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
if (FLASH_EraseSector(SectorNum, VoltageRange_3) != FLASH_COMPLETE) while (1);
FLASH_Lock(); 
}

/****************************************************************************
* ��    ��: д�볤��Ϊlength��32λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_32��Ҫд�������ָ��
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Write32BitDatas(uint32_t address, uint16_t length, int32_t* data_32)
{
uint16_t StartSector, EndSector,i;
FLASH_Unlock(); //����FLASH�������FLASH��д���ݡ�
FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
StartSector = Flash_GetSector(address);  //��ȡFLASH��Sector���
EndSector = Flash_GetSector(address+4*length);
for (i = StartSector; i < EndSector; i += 8)  //ÿ��FLASH�������8���ɲο��ϱ�FLASH Sector�Ķ��塣
{
if (FLASH_EraseSector(i, VoltageRange_3) != FLASH_COMPLETE) while (1);
}
for(i=0; i<length; i++)
{
if (FLASH_ProgramWord(address, data_32[i]) == FLASH_COMPLETE)   //��DATA_32д����Ӧ�ĵ�ַ��
{
   address = address + 4;
}
else
{ 
while (1);
}
}
FLASH_Lock();  //��FLASH����ҪFLASH���ڽ���״̬��
}

/****************************************************************************
* ��    ��: ��ȡ����Ϊlength��32λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_32  ָ�����������
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Read32BitDatas(uint32_t address, uint16_t length, int32_t* data_32)
{
uint8_t i;
for(i=0; i<length; i++)
{
data_32[i]=*(__IO int32_t*)address;
address=address + 4;
}
}

/****************************************************************************
* ��    ��: д�볤��Ϊlength��16λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_16��Ҫд�������ָ��
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Write16BitDatas(uint32_t address, uint16_t length, int16_t* data_16)
{
uint16_t StartSector, EndSector,i;
FLASH_Unlock(); //����FLASH�������FLASH��д���ݡ�
FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
StartSector = Flash_GetSector(address);  //��ȡFLASH��Sector���
EndSector = Flash_GetSector(address+2*length);
for (i = StartSector; i < EndSector+1; i += 8)  //ÿ��FLASH�������8���ɲο��ϱ�FLASH Sector�Ķ��塣
{
if (FLASH_EraseSector(i, VoltageRange_3) != FLASH_COMPLETE) while (1);
}
for(i=0; i<length; i++)
{
if (FLASH_ProgramHalfWord(address, data_16[i]) == FLASH_COMPLETE)   
{
   address = address + 2;
}
else
{ 
while (1);
}
}
FLASH_Lock();  //��FLASH����ҪFLASH���ڽ���״̬��
}

/****************************************************************************
* ��    ��: ��ȡ����Ϊlength��16λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_16  ָ�����������
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Read16BitDatas(uint32_t address, uint16_t length, int16_t* data_16)
{
uint8_t i;
for(i=0; i<length; i++)
{
data_16[i]=*(__IO int16_t*)address;
address=address + 2;
}
}

/****************************************************************************
* ��    ��: д�볤��Ϊlength��8λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_8��Ҫд�������ָ��
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Write8BitDatas(uint32_t address, uint16_t length, int8_t* data_8)
{
uint16_t StartSector, EndSector,i;
FLASH_Unlock(); //����FLASH�������FLASH��д���ݡ�
FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
StartSector = Flash_GetSector(address);  //��ȡFLASH��Sector���
EndSector = Flash_GetSector(address+length);
for (i = StartSector; i < EndSector; i += 8)  //ÿ��FLASH�������8���ɲο��ϱ�FLASH Sector�Ķ��塣
{
if (FLASH_EraseSector(i, VoltageRange_3) != FLASH_COMPLETE) while (1);
}
for(i=0; i<length; i++)
{
if (FLASH_ProgramByte(address, data_8[i]) == FLASH_COMPLETE)   
{
   address++;
}
else
{ 
while (1);
}
}
FLASH_Lock();  //��FLASH����ҪFLASH���ڽ���״̬��
}

/****************************************************************************
* ��    ��: ��ȡ����Ϊlength��8λ����
* ��ڲ�����address����ַ
length�� ���ݳ���
data_8  ָ�����������
* ���ڲ�������
* ˵    ������
* ���÷�������
****************************************************************************/
void Flash_Read8BitDatas(uint32_t address, uint16_t length, int8_t* data_8)
{
uint8_t i;
for(i=0; i<length; i++)
{
data_8[i]=*(__IO int8_t*)address;
address++;
}
}


//��ȡָ����ַ�İ���(16λ����)
//faddr:����ַ(�˵�ַ����Ϊ2�ı���!!)
//����ֵ:��Ӧ����.
u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}
#if STM32_FLASH_WREN	//���ʹ����д   
//������д��
//WriteAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��   
void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//��ַ����2.
	}  
} 
//��ָ����ַ��ʼд��ָ�����ȵ�����
//WriteAddr:��ʼ��ַ(�˵�ַ����Ϊ2�ı���!!)
//pBuffer:����ָ��
//NumToWrite:����(16λ)��(����Ҫд���16λ���ݵĸ���.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //�ֽ�
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];//�����2K�ֽ�
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //������ַ
	u16 secoff;	   //������ƫ�Ƶ�ַ(16λ�ּ���)
	u16 secremain; //������ʣ���ַ(16λ�ּ���)	   
 	u16 i;    
	u32 offaddr;   //ȥ��0X08000000��ĵ�ַ
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//�Ƿ���ַ
	FLASH_Unlock();						//����
	offaddr=WriteAddr-STM32_FLASH_BASE;		//ʵ��ƫ�Ƶ�ַ.
	secpos=offaddr/STM_SECTOR_SIZE;			//������ַ  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//�������ڵ�ƫ��(2���ֽ�Ϊ������λ.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//����ʣ��ռ��С   
	if(NumToWrite<=secremain)secremain=NumToWrite;//�����ڸ�������Χ
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//������������������
		for(i=0;i<secremain;i++)//У������
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//��Ҫ����  	  
		}
		if(i<secremain)//��Ҫ����
		{
			FLASH_EraseSector(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,VoltageRange_3);//�����������
			for(i=0;i<secremain;i++)//����
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//д����������  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;				//������ַ��1
			secoff=0;				//ƫ��λ��Ϊ0 	 
		   	pBuffer+=secremain;  	//ָ��ƫ��
			WriteAddr+=secremain;	//д��ַƫ��	   
		   	NumToWrite-=secremain;	//�ֽ�(16λ)���ݼ�
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//��һ����������д����
			else secremain=NumToWrite;//��һ����������д����
		}	 
	};	
	FLASH_Lock();//����
}
#endif

//��ָ����ַ��ʼ����ָ�����ȵ�����
//ReadAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//��ȡ2���ֽ�.
		ReadAddr+=2;//ƫ��2���ֽ�.	
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//WriteAddr:��ʼ��ַ
//WriteData:Ҫд�������
void Test_Write(u32 WriteAddr,u16 WriteData)   	
{
	STMFLASH_Write(WriteAddr,&WriteData,1);//д��һ���� 
}