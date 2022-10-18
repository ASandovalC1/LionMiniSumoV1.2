#include "stm32f0xx_hal.h"
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "Estrategias.h"

void detecta_linea(void)
{
	str.ppaso1=1;
	str.conf_negro1=0;
	str.conf_negro2=0;
	if(str.pisoi_1==-1 || str.pisoi_2==-1)
	{
		
		str.control_mi=-999;
		str.control_md=-999;
		osDelay(20);
		
		while((str.pisod_1==1 && str.pisod_2==1) && str.conf_negro1==0)
		{
			str.control_mi=-400;
			str.control_md=400;
			osDelay(20);
			if((str.pisoi_1==1 || str.pisoi_2==1))
			{
					str.conf_negro1=1;
			}
			str.control_mi=0;
			str.control_md=0;
			osDelay(20);
			
		}
	}
	else if((str.pisod_1==-1 || str.pisod_2==-1))
	{
		
		str.control_mi=-999;
		str.control_md=-999;
		osDelay(20);
		
		while((str.pisoi_1==1 && str.pisoi_2==1)&& str.conf_negro2==0)
		{
			str.control_mi=400;
			str.control_md=-400;
			osDelay(20);
			if((str.pisod_1==1 || str.pisod_2==1))
			{
				str.conf_negro2=1;
			}
			str.control_mi=0;
			str.control_md=0;
			osDelay(20);
			
		}	
	}
	if((str.pisoi_1==-1 ||str.pisoi_2==-1) && (str.pisod_1==-1 && str.pisod_2==-1))
	{
			while(str.ppaso1>=1 && str.ppaso1<=3)
			{
				if(str.ppaso1==1)
				{
				
					str.control_mi=-999;
					str.control_md=-999;
					osDelay(150);
					str.ppaso1++;
				}
				if(str.ppaso1==2)
				{
					if((str.pisoi_1==-1 ||str.pisoi_2==-1) && (str.pisod_1==-1 && str.pisod_2==-1))
					{
						str.ppaso1=1;
					}
					else
					{
						str.control_mi=999;
						str.control_md=999;
						osDelay(20);
						
						str.control_mi=700;
						str.control_md=-700;
						osDelay(320);
						str.ppaso1++;
					}
				}
				if (str.ppaso1==3)
				{
					str.control_mi=0;
					str.control_md=0;
					osDelay(50);
					str.control_mi=500;
					str.control_md=500;
					str.ppaso1=4;
				}
			}
		}
	//str.control_mi=0;
	//				str.control_md=0;
	}

