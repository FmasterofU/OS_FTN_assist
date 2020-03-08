/*
Napraviti program koji prihvata proizvoljan broj linija sa standardnog ulaza i zatim ih ispisuje u obrnutom redosledu 
(poslednja prihvaćena linija se ispisuje prva).
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    string s;
    while (getline(cin, s)) {
        vec.push_back(s);
    }
    for_each(vec.rbegin(), vec.rend(), [](string s) {cout << s << endl; });
    return 0;
}
