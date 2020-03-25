/*
Kreirati globalnu celobrojnu promeljivu brojač. Nakon toga kreirati 2 funkcije inkrement i dekrement koje povećavaju i smanjuju dati brojač ITERACIJA puta. ITERACIJA je konstanta koja predstavlja proizvoljno velik broj (npr. 100.000.000). 

Kreirati jednu nit od funkcije inkrement i jednu nit od funkcije dekrement.

Nakon završetka rada niti ispisati vrednosti brojača. Da li je data vrednost očekivana? 
*/


#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;

constexpr auto iter = 10000; // define? ne.
atomic<int> br = 0;
int brojac = 0;
mutex mx;

void increment() {
	//unique_lock<mutex> l(mx); // kakvo ponasanje ce izazvati na ovom mjestu a kakvo unutra
	for (int i = 0; i < iter; i++) {
//		while (!mx.try_lock()); // !!! ne valja; unique_lock ?
		cout << 1; // zasto nemamo realan prikaz bez obzira?; dovoljno dobar za prikaz
		br++;
		//brojac++;
//		mx.unlock();
	}
}

void decrement() {
	//unique_lock<mutex> l(mx);
	for (int i = 0; i < iter; i++) {
//		while (!mx.try_lock());
		cout << 2;
		br--;
		//brojac--;
//		mx.unlock();
	}
}

int main() {
	thread th_inc(increment), th_dec(decrement);
	th_inc.join();
	th_dec.join();
	cout << endl << br << endl;
}