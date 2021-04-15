#include <iostream>
class ABS {
public:
   virtual int getTemperaturu() const = 0;
   virtual void setTemperaturu(int) = 0;
   
};

class Grejac: public ABS{
private:
    int temperatura;
public:
    Grejac() {
        temperatura = 0;
    }
    Grejac(int temp) {
        temperatura = temp;
    }
    Grejac(Grejac& o) {
        temperatura = o.temperatura;
    }
    int getTemperaturu() const {
        return temperatura;
    }
    void setTemperaturu(int t) {
        if (t < 0 || t > 100)
            return;
        temperatura = t;
    }
};
enum Modovi {TOPLO = 1, HLADNO = 0};
class Fen {
private:
    char marka[20];
    Modovi mod;
    Grejac grejac;
public:
    char* getMarka(){
        return marka;
    }
    Modovi getMod() const {
        return mod;
    }
    Grejac getGrejac() { return grejac; }
    Fen(Modovi md, char* mark) {
        grejac = Grejac();
        mod = md;
        strcpy_s(marka, mark);
    }
    Fen(Fen& o) {
        mod = o.mod;
        grejac = o.grejac;
        strcpy_s(marka, o.marka);
    }
};



int main()
{
    
    std::cout << "Hello World!\n";
}

