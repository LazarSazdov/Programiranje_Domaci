#include <iostream>
#include <math.h>

using namespace std;

class JKK_Trougao{

    private:
        int a;
        int b;
        int c;
    public:



        JKK_Trougao(){

            a = 10;
            b = 12;
            c = b;
        }
        JKK_Trougao(int x,int y){

            a = x;
            b = y;
            c = b;
        }


        int getA(){return a;}
        int getB(){return b;}
        int getC(){return c;}

        void setA(int x){a = x;}
        void setB(int x){b = x; c = x;}

        int getO(int x,int y){return x+2*y;}
        double getP(int x,int y){

            double s = (a + b + c)/ 2;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }

};


int main()
{
    JKK_Trougao t;
    JKK_Trougao t2(4,2);

    cout<<"Pocetne vrednosti trougla: "<<endl <<t.getA()<<endl <<t.getB()<<endl <<t.getC()<<endl;
    t.setA(5);
    t.setB(4);
    cout<<"Nove vrednosti trougla: "<<endl <<t.getA()<<endl <<t.getB()<<endl <<t.getC()<<endl;
    cout<<"Obim datog trougla je: "<<endl<<t.getO(t.getA(),t.getB())<<endl;
    cout<<"Povrsina datog trougla je: "<<endl <<t.getP(t.getA(),t.getB())<<endl;




    return 0;
}

