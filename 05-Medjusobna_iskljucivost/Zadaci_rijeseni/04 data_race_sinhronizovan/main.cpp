/*
Izmeniti program data_race i realizovati zaštitu pristupa brojaču uz pomoć klase mutex i njenih operacija lock() i unlock(). Primetiti koliko sada traje izvršavanje programa.
*/



// Pogledati data race primjer sa vise prikazanih detalja


#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;

constexpr auto iter = 10000; // define? ne.
int brojac = 0;
mutex mx;

void increment() {
	for (int i = 0; i < iter; i++) {
		mx.lock();
		cout << 1;
		brojac++;
		mx.unlock();
	}
}

void decrement() {
	for (int i = 0; i < iter; i++) {
		mx.lock();
		cout << 2;
		brojac--;
		mx.unlock();
	}
}

int main() {
	thread th_inc(increment), th_dec(decrement);
	th_inc.join();
	th_dec.join();
	cout << endl << brojac << endl;
}