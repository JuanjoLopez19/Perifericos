
/* Progama de arduino que recoge el funcionamiento de un medidor de distancia basado en ultrasonidos*/

/*Definición de variables a utilizar en el sketch*/

int trigger=9; // Pin de salida
int echo=8; // Pin de entrada
float duration ,distance; // Variables en las que se van a almacenar los datos

void setup() {
 pinMode(trigger, OUTPUT); // Iniciación del Pin 9 como salida
 pinMode(echo, INPUT); // Iniciación del Pin 8 como entrada
 Serial.begin(9600); // Iniciación del puerto serie a una velocidad de 9600 Baudios
}

void loop() {
  // Parte de disparo del módulo  
  digitalWrite(trigger, LOW); // Pin a bajo
  delayMicroseconds(2); // Espera de 2 microsegundos
  digitalWrite(trigger, HIGH); // Pin a alto
  delayMicroseconds(10);
  digitalWrite(trigger, LOW); // Pin a bajo

  duration = pulseIn(echo, HIGH); // Recolección del valor recogido por el módulo 
  
  distance = (duration*.0343)/2; // Cálculo de la distancia recorrida mediante la fórmula distancia = T * Vsonido/2
  
  // Muestra por pantalla del valor obtenido
  Serial.print("Distancia: ");
  Serial.println(distance);
  
  // Tiempo de espera para una mejor lectura de los valores
  delay(1000);
}
