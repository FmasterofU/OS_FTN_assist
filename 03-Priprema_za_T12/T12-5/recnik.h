#ifndef RECNIK_H
#define RECNIK_H

#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Funkcija koja će biti iskorišćena kao funkcija niti - od zadatog englesko-srpskog rečnika ona pravi obrnuti rečnik - srpsko-engleski
//
// engSrp - Englesko-srpski rečnik (ključ je reč na engleskom, podatak je njen prevod na srpski)
// srpEng - Srpsko-engleski rečnik (ključ je reč na srpskom, podatak je njen prevod na engleski) - ovaj parametar treba da se popuni izvršenjem ove funkcije
//
void napraviRecnik(map<string, string> engSrp, map<string, string>& srpEng)
{
    for_each(engSrp.begin(), engSrp.end(), [&srpEng](auto/*pair<string,string>*/ el) {srpEng.insert(pair<string, string>(el.second, el.first)); }); // or use srpEng[el.second] = el.first;
}


#endif // RECNIK_H
