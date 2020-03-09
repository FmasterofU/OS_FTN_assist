#ifndef SUMA_VEKTORA_H_INCLUDED
#define SUMA_VEKTORA_H_INCLUDED

#include <vector>
#include <algorithm>
using namespace std;

typedef vector<double>::const_iterator ci;

/*
pocetak - iterator na prvi element koji se uzima u obzir pri računanju sume
kraj - iterator iza poslednjeg elementa koji se uzima u obzir pri računanju sume
zbir - parameter kroz koji funkcija treba da vrati izračunatu sumu
*/
void f(ci pocetak, ci kraj, double& zbir) {
    for_each(pocetak, kraj, [&zbir](double el) {zbir += el; });
}

#endif // SUMA_VEKTORA_H_INCLUDED
