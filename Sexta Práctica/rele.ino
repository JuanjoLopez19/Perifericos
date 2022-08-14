/* Programa de arduino que va a servir para el control de un relé mecánico */

// Definición de variables
int rele=9; // Pin al que va a estar conectado el relé

void setup() {
pinMode(rele, OUTPUT); // Se establece el pin como de salida
}

void loop() {
digitalWrite(rele, HIGH); // Se le aporta un nivel de voltaje alto por lo que se encenderá un led mientras que el otro se apagará
delay(1000); // Pausa para apreciar mejor el funcionamiento
digitalWrite(rele, LOW); // Se le aporta un nivel de voltaje bajo por lo que se encenderá un led mientras que el otro se apagará
delay(1000); // Pausa para apreciar mejor el funcionamiento
}