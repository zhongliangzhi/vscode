#include "main.h"
int PH=5000,PD=1000,PX=0;
char jiemian_f=0;
int Fre_A,Fre_B;
int fre_ac,fre_bc=0;
int NDA,NDB,NHA,NHB=0;
void task_init()
{
	//key
	key_init();  //要先初始化按键的函数指针，再开启时钟，不然会调用野指针导致报错
	
	

	
	
	
	//LCD
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
	LCD_Init();
	HAL_Delay(100);
  LCD_SetBackColor(Black);
  LCD_SetTextColor(White);
	LCD_Clear(Black);
	HAL_Delay(100);
	

	//led
	led_init();
	
	//TIM  时钟初始化都尽量最后开启
	HAL_TIM_Base_Start_IT(&htim6);  //1ms时钟
	
	htim3.Instance->CNT=0;
	HAL_TIM_IC_Start_IT(&htim3,TIM_CHANNEL_1);
	htim8.Instance->CNT=0;
	HAL_TIM_IC_Start_IT(&htim8,TIM_CHANNEL_1);


}


int count_LCD,count_led,count_key,count_fre=0;
int f_LCD,f_led,f_key,f_fre=0;
int fre_A_l,fre_B_l=0;
int fre_A_min=20000,fre_B_min=20000;
int fre_A_max=400,fre_B_max=400;
int key_time=0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)  //中断里只判断状态
{

	if(htim->Instance==TIM6)  //1ms
	{
		//0.1s
		count_LCD++;
		if(count_LCD>=100)
		{
			count_LCD=0;
			f_LCD=1;
		}
		
		//1s
		count_led++;
		if(count_led>=1000)
		{
			count_led=0;
			f_led=1;
		}
		
		//20ms
		key_time--;
		if(key_time<0)
			key_time=0;
		count_key++;
		if(count_key>=20)
		{
			count_key=0;
			f_key=1;
			key_getmode();//查询各按键状态
		}
		
		//频率超限
		if(fre_A<PH)
		{
			fre_A_l=1;
		}
		if(fre_A>PH &&fre_A_l==1)
		{
			fre_A_l=0;
			NHA++;
		}
		
		if(fre_B<PH)
		{
			fre_B_l=1;
		}
		if(fre_B>PH &&fre_B_l==1)
		{
			fre_B_l=0;
			NHB++;
		}
		
		//频率突变  每三秒为一个周期
		count_fre++;
		if(count_fre==3000)
		{
			count_fre=0;
			f_fre=1;
		}
			//采样
		if(fre_ac==1)
		{
				if(fre_A<fre_A_min)
			 {
				fre_A_min=fre_A;
			 }
				if(fre_A>fre_A_max)
			 {
				fre_A_max=fre_A;
			 }
		}
		if(	fre_bc==1)
		{
				if(fre_B<fre_B_min)
			 {
				fre_B_min=fre_B;
			 }
				if(fre_B>fre_B_max)
			 {
				fre_B_max=fre_B;
			 }
		
		}
				//限幅
		if(fre_B_min<400)
			fre_B_min=400;
		else if(fre_B_max>20000)
			fre_B_max=20000;
		if(fre_A_min<400)
			fre_A_min=400;
		else if(fre_A_max>20000)
			fre_A_max=20000;
		
		
		
					//比较
					 if(f_fre==1)
					 {
							f_fre=0;
							if(fre_A_max-fre_A_min>PD && fre_ac==1)
								NDA++;
							if(fre_B_max-fre_B_min>PD && fre_bc==1)
								NDB++;
							/*重置最大值最小值*/
								fre_A_min=20000;
								fre_B_min=20000;
								fre_A_max=400;
								fre_B_max=400;
					 }
		
	}

}


//输入捕获
int count_a,count_b,fre_A,fre_B=0;


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim==&htim3) //PB4  B
	{
		fre_bc=1;
		count_b=htim->Instance->CNT;
		Fre_B=80000000/80/count_b;
		htim->Instance->CNT=0;
		
		fre_B=Fre_B+PX;	
		if(fre_B<400)
			fre_B=400;
		else if(fre_B>20000)
			fre_B=20000;
	}
	else if(htim==&htim8)  //PA15  A
	{
		fre_ac=1;
		count_a=htim->Instance->CNT;
		Fre_A=80000000/80/count_a;
		htim->Instance->CNT=0;
		
		fre_A=Fre_A+PX;	
		if(fre_A<400)
			fre_A=400;
		else if(fre_A>20000)
			fre_A=20000;
	}

}


void task_scope()
{
	if(PD<100)
		PD=100;
	if(PD>1000)
		PD=1000;
	if(PH<1000)
		PH=1000;
	if(PH>10000)
		PH=10000;
	if(PX<-1000)
		PX=-1000;
	if(PX>1000)
		PX=1000;
	
}



void task_loop()  //无线循环
{
	task_scope();
	lcd_task();
	led_task();
	key_task();
}


