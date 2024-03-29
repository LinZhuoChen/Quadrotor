#include "pwm.h"

/**
  * @brief  Init the PWM  72MHZ
  * @param  None
  * @retval None
  */
void Pwm_init(void)
{
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  				TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	TIM_TimeBaseStructure.TIM_Period = 24000;		         
	TIM_TimeBaseStructure.TIM_Prescaler = 9-1;	           
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);   
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;              
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	/*Open Timer*/
	TIM_Cmd(TIM4, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
/**
  * @brief  Set the PWM1
  * @param  None
  * @retval None
  */
void Pwm_Set1(uint16_t cnt)
{
	TIM_SetCompare1(TIM4,cnt);
}
/**
  * @brief  Set the PWM2
  * @param  None
  * @retval None
  */
void Pwm_Set2(uint16_t cnt)
{
	TIM_SetCompare2(TIM4,cnt);
}
/**
  * @brief  Set the PWM3
  * @param  None
  * @retval None
  */
void Pwm_Set3(uint16_t cnt)
{
	TIM_SetCompare3(TIM4,cnt);
}
/**
  * @brief  Set the PWM4
  * @param  None
  * @retval None
  */
void Pwm_Set4(uint16_t cnt)
{
	TIM_SetCompare4(TIM4,cnt);
}
