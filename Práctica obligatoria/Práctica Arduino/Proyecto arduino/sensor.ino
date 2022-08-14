/* Práctica de Arduino desarrollada por: Juan José López Gómez y Álvaro García Sánchez */

/* 
 *  sensor.ino
 *  Archivo en el que se incluyen la función que va a servir para el reconocimiento del movimiento
*/


int recognise_movement(){

    // Se lee el valor con la función digitalRead(pin) desde el pin designado como entrada en el archivo main.ino
    value = digitalRead(sensorPin);
    if (value == HIGH){ // Si el valor leido es HIGH (movimiento detectado) entra por esta rama
        if (state == LOW){ // Si el estado anterior recogido es LOW (movimiento no detectado) significa que hay movimiento nuevo 
            state = HIGH; // Se cambia el estado para la siguiente iteración a alto
            digitalWrite(greenLedPin,LOW); // Se apaga el LED verde (estado de reposo)
            digitalWrite(redLedPin,HIGH); // Se enciende el LED rojo (estado de "alerta")
            return 2;
        }
        return 0;
    }
    else if (value == LOW){ // Si el valor leido es LOW (movimiento no detectado) entra por esta rama
        if (state == HIGH){ // Si el valor leido es HIGH (movimiento detectado) entra por esta rama
            state = LOW; // Si el estado anterior recogido es HIGH (movimiento no detectado) significa que el movimiento ha parado
            digitalWrite(greenLedPin,HIGH); // Se enciende el LED verde (estado de reposo)
            digitalWrite(redLedPin,LOW); // Se apaga el LED rojo (estado de "alerta")
            return 1;
        }
        return 0; // Retorna 0 si el valor del estado anterior es el mismo en dos iteraciones seguidas
    }
}
