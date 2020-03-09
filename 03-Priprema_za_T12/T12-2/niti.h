#ifndef NITI_H
#define NITI_H

#include <thread>
#include <list>

using namespace std;

// Implementacija pokretanja više niti koje treba da ispišu svoje redne brojeve (koristeći funkciju "ispisi")
//
// brojNiti - Broj niti koje je potrebno startovati
//
void izracunaj(int brojNiti)
{
	thread* ths = new thread[brojNiti];
	for (int i = 0; i < brojNiti; i++)
		ths[i] = thread(ispisi, i);
	for (int i = 0; i < brojNiti; i++)
		ths[i].join();
}

#endif // NITI_H
