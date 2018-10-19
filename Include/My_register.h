/******************** (C) COPYRIGHT 2014 KUNKIN********************
 * ��??  ��my_register
 * ??    ��n?
 * ??    ��????
 * ??    ��Define register??????????��???
 * ??		 ��?��???????��?????
 * ???����2014-12-9
*********************************************************************/

#include "STM32F4xx.h"
#ifndef __my_register_h__
#define __my_register_h__
//=============================================================================
void Write_Limits(void);
void Wrtite_step(void);
void OC_ADD(void);
void Wrtite_S(void);
void Write_oct(void);
void Write_alarm(void);
void Write_btype(void);
void Write_LOAD(void);
void Write_info(void);
void OC_CHECK(void);
void INPUT_POW(char* num);  
void INPUT_NUM(char* num); 
void INPUT_CDC(char* num); 
void INPUT_C(char* num);  
void INPUT_LOAD(char* num);  
void INPUT_INFO(vu8 num);
void SET_OP_DOWN(void);
void SET_OP_UP(void);
void SET_OP_RIGHT(void);
void SET_OP_LEFT(void);
void PARA_SET(void);
void SYS_INFO_RIGHT(void);
void SYS_INFO_LEFT(void);
void SYS_INFO_UP(void);
void SYS_INFO_DOWN(void);
void INPUT_INFO(vu8 num);
void CDC_OP_DOWN(void);
void CDC_OP_UP(void);
void CDC_OP_LEFT(void);
void CDC_OP_RIGHT(void);
void CDC_SET(void);
void INPUT_CDC(char* num); 
//=============================================================================
#define NOP   __nop();	  //???

//============================================================================
extern struct bitDefine flagA,flagB,flagC,flagD,flagE,flagF,flagG;
#define   Flag_ADC_Full             (flagA.bit1)//DMA??????�� 
#define   Flag_BEEP						    	(flagA.bit2)//???????
#define   Flag_Key_Scan							(flagA.bit3)//��???????
#define   UART_SEND_flag						(flagA.bit4)//????????
#define   UART_Buffer_Rece_flag			(flagA.bit5)//????????
#define   Flag_Swtich_ON      			(flagA.bit6)//??��???ON??
#define   Flag_0_5S      		      	(flagA.bit7)//��?????????

#define   Flag_1S      		         	(flagB.bit0)//��????��????
#define   Flag_5S      		        	(flagB.bit1)//????????
#define   Flag_Long                 (flagB.bit2)//��??��??
#define   Flag_DAC_OFF              (flagB.bit3)//�Ƿ�ת��DAC����ֵ��־
#define   Flag_SetA                 (flagB.bit5)//?????��??��
#define   Flag_SetV                 (flagB.bit6)//????????�� 
#define   Flag_DisSet               (flagB.bit7)//��???????��??��

#define   Flag_GE                   (flagC.bit0)//?��????
#define   Flag_SHI                  (flagC.bit1)//?��????
#define   Flag_BAI                  (flagC.bit2)//?��????
#define   Flag_QIAN                 (flagC.bit3)//?��????
#define   Flag_Beep_OFF             (flagC.bit6)//???????

#define   flag_Tim_USART            (flagD.bit0)//?????��??
#define   flag_Test                 (flagD.bit1)//????????
#define   flag_Test_PASS            (flagD.bit2)//????PASS??
#define   flag_Test_FAIL            (flagD.bit3)//????FAIL??
#define   flag_Test_Time            (flagD.bit4)//??????????
#define   flag_Test_Start           (flagD.bit5)//??????????
#define   flag_Test_Min             (flagD.bit6)//?????��??
#define   flag_Load_CC              (flagD.bit7)//??CC/CV????��

#define   flag_Test_Door             (flagE.bit0)//????????
#define   flag_Test_SetTime          (flagE.bit1)//???????? 
#define   flag_OVP                   (flagE.bit2)//OVP??
#define   flag_OCP                   (flagE.bit3)//OCP??
#define   flag_Doub                  (flagE.bit4)//��???
#define   flag_t_Doub                (flagE.bit5)//��???????
#define   flag_Time_SW               (flagE.bit6)//????????
#define   flag_CC_MODE               (flagE.bit7)//??????

