#include <iostream>
#include <cmath>
using namespace std;

class OperatiuneBancara
{
protected:
	double SUMA_OP = 0;
	int DATA_TRANZ = 0;
public:
	OperatiuneBancara() = default;
	OperatiuneBancara(double a, int b):SUMA_OP(a),DATA_TRANZ(b){}
	virtual ~OperatiuneBancara(){}

	virtual double RetragereSuma() = 0; // fara taxe

	virtual void PrimesteSuma() = 0; // se modifica
	
};

class AlimetareCont : public OperatiuneBancara
{
public:
	AlimetareCont() = default;
	AlimetareCont(double a, int b):OperatiuneBancara(a,b){}
	~AlimetareCont(){}

	double RetragereSuma()
	{
		return SUMA_OP;
	}
	void PrimesteSuma()
	{

	}

	friend istream& operator>>(istream&, AlimetareCont&);
};

istream& operator>>(istream& is, AlimetareCont& n)
{
	is >> n.SUMA_OP;
	is >> n.DATA_TRANZ;
	return is;
}

class  DepozitConstituire : public OperatiuneBancara
{
public:
	DepozitConstituire() = default;
	DepozitConstituire(double a, int b):OperatiuneBancara(a,b) {}
	~DepozitConstituire(){}

	double RetragereSuma()
	{
		return SUMA_OP;
	}
	void PrimesteSuma()
	{

	}


	friend istream& operator>>(istream&, DepozitConstituire&);
};

istream& operator>>(istream& is, DepozitConstituire& n)
{
	is >> n.SUMA_OP;
	is >> n.DATA_TRANZ;
	return is;
}

class  DepozitScadenta : public OperatiuneBancara
{
	double DOBANDA_ANUALA = 0;
	int PERIOADA_DEPOZITULUI = 0;
public:
	DepozitScadenta() = default;
	DepozitScadenta(double a, int b, double c, int d):OperatiuneBancara(a, b),DOBANDA_ANUALA(c),PERIOADA_DEPOZITULUI(d){}
	~DepozitScadenta(){}

	double RetragereSuma()
	{
		return SUMA_OP;
	}
	void PrimesteSuma()
	{

	}

	friend istream& operator>>(istream&, DepozitScadenta&);
};

istream& operator>>(istream& is, DepozitScadenta& n)
{
	is >> n.SUMA_OP;
	is >> n.DATA_TRANZ;
	is >> n.DOBANDA_ANUALA;
	is >> n.PERIOADA_DEPOZITULUI;
	return is;
}

class  PlataCredit : public OperatiuneBancara
{
	int DATA_PLATA = 0;
	double DOBANDA_ANUALA = 0;
public:
	PlataCredit() = default;
	PlataCredit(double a, int b, int c, double d):OperatiuneBancara(a, b),DATA_PLATA(c),DOBANDA_ANUALA(d){}
	~PlataCredit(){}

	double RetragereSuma()
	{
		return SUMA_OP;
	}
	void PrimesteSuma()
	{

	}

	friend istream& operator>>(istream&, PlataCredit&);

};

istream& operator>>(istream&is, PlataCredit&n)
{
	is >> n.SUMA_OP;
	is >> n.DATA_TRANZ;
	is >> n.DATA_PLATA;
	is >> n.DOBANDA_ANUALA;
	return is;
}


int main()
{
	int n;
	cin >> n;
	OperatiuneBancara* Operatiuni[300];
	char s[3];
	double m = 0;
	int z;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		if (s[0] == 'A')
		{
			Operatiuni[i] = new AlimetareCont();
			cin >> (AlimetareCont&)*Operatiuni[i];
			/*
			if (m < Operatiuni[i]->RetragereSuma())
			{
				m = max(m, Operatiuni[i]->RetragereSuma());
				z = i+1;
			}
			*/
		}
		else if (s[0] == 'D' && s[1] == 'C')
		{
			Operatiuni[i] = new DepozitConstituire();
			cin >> (DepozitConstituire&)*Operatiuni[i];

			if (m < Operatiuni[i]->RetragereSuma())
			{
				m = max(m, Operatiuni[i]->RetragereSuma());
				z = i+1;
			}
		}
		else if (s[0] == 'D' && s[1] == 'S')
		{
			Operatiuni[i] = new DepozitScadenta();
			cin >> (DepozitScadenta&)*Operatiuni[i];

			if (m < Operatiuni[i]->RetragereSuma())
			{
				m = max(m, Operatiuni[i]->RetragereSuma());
				z = i+1;
			}
		}
		else if (s[0] == 'P')
		{
			Operatiuni[i] = new PlataCredit();
			cin >> (PlataCredit&)*Operatiuni[i];

			if (m < Operatiuni[i]->RetragereSuma())
			{
				m = max(m, Operatiuni[i]->RetragereSuma());
				z = i+1;
			}
		}
	}
	cout << z;

	return 0;
}