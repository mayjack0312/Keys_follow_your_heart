//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   : OLED I2C�ӿ���ʾ����(STM32F103ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND  ��Դ��
//              VCC  3.3v��Դ
//              D0   PA5��SCL��
//              D1   PA7��SDA��
//              RES  PD2��SPIģ��ĳ�IICģ����Ҫ�Ӵ����ţ�IICģ���û�����ԣ�
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"

int main(void)
{
	u8 t=' ';
	delay_init();
	OLED_Init();
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
	LED_ON;
	while(1)
	{
		OLED_ShowPicture(0,0,64,48,BMP1,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
    OLED_ShowChinese(8,0,0,16,1);//��
		OLED_ShowChinese(24,0,1,16,1);//��
		OLED_ShowChinese(40,0,2,16,1);//԰
		OLED_ShowChinese(0,16,3,16,1);//��
		OLED_ShowChinese(16,16,4,16,1);//��
		OLED_ShowChinese(32,16,5,16,1);//��
		OLED_ShowChinese(48,16,6,16,1);//��
		OLED_ShowString(4,32,"2018/05",16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(16,0,"TEXT",16,1);
		OLED_ShowString(0,16,"ASCII:",16,1);
		OLED_ShowString(0,32,"CODE:",16,1);
		OLED_ShowChar(48,16,t,16,1);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(40,32,t,3,16,1);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16,1);//16*16 ��
   	OLED_ShowChinese(0,16,0,24,1);//24*24 ��
	  OLED_ShowChinese(24,0,0,32,1);//32*32 ��
		OLED_Refresh();
	  delay_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"ABC",12,1);//6*12 ��ABC��
		OLED_ShowString(0,12,"ABC",16,1);//8*16 ��ABC��
		OLED_ShowString(0,26,"ABC",24,1);//12*24 ��ABC��
	  OLED_Refresh();
		delay_ms(500);
		OLED_ScrollDisplay(11,4,1);
	}
}

