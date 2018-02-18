// PROJET BEER-PONG INTERACTIF
// CARTE JOUEUR 1
// ARDUINO NANO


#include <Wire.h> //On inclut la librairie pour la communication i2c


int nbGobelets = 10; //Variable pour le nombre de gobelets restants

//PORTS GPIO DE L'ARDUINO
#define GOBELET1 2
#define GOBELET2 3
#define GOBELET3 4
#define GOBELET4 5
#define GOBELET5 6
#define GOBELET6 7
#define GOBELET7 8
#define GOBELET8 9
#define GOBELET9 10
#define GOBELET10 11
#define LED 13

//ADRESSES I2C
#define J1_ADRESS  0x08 //Adresse I2C de la carte Arduino du J1
#define PI_ADRESS  0x03 //Adresse I2C de la raspberry pi maitre


void setup() {
  //On définit la bande passante sur le port série à 9600 bauds
  Serial.begin(9600);

  
  // Port 13 (led arduino) en output
  pinMode (LED, OUTPUT);
  pinMode (GOBELET1, INPUT);
  pinMode (GOBELET2, INPUT);
  pinMode (GOBELET3, INPUT);
  pinMode (GOBELET4, INPUT);
  pinMode (GOBELET5, INPUT);
  pinMode (GOBELET6, INPUT);
  pinMode (GOBELET7, INPUT);
  pinMode (GOBELET8, INPUT);
  pinMode (GOBELET9, INPUT);
  pinMode (GOBELET10, INPUT);
  
  
  // On configure l'i2c de la carte sur le port 8
  Wire.begin(J1_ADRESS); 
  
  // Lorsqu'on reçoit une info I2C de la pi, on appelle la fonction receiveevent.
  Wire.onRequest(envoiDataI2C);
}


void envoiDataI2C(){
  Serial.print("Envoi du nombre de gobelets : ");
  Serial.print(nbGobelets); 
  Serial.print("\n"); 

  blinkLed();
  
  Wire.write(nbGobelets); //Envoi à l'arduino du nombre de gobelets restant
}


void loop() {

  nbGobelets = compterGobelets();
  delay(100);
  digitalWrite(LED, LOW);
}

void blinkLed(){
  digitalWrite(LED, HIGH);   // On allume la led de la carte pour montrer que l'on a envoyé la donnée
}


int compterGobelets(){

  int gobelets = 0;

  for (int i=2; i <= 11 ; i++) {
    
    if (digitalRead(i) == HIGH ){
      gobelets++;
      
    }//fin condition
  
  }//Fin boucle for

  return gobelets;
}//Fin compterGobelets


