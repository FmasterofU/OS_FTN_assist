/*
Napisati konkurentni program koji stvara 2 niti od funkcije f. Funkcija f treba da prolazi kroz petlju dužine 10000 elemenata i ispisuje parne ili neparne brojeve (među tih 10000 elemenata).

Ispis parnih ili neparnih brojeva se vrši pozivom metoda ispisi_parne i ispisi_neparne. U metodi ispisi_parne prvo se pre ispisa zaključava muteks m1, a potom muteks m2. U metodi ispisi_neparne prvo se pre ispisa zaključava muteks m2, a potom muteks m1.

Sva zaključavanja se vrše kroz objekte klase unique_lock.

Pratiti izvršavanje programa.
*/

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

#define FOR_TIMES 10000

void ispisi_parne(int i, mutex& mx1, mutex& mx2) {
	unique_lock<mutex> l1(mx1);
	unique_lock<mutex> l2(mx2);
	printf("%8d\n", i);
}

void ispisi_neparne(int i, mutex& mx1, mutex& mx2) {
	unique_lock<mutex> l1(mx2);
	unique_lock<mutex> l2(mx1);
	printf("%8d\n", i);
}

void f(mutex& mx1, mutex& mx2) {
	for (int i = 0; i < FOR_TIMES; i++)
		if (i % 2) ispisi_neparne(i, mx1, mx2);
		else ispisi_parne(i, mx1, mx2);
}

int main() {
	mutex mx1, mx2;
	thread t1(f, ref(mx1), ref(mx2)), t2(f, ref(mx1), ref(mx2));
	t1.join();
	t2.join();
	return 0;
}