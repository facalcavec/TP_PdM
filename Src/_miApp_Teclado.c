/*
 * miApp_Teclado.c
 *
 *  Created on: Aug 19, 2020
 *      Author: felipe
 */

#include <_main.h>
#include "_miApp_Teclado.h"


/* función de inicialización y error */
void fsmButtonInitError( struct structTecla *tec1 ){
    tec1->estadoTransitorio = STATE_BUTTON_UP;
    tec1->estadoFinal = EVENT_RELEASED;
    tec1->contFalling = 0;
    tec1->contRising = 0;
    tec1->flagFalling = false;
    tec1->flagRising = false;
}


// FSM Update Sate Function
void fsmButtonUpdate( uint16_t tecla, struct structTecla *tec){

   switch( tec->estadoTransitorio ){

      case STATE_BUTTON_UP:
         /* CHECK TRANSITION CONDITIONS */
         if( !HAL_GPIO_ReadPin(GPIOA, tecla) ){
            tec->estadoTransitorio = STATE_BUTTON_FALLING;
         }
      break;

      case STATE_BUTTON_DOWN:
         /* CHECK TRANSITION CONDITIONS */
         if( HAL_GPIO_ReadPin(GPIOA, tecla) ){
            tec->estadoTransitorio = STATE_BUTTON_RISING;
         }
      break;

      case STATE_BUTTON_FALLING:
         /* ENTRY */
         if( tec->flagFalling == false ){
            tec->flagFalling = true;
         }
         /* CHECK TRANSITION CONDITIONS */
         if( tec->contFalling >= 40 ){
            if( HAL_GPIO_ReadPin(GPIOA, tecla) ){
               tec->estadoTransitorio = STATE_BUTTON_DOWN;
               tec->estadoFinal = EVENT_PRESSED;
            } else{
               tec->estadoTransitorio = STATE_BUTTON_UP;
            }
            tec->contFalling = 0;
         }
         tec->contFalling++;
         /* LEAVE */
         if( tec->estadoTransitorio != STATE_BUTTON_FALLING ){
            tec->flagFalling = false;
         }
      break;

      case STATE_BUTTON_RISING:
         /* ENTRY */
         if( tec->flagRising == false ){
            tec->flagRising = true;
         }
         /* CHECK TRANSITION CONDITIONS */

         if( tec->contRising >= 40 ){
            if( HAL_GPIO_ReadPin(GPIOA, tecla) ){
               tec->estadoTransitorio = STATE_BUTTON_UP;
               tec->estadoFinal = EVENT_RELEASED;                             //buttonReleased();
            } else{
               tec->estadoTransitorio = STATE_BUTTON_DOWN;
            }
            tec->contRising = 0;
         }
         tec->contRising++;

         /* LEAVE */
         if( tec->estadoTransitorio != STATE_BUTTON_RISING ){
            tec->flagRising = false;
         }
      break;

      default:
         fsmButtonInitError( &tec );
      break;
   }
}











