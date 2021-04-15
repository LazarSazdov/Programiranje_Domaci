
/// Domaci - Zadatak 3 Kamera
#include <iostream>
#include <string.h>


class Kamera {
protected:
    int megaPikseli;
    int freeSpace;
public:
    static int photoCounter;
    Kamera() {
        megaPikseli = 5;
        freeSpace = 80;
    }
    Kamera(int megaPiskeli, int free_space) {
        megaPikseli = megaPiskeli;
        freeSpace = free_space;
    }
    Kamera(Kamera& kamera) {
        megaPikseli = kamera.megaPikseli;
        freeSpace = kamera.freeSpace;
    }

    int getPhotoCounter() const {
        return photoCounter;
    }

    bool Slikaj() {
        bool retVal = false;
        if (freeSpace - megaPikseli > 0) {
            freeSpace -= megaPikseli;
            retVal = true;
            photoCounter++;
        }

        return retVal;
    }
};
int Kamera::photoCounter = 0;
class VideoKamera : public Kamera {
public:
    static int videoCounter;
public:
    VideoKamera() : Kamera() {
    }
    VideoKamera(int mega_pikseli, int free_space) : Kamera(mega_pikseli, free_space) {
    }
    int getVideoCounter() const {
        return videoCounter;
    }
    bool Snimaj(int sekunde) {
        bool retVal = false;
        if ((freeSpace - (megaPikseli * sekunde)) > 0) {
            freeSpace -= (megaPikseli * sekunde);
            retVal = true;
            videoCounter++;
        }

        return retVal;
    }
};
int VideoKamera::videoCounter = 0;
class Telefon {
protected:
    char broj[10];
public:
    Telefon() {
        strcpy_s(broj,"0123456\n");
    }
    Telefon(char* brojTel) {
        strcpy_s(broj, brojTel);
    }
    bool Pozovi(const char* brojTel) {
        bool retVal = false;
        if (strcmp(broj, brojTel) == 0) {
            retVal = true;
        }
        return retVal;
    }
};

class TelefonGen2 : public Telefon {
protected:
    Kamera k;
public:
    TelefonGen2() : Telefon() {
        k = Kamera();
    }
    TelefonGen2(Kamera kamera, char* brojTel) : Telefon(brojTel) {
        k = kamera;
    }
    bool Slikaj() {
        return k.Slikaj();
    }
};

class TelefonGen3 : public TelefonGen2 {
private:
    VideoKamera vk;
public:

    TelefonGen3() : TelefonGen2() {
        vk = VideoKamera();
    }
    TelefonGen3(Kamera cam, char* brojTel, int mega_piskeli, int free_space) : TelefonGen2(cam, brojTel)
    {
        vk = VideoKamera(mega_piskeli, free_space);
    }
    bool SnimiVideo(int sec) {
        return vk.Snimaj(sec);
    }
};

int main()
{
    Kamera k1;
    Kamera k2;
    k1.Slikaj();
    k2.Slikaj();
    std::cout << k1.getPhotoCounter() << std::endl;
    VideoKamera vk1;
    VideoKamera vk2;
    vk1.Snimaj(9);
    std::cout << vk1.getVideoCounter() << std::endl; 
    vk2.Snimaj(2);
    std::cout << vk1.getVideoCounter() << std::endl; 
    TelefonGen3 tel;
    tel.SnimiVideo(24);
    if (tel.Pozovi("0123456\n")) {
        std::cout << "Uspesno!\n";
    }
    else { std::cout << "Neuspesno!\n";}
}

