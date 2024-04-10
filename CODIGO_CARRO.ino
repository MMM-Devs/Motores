// Define los pines de control del puente H L293N
int motor1Pin1 = 13; // Input 1
int motor1Pin2 = 5;  // Input 2

char incomingByte;    // Variable para almacenar los datos recibidos por Bluetooth

void setup() {
  // Define los pines como salida
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  // Inicializa la comunicación serial a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop() {


  if (Serial.available() > 0) {
    // Lee el dato recibido
    incomingByte = Serial.read();

    Stop();
    switch (incomingByte) {
      case 'F':
        forward();
        break;

     // case 'B':
       // backward();
        //break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        Stop();
        break;
    }
  }
}



//Metodos del motor
void forward(){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, HIGH);
}

void backward(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
}

void left(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
}

void right(){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
}

void Stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
}

