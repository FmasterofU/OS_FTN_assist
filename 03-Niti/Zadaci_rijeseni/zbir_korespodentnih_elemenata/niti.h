#ifndef NITI_H_INCLUDED
#define NITI_H_INCLUDED

#include <vector>
#include <thread>
#include "suma_vektora.h"

#define SEP_NUM 2

using namespace std;

// v - vektor A čije elemente treba sumirati
// v - vektor B čije elemente treba sumirati
// povratna vrednost - suma korespondentnih elemenata vektora A i B, izračunata pozivanjem dve niti
vector<double> sumiraj(vector<double> a, vector<double> b) {
    vector<double> ret(a.size());
    thread ths[SEP_NUM];
    for (int i = 0; i < SEP_NUM; i++)
        ths[i] = thread(f, a.begin() + (a.size() / SEP_NUM) * i, i != SEP_NUM - 1 ? (a.begin() + a.size() / SEP_NUM * (i + 1)) : a.end(), b.begin() + (a.size() / SEP_NUM) * i, ret.begin() + (a.size() / SEP_NUM) * i);
    for (int i = 0; i < SEP_NUM; i++)
        ths[i].join();
    return ret;
}

#endif // NITI_H_INCLUDED
