#pragma once
#include <iostream>
#include <vector>

#include "TSubstance.h"

class TCup
{
	std::vector<TSubstance>		substances;
	std::vector<double>			volumes;


public:
	void add(TSubstance substance, double volume_in_ml);
	void add(std::string nazwa, double volume_in_ml);

	void show();

	int identyfikator(std::string nazwa, std::vector<TSubstance> substances_buffer);

	void add_prc(std::string nazwa, int procent);
	void add_prc_m(std::string nazwa, int procent);

	void zlewanie(TCup* kubek_zlewany);

};