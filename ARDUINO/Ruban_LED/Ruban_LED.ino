// --- Bandeau à Leds - Pilotage via Arduino ---
// TXRobotic
// 17/06/2015

// ************ Inialisation des variables ************

const int R = 1; // Inialisation de R (qui correpond au rouge) à l'état haut au démarrage
const int V = 1; // Inialisation de V (qui correpond au vert) à l'état haut au démarrage
const int B = 1; // Inialisation de B (qui correpond au bleu) à l'état haut au démarrage

const int ledVert = 3; // Configuration de la broche 3 (PWM) de l'Arduino à ledVert
const int ledRouge = 5; // Configuration de la broche 5 (PWM) de l'Arduino à ledRouge
const int ledBleu = 6; // Configuration de la broche 6 (PWM) de l'Arduino à ledBleu

void setup()
{
pinMode (ledVert,OUTPUT); // Broche ledVert configurée en sortie
pinMode (ledRouge,OUTPUT); // Broche ledRouge configurée en sortie
pinMode (ledBleu,OUTPUT); // Broche ledBleu configurée en sortie
}

// ************ Début de la boucle principale du programme ************

void loop()
{
/*all_degresif();
delay(200); // Pause de 200ms

all_lentement();
delay(200);
*/
changement_rapide();
delay(200);
/*
changement_lent();
delay(200);
*/
//while(1); // La fonction while(1) permet de réaliser une boucle infinie, votre programme tournera sans s'arrêter
}

// ************ Fonction pour combiner couleurs ON/OFF ************

void ledRVB(int Rouge, int Vert, int Bleu)
{
if (Rouge==1) digitalWrite(ledRouge,HIGH); // allume couleur
if (Rouge==0) digitalWrite(ledRouge,LOW); // éteint couleur

if (Vert==1) digitalWrite(ledVert,HIGH); // allume couleur
if (Vert==0) digitalWrite(ledVert,LOW); // éteint couleur

if (Bleu==1) digitalWrite(ledBleu,HIGH); // allume couleur
if (Bleu==0) digitalWrite(ledBleu,LOW); // éteint couleur
}

// ************ Fonction pour variation progressive des couleurs ************

void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu) // reçoit valeur 0-255 par couleur
{
analogWrite(ledRouge, pwmRouge);
analogWrite(ledVert, pwmVert);
analogWrite(ledBleu, pwmBleu);

}

// ************ Fonctions allumage d'une seule couleur ************

void vert () // Allume la LED verte puis l'éteint au bout de 200ms
{
digitalWrite(ledVert,HIGH);
delay(200);

digitalWrite(ledVert,LOW);
delay(200);
}

void rouge () // Allume la LED rouge puis l'éteint au bout de 200ms
{
digitalWrite(ledRouge,HIGH);
delay(200);

digitalWrite(ledRouge,LOW);
delay(200);
}

void bleu () // Allume la LED rouge puis l'éteint au bout de 200ms
{
digitalWrite(ledBleu,HIGH);
delay(200);

digitalWrite(ledBleu,LOW);
delay(200);
}

void violet () // Allume les LEDs Rouge et Bleu pour créer du violet puis l'éteint au bout de 200ms
{
ledRVB(R,0,B);
delay(200);

ledRVB(0,0,0);
delay(200);
}

void jaune () // Allume les LED Rouge et Verte pour créer du jaune puis l'éteint au bout de 200ms
{
ledRVB(R,V,0);
delay(200);

ledRVB(0,0,0);
delay(200);
}

void bleu_clair () // Allume les LEDs Verte et Bleu pour créer du bleu clair puis l'éteint au bout de 200ms
{
ledRVB(0,V,B);
delay(200);

ledRVB(0,0,0);
delay(200);
}

void all () // Allume les 3 LEDs pour créer du blanc puis l'éteint au bout de 200ms
{
ledRVB(R,V,B);
delay(200);

ledRVB(0,0,0);
delay(200);
}

// ************ Fonction clignotement d'une seule couleur ************

void vert_clignotement () // Fait clignoter la LED verte 10 fois
{
for (int i = 0; i < 10 ; i++)
{
digitalWrite(ledVert,HIGH);
delay(200);

digitalWrite(ledVert,LOW);
delay(200);
}
}

// ************ Fonction de dégradé de couleur ************

void all_degresif ()
{
// Variation de rouge
for (int i=0; i<=255; i++) // Prends toutes les valeurs de 0 à 255
{
ledRVBpwm(i,0,0); // Génère une impulsion de largeur voulue pour la couleur
delay(40); // pause de 40ms
}

// variation de bleu - rouge dégressif
for (int i=0; i<=255; i++) // Prends toutes les valeurs de 0 à 255
{
ledRVBpwm(255-i,0,i); // Génère une impulsion de largeur voulue pour la couleur
delay(40); // pause de 40ms
}

// variation de vert - bleu dégressif
for (int i=0; i<=255; i++) // Prends toutes les valeurs de 0 à 255
{
ledRVBpwm(0,i,255-i); // Génère une impulsion de largeur voulue pour la couleur
delay(40); // pause de 40ms
}

// variation de bleu - rouge dégressif
for (int i=0; i<=255; i++) // Prends toutes les valeurs de 0 à 255
{
ledRVBpwm(i,255-i,0); // Génère une impulsion de largeur voulue pour la couleur
delay(40); // pause de 40ms
}
}

// ************ Fonction de changement de couleur lente ************
void changement_lent ()
{
ledRVB(1,0,0);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,1,0);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,0,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(1,1,0);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(1,0,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,1,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(1,1,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,1,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(1,0,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(1,1,0);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,0,1);
delay(500);
ledRVB(0,0,0);
delay(200);
ledRVB(0,1,0);
delay(500);
ledRVB(0,0,0);
delay(200);
}

// ************ Fonction de changement de couleur rapide ************

void changement_rapide ()
{
ledRVB(1,0,0);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,0,0);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(1,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(1,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(1,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,1,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(1,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(1,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(1,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,0,1);
delay(100);
ledRVB(0,0,0);
delay(100);

ledRVB(0,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);
ledRVB(0,1,0);
delay(100);
ledRVB(0,0,0);
delay(100);
}

// ************ Fonction de changement de couleur une par une lentement ************

void all_lentement ()
{
for (int i = 0; i < 256; i++)
{
analogWrite(ledVert, i);
analogWrite(ledRouge, i);
analogWrite(ledBleu, i);
delay(100);
}
}
