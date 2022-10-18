#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "T_Pantalla.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
                         // thread function
osThreadId tid_TPantalla;                                          // thread id
osThreadDef (TPantalla, osPriorityNormal, 1, 0);                   // thread object

int Init_TPantalla (void) {

  tid_TPantalla = osThreadCreate (osThread(TPantalla), NULL);
  if (!tid_TPantalla) return(-1);
  
  return(0);
}

void TPantalla (void const *argument) {



		if(str.flash_mode==0 && str.RC_MODE==0)
		{
			pantalla_inicial();
			while (1) {
				

						if(str.pantalla==2)
						{
							verif_sensores();
						}
						else if(str.pantalla==3)
						{
							estrategias_pantalla();
						}
						else if(str.pantalla==4)
						{
							if(str.start==0)
								{
									pantalla4();
								}
								else
								{
									fight();
								}
						}
						else if(str.pantalla==5)
						{
							pantalla5();
						}
						else if(str.pantalla==6)
						{
							if(str.start==0)
								{	
									pantalla6();
								}
								else
								{
									fight();
								}
						}
					osDelay(1);
			}	
		}
		else if(str.RC_MODE==1)
		{
			pantalla_inicial();
			pantalla_RC();
			HAL_UART_Receive_IT(&huart1,str.buffer_rx,17);
			while(1)
			{
					bluetooth_RC();
			}
			
		}
		else
		{
				pantalla_inicial();
				
				HAL_UART_Receive_IT(&huart1,str.buffer_rx,42);
				while(1)
				{					
					bluetooth();
					pantalla_APP();
				}
					
		}

	
}

void End_TPantalla (void) {

  osThreadTerminate(tid_TPantalla);
  
  
}
