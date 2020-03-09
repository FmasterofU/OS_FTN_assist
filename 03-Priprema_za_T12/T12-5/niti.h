#ifndef NITI_H
#define NITI_H

#include <thread>
#include <map>

using namespace std;

// Implementacija pokretanja dodatne niti koja treba da napravi novi rečnik (koristeći funkciju "napraviRecnik")
//
// brojNiti - Broj niti koje je potrebno startovati
map<string, string> izracunaj(map<string, string> engSrp)
{
    map<string, string> ret;
    thread th(napraviRecnik, engSrp, ref(ret));
    th.join();
    return ret;
}

#endif // NITI_H
