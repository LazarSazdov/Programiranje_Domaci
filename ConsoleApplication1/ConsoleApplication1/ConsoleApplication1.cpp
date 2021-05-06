#include <iostream>
#include <list>
#include "dinstring.hpp"
class Artikal {
public:
    virtual double VrednostArtikla()const = 0;
};
class Lek : public Artikal {
private:
    long int jkl;
    DinString naziv;
    double jedinicna_cena;
    int kolicina;
public:
    Lek() {
        jkl = 50;
        naziv = "kapi za nos";
        jedinicna_cena = 200;
        kolicina = 2;
    }
    Lek(long int jkl_, char naziv_[], double jedinicna_cena, int kolicina_) {
        jkl = jkl_;
        naziv = naziv_;
        jedinicna_cena = jedinicna_cena;
        kolicina = kolicina_;
    }
    Lek(long int jkl_, DinString& naziv_, double jedinicna_cena, int kolicina_) {
        jkl = jkl_;
        naziv = naziv_;
        jedinicna_cena = jedinicna_cena;
        kolicina = kolicina_;
    }
    Lek(const Lek& lek) {
        jkl = lek.jkl;
        naziv = lek.naziv;
        jedinicna_cena = lek.jedinicna_cena;
        kolicina = lek.kolicina;
    }
    double VrednostArtikla()const {
        return (kolicina * jedinicna_cena);
    }
    friend std::ostream& operator<<(std::ostream& out, const Lek& lek) {
        out << lek.jkl << std::endl;
        out << lek.naziv << std::endl;
        out << lek.jedinicna_cena << std::endl;
        out << lek.kolicina << std::endl;
        return out;
    }
    friend bool operator<(const Lek& lek_1, const Lek& lek_2) {
        if (lek_1.VrednostArtikla() < lek_2.VrednostArtikla()) {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class EvidencijaLekova {
private:
    DinString naziv_apoteke;
    DinString datum;
    std::list <Lek> lekovi;
public:
    EvidencijaLekova() {
        naziv_apoteke = "Galenika";
        datum = "06.06.6060";
        lekovi.push_back(Lek());
        lekovi.push_back(Lek());
        lekovi.push_back(Lek());
    }
    void DodajNoviLek(const Lek& lek) {
        lekovi.push_back(lek);
    }
    void DodajNoviLekNaPocetak(const Lek& lek) {
        lekovi.push_front(lek);
    }
    void BrisanjeLeka(int n) {
        std::list <Lek> ::iterator it = lekovi.begin();
        int i;
        for (i = 0; i < n; it++, i++) {

        }
        lekovi.erase(it);
    }
    void Ispis() {
        std::list <Lek> ::iterator it = lekovi.begin();
        for (; it != lekovi.end(); it++) {
            std::cout << *it << " ";
        }
    }
    void SortiranjePoVrednostiLeka() {
        lekovi.sort();
    }
};
int main()
{
    EvidencijaLekova el;
    el.BrisanjeLeka(1);
    el.Ispis();
    return 0;
}
