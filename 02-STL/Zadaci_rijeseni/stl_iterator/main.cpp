/*
Napraviti program koji prihvata proizvoljan broj linija sa standardnog ulaza i zatim ih ispisuje u redosledu kojim su uneti.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<string> vec;
    string s;
    while (getline(cin,s)) {
        vec.push_back(s);
    }
    for_each(vec.begin(), vec.end(), [](string s) {cout << s << endl; });
    return 0;
}
