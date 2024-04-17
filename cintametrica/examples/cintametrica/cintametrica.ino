#define BUZZER 13
#include <cintametrica.h>

// Construimos el objeto Ultrasonido(pintrigger, pinecho)
Ultrasonido sensor(11, 10);
byte pines[7] = {2, 3, 4, 5, 6, 7, 8}; // Pines para display 7 segmentos
Display7 pantalla;
int distancia;

void setup() {
    // Configuramos la pantalla
    Serial.begin(9600);
    pantalla.configurar(pines);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    distancia = sensor.medirCM(); // Medimos distancia
    Serial.println(distancia);
    distancia = (byte) distancia / 10;
    Serial.println(distancia);
    pantalla.mostrar(distancia); // Mostramos en display
    digitalWrite(BUZZER, 1);
    delay(500);
    digitalWrite(BUZZER, 0);
    delay(120 * distancia);
}
