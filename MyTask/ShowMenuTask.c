/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "event_groups.h"
#include "semphr.h"
#include "queue.h"
#include "gpio.h"
#include "beep.h"

#include "ShowMenuTask.h"
#include "OLED.h"


extern QueueHandle_t g_xQueueMenu;
static int current_page = 1;//�˵���ǰ��ʾҳ��

/*
 * ��ʾ��ͬ�Ĳ˵�UI����
 * 
 * ���ߣ�cube
**/
void ShowMenuUI(int current_page)
{
	OLED_Init();
	switch(current_page)
	{
		case 1:{
			OLED_Clear();
			OLED_ShowImage(0,0,128,64,gameImg);
			break;
		}
		case 2:{
			OLED_Clear();
			OLED_ShowImage(0,0,128,64,clockImg);
		}
	}
	OLED_Update();
}

/*
 * ������ʾ�˵�
 * ���������
------- ��������ʼ��
------- �������У����ҳ���л�
------- 
-------
 * ���ߣ�cube
**/
void ShowMenuTask(void *params)
{
	buzzer_init();
	g_xQueueMenu = xQueueCreate(4,4);
	if(NULL != g_xQueueMenu)HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	
	uint8_t key_data;
	
	while(1)
	{
		
	}
}