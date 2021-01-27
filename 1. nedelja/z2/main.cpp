#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int i;
    int pom1,pom2,pom3;
    for(i = 100; i < 1000; i++){
        pom1 = i%10;
        pom2 = i%100 - pom1;
        pom2 /= 10;
        pom3 = i - pom2 - pom1;
        pom3 /= 100;
        pom1 = pow(pom1,3);
        pom2 = pow(pom2,3);
        pom3 = pow(pom3,3);
        if (pom1 + pom2 + pom3 == i){
            cout << i << endl;
        }
    }
    return 0;
}
