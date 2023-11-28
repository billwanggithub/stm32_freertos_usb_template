#include "task_FreeRtos.h"
#include "usb_device.h"
#include "usb_otg.h"

void vApplicationMallocFailedHook(void)
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();


	for (;;) ;
}


void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
	/* This function will get called if a task overflows its stack.   If the
	parameters are corrupt then inspect pxCurrentTCB to find which was the
	offending task. */


	(void) pxTask;
	(void) pcTaskName;


	for (;;) ;
}


void Blink1_Task(void *pvParameters)
{
	TickType_t xlastFlashTime;
	xlastFlashTime = xTaskGetTickCount();
	
	MX_USB_OTG_FS_PCD_Init();
	MX_USB_DEVICE_Init();
	
	uint16_t period = 33; // 1/30 Hz
	uint16_t duty = 0;
	int8_t direction = 1;
	while (1) {
		// 呼吸燈
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);		
		vTaskDelay(duty);		
		//vTaskDelayUntil(&xlastFlashTime, duty++);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);		
		vTaskDelay(period-duty);
		//vTaskDelayUntil(&xlastFlashTime, 255);
		if (direction >= 0)
		{
			duty += 1;
			if ( duty >= period)			
			{
				direction = -1;
				duty = period;
			}
		}
		else
		{
			duty -= 1;
			if ( duty <= 0)
			{
				direction = 1;
				duty = 0;
			}			
		}
	}
}