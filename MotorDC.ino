//Definiendo variables, puerto donte estan conectadas las llantas en el arduino
int motorPin = 5;

int dutyCycle = 1;
int valor = 1;

void setup() {
  // Inicializamos el pin del motor como salida
  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //Conforme pasa el tiempo el motor va aumentando la velocidad, hasta que llega al final del ciclo y se detiene.


  do {

  analogWrite(motorPin, dutyCycle);

    dutyCycle+=20;
    valor+=20;

    delay(5000);
    Serial.println(valor);

  } while (valor<256);

  analogWrite(motorPin, 0);
}


