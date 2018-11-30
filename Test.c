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

void sortieren_nach_alphabet(struct listElement *p_array, int anz) {
    for (int i = 0; i < anz - 1; ++i) {
        for (int j = i + 1; j < anz; ++j) {
            if (strcmp((p_array + i)->gericht, (p_array + j)->gericht) > 0) {
                tausche(p_array + i, p_array + j); 
            }
        }
    }
}
 
void tausche(struct listElement *firstItem, struct listElement *secondItem) {
 
    struct listElement temp;
    temp.anzahl = firstItem->anzahl;
    temp.k = firstItem->k;
    strcpy(temp.gericht, firstItem->gericht);

    firstItem->anzahl = secondItem->anzahl;
    firstItem->k = secondItem->k;
    strcpy(firstItem->gericht, secondItem->gericht);

    secondItem->anzahl = temp.anzahl;
    secondItem->k = temp.k;
    strcpy(secondItem->gericht, temp.gericht);
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
    printf("Original:\n");
    ausgabe(&myarray[0], 7);

    sortieren_nach_kalorien(&myarray[0], 7);
    printf("Nach Kalorieren sortiert:\n");
    ausgabe(&myarray[0], 7);

    sortieren_nach_alphabet(&myarray[0], 7);
    printf("Nach Alphabet sortiert:\n");
    ausgabe(&myarray[0], 7);
 
    return 0;
}