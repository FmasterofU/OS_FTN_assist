/*
Napraviti jednostavan program za prevođenje reči sa engleskog na srpski jezik.
Nakon unosa reči sa standardnog ulaza, ispisuje se prevod (ukoliko unesena reč postoji u rečniku). 

Uneti 3 engleske reči i njihove prevode na srpski.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string s;
    map<string,string> dict;
    dict["someone"] = "neko";
    dict["dumb"] = "glup";
    dict["retard"] = "retard";
    while (getline(cin, s)) {
        cout << dict[s] << endl;
    }
    return 0;
}
