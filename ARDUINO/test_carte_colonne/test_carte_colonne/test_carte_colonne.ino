//Broche connectée au ST_CP du 74HC595
const int verrou = 11;
//Broche connectée au SH_CP du 74HC595
const int horloge = 12;
//Broche connectée au DS du 74HC595
const int data = 10;
 
void setup()
{
    //On met les broches en sortie
    pinMode(verrou, OUTPUT);
    pinMode(horloge, OUTPUT);
    pinMode(data, OUTPUT);
}
 
void loop()
{
    //on affiche les nombres de 0 à 255 en binaire
    for (int i = 0; i < 256; i++)
    {
        //On active le verrou le temps de transférer les données
        digitalWrite(verrou, LOW);
        //on envoi toutes les données grâce à shiftOut (octet inversée avec '~' pour piloter les LED à l'état bas)
        shiftOut(data, horloge, LSBFIRST, ~i);
        //et enfin on relache le verrou
        digitalWrite(verrou, HIGH);
        //une petite pause pour constater l'affichage
        delay(1000);
    }
}

