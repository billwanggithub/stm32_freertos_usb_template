#include "task_FreeRtos.h"

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
	while (1) {
		vTaskDelayUntil(&xlastFlashTime, 500);
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}