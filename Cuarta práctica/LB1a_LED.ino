/* Progama de arduino que va a encender y apagar un LED repetidamente*/

/*Definición de variables a utilizar en el sketch*/

int led = 13; // Pin digital que se va a utilizar como salida

void setup() {
  pinMode(led, OUTPUT); // Se actualiza el pin 13 como pin de salida
}

void loop() {

  digitalWrite(led, HIGH); // Se envía al pin una señal alta, es decir 5V haciendo que el led conectado se encienda
  delay(1000); // tiempo de espera medido en milisegundos
  digitalWrite(led, LOW);/ Se envía al pin una señal naja, es decir 0V haciendo que el led conectado se apague
  delay(1000);
}
