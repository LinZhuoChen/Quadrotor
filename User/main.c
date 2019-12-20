#include "mcu.h"
#include "bsp.h"
#include "global.h"
#include "app.h"

Vector Acc,Gyro;

/***************************foreground start*************************************************/
void TIM2_IRQHandler(void)
{
	Remote_ChxGet();
	Lock_Control(&Command_Uint);
	TIM_ClearITPendingBit(TIM2,TIM_FLAG_CC1|TIM_FLAG_CC2|TIM_FLAG_CC3|TIM_FLAG_CC4|TIM_IT_Update);
}

void TIM3_IRQHandler(void)
{
	Remote_StatusGet();
	TIM_ClearITPendingBit(TIM3,TIM_FLAG_CC3|TIM_FLAG_CC4|TIM_IT_Update);
}

void EXTI1_IRQHandler(void)
{
	Sonar_DataGet();
	EXTI_ClearITPendingBit(EXTI_Line1); 	
}
void EXTI15_10_IRQHandler(void)
{
	static uint16_t Basetime;
	static float Dt;
	Dt=G_GetDt(&Basetime);
	Quadrotor_Control(Dt,System_Status,&Acc,&Gyro,g_SensorUpdate,g_TargetEuler,Command);
	EXTI_ClearITPendingBit(EXTI_Line13);
}
void USART1_IRQHandler(void)
{
	Uart1_GetData();
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
/***************************foreground end*************************************************/
/***************************background start*************************************************/
int main(void)
{
	Startup();
	while(1)
	{
		Data_Update();
	}
}
/***************************background end*************************************************/
