/* 
 *  Práctica de Arduino desarrollada por: Juan José López Gómez y Álvaro García Sánchez 
 *  La práctica consiste en el uso del Sensor de presencia PIR HC-SR501 mediante el cúal
 *  se detecta la presencia y haciendo uso del puerto serie se comunica con un script de
 *  python que permite el envío autómatico de emails para asi avisar de la presencia de 
 *  movimiento
*/


/* 
 *  main.ino 
 *  Se desarrolla la estructura básica del programa
*/


/* Inclusión del archivo de cabecera main.h en el que están definidas todas las variables que utiliza el programa */
#include "main.h" 

void setup(){
 
    //Establecimiento de los pines digitales asociados a los LEDs y al buzzer como salida mediante la función pinMode(pin,mode)
    pinMode(greenLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    //Establecimiento del pin asociado al sensor como entrada mediante la función pinMode(pin,mode)
    pinMode(sensorPin, INPUT);

    //Iniciación del puerto serie a una velocidad de 9600 Baudios
    Serial.begin(9600);

    // Una espera ocupada necesaria para la sincronización externa con el script de python mediante el valor de Serial que devuelve el estado del mismo y no sale del bucle hasta que este listo
    while(!Serial){;}

    // Encendido y apagado de los LEDs para denotar el estado inicial 
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
}


void loop(){
    // Dependiendo del valor recogido por el sensor se ejecuta una parte y otra del programa si result != 0 se ejecuta el envío si no se vuelve a ejecutar
    result = recognise_movement();
    if (result){
        // Función para envíar el mensaje por el puerto serie
        send_alert(result);
        // Función que se ejecuta mientras no se haya recibido la confirmación mediante el puerto serie
        wait_response();
        // Función que genera el sonido del zumbador
        play_sound();
    }
    // Un delay para no saturar
    delay(1500);
    
    
}
