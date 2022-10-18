#include "Funciones.h"
#include "gpio.h"
#include "stm32f0xx_hal.h"
#include "Lion1.h"
#include "cmsis_os.h"
#include "ssd1306.h"
#include "main.h"

extern Variables_flash v_flash;
extern Lion1_2 str;


void Lectura_botones(void)
{

osDelay(200);
	if(HAL_GPIO_ReadPin(UP_GPIO_Port,UP_Pin)==0)
	{
		str.up_but=1;
	}
	else
	{
		str.up_but=0;
	}

	if(HAL_GPIO_ReadPin(PUERTO_DOWN,DOWN_Pin)==0)
	{
		str.down_but=1;
	}
	else
	{
		str.down_but=0;
	}

	if(HAL_GPIO_ReadPin(PUERTO_OK,RIGHT_Pin)==0)
	{
		str.right_but=1;
	}
	else
	{
		str.right_but=0;
	}

	if(HAL_GPIO_ReadPin(PUERTO_BACK,LEFT_Pin)==0)
	{
		str.left_but=1;
	}
	else
	{
		str.left_but=0;
	}

}




void Comprobar_sensores(void)
{
	//funcion para habilitar o deshabilitar sensores
	//1 activado
	//0 desactivado
switch (str.sens_num)
				{
					case 1:
						if(str.sens_1==1)
						{
							str.sens_1=0;
						}
						else
						{
							str.sens_1=1;
						}
					break;
					case 2:
						if(str.sens_2==1)
						{
							str.sens_2=0;
						}
						else
						{
							str.sens_2=1;
						}
					break;
						case 3:
						if(str.sens_3==1)
						{
							str.sens_3=0;
						}
						else
						{
							str.sens_3=1;
						}
					break;
						case 4:
						if(str.sens_4==1)
						{
							str.sens_4=0;
						}
						else
						{
							str.sens_4=1;
						}
					break;
						case 5:
						if(str.sens_5==1)
						{
							str.sens_5=0;
						}
						else
						{
							str.sens_5=1;
						}
					break;
						case 6:
						if(str.sens_6==1)
						{
							str.sens_6=0;
						}
						else
						{
							str.sens_6=1;
						}
					break;
						case 7:
						if(str.sens_7==1)
						{
							str.sens_7=0;
						}
						else
						{
							str.sens_7=1;
						}
					break;
						case 8:
						if(str.sens_8==1)
						{
							str.sens_8=0;
						}
						else
						{
							str.sens_8=1;
						}
					break;
						case 9:
						if(str.sens_9==1)
						{
							str.sens_9=0;
						}
						else
						{
							str.sens_9=1;
						}
					break;
				}
}

void check_sensor(void)
{
	//Check sensor 1
	if(str.sens_1==0)
	{
		SSD1306_DrawRectangle(73,33,6,5,1); //Sensor 1
	}
	else if(str.sens_1==2)
	{
		SSD1306_DrawFilledRectangle(73,33,6,5,1); //Sensor 1
	}

	//Check sensor 2
	if(str.sens_2==0)
	{
		SSD1306_DrawRectangle(70,18,9,5,1); //Sensor 2
	}
	else if(str.sens_2==2)
	{
		SSD1306_DrawFilledRectangle(70,18,9,5,1); //Sensor 2
	}

	//Check sensor 3
	if(str.sens_3==0)
	{
		SSD1306_DrawRectangle(56,18,5,6,1); //Sensor 3
	}
	else if(str.sens_3==2)
	{
		SSD1306_DrawFilledRectangle(56,18,5,6,1); //Sensor 3
	}

	//Check sensor 4
	if(str.sens_4==0)
	{
		SSD1306_DrawRectangle(38,18,9,5,1); //Sensor 4
	}
	else if(str.sens_4==2)
	{
		SSD1306_DrawFilledRectangle(38,18,9,5,1); //Sensor 4
	}

//Check sensor 5
	if(str.sens_5==0)
	{
		SSD1306_DrawRectangle(38,33,6,5,1); //Sensor 5
	}
	else if(str.sens_5==2)
	{
		SSD1306_DrawFilledRectangle(38,33,6,5,1); //Sensor 5
	}
	
	//Check sensor 6
	if(str.sens_6==0)
	{
		SSD1306_DrawRectangle(74,8,4,5,1);  //Sensor 6
	}
	else if(str.sens_6==2)
	{
		SSD1306_DrawFilledRectangle(74,8,4,5,1);  //Sensor 6
	}

	//Check sensor 7
	if(str.sens_7==0)
	{
		SSD1306_DrawRectangle(66,8,4,5,1);  //Sensor 7
	}
	else if(str.sens_7==2)
	{
		SSD1306_DrawFilledRectangle(66,8,4,5,1);  //Sensor 7
	}

	//Check sensor 8
	if(str.sens_8==0)
	{
		SSD1306_DrawRectangle(47,8,4,5,1);  //Sensor 8
	}
	else if(str.sens_8==2)
	{
		SSD1306_DrawFilledRectangle(47,8,4,5,1);  //Sensor 8
	}

	//Check sensor 9
	if(str.sens_9==0)
	{
		SSD1306_DrawRectangle(39,8,4,5,1);  //Sensor 9
	}
	else if(str.sens_9==2)
	{
		SSD1306_DrawFilledRectangle(39,8,4,5,1);  //Sensor 9
	}
	

}

