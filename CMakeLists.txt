cmake_minimum_required(VERSION 3.15)

project(stm32_freertos LANGUAGES C CXX ASM)

find_bsp(ID com.sysprogs.project_importers.stm32.cubemx SOURCE_PROJECT stm32_freertos.ioc)

add_bsp_based_executable(
	NAME stm32_freertos
	GENERATE_BIN
	GENERATE_MAP
	SOURCES
		${BSP_ROOT}/FreeRTOS/croutine.c
		${BSP_ROOT}/FreeRTOS/event_groups.c
		${BSP_ROOT}/FreeRTOS/list.c
		${BSP_ROOT}/FreeRTOS/queue.c
		${BSP_ROOT}/FreeRTOS/stream_buffer.c
		${BSP_ROOT}/FreeRTOS/tasks.c
		${BSP_ROOT}/FreeRTOS/timers.c
		${BSP_ROOT}/FreeRTOS/include/atomic.h
		${BSP_ROOT}/FreeRTOS/include/croutine.h
		${BSP_ROOT}/FreeRTOS/include/deprecated_definitions.h
		${BSP_ROOT}/FreeRTOS/include/event_groups.h
		${BSP_ROOT}/FreeRTOS/include/FreeRTOS.h
		${BSP_ROOT}/FreeRTOS/include/list.h
		${BSP_ROOT}/FreeRTOS/include/message_buffer.h
		${BSP_ROOT}/FreeRTOS/include/mpu_prototypes.h
		${BSP_ROOT}/FreeRTOS/include/mpu_wrappers.h
		${BSP_ROOT}/FreeRTOS/include/newlib-freertos.h
		${BSP_ROOT}/FreeRTOS/include/picolibc-freertos.h
		${BSP_ROOT}/FreeRTOS/include/portable.h
		${BSP_ROOT}/FreeRTOS/include/projdefs.h
		${BSP_ROOT}/FreeRTOS/include/queue.h
		${BSP_ROOT}/FreeRTOS/include/semphr.h
		${BSP_ROOT}/FreeRTOS/include/StackMacros.h
		${BSP_ROOT}/FreeRTOS/include/stack_macros.h
		${BSP_ROOT}/FreeRTOS/include/stream_buffer.h
		${BSP_ROOT}/FreeRTOS/include/task.h
		${BSP_ROOT}/FreeRTOS/include/timers.h
		${BSP_ROOT}/FreeRTOS/portable/GCC/ARM_CM4F/portmacro.h
		${BSP_ROOT}/FreeRTOS/portable/GCC/ARM_CM4F/port.c
		${BSP_ROOT}/FreeRTOS/portable/MemMang/heap_4.c
		${BSP_ROOT}/Core/Inc/FreeRTOSConfig.h
		${BSP_ROOT}/task_FreeRtos.c
		${BSP_ROOT}/task_FreeRtos.h)

target_include_directories(stm32_freertos PRIVATE FreeRTOS/include FreeRTOS/portable/GCC/ARM_CM4F)
