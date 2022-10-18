#include "Funciones_pantalla.h"
extern Variables_flash v_flash;

void pantalla_RC(void)
{
	SSD1306_Fill(1); //black
	SSD1306_GotoXY(40,30);
	SSD1306_Puts("RC MODE",&Font_7x10,1);
	SSD1306_GotoXY(40,50);
	SSD1306_Puts("Bluetooth",&Font_7x10,1);
	SSD1306_UpdateScreen();
	osDelay(500);
}

void pantalla_APP(void)
{
	SSD1306_Fill(1); //black
	SSD1306_GotoXY(40,30);
	SSD1306_Puts("APP MODE",&Font_7x10,1);
	if(v_flash.PULL_SELECT==0)
	{
		SSD1306_GotoXY(40,50);
		SSD1306_Puts("Pull UP",&Font_7x10,1);
		
	}
	else if(v_flash.PULL_SELECT==1)
	{
		SSD1306_GotoXY(40,50);
		SSD1306_Puts("No PULL",&Font_7x10,1);
		
	}
	SSD1306_UpdateScreen();
	
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
	if(str.down_but==1)
	{
		//str.cnt_pull=10;
		v_flash.PULL_SELECT = 1;
	}
	if(str.right_but==1)
	{
		//str.cnt_pull=20;
		v_flash.PULL_SELECT =0;
	}
	
}

void pantalla_inicial(void)
{
			osDelay(200);
			SSD1306_Init();
			SSD1306_Fill(1); //black
			SSD1306_GotoXY(45,1);
			SSD1306_Puts("LION",&Font_7x10,0);
			SSD1306_GotoXY(53,20);
			SSD1306_Puts("V1.2",&Font_7x10,0);

			SSD1306_DrawFilledRectangle(50,40,35,20,0);
			SSD1306_DrawFilledRectangle(1,0,29,64,0);
			SSD1306_DrawFilledRectangle(107,0,30,64,0);
			for(int e=85;e<=105;e++)
			{
				SSD1306_DrawLine(85,40,e,60,0);
			}

			SSD1306_DrawCircle(43,50,11,0);

			SSD1306_DrawFilledCircle(43,50,2,0);
			SSD1306_UpdateScreen();
			osDelay(1000);
//			SSD1306_Fill(1); //black
//			SSD1306_UpdateScreen();
}
void verif_sensores(void)
{
	switch(str.sens_num)
	{
		case 1:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(76,35,6,1); //selector 1
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 2:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(75,20,7,1); //selector 2
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 3:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(59,21,6,1); //selector 3
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 4:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(42,20,7,1); //selector 4
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 5:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(41,35,6,1); //selector 5
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 6:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(76,10,4,1); //selector 6
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 7:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(68,10,4,1); //selector 7
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 8:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(49,10,4,1); //selector 8
			check_sensor();
			SSD1306_UpdateScreen();
		break;
		case 9:
			SSD1306_Fill(0); //black
			SSD1306_DrawRectangle(37,15,43,32,1);
			SSD1306_DrawRectangle(37,5,43,10,1);
			SSD1306_DrawCircle(42,54,6,1);
			SSD1306_DrawRectangle(48,48,21,12,1);
			SSD1306_DrawCircle(75,54,6,1);
			SSD1306_DrawCircle(41,10,4,1); //selector 9
			check_sensor();
			SSD1306_UpdateScreen();
		break;
	}
}

