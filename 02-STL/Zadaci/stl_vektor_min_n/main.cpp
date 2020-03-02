/*
Napraviti funkciju:
	
vector<int> min_n(const vector<int>& v,	int n);

Ova funkcija vraća vektor koji sadrži n najmanjih elemenata iz vektora v.
Podrazumeva se: v.size()>=n
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> min_n(const vector<int>& v, int n) {
	vector<int> ret = v;
	sort(ret.begin(), ret.end(), [](int a, int b) {return a < b; });
	ret.resize(n);
	return ret;
}

int main()
{
	vector<int> a{ 9,8,7,6,5,4,3,2,1 };
	vector<int> b = min_n(a, 5);
	for (auto it = b.begin(); it != b.end(); it++)
		cout << *it << " ";
    return 0;
}
