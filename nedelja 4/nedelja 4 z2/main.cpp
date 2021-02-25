#include <iostream>

using namespace std;
enum tip_menjaca {manuelni=1, automatski};
enum boja_skoljke {plava = 1,crvena,zelena};
enum stanje_auta {POKVAREN, U_VOZNJI, UGASEN};
class Menjac{
private:
    tip_menjaca tip;
    int broj_brzina;
public:
    Menjac(){
     tip = manuelni;
    broj_brzina = 3;
    }
    Menjac(tip_menjaca tp, int br){
    tip = tp;
    broj_brzina = br;
    }
    Menjac(const Menjac &o){
    tip = o.tip;
    broj_brzina = o.broj_brzina;
    }
    int getTip()const{return tip;}
    int getBB()const{return broj_brzina;}
    void setTip(tip_menjaca tp){
    tip = tp;
    }
    void setBB(int bb){
    broj_brzina = bb;
    }
};
class Skoljka{
private:
    boja_skoljke tip;

public:
    Skoljka(){
     tip = plava;
    }
    Skoljka(boja_skoljke tp){
    tip = tp;
    }
    Skoljka(const Skoljka &o){
    tip = o.tip;
    }
    int getTip()const{return tip;}

    void setTip(boja_skoljke tp){
    tip = tp;
    }
};
class automobil{
private:
   Menjac Men;
   Skoljka Sko;
   stanje_auta stanje;
   int brzina;
public:
    automobil(){
    Men = Menjac();
    Sko = Skoljka();
    stanje = UGASEN;
    brzina = 0;
    }
    automobil(tip_menjaca tp,int bb,boja_skoljke boja){
    Men = Menjac(tp,bb);
    Sko = Skoljka(boja);
    stanje = UGASEN;
    brzina = 0;
    }
    automobil(const automobil &o){
    Men = o.Men;
    Sko = o.Sko;
    stanje = o.stanje;
    brzina = o.brzina;
    }
    bool upali(){
    if (stanje == UGASEN){
        stanje = U_VOZNJI;
        brzina = 1;
        return 1;
    }else{
        return 0;
    }
    }
    bool ugasi(){
        if (stanje == U_VOZNJI){
        stanje = UGASEN;
        brzina = 0;
        return 1;
    }else{
        return 0;
    }
    }
    bool pokvari(){
        if (stanje != POKVAREN){
            stanje = POKVAREN;
            brzina = 0;
            return 1;
        }else{
        return 0;
        }
    }
    bool popravi(){
        if (stanje == POKVAREN){
            stanje = UGASEN;
            brzina = 0;
            return 1;
        }else{
        return 0;
        }

    }
    bool povecajBrzinu(){
        if(brzina > 0 && brzina <= Men.getBB() - 1){
            brzina++;
            return 1;
        }else{
            return 0;
        }

    }
    bool smanjiBrzinu(){
        if(brzina > 1){
            brzina--;
            return 1;
        }else{
            return 0;
        }
    }
    void ispisi(){
    cout << Men.getBB() << endl;
    if (Men.getTip() == 1){
        cout << "Automatski" << endl;
    }else{
        cout << "manuelni" << endl;
    }
    if (Sko.getTip() == 1){
        cout << "plava" << endl;
    }else if(Sko.getTip() == 2){
        cout << "crvena" << endl;
    }else{
        cout << "zelena" << endl;
    }
    if (stanje == 0){
        cout << "pokvaren" << endl;
    }else if(stanje == 1){
        cout << "u voznji" << endl;
    }else{
        cout << "ugasen" << endl;
    }
    cout << brzina << endl;
    }
};

int main()
{
    automobil auto1();
    auto1.ispisi();
    automobil auto2(automatski,5,crvena);
    auto2.upali;
    auto2.ispisi();
    automobil auto3(auto1);
    auto3.povecajBrzinu();
    auto3.ispisi();


    return 0;
}
