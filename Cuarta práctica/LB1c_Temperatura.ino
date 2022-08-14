
/* Progama de arduino del que se va a obtener la medición de temperatura a partir del chip TMP36*/

/*Definición de variables a utilizar en el sketch*/

int analogPin= 0; // Pin analógico utilizado para leer los valores
int val = 0; // Variable en la que se va a recoger la lectura
float voltaje = 0; // Variable en la que se almacenará el voltaje
float temp = 0; // Variable en la que se almacenará la temperatura del chip

void setup() {
   Serial.begin(9600); // Iniciación del puerto serie a una velocidad de 9600 Baudios
}

void loop() {
    
 val = analogRead(analogPin); // Lectura analógica desde el pin específicado
 
 voltaje = (5/1024)*val; // Cálculo del voltaje en función de la lectura del chip
 temp = (5/1024)*val*100-50;// Cálculo de la temperatura en función de la lectura del chip
 
 // Muestra por la por el monitor de los valores
 Serial.print("Voltaje registrado en el pin: ");
 Serial.println(voltaje);
 
 Serial.print("la temperatura registrada en el pin: ");
 Serial.println(temp);
 
 // Tiempo de espera para una mejor lectura de los valores
 delay(1500);


}
