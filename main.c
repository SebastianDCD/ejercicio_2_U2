/* Intermitencia LED1
 * Sebastian De la Cruz Delgado  18060707
 * ITCH
 * April / 2023
 * */
//Incluimos la libreria para interactuar con el MSP...
#include "msp.h"

//Ciclo principal
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1->DIR |= 0x01;    //Configuramos el pin 1.0, como salida
	P1->OUT |= 0x01;    //El Pin 1.0 en estado alto

	while(1)    //Bucle infinito de trabajo
	{
	    P1->OUT ^= 0x01;    //Por medio de un XOR invertimos el valor del Pin 1.0
	    _delay_cycles(500000);  //Delay por aproximado a 500 mS.
	}
}
