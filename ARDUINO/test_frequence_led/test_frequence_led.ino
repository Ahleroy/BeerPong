const int LED=5;

void setup() {

pinMode(LED, OUTPUT); //met la broche en sortie 
}

void loop() {
digitalWrite(LED,HIGH); // met la broche au niveau haut (5V) – allume la LED

delay(1.4); // pause de 500 millisecondes (ms)

digitalWrite(LED,LOW); // met la broche au niveau bas (0V) – éteint la LED

delay(1);
}

