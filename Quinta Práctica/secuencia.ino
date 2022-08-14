
/* Programa de arduino que emula el led que tiene el coche fantastico mediante el uso de funciones definidas por el usuario*/


// Zona de definicion de las variables, una por cada led que se va a utilizar referenciando al pin que van a estar conectados
int led1 = 2, led2= 3, led3=4, led4=5, led5=6;

void setup() {
  pinMode(led1, OUTPUT); // Se pone cada uno de esos pines digitales como pines de salida 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  goRight(); // Llamada a la funcion primera
  delay(100); // tiempo de espera
  goLeft(); // Llamada a la funcion segunda
  delay(100);
}


void goRight(){
  digitalWrite(led1, HIGH); // Funcionamiento sencillo, se enciende un led, se espera y despues se apaga mientras se enciende el siguiente de izquierda a derecha
  delay(100);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led4, HIGH);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led5, HIGH);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led5, LOW);
  
}

void goLeft(){
  digitalWrite(led5, HIGH); // Funcionamiento sencillo, se enciende un led, se espera y despues se apaga mientras se enciende el siguiente de derecha a izquierda
  delay(100);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led1, LOW);
}

