/*
Korisnik treba da unese 5 celih brojeva koristeći tastaturu (standardni ulaz).
Korišćenjem STL algoritma, među tih 5 brojeva potrebno je pronaći najveći.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec;
    int num;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        vec.push_back(num);
    }
    cout << *max_element(vec.begin(), vec.end()) << endl;
    return 0;
}
