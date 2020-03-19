/*
Napraviti konkurentni program koji pronalazi element najbliži broju 0 u zadatom vektoru brojeva.

Pretragu podeliti u 3 programske niti. Ulazni vektor brojeva treba da sadrži 900.000 slučajno generisanih brojeva.

Za svaku nit, evidentirati trenutke kada je izvršavanje počelo i kada se završilo. Na kraju programa, ispisati koliko je trajalo izvršavanje svake niti u milisekundama.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using namespace chrono;

typedef vector<double>::const_iterator cit;

struct vreme {
    system_clock::time_point pocetak;
    system_clock::time_point kraj;
};

void f(cit pocetak, cit kraj, double & min, struct vreme * v) {
	// Implementirati...
    v->pocetak = system_clock::now();
    min = numeric_limits<double>::max();
    for_each(pocetak, kraj, [&min](double el) {if (abs(el) < abs(min)) min = el; });
    v->kraj = system_clock::now();
    // Done.
}

const int BROJ_NITI = 3;
const int DUZINA = 900000;

int main() {
    int SEGMENT = DUZINA / BROJ_NITI;

    srand(time(NULL));   // Postavljamo seme random generatora na trenutno vreme, što dovodi do kvalitetnijeg izbora slučajnih brojeva.

    vector<double> v(DUZINA);
    // Puni se vektor pseudo-slučajnim brojevima
    for (int i = 0; i < DUZINA; i++)
	v[i] = rand();

    double minimumi[BROJ_NITI];  // Niz elemenata najbližih nuli - svaka programska nit će dati svoj međurezltat
    struct vreme vremena[BROJ_NITI]; // Niz struktura u koji će biti upisani podaci o trajanju izvršavanja svake niti

    thread niti[BROJ_NITI];

	// Implementirati...

    for (int i = 0; i < BROJ_NITI; i++)
        niti[i] = thread(f, v.begin() + i * v.size() / BROJ_NITI, i != BROJ_NITI - 1 ? v.begin() + (i + 1) * v.size() / 3 : v.end(), ref(minimumi[i]), &vremena[i]);
    for_each(niti, niti + BROJ_NITI, [](thread& th) {th.join(); });

    for (int i = 0; i < BROJ_NITI; i++) {
        duration<double, milli> dur = vremena[i].kraj - vremena[i].pocetak;
        cout << "Thread " << i + 1 << " : " << dur.count() << " ms" << endl;
    }

    // Done.
}

