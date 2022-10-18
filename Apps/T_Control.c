
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "T_Control.h"
#include "T_Pantalla.h"
#include "T_Motores.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
                            // thread function
osThreadId tid_TControl;                                          // thread id
osThreadDef (TControl, osPriorityNormal, 1, 0);                   // thread object

int Init_TControl (void) {

  tid_TControl = osThreadCreate (osThread(TControl), NULL);
  if (!tid_TControl) return(-1);
  
  return(0);
}

void TControl (void const *argument) {

    /* USER CODE BEGIN TControl_F */
  /* Infinite loop */
	
	str.pantalla=2;
	str.num_estrategia=1;
	str.sens_num=1;
	
	while(1)
  {
				
	  if(str.pantalla==2)
	  {
		  Lectura_botones();
		  if(str.left_but)
		  {
			  osDelay(100);
			  Comprobar_sensores();
		  }
		  str.sens_num=str.sens_num+str.up_but-str.down_but;
			str.pantalla=str.pantalla+str.right_but;
			
		  if(str.sens_num>9)
			  str.sens_num=1;
		  if(str.sens_num<1)
			  str.sens_num=9;
			
		  lectura_sensores_verif();
	  }
		else if(str.pantalla==3)
		{	
			Lectura_botones();
			osDelay(100);
			str.num_estrategia=str.num_estrategia+str.up_but-str.down_but;
			str.pantalla=str.pantalla+str.right_but-str.left_but;
			if(str.num_estrategia>9)
				str.num_estrategia=1;
			if(str.num_estrategia<1)
				str.num_estrategia=9;
		}
		else if(str.pantalla==4)
		{
			Lectura_botones();
				osDelay(50);
				str.pantalla=str.pantalla+str.right_but-str.left_but;
							
				if(HAL_GPIO_ReadPin(PUERTO_IN_START,IN_START))
				{
					str.start=1;
					str.tiempo=1; //variable para saber si esta activado por control o tiempo (1 control, 2 tiempo)
					//estrategias_sw();
				}
				//str.start=1;
				//str.tiempo=1; //variable para saber si esta activado por control o tiempo (1 control, 2 tiempo)
				//estrategias_sw();
			
			if(str.start==1)
			{
				//acabar tarea pantalla
				End_TPantalla();
				Init_TMotores();
				mov_minisumo();
			}
			
		}
		else if(str.pantalla==5)
		{
			Lectura_botones();
			osDelay(100);
			str.pantalla=str.pantalla+str.right_but-str.left_but;
			if(HAL_GPIO_ReadPin(PUERTO_IN_START,IN_START))
			{
				str.pantalla=6;
				str.tiempo=1;
			}
		}
		else if(str.pantalla==6)
		{
			if(str.start==0)
			{
				Lectura_botones();
				osDelay(100);
				str.pantalla=str.pantalla-str.left_but;
				str.timt_start++;
				osDelay(692);
				if(str.timt_start==5)
				{
					str.start=1; 
					//str.tiempo=1; //variable para saber si esta activado por control o tiempo (1 control, 2 tiempo)
					End_TPantalla();
					Init_TMotores();
					mov_minisumo();		
				}
		}
    osDelay(100);
  }
  /* USER CODE END Init_TControl */
}
}
