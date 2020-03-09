#ifndef NITI_H
#define NITI_H

#include <thread>
#include <vector>

#define THREAD_NUM 2
using namespace std;

// Implementacija operacije XOR nad ulaznim vektorima A i B izvršene uz pomoć dve niti (svaka nit obrađuje polovinu)
//
// a - Vektor A (16 binarnih cifara)
// b - Vektor B (16 binarnih cifara)
//
// Rezultat izvršavanja treba da bude vector<int> koji sadrži rezultat izvršenja XOR operacije nad ulaznim vektorima.
//
vector<int> izracunaj(vector<int>& a, vector<int>& b)
{
    thread ths[THREAD_NUM];
    vector<int> ret(a.size());
    for (int i = 0; i < THREAD_NUM; i++)
        ths[i] = thread(izvrsiXOR, a.begin() + a.size() / THREAD_NUM * i, i != THREAD_NUM - 1 ? (a.begin() + a.size() / THREAD_NUM * (i + 1)) : a.end(), 
            b.begin() + a.size() / THREAD_NUM * i, ret.begin() + a.size() / THREAD_NUM * i);
    for (int i = 0; i < THREAD_NUM; i++)
        ths[i].join();
    return ret;
}

#endif // NITI_H
