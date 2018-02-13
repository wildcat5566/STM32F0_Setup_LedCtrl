#include "stm32f0xx.h"          
#include "stm32f0xx_gpio.h"     // Pins Interface
#include "stm32f0xx_rcc.h"      // Enable peripheral clock

int main(void) {
	// Enable GPIO clock
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	// GPIO Configuration for led at pin C14
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;         // Pin C14
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;      // Pinmode = Output
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  // Clock freq
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;     // Push pull mode
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;       // Pull up
	GPIO_Init(GPIOC, &GPIO_InitStruct);             // GPIO port = C
	
	GPIO_SetBits(GPIOC, GPIO_Pin_14);               // SetBits = High, led on
	//GPIO_ResetBits(GPIOC, GPIO_Pin_14);           // ResetBits = Low, led off
}
