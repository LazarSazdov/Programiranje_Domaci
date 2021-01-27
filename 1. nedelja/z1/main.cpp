#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Unesite neki broj: " ;
    cin >> n;
    cout << "Faktorijel je: ";
    if (n == 0){
        cout << 1 ;
        return 0;
    }
    for(int i =n - 1;i>0;--i){
        n *= i;
    }
    cout << n ;
    return 0;
}