#define   flag_Adjust                (flagF.bit0)//
#define   flag_ADJ_ON                (flagF.bit1)//
#define   flag_ADJ_VL                (flagF.bit2)//
#define   flag_ADJ_VH                (flagF.bit3)//
#define   flag_ADJ_ALCC              (flagF.bit4)//
#define   flag_ADJ_AHCC              (flagF.bit5)//
#define   flag_ADJ_ALCV              (flagF.bit6)//
#define   flag_ADJ_AHCV              (flagF.bit7)//

#define   flag_DisVL                 (flagG.bit0)//
#define   flag_OverV                 (flagG.bit1)//
#define   flag_OverACC               (flagG.bit2)//
#define   flag_OverACV               (flagG.bit3)//
#define   flag_Just_Usart            (flagG.bit4)//
#define   flag_FAN_ON                (flagG.bit5)//
#define   flag_ADJ_FAN               (flagG.bit6)//
#define   flag_TM7707_CH						 (flagG.bit7)//
//=============================================================================
extern vu32 GE_V;
extern vu32 SHI_V;
extern vu32 BAI_V;
extern vu32 QIAN_V;  //???????
extern vu32 GE_A;
extern vu32 SHI_A;
extern vu32 BAI_A;
extern vu32 QIAN_A;
//--------------------------
extern vu8 NewKey;
extern vu8 DAC_Flag;
extern vu8 Beep_Flag;
extern vu8 t_beep;
extern vu8 t_KeyScan;
extern vu8 t_LEDScan;  //?????
extern vu8 t_KEYON;
extern vu16 t_0_5S;
extern vu16 t_1S;
extern vu16 t_5S;
extern vu16 t_Basket;
extern vu16 Basket_V;
extern vu16 Basket_A;
extern vu16 t_OFF_V;
extern vu16 t_ON_V;
extern vu16 t_OFF_A;
extern vu16 t_ON_A;
extern vu8 t_USART;
extern vu16 ADJ_Write;//��???��?????
extern vu8 OFFSET_Zore;//��??
extern vu8 ADDR;
extern vu8 t_lock;
extern vu8 t_onoff;
extern vu16 MAX_limit;
extern vu16 MIN_limit;
extern vu16 Test_Time;
extern vu16 Test_Time1;
extern vu16 Time_sw;
extern vu16 Test_Daley;
extern vu16 Test_C_Door;
extern vu16 TEMP_OFFSET;//?????
//--------------------------
extern vu8 UART_Buffer_Size;//????????
extern vu8 Transmit_BUFFERsize;
//---------------------------
extern vu16 NTC_value;   //AD?
extern vu16 Imon_value;
extern vu32 Imon1_value;
extern vu16 Vmon_value;
extern vu32 Vmon1_value;
extern vu16 Rmon_value;

extern float DISS_Voltage;
extern  float DISS_POW_Voltage;
extern float DISS_Current;
extern float DISS_POW_Current;
extern float DISS_R;
extern vu16 steptime;
extern vu8 r_stable;
extern char set_limit[5];
extern vu8 bit;
extern vu8 bit1;
extern vu8 dot_flag;
extern vu8 page_sw;
extern vu8 para_set1;
extern vu8 para_set2;
extern vu8 para_set3;
extern vu8 para_set4;
extern vu8 oct_sw;
extern vu8 set_sw;
extern vu8 charge_step;
extern vu8 cutoff_flag;
extern vu8 lang;
extern vu8 r_raly;
extern vu16 steptime;
extern vu8 alert_flag;
extern vu8 t_onoff;
extern vu8 ocstop;
extern float temp;
extern vu8 mode_sw;
extern vu16 stepcount;
extern vu16 battery_c;
extern float bc_raw;
extern vu8 track;
extern vu8 clear_flag1;
extern vu8 clear_flag2;
extern vu8 clear_flag3;
extern vu8 pass;
extern vu8 b_type;
extern vu8 buffer;
extern float clear_v;
extern float clear_pv;
extern float clear_lv;
extern float temp;
extern vu8 set_loop_count;

