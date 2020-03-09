/* 
Napraviti program koji kreira jednu nit i u okviru niti ispisuje proizvoljnu rečenicu.
*/

#include <iostream>
#include <thread>
using namespace std;

void nit() {
    cout << "Well, fuck.";
}

int main()
{
    thread th(nit);
    th.join();
    return 0;
}
