/*		
Napraviti konkurentni program koji modeluje klasu brojača. Interfejs klase sadrži sledeće metode: 

class Brojac {
   public:
      void inc();
      void dec();
      friend ostream& operator<<(ostream& , Brojac& );
};

Metode inc i dec povećavaću i smanjuju vrednost brojača respektivno. Operator << služi za ispis brojača na ekran.

Klasa treba da zaštiti konzistentnost brojača u datim metodama uz pomoć klasa mutex i unique_lock. 

Kreirati 1 globalni objekat brojača kome će pristupati 2 niti. 

Kreirati 2 niti pri čemu jedna nit poziva metodu uvećavanja brojača 1000000 puta a druga metodu smanjivanja brojača 1000000 puta. Na kraju programa ispisati konačnu vrednost brojača nakon uvećavanja i smanjivanja.
*/

#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
using namespace std;

class Brojac {
public:
    void inc();
    void dec();
    friend ostream& operator<<(ostream&, Brojac&);
private:
    mutex mx;
    atomic<int> br = 0; // sve se moglo izbjeci tako sto bi ova promjenljiva bila atomic!!!
};

void Brojac::inc() {
    //unique_lock<mutex> l(mx);
    ++br;
}

void Brojac::dec() {
    //unique_lock<mutex> l(mx);
    --br;
}

ostream& operator<<(ostream& out, Brojac& b) {
    return out << b.br;
}

Brojac b;
#define TIMES 1000

void finc() {
    for (int i = 0; i < TIMES; i++) {
        b.inc();
        cout << b << endl; // ispis nije dobar? zasto? ipak nam okvirno prikazuje stanje
    }
}

void fdec() {
    for (int i = 0; i < TIMES; i++){
        b.dec();
        cout << b << endl;
    }
}

int main() {
    thread t1(finc), t2(fdec);
    t1.join();
    t2.join();
    return 0;
}