void no_oponente(void) //busqueda oscilando
{
	str.confirma_izquierda=0;
	//TIM2->PSC=25;
	
	if(str.avance>str.vel_min)
	{ 
		str.avance--;
	}
	
	if(str.oscilacion==1)
	{
		str.tim_oscilacion++;
		str.control_mi=str.vel_no_op;
		str.control_md=-str.vel_no_op;
		if(str.tim_oscilacion>str.osc_no_op)
		{
			str.tim_oscilacion=0;
			str.oscilacion=-1;
			
		}
	}
	else if (str.oscilacion==-1)
	{
		str.tim_oscilacion++;
		str.control_mi=-str.vel_no_op;
		str.control_md=str.vel_no_op;
		if(str.tim_oscilacion>str.osc_no_op)
		{
			str.tim_oscilacion=0;
			str.oscilacion=1;
		}
	}
}
void control_busqueda(int a_ubicacion_l) //control busqueda -ataque
{	
	str.error_b[0]=a_ubicacion_l;
	str.error_b[9]=str.error_b[8];
	str.error_b[8]=str.error_b[7];
	str.error_b[7]=str.error_b[6];
	str.error_b[6]=str.error_b[5];
	str.error_b[5]=str.error_b[4];
	str.error_b[4]=str.error_b[3];
	str.error_b[3]=str.error_b[2];
	str.error_b[2]=str.error_b[1];
	str.error_b[1]=str.error_b[0];
	
	
	str.derivativo_b = str.error_b[0]-str.error_b[5];
	
	if(str.a_ubicacion == 0)
	{
		 str.integral_b = 0;
	}
	else
	{
	   str.integral_b += str.error_b[0];
	}
	
	if(str.integral_b > 100000)
		str.integral_b = 100000;
	if(str.integral_b <- 100000)
	 str.integral_b = -100000;
	
	
	str.control_b = (str.error_b[0]*str.cte_prop_b)+(str.derivativo_b*str.cte_deriv_b)+(str.integral_b/1000);
	str.control_b = (int)str.control_b;

//	str.avance = 0;//400
	
	
//		if(str.control_b == 0 )
//		{
			if(str.SensorDistaciaCentral)
				{
					str.avance = 1000;//400
				}
////				else //AVANCE CENTRO LEJANO
////				{
////				   str.avance = 400;//400
////				}
////				
//				str.timeout_ataque_retiro ++;
//		}
//		else
//		{
//      str.timeout_ataque_retiro = 0;
//			
//			str.f_avance = 400*abs((int)str.control_b)/500;
//			str.f_avance = 400 - str.f_avance;
//			if(str.f_avance<=0)
//			{
//				str.avance=0;
//			}
//			else
//			{
//				str.avance=str.f_avance;
//			}
//		}
		
	
//	

	if(abs(str.error_b[0])>100 || str.error_b[0]==-1)
	{
		str.avance--;
	}
	else
	{
//		TIM2->PSC=200;
		str.cnt_avance++;
		if(str.cnt_avance==3)
		{
			str.avance=str.avance+20;
			str.cnt_avance=0;
		}
		
	}

		if(str.avance>str.vel_max)
		{
			str.avance=str.vel_max;
		}
		else if(str.avance<str.vel_min)
		{
			str.avance=str.vel_min;
		}

		
//     if(str.timeout_ataque_retiro < 500 * 6)
//		 {
		   str.control_md = str.avance- (str.control_b);
		   str.control_mi = str.avance+ (str.control_b);
//		 }
//		 else
//		 {
//		   str.control_md = -100;
//		   str.control_mi = -1000;
//		   osDelay(50);
//			 str.control_md = 500;
//		   str.control_mi = 500;
//			 osDelay(15);
//			 str.control_md = 0;
//		   str.control_mi = 0;
//		 } 
}


void estrategias_ex(void)
{
	switch (str.num_estrategia)
	{
		case 1:
		{
			estrategia_1();
			break;
		}
		case 2:
		{
			estrategia_2();
			break;
		}
		case 3:
		{
			estrategia_3();
			break;
		}
		case 4:
		{
			estrategia_4();
			break;
		}
		case 5:
		{
			estrategia_5();
			break;
		}
		case 6:
		{
			estrategia_6();
			break;
		}
		case 7:
		{
			estrategia_7();
			break;
		}
		case 8:
		{
			estrategia_8();
			break;
		}
		case 9:
		{
			estrategia_9();
			break;
		}
		default:
		{
			break;
		}
		
		
	}
	str.control_mi=0;
	str.control_md=0;	
}


