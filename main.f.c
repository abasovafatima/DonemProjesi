#include <stdio.h>
#include <string.h>

const int MAX_ISIM = 50;
const int MAX_EMAIL = 100;
const int MAX_SIFRE = 20;
const int MAX_KART_BILGI = 20;
const int MAX_PAKET = 20;
const int MAX_TARIH_SAAT = 50;

// Fonksiyon deklarasyonlar�
void kullaniciKaydi(char *isim, char *email, char *sifre);
void paketSecimi(char *paket);
void tarihVeSaatSecimi(char *tarihVeSaat);
int odemeIslemi(char *kartBilgileri);
void dosyayaKaydet(char *isim, char *email, char *paket, char *tarihVeSaat);

int main() {
    char isim[MAX_ISIM];
    char email[MAX_EMAIL];
    char sifre[MAX_SIFRE];
    char paket[MAX_PAKET];
    char tarihVeSaat[MAX_TARIH_SAAT];
    char kartBilgileri[MAX_KART_BILGI];

    
    kullaniciKaydi(isim, email, sifre);
    paketSecimi(paket);
    tarihVeSaatSecimi(tarihVeSaat);
    if (odemeIslemi(kartBilgileri)) {
        // Bilgileri dosyaya kaydet
        dosyayaKaydet(isim, email, paket, tarihVeSaat);
        printf("\nRezervasyonunuz ba�ar�yla tamamland�.\n");
    } else {
        printf("\n�deme i�lemi ba�ar�s�z. Rezervasyonunuz tamamlanamad�.\n");
    }

    return 0;
}

// Kullan�c� kayd�n� 
void kullaniciKaydi(char *isim, char *email, char *sifre) {
    printf("Kullan�c� ad�n� girin: ");
    fgets(isim, MAX_ISIM, stdin);
    isim[strcspn(isim, "\n")] = 0; // 

    printf("E-posta adresinizi girin: ");
    fgets(email, MAX_EMAIL, stdin);
    email[strcspn(email, "\n")] = 0; 

    printf("�ifrenizi girin: ");
    fgets(sifre, MAX_SIFRE, stdin);
    sifre[strcspn(sifre, "\n")] = 0; 
}

void paketSecimi(char *paket) {
    int secim;
    while (1) {  
        printf("\nPegasus U�u� Paketleri:\n");
        printf("1. Light\n2. Super Eko\n3. Avantaj\n4. Comfort Flex\n");
        printf("Paket se�in (1-4): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                strcpy(paket, "Light");
                return;  
            case 2:
                strcpy(paket, "Super Eko");
                return;
            case 3:
                strcpy(paket, "Avantaj");
                return;
            case 4:
                strcpy(paket, "Comfort Flex");
                return;
            default:
                printf("Ge�ersiz se�im. L�tfen tekrar deneyin.\n");
        }
    }
}

// Tarih ve saat se�imi 
void tarihVeSaatSecimi(char *tarihVeSaat) {
    int yil, ay, gun, saat, dakika;

    printf("\nL�tfen tarih ve saat bilgilerini girin:\n");
    printf("Y�l (2025): ");
    scanf("%d", &yil);
    printf("Ay (1-12): ");
    scanf("%d", &ay);
    printf("G�n (1-31): ");
    scanf("%d", &gun);
    printf("Saat (0-23): ");
    scanf("%d", &saat);
    printf("Dakika (0-59): ");
    scanf("%d", &dakika);

    // Tarih ve saat bilgisini karakter dizisi 
    snprintf(tarihVeSaat, MAX_TARIH_SAAT, "%04d-%02d-%02d %02d:%02d", yil, ay, gun, saat, dakika);
}
// �deme i�lemi
int odemeIslemi(char *kartBilgileri) {
    printf("\nKredi kart� bilgilerinizi girin:\n");
    printf("Kart Numaras�: ");
    scanf("%s", kartBilgileri);
    return 1;
}

void dosyayaKaydet(char *isim, char *email, char *paket, char *tarihVeSaat) {
    FILE *dosya = fopen("rezervasyon.txt", "w");

    if (dosya == NULL) {
        printf("Dosya a��lamad�.\n");
        return;
    }

    fprintf(dosya, "Kullan�c� Ad�: %s\n", isim);
    fprintf(dosya, "E-posta Adresi: %s\n", email);
    fprintf(dosya, "Se�ilen Paket: %s\n", paket);
    fprintf(dosya, "U�u� Tarihi ve Saati: %s\n", tarihVeSaat);

    fclose(dosya);
} 
