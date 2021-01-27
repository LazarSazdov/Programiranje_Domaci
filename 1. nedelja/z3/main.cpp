#include <iostream>

using namespace std;

int prestupna(int god){
   if (god % 100 == 0){
    if( god % 400 == 0 ){
        return 1;
    }else {
        return 0;
    }
   }
   if(god%4 == 0){
    return 1;
   }

}

int main()
{
    int god;
    cout << "Unesite godinu: ";
    cin >> god;
    if(prestupna(god)){
        cout << "Da" << endl;
    }else{
    cout << "Ne" << endl;
    }
    return 0;
}
