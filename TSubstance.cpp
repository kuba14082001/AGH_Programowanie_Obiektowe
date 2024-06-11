#include "TSubstance.h"
using namespace std;

TSubstance::TSubstance(string name, double ro) // konstruktor
{
	this->name = name;			// przypisanie nazwy substancji
	this->ro = ro;				// przypisanie gestosci substancji
}

string TSubstance::get_name()	// metoda get_name zwracajaca nazwe substancji
{
	return name;
}

double TSubstance::get_ro()		// metoda get_ro zwracajaca gestosc substancji
{
	return ro;
}

vector<TSubstance> substancje = // deklaracja wektora substancji - globalny wektor substancji
{
	TSubstance{"krew", 1050.0},
	TSubstance{"olej", 900.0},
	TSubstance{"woda", 997.0},
	TSubstance{"piasek", 2620.0}
};
