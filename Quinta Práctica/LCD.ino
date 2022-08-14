
/* Programa de arduino con el que mediante un teclado matricial se muestra por una pantalla LCD la tecla pulsada*/

// Importacion de las variables
#include <Keypad.h>
#include <LiquidCrystal.h>


// Zona de declaracion de las variables

const byte ROWS = 4; // Constante para el numero de filas
const byte COLS = 4; // Constante para el numero de columnas

// Matriz de 4x4 con la que se va a mapear el teclado real para trabajar luego la salida
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte rowPins[ROWS] = {0,1,2,3}; // Vector con el que se va a representar los pines digitales de la placa a los que van a estar conectadas las filas del teclado
byte colPins[COLS] = {4,5,6,7}; // Vector con el que se va a representar los pines digitales de la placa a los que van a estar conectadas las columnas del teclado

// Iniciacion del objeto que manejara el LCD, mediante el numero del pin digital de la placa a la que estara conectado
LiquidCrystal lc(9, 8, 10, 11, 12, 13); // PIN de RS del led, pin enable, y pines ultimos 

// Constructor del objeto del teclado, con el mapeo de la teclas y los pines correspondientes
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  lc.begin(16,2); // Inicacion del LCD, con su numero de columnas y el numero de filas del display
}

void loop()
{
  char key = keypad.getKey(); // Se recoge la entrada del teclado
 
  if (key != NO_KEY){ // Si es valida
    lc.clear(); // Se limpia la pantalla del LCD para una mayor claridad
    lc.print(key); // Se imprime en ella la tecla pulsada
  }
}
