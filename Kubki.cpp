#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "TCup.h"

using namespace std;

int main()
{
    
    TCup kubek1;
    TCup kubek2;
    TCup kubek3;
    TCup kubek4;

    cout << "----------------------------------\n----------------------------------\n\n";
    cout << "\t Dodawanie procentowe objetosci \n\n";

    cout << "\t ------ Dodanie 50ml krwi i 10ml wody ------\n\n";

    kubek1.add("krew", 50);
    kubek1.add("woda", 10);
    kubek1.show();

    cout << "\t ------ Dolanie wody do 80% ------\n\n";

    kubek1.add_prc("woda", 80);
    kubek1.show();

    cout << "\t ------ Sprawdzenie czy mozna dolac wody do 70% ------ \n\n";

    kubek1.add_prc("woda", 70);
    kubek1.show();

    cout << "\t ------ Dosypanie piasku do 30% ------ \n\n";
    kubek1.add_prc("piasek", 30);
    kubek1.show();

    cout << "----------------------------------\n----------------------------------\n\n";
    cout << "\t Dodawanie procentowe masy \n\n";

    cout << "\t ------ Dodanie 50ml krwi i 10ml wody ------\n\n";

    kubek2.add("krew", 50);
    kubek2.add("woda", 10);
    kubek2.show();


    cout << "\t ------ Dolanie wody do 80% ------\n\n";

    kubek2.add_prc_m("woda", 80);
    kubek2.show();

    cout << "\t ------ Sprawdzenie czy mozna dolac wody do 70% ------ \n\n";

    kubek2.add_prc_m("woda", 70);
    kubek2.show();

    cout << "\t ------ Dosypanie piasku do 30% ------ \n\n";
    kubek2.add_prc_m("piasek", 30);
    kubek2.show();

    cout << "----------------------------------\n----------------------------------\n\n";
    cout << "\t Zlewanie kubkow \n\n";

    cout << "\t ------ Dodanie 10ml oleju ------\n\n";
   
    kubek3.add("olej", 10);
    kubek3.show();

    cout << "\t ------ Zlanie kubkow 2 i 3 ------ \n\n";

    kubek2.zlewanie(&kubek3);
    cout << "\t Kubek 2 \n\n";
    kubek2.show();
    cout << "\t Kubek 3 \n\n";
    kubek3.show();

}