void lectura_sensores_verif(void)
{
	//verificacion de sensores para ver en pantalla
	//pantalla 2 comprobar sensores 
		//estado 0 == sin presencia
		//estado 1 == deshabilitados
		//estado 2 == presencia
	if(str.sens_1!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_SH_RIGHT,SH_RIGHT)==0)
		{
			str.sens_1=2;
		}
		else
		{
			str.sens_1=0;
		}
	}
	if(str.sens_2!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_OM_RIGHT,OM_RIGHT)==0)
		{
			str.sens_2=2;
		}
		else
		{
			str.sens_2=0;
		}
	}
	if(str.sens_3!=1)
	{
		if(str.SensorDistaciaCentral==1)
		{
			str.sens_3=2;
		}
		else
		{
			str.sens_3=0;
		}
	}
	if(str.sens_4!=1)
	{
		if(HAL_GPIO_ReadPin(PUERTO_OM_LEFT,OM_LEFT)==0)
		{
			str.sens_4=2;
		}
		else
		{
			str.sens_4=0;
		}
	}
	if(str.sens_5!=1)
	{	
		if(HAL_GPIO_ReadPin(PUERTO_SH_LEFT,SH_LEFT)==0)
		{
			str.sens_5=2;
		}
		else
		{
			str.sens_5=0;
		}
	}
	if(str.sens_6!=1)
	{
		if(str.pisod_1==-1)
		{
			str.sens_6=2;
		}
		else
		{
			str.sens_6=0;
		}	
	}
	if(str.sens_7!=1)
	{
		if(str.pisod_2==-1)
		{
			str.sens_7=2;
		}
		else
		{
			str.sens_7=0;
		}
	}
	if(str.sens_8!=1)
	{
		if(str.pisoi_1==-1)
		{
			str.sens_8=2;
		}
		else
		{
			str.sens_8=0;
		}
	}
	if(str.sens_9!=1)
	{
		if(str.pisoi_2==-1)
		{
			str.sens_9=2;
		}
		else
		{
			str.sens_9=0;
		}
	}

}


