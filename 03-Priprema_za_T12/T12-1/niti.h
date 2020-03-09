#ifndef NITI_H
#define NITI_H

#include <thread>
#include <vector>
#include <thread>
using namespace std;

// Implementacija sabiranja korespondentnih elemenata celih vektora A i B pokretanjem onoliko niti koliko ima elemenata u vektorima
//
// a - Vektor A
// b - Vektor B
//
// Rezultat izvršavanja treba da bude vector<int> koji sadrži rezultat sabiranja korespondentnih elemenata.
//
vector<int> izracunaj(vector<int>& a, vector<int>& b)
{
    vector<int> ret(a.size());
    thread* ths = new thread[a.size()];
    unsigned thread_it = 0;
    for (auto it_a = a.begin(), it_b = b.begin(), it_ret = ret.begin(); it_a != a.end(); it_a++, it_b++, it_ret++, thread_it++)
        ths[thread_it] = thread(saberiPar, it_a, it_b, it_ret);
    for_each(ths, ths + a.size(), [](thread& th) {th.join(); });
    return ret;
}

#endif // NITI_H
