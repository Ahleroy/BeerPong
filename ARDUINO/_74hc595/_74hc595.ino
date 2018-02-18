const int verrou = 11;
const int donnee = 10;
const int horloge = 12;
 
 
void setup()
{
    //on déclare les broches en sortie
    pinMode(verrou, OUTPUT);
    pinMode(donnee, OUTPUT);
    pinMode(horloge, OUTPUT);
}
 
void loop()
{
    int masque = 0;
    for(int i=1; i<16; i++)
    {
        //on décale d'un cran le masque 
        masque = 0x01 << i;                 
        //on commence par mettre le verrou         
        digitalWrite(verrou, LOW);         
        //on envoie la seconde donnée d'abord         
        //On envoie les 8 premiers bits         
        shiftOut(donnee, horloge, LSBFIRST, ~(masque & 0x00FF));         
        //on envoie la première donnée         
        //On envoie les 8 derniers bits         
        shiftOut(donnee, horloge, LSBFIRST, ~((masque & 0xFF00) >> 8));
        //et on relache le verrou pour mettre à jour les données
        digitalWrite(verrou, HIGH);
        delay(10);
    }

}