extern vu32 Run_Control[41];	
#define onoff_ch                    Run_Control[0]  //ON/OFF
#define SET_Voltage 	    	        Run_Control[1]  //??????
#define SET_Current	    	    		  Run_Control[2]  //?????��
#define SET_Voltage_Laod 					  Run_Control[3]  //??????
#define SET_Current_Laod					  Run_Control[4]  //?????��
#define LOCK_KEY								    Run_Control[5]  //
#define BEEP_KEY								    Run_Control[6]  //
#define STRONG_KEY							    Run_Control[7]  //

#define MODE_Woke							   	  Run_Control[8]  //
#define POW_Voltage	    	            Run_Control[9]  //?????
#define Voltage	    	                Run_Control[10]  //?????
#define Current	    	    		    Run_Control[11]  //????��
#define Laod_Current	    		    Run_Control[12]  //????��
#define R_VLUE							Run_Control[13]  //???
#define set_max_v						Run_Control[14]  //���ò�����ѹ����
#define set_min_v						Run_Control[15]  //���ò�����ѹ����
#define set_max_r						Run_Control[16]  //���ò�����������
#define set_min_r						Run_Control[17]  //���ò�����������
#define set_max_c						Run_Control[18]  //���ò�����������
#define set_min_c						Run_Control[19]  //���ò�����������
#define set_output_v					Run_Control[20]  //���ò��������ѹ
#define set_output_c					Run_Control[21]  //���ò����������
#define set_init_c					    Run_Control[22]  //���ò��������ѹ
#define set_sbs_c					    Run_Control[23]  //���ò����������
#define set_add_c					    Run_Control[24]
#define set_c_cutoff_v					Run_Control[25]
#define set_c_cutoff_c					Run_Control[26]
#define set_dc_cutoff_v					Run_Control[27]
#define set_dc_cutoff_c					Run_Control[28]
#define start_time					    Run_Control[29]
#define end_time					    Run_Control[30]
#define opv1    					    Run_Control[31]
#define opv2    					    Run_Control[32]
#define opv3    					    Run_Control[33]
#define opc1    					    Run_Control[34]
#define opc2    					    Run_Control[35]
#define opc3    					    Run_Control[36]
#define load_c    					    Run_Control[37]
#define pow_v    					    Run_Control[38]
#define cdc_dc    					    Run_Control[39]
#define pow_c    					    Run_Control[40]


extern vu16 coff[6];
#define cov1    					    coff[0]
#define cov2    					    coff[1]
#define cov3    					    coff[2]
#define coc1    					    coff[3]
#define coc2    					    coff[4]
#define coc3    					    coff[5]										 //???

/*
************************************************************************
*						ҳ��ʶ���
************************************************************************
*/

#define face_graph      0
#define face_cdc        1
#define face_menu       2
#define face_r          3
#define face_load       4
#define face_set        5
#define face_starter    6
#define face_sys_info   7
/*
************************************************************************
*						����ѡ��ʶ���
************************************************************************
*/

#define set_1           0
#define set_2           1
#define set_3           2
#define set_4           3
#define set_5           4
#define set_6           5
#define set_7           6
#define set_8           7
#define set_9           8
#define set_10          9
#define set_11          10
#define set_12          11
#define set_13          12
#define set_14          13
#define set_15          14
#define set_16          15
#define set_17          16
#define set_18          17
#define set_19          18
#define set_20          19
#define set_21          20
#define set_22          21
#define set_23          22
#define set_24          23
#define set_25          24
#define set_26          25
#define set_27          26
#define set_28          27
#define set_29          28
#define set_30          29
#define set_31          30
#define set_32          31
#define set_33          32
#define set_34          33
#define set_35          34
#define set_36          35
#define set_37          36
#define set_38          37
#define set_39          38
#define set_40          39
#define set_41          40
#define set_42          41
#define set_43          42
#define set_44          43
#define set_45          44
#define set_46          45
#define set_47          46
#define set_48          47
#define set_49          48
#define set_50          49
#define set_51          50
#define set_52          51
#define set_53          52
#define set_54          53
#define set_55          54
#define set_56          55
#define set_57          56
#define set_58          57
#define set_59          58
#define set_60          59
#define set_61          60
#define set_62          61
#define set_63          62
#define set_64          63
#define set_65          64
#define set_66          65
#define set_67          66
#define set_68          67
#define set_69          68
#define set_70          69
#define set_71          70
#define set_72          71
/*
************************************************************************
*						��������ʶ���
************************************************************************
*/

