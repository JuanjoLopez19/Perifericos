/* Práctica de Arduino desarrollada por: Juan José López Gómez y Álvaro García Sánchez */

/* 
 *  message.ino
 *  Archivo en el que se incluyen las funciones que van a servir para recibir y enviar datos por el puerto serie
*/


void send_alert(int option){
    if (option == 2 ){ // Si se ha detectado movimiento se entra por esta rama
        digitalWrite(blueLedPin, HIGH); // Se enciende el LED azul (estado de envío/recibo)
        Serial.flush(); // Se limpia el puerto serie para que no haya datos que puedan intervenir en la ejecución del programa
        Serial.println("Movement detected"); // Se envía por el puerto serie hacia el script el mensaje 
    }
    else if (option == 1){ // Si no se ha detectado movimiento se entra por esta rama
        digitalWrite(blueLedPin, HIGH); // Se enciende el LED azul (estado de envío/recibo)
        Serial.flush(); // Se limpia el puerto serie para que no haya datos que puedan intervenir en la ejecución del programa
        Serial.println("Movement stopped"); // Se envía por el puerto serie hacia el script el mensaje 
    }
    delay(2000);
}


void wait_response(){

    Serial.flush(); // Se limpia el puerto serie para que no haya datos que puedan intervenir en la ejecución del programa
    while(!Serial.available()){ // Bucle while que itera mientras no haya ningún dato en el puerto serie (el script todavía no ha envíado la respuesta)
        // Ciclo parpadeante del LED azul
        digitalWrite(blueLedPin, LOW);
        delay(1000);
        digitalWrite(blueLedPin, HIGH);
        delay(1000);
    }
    // Se apaga el LED azul ya que el mensaje ha sido recibido correctamente
    digitalWrite(blueLedPin, LOW);
}
