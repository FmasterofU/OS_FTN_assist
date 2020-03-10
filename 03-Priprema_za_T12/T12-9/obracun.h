#ifndef OBRACUN_H
#define OBRACUN_H

#include <string>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

void obracunajUkupno(list<string> kupljeno, map<string, double> cenovnik, double& ukupno)
{
	for_each(kupljeno.begin(), kupljeno.end(), [&](auto el) {ukupno += cenovnik[el]; });
}

#endif // OBRACUN_H
