#ifndef NITI_H
#define NITI_H

#include <thread>

using namespace std;

double izracunaj(list<string> kupljeno, map<string, double> cenovnik)
{
    double ret = 0;
    thread th(obracunajUkupno, kupljeno, cenovnik, ref(ret));
    th.join();
    return ret;
}

#endif // NITI_H
