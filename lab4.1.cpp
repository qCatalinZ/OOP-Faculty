#include <iostream>
#include <string.h>
using namespace std;


class Persoana
{
protected:
	char Nume[30];
	int an_nastere = 0;
public:
	friend istream& operator>>(istream&, Persoana&);
	Persoana() = default;

	void AfisareNume()
	{
		cout << Nume << " ";
	}
};

class Profesor : public Persoana
{
	int NrCursuri = 0;
	string id[10]; // int ??
public:
	Profesor() = default;
	friend istream& operator>>(istream&, Profesor&);
};

istream& operator>>(istream& is, Profesor& n)
{
	is >> n.Nume;
	is >> n.an_nastere;
	is >> n.NrCursuri;
	for (int i = 0; i < n.NrCursuri; ++i)
	{
		is >> n.id[i];
	}
	return is;
}

class Student : public Persoana
{
	int an_licenta = 0;
	int NrCursuri = 0;
	string id[30];
	int NoteCurs[30];
public:
	Student() = default;
	friend istream& operator>>(istream&, Student&);

	int TrimiteNoteCurs(int i)
	{
		return NoteCurs[i];
	}
	string Trimiteid(int i)
	{
		return id[i];
	}
	int TrimiteNrCursuri()
	{
		return NrCursuri;
	}


	

	void AfisareNume()
	{
		Persoana::AfisareNume();
	}

};

istream& operator>>(istream& is, Student& n)
{
	is >> n.Nume;
	is >> n.an_nastere;
	is >> n.an_licenta;
	is >> n.NrCursuri;
	for (int i = 0; i < n.NrCursuri; ++i)
	{
		is >> n.id[i];
	}
	for (int i = 0; i < n.NrCursuri; ++i)
	{
		is >> n.NoteCurs[i];
	}
	return is;
}

class Curs
{

	string idCurs;
	char nume[50];
	int pct_credit = 0;
	int an_studiu = 0;
public:

	Curs() = default;
	friend istream& operator>>(istream&, Curs&);
	string TrimiteidCurs()
	{
		return idCurs;
	}
	int TrimitePct_Credit()
	{
		return pct_credit;
	}
};
istream& operator>>(istream& is, Curs& n)
{
	is >> n.idCurs;
	is >> n.nume;
	is >> n.pct_credit;
	is >> n.an_studiu;
	return is;
}



int main()
{
	int n;
	cin >> n;
	Profesor* listaProfesor = new Profesor[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> listaProfesor[i];
	}

	int m;
	cin >> m;
	Student* listaStudent =new Student[m];

	for (int i = 0; i < m; ++i)
	{

		cin >>listaStudent[i];
	}
	int k;
	cin >> k;
	Curs* listaCurs = new Curs[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> listaCurs[i];
	}

	for (int i = 0; i < m; i++)
	{
		int puncte = 0;
		int x=listaStudent[i].TrimiteNrCursuri();
		for (int j = 0; j < x; j++)
		{
			for (int z = 0; z < k; z++)
			{
				if (listaStudent[i].Trimiteid(j) == listaCurs[z].TrimiteidCurs())
				{
					if (listaStudent[i].TrimiteNoteCurs(j) >= 5)
						puncte = puncte + listaCurs[z].TrimitePct_Credit();
				}
			}
		}
		if (puncte < 20)
			listaStudent[i].AfisareNume();
	}



	delete[] listaProfesor;
	delete[] listaStudent;
	delete[] listaCurs;


	return 0;
}