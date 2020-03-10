#ifndef CENOVNIK_H
#define CENOVNIK_H

#include <string>
#include <map>
#include <algorithm>
using namespace std;

void nadjiPovoljno(map<string, double> a, map<string, double> b, map<string, double> &jeftino)
{
	for_each(a.begin(), a.end(), [&](auto el) {jeftino[el.first] = el.second < b[el.first] ? el.second : b[el.first]; });
}

#endif // CENOVNIK_H
