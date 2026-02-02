#include "main.h"


void led_on(int num)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8<<(num-1),GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}


void led_off(int num)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8<<(num-1),GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}


void led_init()
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	for(int i=1;i<=8;i++)
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8<<(i-1),GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}



void led_task()
{
	if(jiemian==0)  //数据
	{
		led_on(1);
	}
	else
	{
		led_off(1);
	}
	
	if(fre_A>PH)
	{
		led_on(2);
	}
	else
	{
		led_off(2);
	}
	
	if(fre_B>PH)
	{
		led_on(3);
	}
	else
	{
		led_off(3);
	}
	
	
	for(int i=4;i<=7;i++)
	led_off(i);
	
	//任意通道突变3次
	if(NDA>=3 || NDB>=3 )
	{
		led_on(8);
	}
	else
	{
		led_off(8);
	}
}
	

void led_toggle(int num)
{
	
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8<<(num-1))==GPIO_PIN_RESET)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8<<(num-1),GPIO_PIN_SET);
	}
	else
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8<<(num-1),GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}




