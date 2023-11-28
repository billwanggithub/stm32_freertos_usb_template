# STM32 FreeRTOS/USB Composite Device(CDC+HID) Template

## USB Init

- ***Enable Usb Interrupt***

![Enable Usb Interrupt](assets/enable_usb_interrupt.png)

- ***Select AL94 Usb Software Pack***

![Al94 Usb Pack Select](assets/al94_usb_pack_select.png)

- ***Select USB Class***

![Usb Class Selection](assets/usb_class_selection.png)

- ***Check Generate Peripheral Initialization as a pair *.c/*.h***

![Check Generate Peripheral Initialization](assets/check_generate_peripheral_initialization.png)


## Porting FreeRTOS when using with USB
- ***Change TimeBase Source to TIM***

![Change Timebase](assets/change_timebase.png)

- ***Move USB Initialation`MX_USB_OTG_FS_PCD_Init()` `MX_USB_DEVICE_Init()` to a Task, Not at main()***

```clike=
void Blink1_Task(void *pvParameters)
{
	TickType_t xlastFlashTime;
	xlastFlashTime = xTaskGetTickCount();
	
	MX_USB_OTG_FS_PCD_Init();
	MX_USB_DEVICE_Init();
	
	while (1) {
		vTaskDelayUntil(&xlastFlashTime, 500);
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}
```

## Reference

- [STM32 FreeRTOS 手動移植至 CubeIDE 過程記錄](https://www.makdev.net/2022/10/rtos-op.html)
- [Programming USB Device](https://hackmd.io/@billwang168/B1oAqEi7p)