void estrategia_1(void)
{
		str.timeout_str=str.t_str1;//2700;
		if(str.paso==1)
		{
			while(str.timeout_str!=0 && str.confirma_frente<str.conf_op_lim)//1000)
			{
				//control_busqueda(str.a_ubicacion);
				
				if(str.estr1_esp<str.limite_entre_paso_str1)
				{
					str.control_md=str.vel_mot_str1;//420;
					str.control_mi=str.vel_mot_str1;//420;
					str.estr1_esp++;
				}
				else if(str.estr1_esp>=str.limite_entre_paso_str1 && str.estr1_esp<200)
				{
					control_busqueda(str.a_ubicacion);
					str.estr1_esp++;
				}
				else if(str.estr1_esp>=200 && str.estr1_esp<str.limite_entre_paso_off_str1)
				{
					str.estr1_esp++;
					str.control_md=0;
					str.control_mi=0;
				}
				else
				{
					str.estr1_esp=0;
				}
				if(str.a_ubicacion!=-1)
				{
					str.confirma_frente++;
				}
				str.timeout_str--;
				osDelay(1);
			}
		}
}
void estrategia_2(void)
{
		str.timeout_str=str.t_str2;//350;
		if(str.paso==1)
		{
			str.control_md=str.vel_der_str2;//990;
			str.control_mi=str.vel_izq_str2;//990;
			while(str.timeout_str!=0 && str.confirma_frente<str.conf_op_lim_str2)
			{
				if(str.a_ubicacion!=-1)
				{
					str.confirma_frente++;
				}
				str.timeout_str--;
				osDelay(1);
			}

		}
}
void estrategia_3(void)
{
						str.timeout_str=str.t_str3;//370;
						if(str.paso==1)
						{
							str.control_md=-str.vel_giro1_str3;
							str.control_mi=str.vel_giro1_str3;
							osDelay(str.duracion_giro1_str3);
							while(str.timeout_str!=0 && str.a_ubicacion!=-200)
							{
								str.control_mi=str.vel_izq_gir2_str3;
								str.control_md=str.vel_der_gir2_str3;
								str.timeout_str--;
								osDelay(1);
								if(str.sp_d1<-1500) //cambiar a valor relacionado a funcion piso 1 o -1 creo...
								{
									str.timeout_str=0; //sale de estrategia en caso de detectar piso
								}
							}
							str.paso=2;
							
								if(str.a_ubicacion==-200)
								{
									str.paso=4; // si detecta oponente al lado salta a paso 4
								}												
						}
						if(str.paso==2)
						{
								str.control_mi=-str.vel_gir3_str3;
								str.control_md=str.vel_gir3_str3;
								osDelay(str.duracion_giro3_str3);
								str.paso=3;
						}
						if(str.paso==3)
						{
								str.control_mi=str.vel_ataque_str3;
								str.control_md=str.vel_ataque_str3;
								osDelay(str.duracion_ataque_str3);
								str.paso=4;
						}
		
}

