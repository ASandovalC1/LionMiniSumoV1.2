#ifndef _FUNCIONES_LION_H
#define _FUNCIONES_LION_H
#include "stm32f0xx_hal.h"
#include "Estrategias.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "stdlib.h"
#include "Lion1.h"

extern Lion1_2 str;
extern Variables_flash v_flash;
extern Variables_flash Lion_flash;
extern TIM_HandleTypeDef htim2;

void pinMode(int pin, int estado,GPIO_TypeDef *port);
int Detectar_Ubicacion(void);
void mov_minisumo(void);
void Control_Motores(int mi , int md);

#endif
