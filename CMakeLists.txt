cmake_minimum_required(VERSION 3.15)

project(stm32_freertos LANGUAGES C CXX ASM)

find_bsp(ID com.sysprogs.project_importers.stm32.cubemx SOURCE_PROJECT stm32_freertos.ioc)

add_bsp_based_executable(NAME stm32_freertos
	GENERATE_BIN
	GENERATE_MAP)

