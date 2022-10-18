/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "T_Control.h"
#include "T_Pantalla.h"
#include "T_Piso.h"
#include "T_Sensores.h"
#include "T_Motores.h"
#include "Funciones.h"
#include "Lion1.h"
#include "gpio.h"
#include "stm32f0xx_hal.h"
#include "stdlib.h"
Lion1_2 str;
Variables_flash Lion_flash;




void SystemClock_Config(void);



int main(void)
{
  
  HAL_Init();

  SystemClock_Config();
	MX_GPIO_Init();
	GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_15; //UP DOWN
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_1;  //B1 -- ok
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	
	MC_Load_Setup();
		//mov normal
	str.frecuencia=v_flash.frecuencia;
	TIM2->PSC = 48000000/(str.frecuencia*1001);
	str.cte_deriv_b = v_flash.cte_deriv_b;
	str.cte_prop_b = v_flash.cte_prop_b/2;
	str.vel_max = v_flash.vel_max;
	str.vel_min = v_flash.vel_min;
	str.vel_no_op=v_flash.vel_no_op;
	str.osc_no_op=v_flash.osc_no_op;
	
	//str1
	str.t_str1=v_flash.t_str1;
	str.conf_op_lim=v_flash.conf_op_lim;
	str.vel_mot_str1=v_flash.vel_mot_str1;
	str.limite_entre_paso_str1=v_flash.limite_entre_paso_str1;
	str.limite_entre_paso_off_str1=v_flash.limite_entre_paso_off_str1;
	
	//str 2
	//tiempo estrategia 2
	str.t_str2=v_flash.t_str2;
	str.vel_der_str2=v_flash.vel_der_str2; //actualmente 990
	str.vel_izq_str2=v_flash.vel_izq_str2; //actualmente 990
	str.conf_op_lim_str2=v_flash.conf_op_lim_str2; //actualmente 1000
	
//estrategia 3

	//paso 1 
		str.t_str3=v_flash.t_str3; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 370
		str.vel_giro1_str3=v_flash.vel_giro1_str3; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		str.duracion_giro1_str3=v_flash.duracion_giro1_str3; //duracion giro 1 estrategia 3 100
		str.vel_der_gir2_str3=v_flash.vel_der_gir2_str3;  //velocidad derecha durante curva (giro 2 ) estrategia 3 actualmente 970
		str.vel_izq_gir2_str3=v_flash.vel_izq_gir2_str3;  //velocidad izquierda durante curva (giro2) estrategia 3 actualmente 660
		
		//paso 2
		str.vel_gir3_str3=v_flash.vel_gir3_str3; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 890
		str.duracion_giro3_str3=v_flash.duracion_giro3_str3; //duracion giro 3 estrategia 3	actualmente 110
		
		//paso3
		str.vel_ataque_str3=v_flash.vel_ataque_str3; //duracion ataque frontal despues de giro 3 // actualmente 800
		str.duracion_ataque_str3=v_flash.duracion_ataque_str3; //duracion de ataque frontal actualmente 150 
		
		
//estrategia 4
	//paso 1 
		str.t_str4=v_flash.t_str4; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 350
		str.vel_giro1_str4=v_flash.vel_giro1_str4; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		str.duracion_giro1_str4=v_flash.duracion_giro1_str4; //duracion giro 1 estrategia 4 100
		str.vel_der_gir2_str4=v_flash.vel_der_gir2_str4;  //velocidad derecha durante curva (giro 2 ) estrategia 4 actualmente 660
		str.vel_izq_gir2_str4=v_flash.vel_izq_gir2_str4;  //velocidad izquierda durante curva (giro2) estrategia 4 actualmente 970
		
	//paso 2
		str.vel_gir3_str4=v_flash.vel_gir3_str4; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 910
		str.duracion_giro3_str4=v_flash.duracion_giro3_str4; //duracion giro 3 estrategia 4	actualmente 150
		
	//paso3
		str.vel_ataque_str4=v_flash.vel_ataque_str4; //duracion ataque frontal despues de giro 3 // actualmente  800
		str.duracion_ataque_str4=v_flash.duracion_ataque_str4; //duracion de ataque frontal actualmente 150
		
		
//estrategia 5
		
	//tiempo estrategia 5
		str.t_str5=v_flash.t_str5; //400
		str.vel_der_str5=v_flash.vel_der_str5; //actualmente 620
		str.vel_izq_str5=v_flash.vel_izq_str5; //actualmente 620
		str.conf_op_lim_str5=v_flash.conf_op_lim_str5; //actualmente 100
		
//estrategia 6
	
		//tiempo estrategia 6
		str.t_str6=v_flash.t_str6; //400
		str.vel_der_str6=v_flash.vel_der_str6; //actualmente 620
		str.vel_izq_str6=v_flash.vel_izq_str6; //actualmente 620
		str.conf_op_lim_str6=v_flash.conf_op_lim_str6; //actualmente 100
		
//estrategia 7	
	//tiempo estrategia 7
		str.t_str7=v_flash.t_str7; //750
		//constantes para estrategias de borde de pista (estrategia 7)
		str.proporcional1=v_flash.proporcional1;
		str.cte_integral1=v_flash.cte_integral1;
		str.cte_derivativa1=v_flash.cte_integral1;
		str.avance_der_str7=v_flash.avance_der_str7; //700
		str.avance_izq_str7=v_flash.avance_izq_str7; //700
		str.vel_giro_str7=v_flash.vel_giro_str7; //600
		str.duracion_giro_str7=v_flash.duracion_giro_str7; //120
		
//estrategia 8	
		//tiempo estrategia 8
		str.t_str8=v_flash.t_str8; //750
		//constantes para estrategias de borde de pista (estrategia 8)
		str.proporcional2=v_flash.proporcional2;
		str.cte_integral2=v_flash.cte_integral2;
		str.cte_derivativa2=v_flash.cte_derivativa2;
		str.avance_der_str8=v_flash.avance_der_str8; //400
		str.avance_izq_str8=v_flash.avance_izq_str8; //400
		str.vel_giro_str8=v_flash.vel_giro_str8; //600
		str.duracion_giro_str8=v_flash.duracion_giro_str8; //220
		
//estrategia 9
		//tiempo estrategia 9
		str.t_str9=v_flash.t_str9; //83
		str.vel_giro_str9=v_flash.vel_giro_str9; //999
		
		str.PULL_SELECT=v_flash.PULL_SELECT;
		
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0) //UP 
	{		
		//gpioa 4
		MX_I2C1_Init();
		MX_USART1_UART_Init();
		str.flash_mode=1; //flash mode ON
		str.RC_MODE=0;
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==0)
	{
		str.RC_MODE=1;
		MX_I2C1_Init();
		MX_USART1_UART_Init();
		MX_TIM2_Init();
		HAL_TIM_Base_Start(&htim2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	}
	else
	{
		str.flash_mode=0; //flash mode OFF
		Init_buttons();
		Init_sensors();
		MX_I2C1_Init();
		MX_TIM2_Init();
		HAL_TIM_Base_Start(&htim2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
		str.RC_MODE=0;
		//MX_ADC_Init();
	}
	

  /* USER CODE BEGIN 2 */
osKernelInitialize ();                    // initialize CMSIS-RTOS

  // initialize peripherals here

  // create 'thread' functions that start executing,
  // example: tid_name = osThreadCreate (osThread(name), NULL);
if(str.flash_mode)
{
	Init_TPantalla();
}
else if(str.RC_MODE)
{
	Init_TPantalla();
	Init_TMotores();
}
else
{
	Init_TPantalla();
	Init_TControl();
	Init_TPiso();
	Init_TSensores();
	Init_TMotores();
	   
}

  osKernelStart (); 
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */
osDelay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);
//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
//  {
//    Error_Handler();
//  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
//  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
//  {
//    Error_Handler();
//  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */

//  /* USER CODE END Error_Handler_Debug */
//}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
