/* u09a.c
 * Beschreibung: Strukturen-Array
 * Datum: 28.11.2018
 * Name: Enis Kecevic
 */
 
#include <stdio.h>
#include <string.h>
 
struct listElement {
 
    int anzahl;
    double k;
    char gericht[100];
 
};
 
char ausgabe(struct listElement *text, int anz) {
 
    for(int j = 0; j < anz; j++) { 
        printf("Tag %i: %i, %.2lf, %s\n", j + 1, (text + j)->anzahl, (text + j)->k, (text + j)->gericht);   
    }
    return 0;
}
 
void sortieren_nach_kalorien(struct listElement *p_array, int anz) {
 
    for(int n = anz; n > 1; --n) {
        for(int j = 0; j < (n - 1); ++j) {
            if((p_array + j)->k > (p_array + j + 1)->k) {                    
                tausche(p_array + j, p_array + j + 1); 
            } 
        }
    } 
}
 
void tausche(struct listElement *firstItem, struct listElement *secondItem) {
 
    struct listElement temp;
    temp.anzahl = firstItem->anzahl;
    temp.k = firstItem->k;
    strncpy(temp.gericht, firstItem->gericht, 100);

    firstItem->anzahl = secondItem->anzahl;
    firstItem->k = secondItem->k;
    strncpy(firstItem->gericht, secondItem->gericht, 100);

    secondItem->anzahl = temp.anzahl;
    secondItem->k = temp.k;
    strncpy(secondItem->gericht, temp.gericht, 100);
    printf("Successfull swap!\n");
}
 
int main() {
 
    struct listElement myarray[7] = {
        {34, 812.3, "Fledermauszaehne in Aspik mit Algenglibber"},
        {13, 77.7, "ganzer Kuerbisgeist flambiert nach Tageslaune"},
        {57, 178.178, "Huettenzauber mit Baiserhaube im Sauerampferbett"},
        {42, 737.3, "Stinkmorchel im eigenen Saft mit Pantoffelpuffern"},
        {117, 123.55, "Teufelswurz im Marzipanmantel auf Blattspinat"},
        {12, 1024.7, "Fliegenpilz am feinen Rattengift im Schmalzbad"},
        {1, 13.08, "Knoblauchzehe gut gegart an einem Hauch von Panik"},
    };
 
    ausgabe(&myarray[0], 7);
    sortieren_nach_kalorien(&myarray[0], 7);
    ausgabe(&myarray[0], 7);
 
    return 0;
}