#ifndef NITI_H_INCLUDED
#define NITI_H_INCLUDED

#include <vector>
#include <thread>
#include "suma_vektora.h"

using namespace std;

#define SEP_NUM 2

// v - vektor čije elemente treba sumirati
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem 2 niti (svaka treba da obradi jednu polovinu elemenata)
double sumiraj(vector<double> v) {
    double ret = 0;
    double results[SEP_NUM] = { 0 };
    thread ths[SEP_NUM];
    for (int i = 0; i < SEP_NUM; i++)
        ths[i] = thread(f, v.begin() + (v.size() / SEP_NUM) * i, i != SEP_NUM - 1 ? (v.begin() + v.size() / SEP_NUM * (i + 1)) : v.end(), ref(results[i]));
    for (int i = 0; i < SEP_NUM; i++) {
        ths[i].join();
        ret += results[i];
    }
    return ret;
}

#endif // NITI_H_INCLUDED
