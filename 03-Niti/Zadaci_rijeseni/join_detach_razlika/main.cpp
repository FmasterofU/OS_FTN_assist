/*
Napraviti konkurentni program koji stvara nit iz koje pita korisnika za visinu u centimetrima i potom ispisuje: “Vasa visina je <uneta_visina> cm.”

Testirati program tako što će main nit, koristeći objekat koji predstavlja novu nit, da pozove metodu join. Potom promeniti taj poziv u poziv metode detach.
*/

#include <iostream>
#include <thread>
using namespace std;

void visina() {
    int height;
    cout << "Koliko ste visoki?" << endl;
    cin >> height;
    cout << endl << "Vasa visina je " << height << " cm." << endl;
}

int main()
{
    thread nit(visina);
    nit.join();
    //nit.detach();
    return 0;
}



