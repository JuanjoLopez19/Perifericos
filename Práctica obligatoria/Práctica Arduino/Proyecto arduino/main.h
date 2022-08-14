/* Práctica de Arduino desarrollada por: Juan José López Gómez y Álvaro García Sánchez */

/* 
 *  main.h
 *  Archivo de cabecera en el que se van a definir las variables a usar en el proyecto
*/


#include "pitches.h"

/*****Constantes*****/
const int sensorPin = 2; // Pin asociado al sensor PIR
const int greenLedPin = 6; // Pin asociado al LED verde
const int redLedPin = 5; // Pin asociado al LED rojo
const int blueLedPin = 4; // Pin asociado al LED azul
const int buzzerPin = 8; // Pin asociado al buzzer

const int melody[] = { // Vector en el que están almacenadas las notas de la melodía que va a entonar el zumbador
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

const int noteDurations[] = { // Vector en el que están almacenadas la duración de cada nota de la melodía
  4, 8, 8, 4, 4, 4, 4, 4};

/*****Variables*****/
int value = 0;
int state = 0;
int result = 0;