void estrategias_pantalla(void)
{
	SSD1306_Fill(0); //black
		SSD1306_DrawCircle(64,32,31,1);
		SSD1306_DrawCircle(64,32,32,1);
		SSD1306_DrawCircle(64,32,33,1);
	switch(str.num_estrategia)
		{
			case 1:
			
		//Estrategia esperar oponente 1
		
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,65,35,1);
		SSD1306_DrawFilledTriangle(63,35,67,35,65,33,1);
		
		break;
			
		case 2:
		//Estrategia atacar de frente 2
		
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,65,25,1);
		SSD1306_DrawFilledTriangle(63,25,67,25,65,23,1);

		break;
		
		case 3:
		//Estrategia diagonal derecha->linea->giro y ataque  3
		
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,93,20,1);
		SSD1306_DrawLine(93,20,75,20,1);
		SSD1306_DrawFilledTriangle(75,18,75,22,71,20,1);

	break;
	
		case 4:
		//Estrategia diagonal izquierda->linea->giro y ataque 4 
		
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,37,20,1);
		SSD1306_DrawLine(37,20,55,20,1);
		SSD1306_DrawFilledTriangle(55,18,55,22,59,20,1);
		break;
		
		case 5:
	//Estrategia diagonal izquierda  5
		
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,50,25,1);
		SSD1306_DrawFilledTriangle(48,26,51,22,45,19,1);

		break;
		
		case 6: 
	//Estrategia diagonal derecha 6
	
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		SSD1306_DrawLine(65,42,80,25,1);
		SSD1306_DrawFilledTriangle(82,26,78,22,84,19,1);
		
		break;
		
		case 7:
	//Borde de pista por derecha 7

		SSD1306_DrawCircle(64,32,23,1);
		SSD1306_DrawFilledTriangle(84,32,90,32,87,27,1);
		SSD1306_DrawFilledTriangle(64,6,64,12,59,9,1);
		SSD1306_DrawFilledTriangle(38,28,44,28,41,33,1);
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		break;
		
		case 8:
			//Borde de pista por izquierda 8

		SSD1306_DrawCircle(64,32,23,1);
		SSD1306_DrawFilledTriangle(84,27,90,27,87,32,1);
		SSD1306_DrawFilledTriangle(59,6,59,12,64,9,1);
		SSD1306_DrawFilledTriangle(38,33,44,33,41,28,1);
		SSD1306_DrawRectangle(58,44,14,12,1);
		SSD1306_DrawRectangle(58,44,14,3,1);
		SSD1306_DrawCircle(60,59,2,1);
		SSD1306_DrawRectangle(62,57,6,4,1);
		SSD1306_DrawCircle(70,59,2,1);
		
		break;
		case 9:
			//GIRO INMEDIATO IZQUIERDA

		SSD1306_DrawRectangle(58,36,12,14,1); // MINI
		SSD1306_DrawRectangle(70,36,3,14,1); // MINI
		SSD1306_DrawCircle(56,38,2,1); // MINI LLANTA
		SSD1306_DrawCircle(56,48,2,1); // MINI LLANTA
		SSD1306_DrawRectangle(54,40,4,6,1); // MINI BASE MOTORES
		SSD1306_DrawLine(65,36,65,25,1); //FLECHA
		SSD1306_DrawFilledTriangle(63,25,67,25,65,22,1); //FLECHA
			
		break;
	}
		
	SSD1306_UpdateScreen();
}

void pantalla4(void)
{
		SSD1306_Fill(0); //black
		SSD1306_DrawFilledRectangle(50,40,35,20,0);
		SSD1306_GotoXY(20,20);
		SSD1306_Puts("Remote",&Font_7x10,1);
		SSD1306_GotoXY(1,50);
		SSD1306_Puts("Press remote start",&Font_7x10,1);
		SSD1306_UpdateScreen();
}
void pantalla5(void)
{
		SSD1306_Fill(0); //black
		SSD1306_GotoXY(20,20);
		SSD1306_Puts("Time",&Font_7x10,1);
		SSD1306_GotoXY(5,50);
		SSD1306_Puts("Press ok to start",&Font_7x10,1);
		SSD1306_UpdateScreen();
}
void pantalla6(void)
{
		SSD1306_Fill(0); //black
		SSD1306_GotoXY(50,20);
		if(str.timt_start==1)
			SSD1306_Puts("1",&Font_7x10,1);
		if(str.timt_start==2)
			SSD1306_Puts("2",&Font_7x10,1);
		if(str.timt_start==3)
			SSD1306_Puts("3",&Font_7x10,1);
		if(str.timt_start==4)
			SSD1306_Puts("4",&Font_7x10,1);
		if(str.timt_start==5)
			SSD1306_Puts("5",&Font_7x10,1);
		SSD1306_UpdateScreen();
}

void fight(void)
{
	SSD1306_Fill(0); //black
	SSD1306_GotoXY(20,20);
	SSD1306_Puts("Fight",&Font_7x10,1);
	SSD1306_UpdateScreen();
}
