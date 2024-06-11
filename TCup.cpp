#include "TCup.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml)
{
	int count = substances.size();
	int g = 0;

	for (int i = 0; i < count; i++)
	{
		if (substances[i].get_name() == substance.get_name())
		{
			volumes[i] = volumes[i] + (volume_in_ml / 1e6);
			g = 0;
			break;
		}
		g += 1;
	}
	if (g == count)
	{
		substances.push_back(substance);

		volumes.push_back(volume_in_ml / 1e6);
	}
}

void TCup::add_prc(string nazwa, int procent)
{
	int id_ = identyfikator(nazwa, substances);		
	int idd_ = identyfikator(nazwa, substancje);	

	int count = substances.size();
	double obj_kubka = 0;
	double obj_kubka_p = 0;
	double obj_cieczy = 0;
	double prc_innych = 1.0 - (double(procent) / 100);
	double prc_cieczy = double(procent) / 100;

	for (int i = 0; i < count; i++)
	{
		obj_kubka = obj_kubka + volumes[i] * 1e6;
	}


	if (id_ >= 0)
	{
		obj_kubka_p = obj_kubka - volumes[id_] * 1e6;
		obj_cieczy = (obj_kubka_p * prc_cieczy) / prc_innych - (volumes[id_] * 1e6);
		if (obj_cieczy > 0) { this->add(substancje[idd_], obj_cieczy); }
		else if (obj_cieczy < 0) { cout << "\nOverflow error \"" << nazwa << "\" przekracza pozadana obejtosc, nie da sie jej dolac!!! \n\n"; }

	}
	else if (id_ < 0)	
	{
		obj_cieczy = (obj_kubka * prc_cieczy) / prc_innych;
		this->add(substancje[idd_], obj_cieczy);

	}
}

void TCup::add_prc_m(string nazwa, int procent)
{
	int id_ = identyfikator(nazwa, substances);		
	int idd_ = identyfikator(nazwa, substancje);	
	int count = substances.size();

	double masa_kubka = 0;
	double masa_kubka_p = 0;
	double masa_cieczy = 0;

	double prc_innych = 1.0 - (double(procent) / 100);
	double prc_cieczy = double(procent) / 100;

	for (int i = 0; i < count; i++)
	{
		masa_kubka = masa_kubka + substances[i].get_ro() * volumes[i] * 1000;
	}



	if (id_ >= 0) 
	{
		masa_kubka_p = masa_kubka - substancje[idd_].get_ro() * volumes[id_] * 1000;
		masa_cieczy = (masa_kubka_p * prc_cieczy) / prc_innych - (substancje[idd_].get_ro() * volumes[id_] * 1000);
		if (masa_cieczy > 0) { this->add(substancje[idd_], (masa_cieczy * 1000) / substancje[idd_].get_ro()); }
		else if (masa_cieczy < 0) { cout << "\nOverflow error \"" << nazwa << "\" przekracza pozadana obejtosc, nie da sie jej dolac!!! \n\n"; }

	}
	else if (id_ < 0)	
	{
		masa_cieczy = (masa_kubka * prc_cieczy) / prc_innych;
		this->add(substancje[idd_], (masa_cieczy * 1000) / substancje[idd_].get_ro());

	}

}

void TCup::zlewanie(TCup* kubek_zlewany)
{
	int count = kubek_zlewany->substances.size();
	for (int i = 0; i < count; i++)
	{
		this->add(kubek_zlewany->substances[i].get_name(), kubek_zlewany->volumes[i] * 1e6);
		kubek_zlewany->volumes[i] = 0;
	}
	
}

void TCup::add(string nazwa, double volume_in_ml)
{
	int id_ = identyfikator(nazwa, substancje);
	if (id_ >= 0)
	{
		this->add(substancje[id_], volume_in_ml);
	}
	else
	{
		cout << "Nie ma takiej cieczy" << endl;
	}

}

void TCup::show()
{
	double obj_kubka = 0;
	double masa_kubka = 0;
	int count = substances.size();


	for (int i = 0; i < count; i++)
	{
		obj_kubka = obj_kubka + volumes[i] * 1e6;
	}

	for (int i = 0; i < count; i++)
	{
		masa_kubka = masa_kubka + substances[i].get_ro() * volumes[i] * 1000;
	}

	if (obj_kubka != 0)
	{
		for (int i = 0; i < count; i++)
		{

			double mass = substances[i].get_ro() * volumes[i] * 1000;
			cout << substances[i].get_name() << ";\t volume: " << volumes[i] * 1e6 << " ml" << ";\t mass: " << mass << " g;\t V_prc: " << ((volumes[i] * 1e6) / obj_kubka) * 100 << " %;\t";
			cout << "M_prc: " << (mass / masa_kubka) * 100 << " %\n";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << substances[i].get_name() << ";\t volume: 0" << " ml" << ";\t mass: 0" << " g;\t V_prc: 0 %;\t";
			cout << "M_prc: 0 %\n";
		}
		cout << "\n";

	}
}

int TCup::identyfikator(std::string nazwa, vector<TSubstance> substances_buffer)
{
	int count = substances_buffer.size();
	int id_ = -1;
	int fl = 0;

	for (int i = 0; i < count; i++)
	{
		string sub_name = substances_buffer[i].get_name();
		if (sub_name == nazwa)
		{
			id_ = i;
			i = count;

		}
		else
		{
			fl++;
		}

		if (fl == 4)
		{
			id_ = -1;
			i = count;
		}

	}
	return id_;
}



