#include <iostream>
#include <fstream>

#define Ld1 100
#define Ld2 1000
#define Ld3 5000
#define Ld4 100

using namespace std;

struct coord2D
{
    double x;
    double y;
};

istream& operator>>(istream& is, coord2D& c)
{
    is>>c.x>>c.y;
    return is;
}

class forma
{
    int nrVf;
    coord2D* vf;
    double densitate;
    char material; // codat: 0=plastic, 1=Al, 2=Fe
public:

    forma()=default;

    forma(int nrV, coord2D* v)
    {
        nrVf=nrV;
        vf= new coord2D[nrVf];
        for(int i=0;i<nrVf;++i)
            vf[i]=v[i];
    }

    forma(const forma& f)
    {
        nrVf=f.nrVf;
        vf=new coord2D[nrVf];
        for(int i=0; i<nrVf;++i)
            vf[i]=f.vf[i];
    }
    virtual ~forma()
    {
        if(vf)
            delete[] vf;
    }
    friend istream& operator>>(istream&, forma&);
};

istream& operator>>(istream& is,forma& f)
{
    is>>f.nrVf;
    f.vf=new coord2D[f.nrVf];
    for(int i=0;i<f.nrVf;++i)
        is>>f.vf[i];
    return is;
}

class triunghi: public forma
{
public:
    triunghi()=default;
    triunghi(coord2D* v):forma(3,v)
    {
    }

    triunghi(const triunghi& c):forma(c)
    {
    }
};

class dreptunghi: public forma
{
public:
    dreptunghi()=default;
    dreptunghi(coord2D* v):forma(4,v)
    {
    }

    dreptunghi(const dreptunghi& c):forma(c)
    {
    }
};

class patrat: public dreptunghi
{
public:
    patrat()=default;
    patrat(coord2D* v):dreptunghi(v)
    {
    }

    patrat(const patrat& c):dreptunghi(c)
    {
    }
};

class cerc: public forma
{
    double raza;
public:
    cerc()=default;
    cerc(coord2D* v):forma(1,v)
    {
    }
    cerc(const cerc& c):forma(c)
    {
        raza=c.raza;
    }
};
//citire pt fiecare clasa
int main()
{
    ifstream cin("data.txt");

    double p1,p2,g;
    int no,i, tip;
    coord2D* listaVf;
    forma* listaOb[20];

    cin>>p1>>p2>>g>>no;

    for(int i=0; i<no;i++)
    {
        cin>>tip;
        switch(tip)
        {
            case 1:
                listaOb[i]=new triunghi;
                cin>>&((triunghi*)listaOb[i]);
                cout<<(triunghi*)listaOb[i];
                break;
        }

    }

    return 0;
}
