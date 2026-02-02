#include "main.h"


typedef struct
{
	int key_s;
	int key_mode;
	GPIO_PinState (*key_v)(int);
}key;

key key_b[4];

GPIO_PinState key_v(int i)
{
	if(i<3)
	{
		if(HAL_GPIO_ReadPin(GPIOB,(GPIO_PIN_0<<i))==0)
			return GPIO_PIN_RESET;
		else
			return GPIO_PIN_SET;
	}
	else
	{
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==0)
			return GPIO_PIN_RESET;
		else
			return GPIO_PIN_SET;
	
	}

}

void key_init()
{
	for(int i=0;i<4;i++)
	{
		key_b[i].key_s=0;
		key_b[i].key_mode=0;
		key_b[i].key_v=key_v;
	}
	
}





void key_getmode()
{
	if(f_key==1)//20ms
	{
		f_key=0;
		for(int i=0;i<4;i++)
		{
				if(key_b[i].key_s==0)//idle
			{
				
				if(key_b[i].key_v(i)==0) //按下
				{		
						key_time=1000;
						key_b[i].key_s=1;
				}
			}
			else if(key_b[i].key_s==1) //first down
			{
				if(key_time==0)
				{
					key_b[i].key_s=2;
					key_b[i].key_mode=2; 
				}
				else if(key_b[i].key_v(i)==1) //抬起
				{
					key_b[i].key_s=0;
					key_b[i].key_mode=1;
				}
			}
			else if(key_b[i].key_s==2) //long down
			{
				if(key_b[i].key_v(i)==1) //抬起
				{
					key_b[i].key_s=0;
				}
			}

		}

		
		}


	}



int jiemian=0;

void key_task()  //只要判断状态就可以
{
	
		if(key_b[B1].key_mode==1)
	{
		key_b[B1].key_mode=0;
		led_toggle(2);
	}
		else if(key_b[B2].key_mode==1)
	{
		key_b[B2].key_mode=0;
		led_toggle(3);
	}
		else if(key_b[B3].key_mode==1 && jiemian==0)
	{
		key_b[B3].key_mode=0;
		jiemian_f=!jiemian_f;  //数据界面两flag
	}
		else if(key_b[B4].key_mode==1)  //切换界面
	{
		key_b[B4].key_mode=0;
		jiemian++;
		if(jiemian>2)
		{
			jiemian=0;
			jiemian_f=0;
		}
	}
	else if(key_b[B3].key_mode==2 && jiemian==2)
	{
		key_b[B3].key_mode=0;
		NDA=0;
		NDB=0;
		NHA=0;
		NHB=0;
	}
	
}

