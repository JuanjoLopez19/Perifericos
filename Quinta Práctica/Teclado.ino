/* Código arduino en el que se implementa el uso de un teclado matricial*/
#include <Keypad.h>

const byte ROWS = 4; // Constante para el numero de filas
const byte COLS = 4; // Constante para el numero de columnas

// Matriz de 4x4 con la que se va a mapear el teclado real para trabajar luego la salida
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {2,3,4,5}; /// Vector con el que se va a representar los pines digitales de la placa a los que van a estar conectadas las filas del teclado
byte colPins[COLS] = {6,7,8,9}; // Vector con el que se va a representar los pines digitales de la placa a los que van a estar conectadas las columnas del teclado

// Constructor del objeto del teclado, con el mapeo de la teclas y los pines correspondientes
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
 Serial.begin(9600); // Iniciacion del puerto serie para la muestra por pantalla con 9600 Baudios
}

void loop(){

  char key = keypad.getKey(); // Se recoge la entrada del teclado

  if (key != NO_KEY){ // Si es correcta
    Serial.println(key); // Se muestra por la pantalla del monitor serie
  }
}
