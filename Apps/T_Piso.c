#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "T_Piso.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void TPiso (void const *argument);                             // thread function
osThreadId tid_TPiso;                                          // thread id
osThreadDef (TPiso, osPriorityNormal, 1, 0);                   // thread object

int Init_TPiso (void) {

  tid_TPiso = osThreadCreate (osThread(TPiso), NULL);
  if (!tid_TPiso) return(-1);
  
  return(0);
}

void TPiso (void const *argument) {
	int cnt;
	int l1,l2,r1,r2;
	
	str.cal_spi1 = 0;
	str.cal_spi2 = 0;
  str.cal_spd1 = 0;
	str.cal_spd2 = 0;
	
	for(int i = 0; i<10; i++)
	{
		pinMode(FS_L1,OUTPUT,PUERTO_FS_L1);
		pinMode(FS_L2,OUTPUT,PUERTO_FS_L2);
		pinMode(FS_R1,OUTPUT,PUERTO_FS_R1);
		pinMode(FS_R2,OUTPUT,PUERTO_FS_R2);
				
	  HAL_GPIO_WritePin(PUERTO_FS_L1,FS_L1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_L2,FS_L2,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_R1,FS_R1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_R2,FS_R2,GPIO_PIN_SET);

	  //osDelay(1);
		
		pinMode(FS_L1,INPUT,PUERTO_FS_L1);
		pinMode(FS_L2,INPUT,PUERTO_FS_L2);
		pinMode(FS_R1,INPUT,PUERTO_FS_R1);
		pinMode(FS_R2,INPUT,PUERTO_FS_R2);
		
	 cnt = 0;
	 l1 = CUENTA_MAX;
	 l2 = CUENTA_MAX;
	 r1 = CUENTA_MAX;
	 r2 = CUENTA_MAX;
		
		
   do{
     cnt ++;
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_L1,FS_L1) == GPIO_PIN_RESET &&  l1 == CUENTA_MAX)
		 {
		    l1 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_L2,FS_L2) == GPIO_PIN_RESET &&  l2 == CUENTA_MAX)
		 {
		    l2 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_R1,FS_R1) == GPIO_PIN_RESET &&  r1 == CUENTA_MAX)
		 {
		    r1 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_R2,FS_R2) == GPIO_PIN_RESET &&  r2 == CUENTA_MAX)
		 {
		    r2 = cnt;
		 }
		 
   }while( cnt < CUENTA_MAX);
     
	 //SAVE DATA
	 str.cal_spi1 +=  l1;// - str.cal_spi1;
	 str.cal_spi2 +=  l2;// - str.cal_spi2;
	 str.cal_spd1 +=  r1;// - str.cal_spd1;
	 str.cal_spd2 +=  r2;// - str.cal_spd2;
	}
	
		str.cal_spi1 = str.cal_spi1/10;
	  str.cal_spi2 = str.cal_spi2/10;
    str.cal_spd1 = str.cal_spd1/10;
	  str.cal_spd2 = str.cal_spd2/10;
	
	
	
  while (1)
	{
		pinMode(FS_L1,OUTPUT,PUERTO_FS_L1);
		pinMode(FS_L2,OUTPUT,PUERTO_FS_L2);
		pinMode(FS_R1,OUTPUT,PUERTO_FS_R1);
		pinMode(FS_R2,OUTPUT,PUERTO_FS_R2);
				
	  HAL_GPIO_WritePin(PUERTO_FS_L1,FS_L1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_L2,FS_L2,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_R1,FS_R1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUERTO_FS_R2,FS_R2,GPIO_PIN_SET);

	  //osDelay(1);
		
		pinMode(FS_L1,INPUT,PUERTO_FS_L1);
		pinMode(FS_L2,INPUT,PUERTO_FS_L2);
		pinMode(FS_R1,INPUT,PUERTO_FS_R1);
		pinMode(FS_R2,INPUT,PUERTO_FS_R2);
		
	 cnt = 0;
	 l1 = CUENTA_MAX;
	 l2 = CUENTA_MAX;
	 r1 = CUENTA_MAX;
	 r2 = CUENTA_MAX;
		
		
   do{
     cnt ++;
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_L1,FS_L1) == GPIO_PIN_RESET &&  l1 == CUENTA_MAX)
		 {
		    l1 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_L2,FS_L2) == GPIO_PIN_RESET &&  l2 == CUENTA_MAX)
		 {
		    l2 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_R1,FS_R1) == GPIO_PIN_RESET &&  r1 == CUENTA_MAX)
		 {
		    r1 = cnt;
		 }
		 
		 if(HAL_GPIO_ReadPin(PUERTO_FS_R2,FS_R2) == GPIO_PIN_RESET &&  r2 == CUENTA_MAX)
		 {
		    r2 = cnt;
		 }
		 
   }while( cnt < CUENTA_MAX);
     
	 //SAVE DATA
	 str.sp_i1 =  str.cal_spi1 - l1;
	 str.sp_i2 =  str.cal_spi2 - l2;
	 str.sp_d1 =  str.cal_spi2 - r1;
	 str.sp_d2 =  str.cal_spd2 - r2;

	 
		if(abs(str.sp_d2)>120)
		{
			str.pisod_1=-1;
		}
		else
		{
			str.pisod_1=1;
		}
		
		if(abs(str.sp_d2)>120)
		{
			str.pisod_2=-1;
		}
		else
		{
			str.pisod_2=1;
		}
		

		
		////////////////////////////////////////////////
		if(abs(str.sp_i2)>150)//300
		{
			str.pisoi_1=-1;
		}
		else
		{
			str.pisoi_1=1;
		}
		
		if(abs(str.sp_i2)>150)//300
		{
			str.pisoi_2=-1;
		}
		else
		{
			str.pisoi_2=1;
		}
		
		
    osDelay(2);
  }
}
