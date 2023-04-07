#include <stdio.h>
#include <string.h>
#include <ctype.h>// tolower fonksiyonu için kütüphaneyi tanýmladýk.

#define MAX_KELIMELER 100//max kelime sayýsýný verdik
#define MAX_KELIME_UZUNLUK 50//max uzunluýk

int anagramlar_mi(char* kelime1, char* kelime2) {
    int frekans[26] = {0};
    int i;
    char c;

    // Her bir kelimenin harflerini sayan denklem 
    for (i = 0; i < strlen(kelime1); i++) {
        c = tolower(kelime1[i]);
        if (c >= 'a' && c <= 'z') {
            frekans[c - 'a']++;
        }
    }

    // Ýkinci kelimenin harflerini saydýk  ve karþýlaþtýrdý
    for (i = 0; i < strlen(kelime2); i++) {
        c = tolower(kelime2[i]);
        if (c >= 'a' && c <= 'z') {
            frekans[c - 'a']--;
        }
    }

    // Eðer her harf için sayýlarý eþleþiyorsa anagramdýrlar
    for (i = 0; i < 26; i++) {
        if (frekans[i] != 0) return 0;
    }

    return 1;
}

int main() {
    char kelimeler[MAX_KELIMELER][MAX_KELIME_UZUNLUK];
    int frekans[MAX_KELIMELER] = {0};
    int ziyaret_edildi[MAX_KELIMELER] = {0};
    int n, i, j;

    printf("Metinleri lutfen girin: ");
    fgets(kelimeler[0], MAX_KELIMELER * MAX_KELIME_UZUNLUK, stdin);

    // Metin dizisini kelime kelime ayýrma iþlemi yaptýk
    n = 0;
    char* kelime = strtok(kelimeler[0], " ");
    while (kelime != NULL && n < MAX_KELIMELER) {
        strcpy(kelimeler[n], kelime);
        frekans[n] = 1;
        ziyaret_edildi[n] = 0;
        n++;
        kelime = strtok(NULL, " ");
    }

    // Anagramlarý bulma
    for (i = 0; i < n - 1; i++) {
        if (ziyaret_edildi[i]) continue;//kontrol kelimesi ayný kelime üzerinde tekrar tekrar anagram kontrolü yapýlmasý engellenir ve programýn çalýþmasý hýzlandýrýlýr.
        for (j = i + 1; j < n; j++) {
            if (ziyaret_edildi[j]) continue;
            if (anagramlar_mi(kelimeler[i], kelimeler[j])) {
                printf("%s - %s\n", kelimeler[i], kelimeler[j]);
                ziyaret_edildi[j] = 1;
            }
        }
    }

    return 0;
}

