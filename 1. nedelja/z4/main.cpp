#include <iostream>
#include <math.h>
#include <iomanip>
double izr(int n){
int i = 0;
double izraz = 0;
for(i=0;i<=n;i++){
    izraz += sqrt(i);
}
return izraz;
}
using namespace std;

int main()
{
    int n;
    cout << "Unesite broj: ";
    cin >> n;
    cout << "Vrednost izraza je: "<< fixed << setprecision(2) << izr(n) << endl;
    return 0;
}
