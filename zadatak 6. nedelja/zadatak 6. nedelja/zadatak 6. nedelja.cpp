// zadatak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

enum tipPreliva { COKOLADNI = 1, COKOLADNI_SA_PRELIVOM };
enum kolacStanje { U_PRIPREMI = 1, PECE_SE, ZAGOREO, PRIPREMLJEN };

class Preliv {
protected:
    tipPreliva tip;
public:
    Preliv() {
        tip = COKOLADNI;
    }
    Preliv(tipPreliva p) {
        tip = p;
    }
    Preliv(const Preliv& o) {
        tip = o.tip;
    }
    bool dodajSlag() {
        if (tip == 1) {
            tip = COKOLADNI_SA_PRELIVOM;
            return 0;
        }
        else {
            return 1;
        }

    }
    bool ukloniSlag() {
        if (tip == 2) {
            tip = COKOLADNI;
            return 0;
        }
        else {
            return 1;
        }

    }
    int getTip()const {
        return tip;
    }
};
class Kolac : public Preliv
{
public:
    Kolac() : Preliv()
    {
        stanje = U_PRIPREMI;
        temperatura = 20;
    }
    Kolac(int temp, kolacStanje kst, tipPreliva preliv) : Preliv(preliv) {
        
        stanje = kst;
        temperatura = temp;
    }
    Kolac(const Kolac& o): Preliv(o)
    {
        
        stanje = o.stanje;
        temperatura = o.temperatura;


    }
    int getStanje()const { return stanje; }
    int getTemp()const { return temperatura; }

    bool staviDaSePece();
    bool ispeciKolac();
    bool zavrsiKolac();
    bool povecajTemperaturu();
    bool smanjiTemperaturu();
    bool dodajSlag();
    bool ukloniSlag();


private:
    kolacStanje stanje;
    int temperatura;

};

bool Kolac::staviDaSePece() {
    if (stanje == U_PRIPREMI && tip != COKOLADNI_SA_PRELIVOM) {
        stanje = PECE_SE;
        return 0;
        temperatura = 40;
    }
    else {
        return 1;
    }
}
bool Kolac::ispeciKolac() {
    if (stanje == PECE_SE) {
        stanje = U_PRIPREMI;
        temperatura = 20;
        return 0;
    }
    else {
        return 1;
    }
}
bool Kolac::zavrsiKolac() {
    if (stanje == U_PRIPREMI) {
        stanje = PRIPREMLJEN;
        return 0;
    }
    else {
        return 1;
    }
}
bool Kolac::povecajTemperaturu() {
    if (stanje == PECE_SE) {
        temperatura+=10;
        if (temperatura > 100) {
            stanje = ZAGOREO;
            temperatura = 20;
        }
        return 0;
    }
    else {
        return 1;
    }
}
bool Kolac::smanjiTemperaturu() {
    if (stanje == PECE_SE) {
        temperatura-= 10;
        if (temperatura <40 ) {
            temperatura = 40;
        }
        return 0;
    }
    else {
        return 1;
    }
}
bool Kolac::dodajSlag() {
    if (stanje == U_PRIPREMI) {
        Preliv::dodajSlag();
        return 0;
    }
    else {
        return 1;
    }

}
bool Kolac::ukloniSlag() {
    if (stanje == U_PRIPREMI) {
        Preliv::ukloniSlag();
        return 0;
    }
    else {
        return 1;
    }
}


int main()
{
    Kolac kol1;
    Kolac kol2(30, U_PRIPREMI, COKOLADNI_SA_PRELIVOM);
    Kolac kol3(kol2);
    cout << kol3.getTip() << endl;
    cout << kol3.getTemp() << endl;
    cout << kol3.getStanje() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
