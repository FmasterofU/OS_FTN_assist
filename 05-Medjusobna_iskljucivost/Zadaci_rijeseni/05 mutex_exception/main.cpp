/*
Napraviti konkurentni program u kom se u funkciji niti pravi veliki niz od 1.000.000.000.000 elemenata. Niz se pravi dinamički. Kreiranje niza zaštititi try - catch blokom. U okviru try catch bloka zaključati mutex pre pravljenja niza i otključati ga nakon pravljenja niza. 

Posmatrati ponašanje programa.

Nakon toga promeniti kod tako da se ne zaključava mutex eksplicitno, već da se koristi klasa unique_lock.
*/


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void handle_eptr(std::exception_ptr eptr) {
	try {
		if (eptr) {
			rethrow_exception(eptr);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

void fun(mutex& mx) {
	exception_ptr eptr;
	try {
		mx.lock();
		int* arr = new int[1000000000000];
		mx.unlock();
	}
	catch (...) {
		eptr = current_exception();
	}
	handle_eptr(eptr);
}

int main() {
	mutex mx;
	thread th(fun, ref(mx));
	th.join();
	return 0;
}