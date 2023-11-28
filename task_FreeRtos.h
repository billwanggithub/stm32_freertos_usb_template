//#pragma once

#ifndef TASK_FREERTOS_H
#define Tasks_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"	
void Blink1_Task(void *pvParameters);
	
#ifdef __cplusplus
}
#endif

#endif /* TASK_FREERTOS_H*/	