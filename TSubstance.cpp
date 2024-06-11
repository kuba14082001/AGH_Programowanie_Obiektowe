#include "TSubstance.h"
using namespace std;

TSubstance::TSubstance(string name, double ro)
{
	this->name = name;
	this->ro = ro;
}

string TSubstance::get_name()
{
	return name;
}

double TSubstance::get_ro()
{
	return ro;
}

vector<TSubstance> substancje =
{
	TSubstance{"krew", 1050.0},
	TSubstance{"olej", 900.0},
	TSubstance{"woda", 997.0},
	TSubstance{"piasek", 2620.0}
};
