#ifndef NITI_H
#define NITI_H

#include <thread>
#include <vector>
#include <algorithm>
#define THREAD_NUM 3
using namespace std;

// Implementacija pokretanja tri niti koje treba da pretraže (svaka svoju trećinu) ulazni vektor brojeva i nađu element najbliži nuli
//
// ulaz - Ulazni vektor brojeva koji se pretražuje
//
// Povratna vrednost je nađeni element, najbliži nuli od svih elemenata koji su obuhvaćeni pretragom
//
double izracunaj(vector<double> ulaz)
{
    thread ths[THREAD_NUM];
    double results[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++)
        ths[i] = thread(pretrazi, ulaz.begin() + ulaz.size() / THREAD_NUM * i, i != THREAD_NUM - 1 ? (ulaz.begin() + ulaz.size() / THREAD_NUM * (i + 1)) : ulaz.end(),ref(results[i]));
    for (int i = 0; i < THREAD_NUM; i++)
        ths[i].join();
    return *min_element(results, results + THREAD_NUM, [](double a, double b) {return abs(a) < abs(b); });
}


#endif // NITI_H
