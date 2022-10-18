#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "T_Sensores.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void TSensores (void const *argument);                             // thread function
osThreadId tid_TSensores;                                          // thread id
osThreadDef (TSensores, osPriorityNormal, 1, 0);                   // thread object

int Init_TSensores (void) {

  tid_TSensores = osThreadCreate (osThread(TSensores), NULL);
  if (!tid_TSensores) return(-1);
  
  return(0);
}

void TSensores (void const *argument) {

  while (1) {
		if(str.sens_3!=1)
		{
			if(HAL_GPIO_ReadPin(PUERTO_SH_CENTER,SH_CENTER)==0)
			{
				str.SensorDistaciaCentral=1;
			}
			else
			{
				str.SensorDistaciaCentral=0;
			}
		}
		if(str.a_ubicacion !=-1 )
		{
			str.a_ubicacion_anterior = str.a_ubicacion;
			HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_SET);
			str.tim_oscilacion=0;
			if(str.a_ubicacion >0)
			{
				str.oscilacion=1;
			}
			else	if(str.a_ubicacion <0)
			{
				str.oscilacion=-1;
			}
			else
			{
				;
			}
		
			
		}
		else
		{
			HAL_GPIO_WritePin(PUERTO_DLED,DLED,GPIO_PIN_RESET);
		}
		
		str.a_ubicacion= Detectar_Ubicacion();
		osDelay(2);
  }
}
