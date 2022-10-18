#ifndef FUNCIONES_PANTALLA_H
#define FUNCIONES_PANTALLA_H
#include "ssd1306.h"
#include "Lion1.h"
//#define osObjectsPublic                     // define objects in main module
//#include "osObjects.h"                      // RTOS object definitions
extern Lion1_2 str;
void pantalla_APP(void);
void pantalla_RC(void);
void pantalla_inicial(void);
void verif_sensores(void);
void estrategias_pantalla(void);
void pantalla4(void);
void pantalla5(void);
void pantalla6(void);
void fight(void);

#endif

