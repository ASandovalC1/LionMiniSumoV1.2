#include "Funciones_Lion.h"


#define VELOCIDAD_ATAQUE        800
#define VELOCIDAD_REVERSA 			900       
//#define VELOCIDAD_ATAQUE2        220 //3s

#define VELOCIDAD_BUSQUEDA      400
#define VELOCIDAD_BUSQUEDA_NOOP      300

#define TIME_OUT_REEV   150
#define TIME_OUT_ATAC 6000





void mov_minisumo(void)
{
	str.ppaso1=1;

		
	
//	Lion_flash.cte_deriv_b=20; //busqueda
//	Lion_flash.cte_prop_b=12; //busqueda
	str.oscilacion=0; //no oponente
	str.tim_oscilacion=0; //no oponente
	
	
		if(HAL_GPIO_ReadPin(PUERTO_IN_START,IN_START)==1 || (str.start==1 && str.tiempo==2))
		{
			//str.avance=300;
			str.cnt_avance=0;
			str.paso=1;
			//arrancar estrategias en while independientes
			//ESTRATEGIAS
			estrategias_ex();
			
			//str.timeout_str;
			//arrancar funcion mini sumo en while (1)
			while(1)
			{
				if(str.pisoi_1==-1 || str.pisoi_2==-1 || str.pisod_1==-1 || str.pisod_2==-1)
				{
					//funcion reversa para evitar linea
					detecta_linea();
				}
				
				else if(str.a_ubicacion!=-1)
				{
					control_busqueda(str.a_ubicacion); // ataque
//					str.control_md=500;
//					str.control_mi=500;
				}
				else if(str.a_ubicacion==-1)
				{
					control_busqueda(str.a_ubicacion_anterior); // ataque
					
//					str.control_md=500;
//					str.control_mi=500;
					
					no_oponente(); //funcion oscila para buscar al oponente
				}
//				Control_Motores(500, 500);
				osDelay(2);
			}
		}

	
}



void pinMode(int pin, int estado,GPIO_TypeDef *port)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	if(estado == OUTPUT)
	{
		HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
		GPIO_InitStruct.Pin = pin;
		GPIO_InitStruct.Mode = estado;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(port, &GPIO_InitStruct);
	}
	else
	{
		GPIO_InitStruct.Pin = pin;
		GPIO_InitStruct.Mode = estado;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(port, &GPIO_InitStruct);
	}
}

int Detectar_Ubicacion(void)
{
 int SensorState;
 int Oponente = 0;
 int num_sensores = 0;
	
	
 //SENSORES
	
   if(str.sens_5!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_SH_LEFT,SH_LEFT)==0)
		{
			Oponente = -300;
			num_sensores++;
		}
	}
	if(str.sens_4!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_OM_LEFT,OM_LEFT)==0)
		{
			//str.confirma_izquierda++;
			//if(str.confirma_izquierda>20)
			//{
				Oponente = Oponente -100;
				num_sensores++;
			//	str.confirma_izquierda=21;
				
			//}
		}
	}
	if(str.sens_2!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_OM_RIGHT,OM_RIGHT)==0)
		{
			Oponente = Oponente + 100;
			num_sensores++;
		}
	}
	if(str.sens_1!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_SH_RIGHT,SH_RIGHT)==0)
		{
			Oponente = Oponente +300;
			num_sensores++;
		}
	}
	if(str.SensorDistaciaCentral==1 || Oponente/num_sensores==0)
	{
		if(str.estrategia!=0)
		{
			//TIM2->PSC=350;
		}
		//htim2.Init.Prescaler = 200;
	}
	else
	{
		//TIM2->PSC=250;
		//htim2.Init.Prescaler = 40;
	}
  if(num_sensores)
  {
     return Oponente/num_sensores;
		//return Oponente;
  }
  else
  {
     return -1;
  }
}


void Control_Motores(int mi , int md)
{
	
	if(str.start==0)
	{
		TIM2->CCR1=0;
		TIM2->CCR2=0;
		TIM2->CCR3=0;
		TIM2->CCR4=0;
	}
	else
	{
		TIM2->CCR1=999;
		TIM2->CCR2=999;
		TIM2->CCR3=999;
		TIM2->CCR4=999;
		
		if(md>=1000)
		{
			md=999;
		}
		else if(md<=-1000)
		{
			md=-999;
		}
		
		if(md>0)
		{
			TIM2-> CCR2 = 999 - abs(md);
			TIM2->CCR1 = 999;
		}
		else if(md<0)
		{
			TIM2-> CCR2 = 999;
			TIM2->CCR1 = 999-abs(md);
		}
		else
		{
			TIM2->CCR1=999;
			TIM2->CCR2=999;
		}
		
		if(mi>=1000)
		{
			mi = 999;
		}
		else if(mi<=-1000)
		{
			mi=-999;
		}
		
		if(mi>0)
		{
			TIM2->CCR3=999-abs(mi);
			TIM2->CCR4 = 999;
		}
		else if(mi<0)
		{
			TIM2->CCR4 = 999-abs(mi);
			TIM2->CCR3=999;
		}
		else
		{
			TIM2->CCR3=999;
			TIM2->CCR4=999;
		}
	}	
}

