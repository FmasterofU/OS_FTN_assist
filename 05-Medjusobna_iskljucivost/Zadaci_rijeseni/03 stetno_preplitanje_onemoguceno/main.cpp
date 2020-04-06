/*
Napraviti konkurentni program koji u funkciji visina pita korisnika koliko je visok. Nakon toga korisnik unosi svoju visinu. Na kraju u funkciji se ispisuje uneta visina.

Sprečiti štetno preplitanje na terminalu korišćenjem klase mutex.

Kreirati 2 niti od date funkcije. Ispratiti ispis.
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void get_height(mutex& mx) {
	unique_lock<mutex> l(mx);
	int height = 0;
	cout << "Unijeti visinu: ";
	cin >> height;
	cout << "Unesena je visina od " << height << "cm. " << endl;
}

int main() {
	mutex mx;
	thread t0(get_height, ref(mx)), t1(get_height, ref(mx));
	t0.join();
	t1.join();
	return 0;
}