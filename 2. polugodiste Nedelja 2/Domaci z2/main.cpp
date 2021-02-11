#include <iostream>

using namespace std;

class Osoba{

private:
        int dan;
        int mesec;
        int godina;
    public:



        Osoba(){

            dan = 1;
            mesec = 1;
            godina = 2000;
        }
        Osoba(int x,int y,int z){

            dan = x;
            mesec = y;
            godina = z;
        }


        int getDan(){return dan;}
        int getMesec(){return mesec;}
        int getGodinu(){return godina;}

        void setDan(int x){dan = x;}
        void setMesec(int x){mesec = x;}
        void setGodinu(int x){godina = x;}

        bool IsValid(int x, int y, int z){
        if (x > 31){
            return false;
        }else if(y > 12){
            return false;
        }else if(2021 - z > 130 || 2021 - z < 0){
            return false;
        }else{
            return true;
        }
        }


};


int main()
{
    Osoba br1;
    Osoba br2(12,5,1998);
    cout<<"Pocetne vrednosti osobe 1: "<<endl <<br1.getDan()<<endl <<br1.getMesec()<<endl <<br1.getGodinu()<<endl;
    cout<<"Pocetne vrednosti osobe 2: "<<endl <<br2.getDan()<<endl <<br2.getMesec()<<endl <<br2.getGodinu()<<endl;
    br1.setDan(14);
    br1.setMesec(5);
    br1.setGodinu(2006);
    cout<<"Nove vrednosti osobe 1: "<<endl <<br1.getDan()<<endl <<br1.getMesec()<<endl <<br1.getGodinu()<<endl;
    br2.setDan(13);
    br2.setMesec(15);
    br2.setGodinu(1090);
    cout<<"Nove vrednosti osobe 2: "<<endl <<br2.getDan()<<endl <<br2.getMesec()<<endl <<br2.getGodinu()<<endl;
    if(br1.IsValid(br1.getDan(),br1.getMesec(),br1.getGodinu())){
        cout << "Podaci osobe 1 su validni." << endl;
    }else{
        cout << "Podaci osobe 1 nisu validni." << endl;
    }
    if(br2.IsValid(br2.getDan(),br2.getMesec(),br2.getGodinu())){
        cout << "Podaci osobe 2 su validni." << endl;
    }else{
        cout << "Podaci osobe 2 nisu validni." << endl;
    }

    return 0;
}
