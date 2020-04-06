/*
Napraviti konkurentni program koji u funkciji visina pita korisnika koliko je visok. Nakon toga korisnik unosi svoju visinu. Na kraju u funkciji se ispisuje uneta visina.

Kreirati 2 niti od date funkcije. Ispratiti ispis.
*/


#include <iostream>
#include <thread>
using namespace std;

void get_height() {
	int height = 0;
	cout << "Unijeti visinu: ";
	cin >> height;
	cout << "Unesena je visina od " << height << "cm. " << endl;
}

int main() {
	thread t0(get_height), t1(get_height);
	t0.join();
	t1.join();
	return 0;
}