#include<iostream>
#include<thread>
using namespace std;
void kod_niti() {
    cout << "Pozdrav iz niti!" << endl;
}
int main() {
    thread nit(kod_niti);
    nit.join();
}
