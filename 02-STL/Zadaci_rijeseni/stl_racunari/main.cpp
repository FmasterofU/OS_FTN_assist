/* 
Napisati program koji omogućava evidentiranje fakultetskih učionica.

Za svaku učionicu potrebno je evidentirati naziv učionice, kvadraturu i sve računare koji se nalaze u učionici. 
Za svaki računar evidentiraju se podaci o hard disku i procesoru.

U okviru main funkcije, definisati jednu učionicu koja sadrži dva računara.
Zatim je potrebno na konzolu ispisati hard disk i procesor svakog računara u učionici.
*/

#include <iostream>
#include <vector>

using namespace std;

class Racunar {
public:
    string hdd, cpu;
};

class Ucionica {
public:
    string naziv;
    double kvadratura;
    vector<Racunar> racunari;
    void print() {
        cout << naziv << " (" << kvadratura << ")" << endl;
        for (auto it = racunari.begin(); it != racunari.end(); it++)
            cout << (*it).cpu << " " << (*it).hdd << endl;
    }
};

int main()
{
    Racunar r1, r2;
    r1.hdd = "western digital";
    r2.hdd = "verbatim";
    r1.cpu = "intel";
    r2.cpu = "amd";
    Ucionica u;
    u.naziv = "MI A2-3";
    u.kvadratura = 42;
    u.racunari.push_back(r1);
    u.racunari.push_back(r2);
    u.print();
    return 0;
}
