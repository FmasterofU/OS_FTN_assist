/*
Uneti 5 celih brojeva sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojeve u rastućem redosledu.
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
    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << " "; });
    return 0;
}