#define set_1_on            0xff
#define set_1_off           0
#define set_2_on            0xff
#define set_2_off           0
#define set_3_on            1
#define set_3_off           0
#define set_4_on            0xff
#define set_4_off           0
#define cdc_on              1
#define cdc_off             0
#define oct_on              1
#define oct_off             0
#define c_on                1
#define c_off               0
#define mode_r              1
#define mode_load           2
#define mode_pow            3
#define load_on             1
#define load_off            0
#define pow_on              1
#define pow_off             0
#define Lion                1
#define NiMH                2
#define NiCd                3
#define SLA                 4
#define LiMH                5
#define step1               0
#define step2               1
#define step3               2



extern vu16 Contr_Voltage;//
extern vu16 Contr_Current;//
extern vu16 Contr_Laod;//
extern vu32 Correct_Parametet[12];
#define  REG_CorrectionV   Correct_Parametet[0]//???????
#define  REG_Load_A			   Correct_Parametet[1]//??CC???��???
#define  SET_LoadA			   Correct_Parametet[2]//??CC?????��??
#define  REG_LoadV			   Correct_Parametet[3]//??CV????????
#define  SET_LoadV			   Correct_Parametet[4]//??CV??????????

#define  REG_CorrectionR   Correct_Parametet[5]//?????

#define  REG_POWERA			   Correct_Parametet[6]//??CC???��???
#define  SET_POWERA			   Correct_Parametet[7]//??CC???��?????
#define  REG_POWERV			   Correct_Parametet[8]//??CV???????
#define  SET_POWERV				 Correct_Parametet[9]//??CV????????
#define  CON_POWERA				 Correct_Parametet[10]//??CV???��???
#define  REG_CorrectionRL    Correct_Parametet[11]//?????



extern vu8  correct_por[6];
#define  Polar             correct_por[0]//???????
#define  Polar1            correct_por[1]//???��????
#define  Polar2						 correct_por[2]//??CV????????
#define  Polar3						 correct_por[3]//??????CV???��?
#define  Polar4						 correct_por[4]//??CC???��????
#define  Polar5						 correct_por[5]//??CV????????

extern vu32 Correct_Strong[12];//��???
#define  REG_ReadV_Offset   Correct_Strong[0]//???????
#define  REG_LoadA_Offset   Correct_Strong[1]//??CC???��???
#define  SET_LoadA_Offset   Correct_Strong[2]//??CC?????��??
#define  REG_LoadV_Offset   Correct_Strong[3]//??CV????????
#define  SET_LoadV_Offset   Correct_Strong[4]//??CV??????????

#define  REG_ReadR_Offset   Correct_Strong[5]//?????

#define  REG_POWERA_Offset  Correct_Strong[6]//??CC???��???
#define  SET_POWERA_Offset  Correct_Strong[7]//??CC???��?????
#define  REG_POWERV_Offset  Correct_Strong[8]//??CV???????
#define  SET_POWERV_Offset	Correct_Strong[9]//??CV????????
#define  CON_POWERA_Offset	Correct_Strong[10]//??CV???��???
#define  REG_ReadRL_Offset   Correct_Strong[11]//?????

//---------------------------
extern vu16 ADC_NTC_Filt[50];
extern vu16 ADC_Vmon_Filt[50];
extern vu16 ADC_Imon_Filt[50];
extern vu8 UART_Buffer_Rece[16];
extern vu8 UART_Buffer_Send[20];
//============================================================================= 
#define Receive_BUFFERSIZE   10
//=============================================================================
#endif
/******************* (C) COPYRIGHT 2015 KUNKIN *****END OF FILE*************************/
