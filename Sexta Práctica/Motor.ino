//Poner en marcha un motor CC

// Definicion de variables
const int digitalPin=9; // Pin al que esta conectado el motor 
int pulso = 0; // Variable para recorrer los bucles del apartado 2
int data = 0; // Variable para recoger el valor del Serial del apartado 3



void setup(){
	pinMode(digitalPin,OUTPUT); // Se establece como pin de salida

  Serial.begin(9600) // Inicializar el puerto serie con una velocidad de 9600 Baudios, para el apartado 3
}

void loop()
{
  // Apartado 1 
	run_stop();

  // Apartado 2
  /* run_inc();
  	delay(2000);
  	run_dec();
  	delay(2000);
  */

  // Apartado 3
  //type_run()
}

// Funcion para el apartado 1
void run_stop(){
  analogWrite(digitalPin,255);
  delay(3000);
  analogWrite(digitalPin,0);
  delay(3000);
}



// Funciones para el apartado 2
void run_inc(){
  for(pulso = 0; pulso <=255; pulso++){ // Se incrementa de uno en uno el valor de la variable aumentando progresivamente las rpm del motor 
  	analogWrite(digitalPin, pulso);
    delay(200);
  }
}

void run_dec(){
  for(pulso = 255; pulso >0; pulso--){ // Se decrementa de uno en uno el valor de la variable disminuyendo progresivamente las rpm del motor 
  	analogWrite(digitalPin, pulso);
    delay(200);
  }
}



// Funcion para el apartado 3
void type_run(){
  if (Serial.available()) // Comprobacion de si el puerto serie ha recogido un valor 
    {
        int data = Serial.parseInt(); // En caso afirmativo se castea el valor a entero
        if (data >= 0 && data <=255) // Se comprueba si esta entre los valores 0 y 255 para enviarselo directemente por el puerto definido
          analogWrite(digitalPin,data); // Se envia el valor al motor
        else
        {
          data = constrain(data,0,255); // Si el valor recogido esta fuera de los límites con constrain se situa dentro de los limites
          analogWrite(digitalPin,data); // Se envia el valor al motor
        }
    }
}