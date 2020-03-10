#ifndef NITI_H
#define NITI_H

#include <thread>

using namespace std;

map<string, double> izracunaj(map<string, double>& a, map<string, double>& b)
{
    map<string, double> ret;
    thread th(nadjiPovoljno, a, b, ref(ret));
    th.join();
    return ret;
}

#endif // NITI_H
