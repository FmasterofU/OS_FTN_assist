/*
Napraviti konkurentni program koji pokreće više niti u petlji. Svakoj niti proslediti njen redni broj prilikom kreiranja i svaka nit treba da ispiše sopstveni redni broj u okviru tela niti.
*/

#include <iostream>
#include <thread>
using namespace std;

void nit(int i) {
    cout << "I'm thread " << i << "." << endl;
}

int main()
{
    thread th[10];
    for (int i = 0; i < 10; i++)
        th[i] = thread(nit, i + 1);
    for (int i = 0; i < 10; i++)
        th[i].join();
    return 0;
}