void bluetooth (void)
{
	
	osDelay(10);
	

		if(str.flag_rx)
		{
			str.flag_rx=0;
			for(int i=0;i<60;i++)
			{
				
				// Indices
				// A configuracion general
				// B str1
				// C str2
				// D str3
				// E str4
				// F str5
				// G str6
				// H str7
				// I str8
				// J str9
				
				if(str.buffer_rx[i]=='K'||str.buffer_rx[i]=='L'||str.buffer_rx[i]=='M'||str.buffer_rx[i]=='N'||str.buffer_rx[i]=='O'
					||str.buffer_rx[i]=='P'||str.buffer_rx[i]=='Q'||str.buffer_rx[i]=='R'||str.buffer_rx[i]=='S'||str.buffer_rx[i]=='T')
				{
					str.seleccion_str_app=str.buffer_rx[i];
					//organizar datos con indice i+x
					//case A
					if(str.buffer_rx[i+1]=='A') //exanmple &A%020%012%1000%0100%0100%200%2000%%%%%%
					{
						v_flash.cte_deriv_b = ((str.buffer_rx[i+3]-48)*100)+((str.buffer_rx[i+4]-48)*10)+((str.buffer_rx[i+5]-48));
						v_flash.cte_prop_b = ((str.buffer_rx[i+7]-48)*100)+((str.buffer_rx[i+8]-48)*10)+(str.buffer_rx[i+9]-48);
						v_flash.vel_max = ((str.buffer_rx[i+11]-48)*1000)+((str.buffer_rx[i+12]-48)*100)+((str.buffer_rx[i+13]-48)*10)+((str.buffer_rx[i+14])-48);
						v_flash.vel_min = ((str.buffer_rx[i+16]-48)*1000)+((str.buffer_rx[i+17]-48)*100)+((str.buffer_rx[i+18]-48)*10)+((str.buffer_rx[i+19]-48));
						v_flash.vel_no_op = ((str.buffer_rx[i+21]-48)*1000)+((str.buffer_rx[i+22]-48)*100)+((str.buffer_rx[i+23]-48)*10)+((str.buffer_rx[i+24]-48));
						v_flash.osc_no_op = ((str.buffer_rx[i+26]-48)*100)+((str.buffer_rx[i+27]-48)*10)+((str.buffer_rx[i+28]-48));
						v_flash.frecuencia = ((str.buffer_rx[i+30]-48)*1000)+((str.buffer_rx[i+31]-48)*100)+((str.buffer_rx[i+32]-48)*10)+((str.buffer_rx[i+33]-48));
						if(str.buffer_rx[i+35] == 'Z')
						{
							MC_Write_Setup();
						}
						
					}
					if(str.buffer_rx[i+1]=='B') //example  str1 &B%0200%0300%100%100%0500%%%%%%%%%%%%%%%  
					{
						v_flash.t_str1 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.conf_op_lim = ((str.buffer_rx[i+8]-48)*1000)+((str.buffer_rx[i+9]-48)*100)+((str.buffer_rx[i+10]-48)*10)+((str.buffer_rx[i+11]-48));
						v_flash.limite_entre_paso_str1 = ((str.buffer_rx[i+13]-48)*100)+((str.buffer_rx[i+14]-48)*10)+((str.buffer_rx[i+15]-48));
						v_flash.limite_entre_paso_off_str1 =((str.buffer_rx[i+17]-48)*100)+((str.buffer_rx[i+18]-48)*10)+((str.buffer_rx[i+19]-48));
						v_flash.vel_mot_str1 = ((str.buffer_rx[i+21]-48)*1000)+((str.buffer_rx[i+22]-48)*100)+((str.buffer_rx[i+23]-48)*10)+((str.buffer_rx[i+24]-48));
						if(str.buffer_rx[i+26] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='C') //example  str2 &C%0500%0800%0800%0200%%%%%%%%%%%%%%%%%%
					{
						v_flash.t_str2 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_der_str2 = ((str.buffer_rx[i+8]-48)*1000)+((str.buffer_rx[i+9]-48)*100)+((str.buffer_rx[i+10]-48)*10)+((str.buffer_rx[i+11]-48));
						v_flash.vel_izq_str2 = ((str.buffer_rx[i+13]-48)*1000)+((str.buffer_rx[i+14]-48)*100)+((str.buffer_rx[i+15]-48)*10)+((str.buffer_rx[i+16]-48));
						v_flash.conf_op_lim_str2 = ((str.buffer_rx[i+18]-48)*1000)+((str.buffer_rx[i+19]-48)*100)+((str.buffer_rx[i+20]-48)*10)+((str.buffer_rx[i+21]-48));
						if(str.buffer_rx[i+23] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='D') //example  str3 &D%0500%500%050%500%500%700%200%800%090%
					{
						v_flash.t_str3 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_giro1_str3 = ((str.buffer_rx[i+8]-48)*100)+((str.buffer_rx[i+9]-48)*10)+((str.buffer_rx[i+10]-48));
						v_flash.duracion_giro1_str3 = ((str.buffer_rx[i+12]-48)*100)+((str.buffer_rx[i+13]-48)*10)+((str.buffer_rx[i+14]-48));
						v_flash.vel_der_gir2_str3 = ((str.buffer_rx[i+16]-48)*100)+((str.buffer_rx[i+17]-48)*10)+((str.buffer_rx[i+18]-48));
						v_flash.vel_izq_gir2_str3 = ((str.buffer_rx[i+20]-48)*100)+((str.buffer_rx[i+21]-48)*10)+((str.buffer_rx[i+22]-48));
						v_flash.vel_gir3_str3 = ((str.buffer_rx[i+24]-48)*100)+((str.buffer_rx[i+25]-48)*10)+((str.buffer_rx[i+26]-48));
						v_flash.duracion_giro3_str3 = ((str.buffer_rx[i+28]-48)*100)+((str.buffer_rx[i+29]-48)*10)+((str.buffer_rx[i+30]-48));
						v_flash.vel_ataque_str3 = ((str.buffer_rx[i+32]-48)*100)+((str.buffer_rx[i+33]-48)*10)+((str.buffer_rx[i+34]-48));
						v_flash.duracion_ataque_str3 = ((str.buffer_rx[i+36]-48)*100)+((str.buffer_rx[i+37]-48)*10)+((str.buffer_rx[i+38]-48));
						if(str.buffer_rx[i+40] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='E') //example  str4 &D%0500%500%050%500%500%700%200%800%090%
					{
						v_flash.t_str4 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_giro1_str4 = ((str.buffer_rx[i+8]-48)*100)+((str.buffer_rx[i+9]-48)*10)+((str.buffer_rx[i+10]-48));
						v_flash.duracion_giro1_str4 = ((str.buffer_rx[i+12]-48)*100)+((str.buffer_rx[i+13]-48)*10)+((str.buffer_rx[i+14]-48));
						v_flash.vel_der_gir2_str4 = ((str.buffer_rx[i+16]-48)*100)+((str.buffer_rx[i+17]-48)*10)+((str.buffer_rx[i+18]-48));
						v_flash.vel_izq_gir2_str4 = ((str.buffer_rx[i+20]-48)*100)+((str.buffer_rx[i+21]-48)*10)+((str.buffer_rx[i+22]-48));
						v_flash.vel_gir3_str4 = ((str.buffer_rx[i+24]-48)*100)+((str.buffer_rx[i+25]-48)*10)+((str.buffer_rx[i+26]-48));
						v_flash.duracion_giro3_str4 = ((str.buffer_rx[i+28]-48)*100)+((str.buffer_rx[i+29]-48)*10)+((str.buffer_rx[i+30]-48));
						v_flash.vel_ataque_str4 = ((str.buffer_rx[i+32]-48)*100)+((str.buffer_rx[i+33]-48)*10)+((str.buffer_rx[i+34]-48));
						v_flash.duracion_ataque_str4 = ((str.buffer_rx[i+36]-48)*100)+((str.buffer_rx[i+37]-48)*10)+((str.buffer_rx[i+38]-48));
						if(str.buffer_rx[i+40] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='F') //example  str5 &F%0500%0800%0800%0200%%%%%%%%%%%%%%%%%%
					{
						v_flash.t_str5 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_der_str5 = ((str.buffer_rx[i+8]-48)*1000)+((str.buffer_rx[i+9]-48)*100)+((str.buffer_rx[i+10]-48)*10)+((str.buffer_rx[i+11]-48));
						v_flash.vel_izq_str5 = ((str.buffer_rx[i+13]-48)*1000)+((str.buffer_rx[i+14]-48)*100)+((str.buffer_rx[i+15]-48)*10)+((str.buffer_rx[i+16]-48));
						v_flash.conf_op_lim_str5 = ((str.buffer_rx[i+18]-48)*1000)+((str.buffer_rx[i+19]-48)*100)+((str.buffer_rx[i+20]-48)*10)+((str.buffer_rx[i+21]-48));
						if(str.buffer_rx[i+23] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='G') //example  str6 &G%0500%0800%0800%0200%%%%%%%%%%%%%%%%%%
					{
						v_flash.t_str6 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_der_str6 = ((str.buffer_rx[i+8]-48)*1000)+((str.buffer_rx[i+9]-48)*100)+((str.buffer_rx[i+10]-48)*10)+((str.buffer_rx[i+11]-48));
						v_flash.vel_izq_str6 = ((str.buffer_rx[i+13]-48)*1000)+((str.buffer_rx[i+14]-48)*100)+((str.buffer_rx[i+15]-48)*10)+((str.buffer_rx[i+16]-48));
						v_flash.conf_op_lim_str6 = ((str.buffer_rx[i+18]-48)*1000)+((str.buffer_rx[i+19]-48)*100)+((str.buffer_rx[i+20]-48)*10)+((str.buffer_rx[i+21]-48));
						if(str.buffer_rx[i+23] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='H') //str 7
					{
						v_flash.t_str7 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.proporcional1 = ((str.buffer_rx[i+8]-48)*100)+((str.buffer_rx[i+9]-48)*10)+((str.buffer_rx[i+10]-48));
						v_flash.cte_integral1 = ((str.buffer_rx[i+12]-48)*100)+((str.buffer_rx[i+13]-48)*10)+((str.buffer_rx[i+14]-48));
						v_flash.cte_derivativa1 = ((str.buffer_rx[i+16]-48)*100)+((str.buffer_rx[i+17]-48)*10)+((str.buffer_rx[i+18]-48));
						v_flash.avance_der_str7 = ((str.buffer_rx[i+20]-48)*100)+((str.buffer_rx[i+21]-48)*10)+((str.buffer_rx[i+22]-48));
						v_flash.avance_izq_str7 = ((str.buffer_rx[i+24]-48)*100)+((str.buffer_rx[i+25]-48)*10)+((str.buffer_rx[i+26]-48));
						v_flash.vel_giro_str7 = ((str.buffer_rx[i+28]-48)*100)+((str.buffer_rx[i+29]-48)*10)+((str.buffer_rx[i+30]-48));
						v_flash.duracion_giro_str7 = ((str.buffer_rx[i+32]-48)*100)+((str.buffer_rx[i+33]-48)*10)+((str.buffer_rx[i+34]-48));
						if(str.buffer_rx[i+36] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='I') //str8
					{
						v_flash.t_str8 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.proporcional2 = ((str.buffer_rx[i+8]-48)*100)+((str.buffer_rx[i+9]-48)*10)+((str.buffer_rx[i+10]-48));
						v_flash.cte_integral2 = ((str.buffer_rx[i+12]-48)*100)+((str.buffer_rx[i+13]-48)*10)+((str.buffer_rx[i+14]-48));
						v_flash.cte_derivativa2 = ((str.buffer_rx[i+16]-48)*100)+((str.buffer_rx[i+17]-48)*10)+((str.buffer_rx[i+18]-48));
						v_flash.avance_der_str8 = ((str.buffer_rx[i+20]-48)*100)+((str.buffer_rx[i+21]-48)*10)+((str.buffer_rx[i+22]-48));
						v_flash.avance_izq_str8 = ((str.buffer_rx[i+24]-48)*100)+((str.buffer_rx[i+25]-48)*10)+((str.buffer_rx[i+26]-48));
						v_flash.vel_giro_str8 = ((str.buffer_rx[i+28]-48)*100)+((str.buffer_rx[i+29]-48)*10)+((str.buffer_rx[i+30]-48));
						v_flash.duracion_giro_str8 = ((str.buffer_rx[i+32]-48)*100)+((str.buffer_rx[i+33]-48)*10)+((str.buffer_rx[i+34]-48));
						if(str.buffer_rx[i+36] == 'Z')
						{
							MC_Write_Setup();
						}
					}
					if(str.buffer_rx[i+1]=='J') //str9
					{
						v_flash.t_str9 = ((str.buffer_rx[i+3]-48)*1000)+((str.buffer_rx[i+4]-48)*100)+((str.buffer_rx[i+5]-48)*10)+((str.buffer_rx[i+6]-48));
						v_flash.vel_giro_str9 = ((str.buffer_rx[i+8]-48)*100)+((str.buffer_rx[i+9]-48)*10)+((str.buffer_rx[i+10]-48));
						if(str.buffer_rx[i+12] == 'Z')
						{
							MC_Write_Setup();
						}
						
					}
					
				}
				//asignar datos a variables de flash
				//luego cargar en la flash, al momento de arrancar programa sin este codigo, se debe cargar la 
				//flash en la estructura 
				//guardar datos
//				if(str.buffer_rx[i] == '$')
//				{
//					if(str.buffer_rx[i+1] == 'Z')
//					{
//						MC_Write_Setup();
//					}
//				}
		//		str.buffer_rx[i]=0;
			}
			osDelay(200);
			for(int i=0;i<60;i++)
			{
				str.buffer_rx[i]=0;
			}
				HAL_UART_Receive_IT(&huart1,str.buffer_rx,42);
		}
		
		if(str.seleccion_str_app=='K')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|%d|%d|",(int)v_flash.cte_deriv_b,(int)v_flash.cte_prop_b,v_flash.vel_max,v_flash.vel_min,
					v_flash.vel_no_op,v_flash.osc_no_op,v_flash.frecuencia);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='L')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|",v_flash.t_str1,v_flash.conf_op_lim,v_flash.vel_mot_str1,
					v_flash.limite_entre_paso_str1,v_flash.limite_entre_paso_off_str1);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='M')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|",v_flash.t_str2,v_flash.vel_der_str2,v_flash.vel_izq_str2,
					v_flash.conf_op_lim_str2);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='N')
		{						
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|%d|%d|%d|%d|",
					v_flash.t_str3,v_flash.vel_giro1_str3,v_flash.duracion_giro1_str3,v_flash.vel_der_gir2_str3,v_flash.vel_izq_gir2_str3,
					v_flash.vel_gir3_str3,v_flash.duracion_giro3_str3,v_flash.vel_ataque_str3,v_flash.duracion_ataque_str3);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='O')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|%d|%d|%d|%d|",
					v_flash.t_str4,v_flash.vel_giro1_str4,v_flash.duracion_giro1_str4,v_flash.vel_der_gir2_str4,v_flash.vel_izq_gir2_str4,
					v_flash.vel_gir3_str4,v_flash.duracion_giro3_str4,v_flash.vel_ataque_str4,v_flash.duracion_ataque_str4);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='P')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|",v_flash.t_str5,v_flash.vel_der_str5,v_flash.vel_izq_str5,
					v_flash.conf_op_lim_str5);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='Q')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|",v_flash.t_str6,v_flash.vel_der_str6,v_flash.vel_izq_str6,
					v_flash.conf_op_lim_str6);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='R')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|%d|%d|%d|",v_flash.t_str7,
					(int)v_flash.proporcional1,(int)v_flash.cte_integral1,(int)v_flash.cte_derivativa1,v_flash.avance_der_str7,v_flash.avance_izq_str7,
				v_flash.vel_giro_str7,v_flash.duracion_giro_str7);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='S')
		{			
				sprintf((char*)str.buffer_tx,"%d|%d|%d|%d|%d|%d|%d|%d|",v_flash.t_str8,
					(int)v_flash.proporcional2,(int)v_flash.cte_integral2,(int)v_flash.cte_derivativa2,v_flash.avance_der_str8,v_flash.avance_izq_str8,
				v_flash.vel_giro_str8,v_flash.duracion_giro_str8);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);
				str.seleccion_str_app=' ';
		}
		
		if(str.seleccion_str_app=='T')
		{
				sprintf((char*)str.buffer_tx,"%d|%d|0|0|0|",v_flash.t_str9,
				v_flash.vel_giro_str9);
				HAL_UART_Transmit(&huart1,str.buffer_tx,sizeof(str.buffer_tx),100);			
				str.seleccion_str_app=' ';
		}
	osDelay(20);
	
	
}

