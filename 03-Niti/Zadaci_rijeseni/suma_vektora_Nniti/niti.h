#ifndef NITI_H_INCLUDED
#define NITI_H_INCLUDED

#include <vector>
#include <thread>
#include "suma_vektora.h"

using namespace std;

// v - vektor čije elemente treba sumirati
// n - koliko niti treba pokrenuti
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem n niti (svaka nit treba da obradi jedan deo elemenata)
double sumiraj(vector<double> v, int n) {
    double ret = 0;
    double* results = new double[n] {0};
    thread * ths = new thread[n];
    for (int i = 0; i < n; i++)
        ths[i] = thread(f, v.begin() + (v.size() / n) * i, i != n - 1 ? (v.begin() + v.size() / n * (i + 1)) : v.end(), ref(results[i]));
    for (int i = 0; i < n; i++) {
        ths[i].join();
        ret += results[i];
    }
    return ret;
}

#endif // NITI_H_INCLUDED
