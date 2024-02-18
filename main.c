#include <stdio.h>
#include <string.h>

#define MAX_TAHMIN_HAKKI 5
#define KELIME_UZUNLUGU 5


int  main() {
    char hedefKelime[KELIME_UZUNLUGU + 1] = "roket"; // Hedef kelimeyi tan�mla
    char tahminKelime[KELIME_UZUNLUGU + 1]; // Kullan�c�n�n tahmin edece�i kelime
    int tahminHakki = MAX_TAHMIN_HAKKI; // Tahmin hakk� sayac�


    printf ("WORDLE\n");
    printf ("Hosgeldiniz!\n");
    printf ("Hedef kelime 5 harften olusmaktadir.\n");
    printf ("Basarilar!\n");

    while  (tahminHakki > 0) {
        printf("Tahmininiz: ");
        scanf("%s", tahminKelime);

         if (strlen(tahminKelime) != KELIME_UZUNLUGU)  {
        printf("Tahmin kelimesi 5 harften olusmalidir!\n");
        return 0;
    }

        if  (strcmp(hedefKelime, tahminKelime) == 0) { // Tahmin do�ru ise
            printf("Tebrikler! Dogru tahmin.\n");
            return 0;
        } else { // Tahmin yanl�� ise
            printf("Yanlis tahmin.\n");
            printf("Olmayan harfler: ");
            for(int i = 0; i < KELIME_UZUNLUGU; i++) {
                if (strchr(hedefKelime, tahminKelime[i]) == NULL) { // Hedef kelime i�inde tahmin kelimesinde bulunmayan harfi bul
                    printf("%c ", tahminKelime[i]);
                }
            }
            printf("\n");
            printf("Yeri yanlis harfler: ");
            for (int i = 0; i < KELIME_UZUNLUGU; i++) {
                if  (hedefKelime[i] != tahminKelime[i]) { // Hedef kelime ile tahmin kelimesinde ayn� harf, fakat farkl� konumda ise
                    printf("%c ", tahminKelime[i]);
                }
            }


            printf ("\n");
            tahminHakki--;
            printf("Kalan tahmin hakkiniz: %d\n\n", tahminHakki);
        }
    }

    printf("Tahmin hakkiniz bitti. Kaybettiniz. Dogru kelime: %s\n", hedefKelime);

    return 0;
}
