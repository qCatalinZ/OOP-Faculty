#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class Autovehicul
{
	char marca[20];
	char model[10];
	int cc;
	short int nr_locuri;
	char culoare[15];
	long int km;
	char nrmat[10];
	int an;
public:
	Autovehicul() = default;
	Autovehicul(const Autovehicul&) = default;
	Autovehicul(Autovehicul&&) = default;
	friend istream& operator>>(istream&, Autovehicul&);
	friend ostream& operator<<(ostream&, Autovehicul);
	void verificare(char* colorC, int cc1, int cc2)
	{
		short int n;
		n = strlen(colorC);
		bool a = true;
		for (short int i = 0; i < n; ++i)
		{
			if (colorC[i] != culoare[i])
			{
				a = false;
				break;
			}
		}
		if (a)
		{
			if (cc1 < cc && cc < cc2)
				cout << nrmat<<endl;
		}
	}
	void jud(char* j, int &t)
	{
		short int aj;
		aj = strlen(j);
		bool a = true;
		for (short int i = 0; i < aj; ++i)
		{
			if (j[i] != nrmat[i])
			{
				a = false;
				break;
			}
		}
		if (a)
		{
			t = min(t, an);
		}

	}
	void mar(int& t, char* j)
	{
		short int aj;
		aj = strlen(j);
		bool a = true;
		for (short int i = 0; i < aj; ++i)
		{
			if (j[i] != nrmat[i])
			{
				a = false;
				break;
			}
		}
		if (t == an && a==true)
			cout << marca << endl;
		t = 0;
	}



};

istream& operator>>(istream& is, Autovehicul& car)
{
//	cout << "citeste marca"<<endl;
	is >> car.marca;
//	cout << "citeste modelul"<<endl;
	is >> car.model;
//	cout << "citeste capacitate cilindrica"<<endl;
	is >> car.cc;
//	cout << "citeste nr_locuri"<<endl;
	is >> car.nr_locuri;
//	cout << "citeste culoare" << endl;
	is >> car.culoare;
//	cout << "citeste km" << endl;
	is >> car.km;
//	cout << "citeste nr matricol" << endl;
	is >> car.nrmat;
//	cout << "citeste an" << endl;
	is >> car.an;
	return is;
}
ostream& operator<<(ostream& os, Autovehicul car)
{
	os << car.marca;
	os << car.model;
	os << car.cc;
	os << car.nr_locuri;
	os << car.culoare;
	os << car.km;
	os << car.nrmat;
	os << car.an;
	return os;
}



int main()
{
	int n;
	cin >> n;
	Autovehicul car[100];
	for (short int i = 0; i < n; ++i)
	{
		cin >> car[i];
	}
	char colorC[15];
	cin >> colorC;
	int cc1, cc2;
	cin >> cc1 >> cc2;

	for (short int i = 0; i < n; ++i)
	{
		car[i].verificare(colorC, cc1, cc2);
	}




	return 0;
}