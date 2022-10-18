#ifndef LION1_H
#define LION1_H

#include <stdint.h>

#define LION_MINISUMO

////DEFINICION BOTONES USUARIO
#define UP_Pin GPIO_PIN_4
#define UP_GPIO_Port GPIOA


#define DOWN_Pin GPIO_PIN_15 
#define PUERTO_DOWN GPIOA

#define RIGHT_Pin GPIO_PIN_1
#define PUERTO_OK GPIOB


#define LEFT_Pin GPIO_PIN_7
#define PUERTO_BACK GPIOB

//DEFINICION LED TEST
#define DLED GPIO_PIN_0
#define PUERTO_DLED GPIOB

//DEFINICION MODULO ARRANQUE 
#define IN_START GPIO_PIN_11
#define PUERTO_IN_START GPIOA


////DEFINICION SENSORES
#define OM_LEFT GPIO_PIN_5
#define PUERTO_OM_RIGHT GPIOA

#define SH_CENTER GPIO_PIN_6 //"SHARP CENTRO"
#define PUERTO_SH_CENTER GPIOA

#define OM_RIGHT GPIO_PIN_7 // "OMRON" IZQUIERDO
#define PUERTO_OM_LEFT GPIOA

#define SH_RIGHT GPIO_PIN_8 //SHARP DERECHO
#define PUERTO_SH_RIGHT GPIOA

#define SH_LEFT GPIO_PIN_6
#define PUERTO_SH_LEFT GPIOB //SHARP LEFT

#define FS_R1 GPIO_PIN_9  //PISO DERECHO 1
#define PUERTO_FS_R1 GPIOA

#define FS_R2 GPIO_PIN_10
#define PUERTO_FS_R2 GPIOA //PISO DERECHO 2

#define FS_L2 GPIO_PIN_4
#define PUERTO_FS_L2 GPIOB //PISO IZQUIERDO 2

#define FS_L1 GPIO_PIN_5
#define PUERTO_FS_L1 GPIOB //PISO IZQUIERDO 1

#define OUTPUT GPIO_MODE_OUTPUT_PP
#define INPUT GPIO_MODE_INPUT

	
typedef struct
{
	//constantes para busqueda de oponente
	float cte_deriv_b;
	float cte_prop_b;
	int frecuencia;	
	//Velocidad maxima durante movimiento
	int vel_max;
	//Velocidad minima durante movimiento
	int vel_min;
	//Velocidad no oponente (durante movimiento)
	int vel_no_op;
	//Variable duracion oscilacion no oponente
	int osc_no_op;
	
	//estrategia 1
		//tiempo estrategia 1
		uint16_t t_str1;
		//variable incremental de confirmacion de oponente
		uint16_t conf_op_lim; //actualmente esta en 1000
		uint16_t vel_mot_str1; //velocidad motores durante estrategia 1 actualmente esta en 420
		uint16_t limite_entre_paso_str1;
		uint16_t limite_entre_paso_off_str1;
	
	//estrategia 2
	
		//tiempo estrategia 2
		uint16_t t_str2;
		uint16_t vel_der_str2; //actualmente 990
		uint16_t vel_izq_str2; //actualmente 990
		uint16_t conf_op_lim_str2; //actualmente 1000
		
	//estrategia 3
		//paso 1 
		uint16_t t_str3; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 370
		uint16_t vel_giro1_str3; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		uint16_t duracion_giro1_str3; //duracion giro 1 estrategia 3 100
		uint16_t vel_der_gir2_str3;  //velocidad derecha durante curva (giro 2 ) estrategia 3 actualmente 970
		uint16_t vel_izq_gir2_str3;  //velocidad izquierda durante curva (giro2) estrategia 3 actualmente 660
		
		//paso 2
		uint16_t vel_gir3_str3; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 890
		uint16_t duracion_giro3_str3; //duracion giro 3 estrategia 3	actualmente 110
		
		//paso3
		uint16_t vel_ataque_str3; //duracion ataque frontal despues de giro 3 // actualmente 800
		uint16_t duracion_ataque_str3; //duracion de ataque frontal actualmente 150 


	//estrategia 4
		//paso 1 
		uint16_t t_str4; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 350
		uint16_t vel_giro1_str4; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		uint16_t duracion_giro1_str4; //duracion giro 1 estrategia 4 100
		uint16_t vel_der_gir2_str4;  //velocidad derecha durante curva (giro 2 ) estrategia 4 actualmente 660
		uint16_t vel_izq_gir2_str4;  //velocidad izquierda durante curva (giro2) estrategia 4 actualmente 970
		
		//paso 2
		uint16_t vel_gir3_str4; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 910
		uint16_t duracion_giro3_str4; //duracion giro 3 estrategia 4	actualmente 150
		
		//paso3
		uint16_t vel_ataque_str4; //duracion ataque frontal despues de giro 3 // actualmente  800
		uint16_t duracion_ataque_str4; //duracion de ataque frontal actualmente 150

	//estrategia 5
	
		//tiempo estrategia 5
		uint16_t t_str5; //400
		uint16_t vel_der_str5; //actualmente 620
		uint16_t vel_izq_str5; //actualmente 620
		uint16_t conf_op_lim_str5; //actualmente 100
		
		
	//estrategia 6
	
		//tiempo estrategia 6
		uint16_t t_str6; //400
		uint16_t vel_der_str6; //actualmente 620
		uint16_t vel_izq_str6; //actualmente 620
		uint16_t conf_op_lim_str6; //actualmente 100
		
	//estrategia 7	
		//tiempo estrategia 7
		uint16_t t_str7; //750
		//constantes para estrategias de borde de pista (estrategia 7)
		float proporcional1;
		float cte_integral1;
		float cte_derivativa1;
		uint16_t avance_der_str7; //700
		uint16_t avance_izq_str7; //700
		uint16_t vel_giro_str7; //600
		uint16_t duracion_giro_str7; //120
		
	//estrategia 8	
		//tiempo estrategia 8
		uint16_t t_str8; //750
		//constantes para estrategias de borde de pista (estrategia 8)
		float proporcional2;
		float cte_integral2;
		float cte_derivativa2;
		uint16_t avance_der_str8; //400
		uint16_t avance_izq_str8; //400
		uint16_t vel_giro_str8; //600
		uint16_t duracion_giro_str8; //220
	
	
	//estrategia 9
		//tiempo estrategia 9
		uint16_t t_str9; //83
		uint16_t vel_giro_str9; //999

		uint16_t PULL_SELECT;
		
} Variables_flash;


