/* 
Napraviti funkciju:
	
vector<int> min(const vector<int>& a, const vector<int>& b);

Ova funkcija vraća vektor koji sadrži minimume korespodentnih elemenata vektora a i b.
Npr: r[0]=min(a[0],b[0]), r[1]=...
Podrazumeva se: a.size()==b.size()
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> min(const vector<int>& a, const vector<int>& b) {
	vector<int> ret;
	for (vector<int>::const_iterator it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
		ret.push_back(*it1 < *it2 ? *it1 : *it2);
	return ret;
}

int main()
{
	vector<int> a{ 4,5,6,7,8,9 }, b{ 7,8,9,1,2,3 };
	vector<int> c = min(a, b);
	for (auto it = c.begin(); it != c.end(); it++)
		cout << *it << " ";
    return 0;
}
