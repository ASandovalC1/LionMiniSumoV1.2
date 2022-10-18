#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "T_Motores.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 

osThreadId tid_TMotores;                                          // thread id
osThreadDef (TMotores, osPriorityNormal, 1, 0);                   // thread object

int Init_TMotores (void) {

  tid_TMotores = osThreadCreate (osThread(TMotores), NULL);
  if (!tid_TMotores) return(-1);
  
  return(0);
}

void TMotores (void const *argument) {

  while (1) {
  if(HAL_GPIO_ReadPin(PUERTO_IN_START,IN_START)==0 && str.tiempo==1)
	{
		Control_Motores(0,0);
		//HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_RESET);	
		str.start=0;
		str.tiempo=1; //variable para saber si esta activado por control o tiempo (1 control, 2 tiempo)
	}
	else if(HAL_GPIO_ReadPin(PUERTO_IN_START,IN_START)==1 && str.tiempo==1)
	{
		Control_Motores(str.control_mi, str.control_md);
		//HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_SET);
		str.start=1;
	}
//	else if(str.start==0 && str.tiempo==2)
//	{
//		Control_Motores(0,0);
//		//HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_RESET);	
//		//str.start=0;
//		//str.tiempo=1; //variable para saber si esta activado por control o tiempo (1 control, 2 tiempo)
//	}
	else if(str.start==1 && str.tiempo==2)
	{
		Control_Motores(str.control_mi, str.control_md);
		//HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_SET);
		//str.start=1;
	}
    osDelay(1);//osThreadYield ();    
  }
}
