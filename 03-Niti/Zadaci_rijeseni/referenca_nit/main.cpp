/*
Definisati funkciju: void increment(int& a);
koja povećava (za jedan) vrednost argumenta.

Napraviti program koji:
a) poziva funkciju increment()
b) stvara nit od funkcije increment()
*/

#include <iostream>
#include <thread>
using namespace std;

void increment(int& a) {
    ++a;
}

int main()
{
    int num = 0;
    increment(num);
    thread th(increment, ref(num));
    th.join();
    cout << num << endl;
    return 0;
}
