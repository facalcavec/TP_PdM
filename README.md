

Plataforma embebida: STM32F103C8

Aplicación:
Se trata de una interfaz de usuario con un teclado de 4 teclas y una pantalla LCD. En el estado inicial la pantalla muestra la fecha y hora y cuando se presiona una tecla cualquiera, se pasa al menú de opciones, por el que se puede navegar y seleccionar una función determinada. Con escape se vuelve al estado inicial.
Periféricos: 
GPIO y si el tiempo me lo permite el RTC.


Definir los módulos de software (archivos) que va  implementar para cada periférico.

miApp_teclado.c y miApp_teclado.h para el antirebote e identificación del teclado.
miApp_Menu.c y miApp_Menu.h para navegar por el menú principal

Definir los prototipos de las principales funciones públicas y privadas de cada módulo definido .