void bluetooth_RC(void)
{
	osDelay(17);
	if(str.flag_rx)
		{
			str.flag_rx=0;
			for(int i=0;i<60;i++)
			{
				if(str.buffer_rx[i]=='&')
				{
					if(str.buffer_rx[i+1]=='A')
					{
						str.control_md_RC = ((str.buffer_rx[i+2]-48)*1000)+((str.buffer_rx[i+3]-48)*100)+((str.buffer_rx[i+4]-48)*10)+((str.buffer_rx[i+5])-48);
					}
					else
					{
						str.control_md_RC=0;
					}
					if(str.buffer_rx[i+6]=='B')
					{
						if(str.buffer_rx[i+7]=='0')
						{
							str.signo_md=-1;
						}
						else if(str.buffer_rx[i+7]=='1')
						{
							str.signo_md=1;
						}
					}
					if(str.buffer_rx[i+8]=='C')
					{
						str.control_mi_RC = ((str.buffer_rx[i+9]-48)*1000)+((str.buffer_rx[i+10]-48)*100)+((str.buffer_rx[i+11]-48)*10)+((str.buffer_rx[i+12])-48);
					}
					else
					{
						str.control_mi_RC = 0;
					}
					if(str.buffer_rx[i+13]=='D')
					{
						if(str.buffer_rx[i+14]=='0')
						{
							str.signo_mi=-1;
						}
						else if(str.buffer_rx[i+14]=='1')
						{
							str.signo_mi=1;
						}
					}
					if(str.buffer_rx[i+15]=='#')
					{
						str.start=1;
						str.tiempo=2;
					}
					else if(str.buffer_rx[i+15]!='#')
					{
						str.start=0;
						str.tiempo=1;
					}
					if(str.start)
					{
						str.control_md=str.control_md_RC*str.signo_md;
						str.control_mi=str.control_mi_RC*str.signo_mi;
					}
					else
					{
						str.control_md=0;
						str.control_mi=0;
					}
					
				}
//				else
//				{
//					str.control_md=0;
//					str.control_mi=0;
//				}
			}
			
			//osDelay(10);
			for(int i=0;i<60;i++)
			{
				str.buffer_rx[i]=0;
			}
				HAL_UART_Receive_IT(&huart1,str.buffer_rx,16);
			
			
		}
}
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	str.flag_rx=1;
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

