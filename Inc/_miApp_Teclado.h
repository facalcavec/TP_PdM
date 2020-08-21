/*
 * miApp_Teclado.h
 *
 *  Created on: Aug 19, 2020
 *      Author: felipe
 */

#ifndef INC__MIAPP_TECLADO_H_
#define INC__MIAPP_TECLADO_H_

typedef enum{
            STATE_BUTTON_UP,
            STATE_BUTTON_FALLING,
            STATE_BUTTON_DOWN,
            STATE_BUTTON_RISING
} fsmButtonState_t;

typedef enum{
            EVENT_RELEASED,
            EVENT_PRESSED,
            EVENT_HOLD
} fsmEventButton_t;

struct structTecla{
			fsmButtonState_t estadoTransitorio;
			fsmEventButton_t estadoFinal;
			uint8_t contFalling;
			uint8_t contRising;
			bool flagFalling;
			bool flagRising;
};

struct structTecla teclaEnter, teclaEscape, teclaUp, teclaDown;


void fsmButtonInitError( struct structTecla * );
void fsmButtonUpdate( uint16_t, struct structTecla * );


#endif /* INC__MIAPP_TECLADO_H_ */
