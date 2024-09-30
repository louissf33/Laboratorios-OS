// Definición de pines
const int semaforo1Rojo = 5;
const int semaforo1Amarillo = 6;
const int semaforo1Verde = 7;

const int semaforo2Rojo = 8;
const int semaforo2Amarillo = 9;
const int semaforo2Verde = 10;

const int semaforo3Rojo = 11;
const int semaforo3Amarillo = 12;
const int semaforo3Verde = 13;

const int interruptor = 2; // Pin para el interruptor
bool encendido = false; // Estado del semáforo

void setup() {
  // Configuración de pines como salida
  pinMode(semaforo1Rojo, OUTPUT);
  pinMode(semaforo1Amarillo, OUTPUT);
  pinMode(semaforo1Verde, OUTPUT);
  pinMode(semaforo2Rojo, OUTPUT);
  pinMode(semaforo2Amarillo, OUTPUT);
  pinMode(semaforo2Verde, OUTPUT);
  pinMode(semaforo3Rojo, OUTPUT);
  pinMode(semaforo3Amarillo, OUTPUT);
  pinMode(semaforo3Verde, OUTPUT);
  pinMode(interruptor, INPUT_PULLUP); // Interruptor con pull-up interno

  Serial.begin(9600); // Iniciar comunicación serial
}

void loop() {
  // Leer estado del interruptor
  encendido = digitalRead(interruptor) == LOW;

  if (encendido) {
    // Ciclo de semáforos
    semaforo1();
    semaforo2();
    semaforo3();
  } else {
    // Parpadeo amarillo si el semáforo está apagado
    parpadearAmarillo();
  }
}

void semaforo1() {
  // Semáforo 1 en verde
  Serial.println("Semáforo 1: Verde");
  digitalWrite(semaforo1Rojo, LOW);
  digitalWrite(semaforo1Amarillo, LOW);
  digitalWrite(semaforo1Verde, HIGH);
  
  // Semáforo 2 y 3 en rojo
  digitalWrite(semaforo2Rojo, HIGH);
  digitalWrite(semaforo2Amarillo, LOW);
  digitalWrite(semaforo2Verde, LOW);
  digitalWrite(semaforo3Rojo, HIGH);
  digitalWrite(semaforo3Amarillo, LOW);
  digitalWrite(semaforo3Verde, LOW);
  delay(5000); // Esperar 5 segundos

  // Semáforo 1 a amarillo
  Serial.println("Semáforo 1: Amarillo");
  digitalWrite(semaforo1Verde, LOW);
  digitalWrite(semaforo1Amarillo, HIGH);
  delay(2000); // Esperar 2 segundos

  // Apagar semáforo 1
  digitalWrite(semaforo1Amarillo, LOW);
  digitalWrite(semaforo1Rojo, HIGH);
}

void semaforo2() {
  // Semáforo 2 en verde
  Serial.println("Semáforo 2: Verde");
  digitalWrite(semaforo2Rojo, LOW);
  digitalWrite(semaforo2Amarillo, LOW);
  digitalWrite(semaforo2Verde, HIGH);
  
  // Semáforo 1 y 3 en rojo
  digitalWrite(semaforo1Rojo, HIGH);
  digitalWrite(semaforo1Amarillo, LOW);
  digitalWrite(semaforo1Verde, LOW);
  digitalWrite(semaforo3Rojo, HIGH);
  digitalWrite(semaforo3Amarillo, LOW);
  digitalWrite(semaforo3Verde, LOW);
  delay(5000); // Esperar 5 segundos

  // Semáforo 2 a amarillo
  Serial.println("Semáforo 2: Amarillo");
  digitalWrite(semaforo2Verde, LOW);
  digitalWrite(semaforo2Amarillo, HIGH);
  delay(2000); // Esperar 2 segundos

  // Apagar semáforo 2
  digitalWrite(semaforo2Amarillo, LOW);
  digitalWrite(semaforo2Rojo, HIGH);
}

void semaforo3() {
  // Semáforo 3 en verde
  Serial.println("Semáforo 3: Verde");
  digitalWrite(semaforo3Rojo, LOW);
  digitalWrite(semaforo3Amarillo, LOW);
  digitalWrite(semaforo3Verde, HIGH);
  
  // Semáforo 1 y 2 en rojo
  digitalWrite(semaforo1Rojo, HIGH);
  digitalWrite(semaforo1Amarillo, LOW);
  digitalWrite(semaforo1Verde, LOW);
  digitalWrite(semaforo2Rojo, HIGH);
  digitalWrite(semaforo2Amarillo, LOW);
  digitalWrite(semaforo2Verde, LOW);
  delay(5000); // Esperar 5 segundos

  // Semáforo 3 a amarillo
  Serial.println("Semáforo 3: Amarillo");
  digitalWrite(semaforo3Verde, LOW);
  digitalWrite(semaforo3Amarillo, HIGH);
  delay(2000); // Esperar 2 segundos

  // Apagar semáforo 3
  digitalWrite(semaforo3Amarillo, LOW);
  digitalWrite(semaforo3Rojo, HIGH);
}

void parpadearAmarillo() {
  for (int i = 0; i < 5; i++) {
    Serial.println("Semáforos: Amarillo intermitente");
    digitalWrite(semaforo1Amarillo, HIGH);
    digitalWrite(semaforo2Amarillo, HIGH);
    digitalWrite(semaforo3Amarillo, HIGH);
    delay(500); // Encendido
    digitalWrite(semaforo1Amarillo, LOW);
    digitalWrite(semaforo2Amarillo, LOW);
    digitalWrite(semaforo3Amarillo, LOW);
    delay(500); // Apagado
  }
}