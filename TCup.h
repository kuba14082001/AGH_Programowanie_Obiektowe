#pragma once
#include <iostream>
#include <vector>

#include "TSubstance.h"

class TCup	//klasa kubka
{
	std::vector<TSubstance>		substances;		//wektor substancji
	std::vector<double>			volumes;		//wektor objetosci substancji


public:
	void add(TSubstance substance, double volume_in_ml);	//metoda dodająca substancję do kubka o określonej objętości
	void add(std::string nazwa, double volume_in_ml);		//metoda dodająca substancję, określoną przez nazwę, do kubka o określonej objętości.

	void show();						//metoda wyświetlająca zawartość kubka

	int identyfikator(std::string nazwa, std::vector<TSubstance> substances_buffer);	//metoda zwracająca identyfikator substancji

	void add_prc(std::string nazwa, int procent);				//metoda dodająca substancję, określoną przez nazwę, do kubka o określonym procentowym udziale w objętości kubka
	void add_prc_m(std::string nazwa, int procent);				//metoda dodająca substancję, określoną przez nazwę, do kubka o określonym procentowym udziale w masie kubka

	void zlewanie(TCup* kubek_zlewany);							//metoda zlewająca zawartość kubka z innym kubkiem

};