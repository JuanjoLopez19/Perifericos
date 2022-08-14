/* Programa de arduino por el cual se va a realizar el control de la rotación de un servo mediante una fotoresistencia*/

// Importación de la libreria para utilizar el servo

#include <Servo.h>

// Parte de definicion de variable 
Servo myServo; // Variable del servo a utilizar
int digitalPin = 9; // Pin al que está conectado el servo
int analogPin = 0; // Pin analógico desde el que se va a leer la fotoresistencia
int aux = 0; // Variable auxiliar

void setup()
{
  myServo.attach(digitalPin); // Establecer el pin por el que va a estar conectado el servo
}

void loop()
{
  aux = analogRead(analogPin); // Lectura del valor de la fotoresistencia
  
  aux = map(aux, 0, 1023, 0, 180);  // Mapear los valores de la fotoresistencia a los valores posibles que tiene el servo 
  aux = constrain(aux, 0, 180); // En caso de que map devuelva valores fuera del rango se establecen en ellos
  
  myServo.write(aux); // Finalmente se escribe en el servo el valor obtenido correctamente
}