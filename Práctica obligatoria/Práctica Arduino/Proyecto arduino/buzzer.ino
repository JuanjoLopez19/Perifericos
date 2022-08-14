/* Práctica de Arduino desarrollada por: Juan José López Gómez y Álvaro García Sánchez */

/* 
 *  Buzzer.ino
 *  Archivo en el que se incluyen la función que hace funcionar el buzzer 
 */


void play_sound(){
  
  // Bucle for que recorre el vector con la melodia y la duración de cada nota de la misma
  for (int thisNote = 0; thisNote < 8; thisNote++) {
      // Se calcula la duración de la nota para que pueda ser utilizado por el buzzer
      int noteDuration = 1000 / noteDurations[thisNote];

      // Función básica de arduino que genera una onda cuadrada a una determinada frecuencia por un tiempo específicado 
      // tone(pin,frecuencia,duración)
      tone(buzzerPin, melody[thisNote], noteDuration);

      // Se calcula una pausa para no solaparse las notas 
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // Función básica de arduino que para la generación de la onda cuadrada que genera la función tone()
      // noTone(pin)
      noTone(buzzerPin);
  }
}
