#pragma once
#include <iostream>
#include <vector>


class TSubstance	//klasa substancji
{
	std::string name;	//nazwa substancji
	double		ro;	//gestosc substancji

public:
	TSubstance(std::string name, double ro); //konstruktor

	std::string		get_name();	// metoda get_name zwracajaca nazwe substancji
	double			get_ro(); // metoda get_ro zwracajaca gestosc substancji
};

extern std::vector<TSubstance>substancje; // deklaracja wektora substancji