typedef struct 
{
	//flash mode
		uint8_t flash_mode;
		uint8_t buffer_rx[60];
		uint8_t flag_rx;
		uint8_t buffer_tx[100];
//Sensores
		int cal_spd1,cal_spd2,cal_spi1,cal_spi2;
		int sp_d1,sp_d2,sp_i1,sp_i2;
		int SensorDistaciaCentral;
		int val_adc;	
	
	//Ataque

		int a_ubicacion_anterior;
		int a_ubicacion;
		int control_md, control_mi;

		//estrategia

		int timeout_str;
		int paso;
		int tiempo;
		int estrategia;
		int confirma_frente; // variable para confirmar que el enemigo esta al frente y no se salga de estrategia
		//seguidor linea
		int pisod_1;
		int pisod_2;
		int pisoi_1;
		int pisoi_2;
		int error1[10];
		//int errorant1;
		int derivativo;
		int integral1;
		
		float control_1;
		int control_11;
		
		//int error2;
		//int errorant2;
		//int integral2;
		

	
	int up_but;
	int down_but;
	int left_but;
	int right_but;
	int pantalla;


	//pantalla 2 comprobar sensores
	//estado 0 == sin presencia
	//estado 1 == deshabilitados
	//estado 2 == presencia
	int sens_num;
	int sens_1;
	int sens_2;
	int sens_3;
	int sens_4;
	int sens_5;
	int sens_6;
	int sens_7;
	int sens_8;
	int sens_9;
	
	
		//Pantalla 3 estrategias
		uint8_t num_estrategia;
		
		//int m_derecha,m_izquierda;
		//pantalla 4 
		uint8_t start;
		uint8_t timt_start;
		
		// control busqueda - ataque
		int error_b[10];
		float derivativo_b;
		//desde flash
			//constantes para busqueda de oponente
		float cte_deriv_b;
		float cte_prop_b;
		int vel_max;
	//Velocidad minima durante movimiento
	int vel_min;
	//Velocidad no oponente (durante movimiento)
	int vel_no_op;
	//Variable duracion oscilacion no oponente
	int osc_no_op;
	int frecuencia;
	
		
		
		float integral_b;
		float control_b;
		int sens_b;
		int avance;
		float f_avance;
		int cnt_avance;
		int8_t oscilacion;
		int tim_oscilacion;
		int estr1_esp;
		int timeout_ataque_retiro;
		int confirma_izquierda;
		
		//pasos piso
		int ppaso1;
		int conf_negro1;
		int conf_negro2;
		
		
		
		//seleccion de pantalla en aplicacion
		uint16_t seleccion_str_app;
		//estrategias
		
	//estrategia 1
		//tiempo estrategia 1
		uint16_t t_str1;
		//variable incremental de confirmacion de oponente
		uint16_t conf_op_lim; //actualmente esta en 1000
		uint16_t vel_mot_str1; //velocidad motores durante estrategia 1 actualmente esta en 420
		uint16_t limite_entre_paso_str1;
		uint16_t limite_entre_paso_off_str1;
		
	//estrategia 2
		//tiempo estrategia 2
		uint16_t t_str2;
		uint16_t vel_der_str2; //actualmente 990
		uint16_t vel_izq_str2; //actualmente 990
		uint16_t conf_op_lim_str2; //actualmente 1000
		
	//estrategia 3
		//paso 1 
		uint16_t t_str3; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 370
		uint16_t vel_giro1_str3; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		uint16_t duracion_giro1_str3; //duracion giro 1 estrategia 3 100
		uint16_t vel_der_gir2_str3;  //velocidad derecha durante curva (giro 2 ) estrategia 3 actualmente 970
		uint16_t vel_izq_gir2_str3;  //velocidad izquierda durante curva (giro2) estrategia 3 actualmente 660
		
		//paso 2
		uint16_t vel_gir3_str3; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 890
		uint16_t duracion_giro3_str3; //duracion giro 3 estrategia 3	actualmente 110
		
		//paso3
		uint16_t vel_ataque_str3; //duracion ataque frontal despues de giro 3 // actualmente 800
		uint16_t duracion_ataque_str3; //duracion de ataque frontal actualmente 150 
		
	//estrategia 4
		//paso 1 
		uint16_t t_str4; //Tiempo que dura haciendo primer giro, curva en velocidad diferencial 350
		uint16_t vel_giro1_str4; //giro completo en borde de pista al inicio de estrategia, actualmente esta en 700
		uint16_t duracion_giro1_str4; //duracion giro 1 estrategia 4 100
		uint16_t vel_der_gir2_str4;  //velocidad derecha durante curva (giro 2 ) estrategia 4 actualmente 660
		uint16_t vel_izq_gir2_str4;  //velocidad izquierda durante curva (giro2) estrategia 4 actualmente 970
		
		//paso 2
		uint16_t vel_gir3_str4; // giro completo (giro 3) despues de realizar curva (giro 2), actualmente 910
		uint16_t duracion_giro3_str4; //duracion giro 3 estrategia 4	actualmente 150
		
		//paso3
		uint16_t vel_ataque_str4; //duracion ataque frontal despues de giro 3 // actualmente  800
		uint16_t duracion_ataque_str4; //duracion de ataque frontal actualmente 150
		
		
	//estrategia 5
		
		//tiempo estrategia 5
		uint16_t t_str5; //400
		uint16_t vel_der_str5; //actualmente 620
		uint16_t vel_izq_str5; //actualmente 620
		uint16_t conf_op_lim_str5; //actualmente 100
		
	//estrategia 6
	
		//tiempo estrategia 6
		uint16_t t_str6; //400
		uint16_t vel_der_str6; //actualmente 620
		uint16_t vel_izq_str6; //actualmente 620
		uint16_t conf_op_lim_str6; //actualmente 100
		
		
	//estrategia 7	
		//tiempo estrategia 7
		uint16_t t_str7; //750
		//constantes para estrategias de borde de pista (estrategia 7)
		float proporcional1;
		float cte_integral1;
		float cte_derivativa1;
		uint16_t avance_der_str7; //700
		uint16_t avance_izq_str7; //700
		uint16_t vel_giro_str7; //600
		uint16_t duracion_giro_str7; //120
		
	//estrategia 8	
		//tiempo estrategia 8
		uint16_t t_str8; //750
		//constantes para estrategias de borde de pista (estrategia 8)
		float proporcional2;
		float cte_integral2;
		float cte_derivativa2;
		uint16_t avance_der_str8; //400
		uint16_t avance_izq_str8; //400
		uint16_t vel_giro_str8; //600
		uint16_t duracion_giro_str8; //220
		
	//estrategia 9
		//tiempo estrategia 9
		uint16_t t_str9; //83
		uint16_t vel_giro_str9; //999
		
		//Variable para configurar pull up o pull down
		uint16_t PULL_SELECT;
		//uint16_t cnt_pull;
		
		uint8_t RC_MODE;
		
		int control_md_RC, control_mi_RC;
		int signo_md, signo_mi;
		
	
}Lion1_2;
#endif
