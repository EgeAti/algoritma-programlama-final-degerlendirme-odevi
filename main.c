#include <stdio.h>
#include <math.h>

int main(){
    float ucret, odenen;
    while (1){
        printf("Ucreti giriniz...\n");
        if (scanf("%f",&ucret) == 0){
            printf("Lutfen sayi giriniz\n");
            fflush(stdin);
            continue;
        }
        printf("Odenen miktari giriniz...\n");
        if (scanf("%f",&odenen) == 0){
            printf("Lutfen sayi giriniz\n");
            fflush(stdin);
            continue;
        }
        if (odenen > ucret){
            break;
        }
        printf("Para üstü eksik. Değerleri tekrar giriniz.\n");
    }
    printf("ucret %f\nodenen %f\n", ucret, odenen);
    int banknot[7] = {20000, 10000, 5000, 2000, 1000, 500, 100};
    char banknotlar[7][10] = {"200 TL", "100 TL", "50 TL", "20 TL", "10 TL", "5 TL", "1 TL"};
    int kuruslar[6] = {50, 25, 10, 5, 1};
    char tKuruslar[5][20] = {"50 kurus", "25 kurus", "10 kurus", "5 kurus", "1 kurus"};
    int kurusSayilari[5] = {0, 0, 0, 0, 0};
    int kupurSayilari[7] = {0, 0, 0, 0, 0, 0, 0};
    float kalan_f = roundf((odenen - ucret)* 100) ;
    printf("%f\n", kalan_f);
    int kalan = (int) kalan_f;
    int kupurSayisi = 0;
    for (int i = 0; i < 7; i++){
        int x = kalan/banknot[i];
        kupurSayisi += x;
        kalan -= x*banknot[i];
        kupurSayilari[i] = x;
    }
    int kurusSayisi = 0;
    for(int i = 0; i < 5; i++){
        int x = kalan/kuruslar[i];
        kurusSayisi += x;
        kalan -= x*kuruslar[i]; 
        kurusSayilari[i] = x;
    }
    printf("kupur sayisi: %d\nkurus sayisi: %d\n", kupurSayisi, kurusSayisi);
    for (int i = 0; i < 7; i++){
        printf("%s: %d, ", banknotlar[i], kupurSayilari[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("%s: %d, ", tKuruslar[i], kurusSayilari[i]);
    }
    return 0;
}