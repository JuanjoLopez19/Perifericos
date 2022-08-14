/* Progama de arduino con el que se va a controlar la intensidad de un LED conectado a un detector Luz/oscuridad*/

/*Definición de variables a utilizar en el sketch*/

int ledPin = 9; // LED conectado al pin digital 9
int analogPin = 0; // detect conectado al pin analógico 0
int val = 0; // variable donde se guarda el valor

void setup() {
 pinMode(ledPin, OUTPUT); // asignar como pin de salida
}

void loop() {
 val = analogRead(analogPin); // leer desde el pin 0
 
 // Como los valores que recoge el detector son de entre 0-1023 se tiene que hacer una correspondecia con los valores que puede tener el LED
 
 val=map(val, 0, 1023, 0, 255); // Con la función map se adecuan entre los rangos
 val=constrain(val, 0, 255); // Con constrain se asegura que aunque map devuelva un valor fuera del rango se convierta en uno dentro de el 
 
 analogWrite(ledPin, val); // valor del analogWrite desde 0 a 255
}