void estrategia_4(void)
{
						str.timeout_str=str.t_str4;//350;
						if(str.paso==1)
						{							
							str.control_md=str.vel_giro1_str4;
							str.control_mi=-str.vel_giro1_str4;
							osDelay(str.duracion_giro1_str4);
							while(str.timeout_str!=0 && str.a_ubicacion!=200)
							{
								str.control_mi=str.vel_izq_gir2_str4;
								str.control_md=str.vel_der_gir2_str4;
								str.timeout_str--;
								osDelay(1);
								if(str.sp_d1<-1500)
								{
									str.timeout_str=0;
								}							
							}
							str.paso=2;
								if(str.a_ubicacion==200)
								{
									str.paso=4;
								}														
						}
						if(str.paso==2)
						{
								str.control_mi=str.vel_gir3_str4;
								str.control_md=-str.vel_gir3_str4;
								osDelay(str.duracion_giro3_str4);
								str.paso=3;
						}
						if(str.paso==3)
						{
								str.control_mi=str.vel_ataque_str4;
								str.control_md=str.vel_ataque_str4;
								osDelay(str.duracion_ataque_str4);
								str.paso=4;
						}
}
void estrategia_5(void)
{
		str.timeout_str=str.t_str5;//400;
		if(str.paso==1)
		{
			str.control_md=str.vel_der_str5;
			str.control_mi=-str.vel_izq_str5;
			while(str.timeout_str!=0 && str.confirma_frente<str.conf_op_lim_str5)
			{
				if(str.a_ubicacion>100 && str.a_ubicacion<200)
				{
					str.confirma_frente++;
				}
				str.timeout_str--;
				osDelay(1);
			}
			str.control_md=0;
			str.control_mi=0;

		}
}
void estrategia_6(void)
{
		str.timeout_str=str.t_str6;//400;
		if(str.paso==1)
		{
			str.control_md=-str.vel_der_str6;
			str.control_mi=str.vel_izq_str6;
			while(str.timeout_str!=0 && str.confirma_frente<str.conf_op_lim_str6)
			{
				if(str.a_ubicacion<-100 && str.a_ubicacion>-200)
				{
					str.confirma_frente++;
				}
				str.timeout_str--;
				osDelay(1);
			}
			str.control_md=0;
			str.control_mi=0;
		}
}
void estrategia_7(void)
{
//			str.control_mi=800;
//			str.control_md=800;
			str.timeout_str=str.t_str7;//700;
		
			//str.a_ubicacion=-200
			while(str.a_ubicacion!=-200 && str.timeout_str!=0)
			{
				str.timeout_str--;
				str.error1[0]=str.pisod_1+str.pisod_2;
				str.error1[9]=str.error1[8];
				str.error1[8]=str.error1[7];
				str.error1[7]=str.error1[6];
				str.error1[6]=str.error1[5];
				str.error1[5]=str.error1[4];
				str.error1[4]=str.error1[3];
				str.error1[3]=str.error1[2];
				str.error1[2]=str.error1[1];
				str.error1[1]=str.error1[0];
				
				str.derivativo= str.error1[0]-str.error1[5];
				//str.error1=str.pisod_1+str.pisod_2;
				str.integral1+=str.error1[0]*10;
//				if((str.error1>0 && str.errorant1<0) || (str.error1>0 && str.errorant1<0))
//				{
//					str.integral1=0;
//				}
				if(str.integral1>8000)
					str.integral1=8000;
				if(str.integral1<-8000)
					str.integral1=-8000;
					str.control_1=(str.error1[0]*str.proporcional1)+(str.derivativo*str.cte_derivativa1)+(str.integral1/50);
					str.control_11= (int)str.control_1;
					if(str.control_11<0)
					{
							str.control_mi=str.avance_izq_str7+str.control_11;
							str.control_md=str.avance_der_str7;
					}
					else
					{
							str.control_md=str.avance_der_str7-str.control_11;
							str.control_mi=str.avance_izq_str7;
					}
				osDelay(1);
			}
			str.control_mi=-str.vel_giro_str7;
			str.control_md=str.vel_giro_str7;
			osDelay(str.duracion_giro_str7);

}
void estrategia_8(void)
{
	str.timeout_str=str.t_str8;//750;
			
			while(str.a_ubicacion!=200 && str.timeout_str!=0)
			{
				
				str.timeout_str--;
				str.error1[0]=str.pisoi_1+str.pisoi_2;
				str.error1[9]=str.error1[8];
				str.error1[8]=str.error1[7];
				str.error1[7]=str.error1[6];
				str.error1[6]=str.error1[5];
				str.error1[5]=str.error1[4];
				str.error1[4]=str.error1[3];
				str.error1[3]=str.error1[2];
				str.error1[2]=str.error1[1];
				str.error1[1]=str.error1[0];
				
				str.derivativo= str.error1[0]-str.error1[5];
				//str.error1=str.pisod_1+str.pisod_2;
				str.integral1+=str.error1[0]*10;
//				if((str.error1>0 && str.errorant1<0) || (str.error1>0 && str.errorant1<0))
//				{
//					str.integral1=0;
//				}
				if(str.integral1>8000)
					str.integral1=8000;
				if(str.integral1<-8000)
					str.integral1=-8000;
					str.control_1=(str.error1[0]*str.proporcional2)+(str.derivativo*str.cte_derivativa2)+(str.integral1/50);
					str.control_11= (int)str.control_1;
					if(str.control_11<0)
					{
							str.control_mi=str.avance_izq_str8-str.control_11;
							str.control_md=str.avance_der_str8;
					}
					else
					{
							str.control_md=str.avance_der_str8+str.control_11;
							str.control_mi=str.avance_izq_str8;
					}
					osDelay(1);
			}
		
			str.control_mi=str.vel_giro_str8;
			str.control_md=-str.vel_giro_str8;
			osDelay(str.duracion_giro_str8);
			
}
void estrategia_9(void)
{
	
			str.control_mi=-str.vel_giro_str9;
			str.control_md=str.vel_giro_str9;
			osDelay(str.t_str9);//83);
			str.control_mi=0;
			str.control_md=0;
			
}