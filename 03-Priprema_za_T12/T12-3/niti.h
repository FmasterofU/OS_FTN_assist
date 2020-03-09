#ifndef NITI_H
#define NITI_H

#include <thread>
#include <list>

using namespace std;

// Implementacija obrtanja redosleda elemenata u listi pokretanjem jedne nove niti
//
// ulazna  - Ulazna lista, koja se obrađuje
//
// Rezultat je rezultujuća lista (popunjena elementima u obrnutom redosledu)
//
list<int> izracunaj(const list<int>& ulazna)
{
    list<int> ret;
    thread th(obrniRedosled, ref(ulazna), ref(ret));
    th.join();
    return ret;
}

#endif // NITI_H
