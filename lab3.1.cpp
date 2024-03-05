#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

class Container
{
protected:

//    double grosime=1;
    double D1=0;

public:

    Container(){}

    Container(const double &z):D1(z){}

    virtual double Masa()=0;

    friend istream& operator>>(istream&,Container&);

    virtual ~Container()=default;

    void SetD1(const double &z)
    {
        D1=z;
    }

};

class ContainerParalelipiped: public Container
{
    double lungime=0;
    double latime=0;
    double inaltime=0;

public:

    ContainerParalelipiped():Container(){}

    ContainerParalelipiped(const double &a, const double &b,const double &c, const double &z):Container(a),lungime(b),latime(c),inaltime(z){}

    double Masa() override
    {
        return (2*(lungime*latime+latime*inaltime+lungime*inaltime)*D1);
    }

    friend istream& operator>>(istream&,ContainerParalelipiped&);

    ~ContainerParalelipiped()override=default;

};

istream& operator>>(istream& is,ContainerParalelipiped& n)
{
    is>>n.lungime;
    is>>n.latime;
    is>>n.inaltime;
    return is;
}

class ContainerCub: public Container
{
    double latura=0;

public:

    ContainerCub():Container(){}

    ContainerCub(const double &a, const double &b):Container(a),latura(b){}

    double Masa() override
    {
        return (6*latura*latura*D1);
    }

    friend istream& operator>>(istream&,ContainerCub&);

    ~ContainerCub()override=default;

};

istream& operator>>(istream& is,ContainerCub& n)
{
    is>>n.latura;
    return is;
}

class ContainerCilindru:public Container
{
    double raza=0;
    double inaltime=0;

public:

    ContainerCilindru():Container(){}

    ContainerCilindru(const double &a, const double &b, const double &c):Container(a),raza(b),inaltime(c){}

    double Masa() override
    {
        return (2*M_PI*raza*(raza+inaltime)*D1);
    }

    friend istream& operator>>(istream&,ContainerCilindru&);

    ~ContainerCilindru()override=default;
};

istream& operator>>(istream& is,ContainerCilindru& n)
{
    is>>n.raza;
    is>>n.inaltime;
    return is;
}

class ContainerSfera: public Container
{
    double raza=0;

public:

    ContainerSfera():Container(){}

    ContainerSfera(const double &a, const double &b):Container(a),raza(b){}

    double Masa() override
    {
        return (4*M_PI*raza*raza*D1);
    }

    friend istream& operator>>(istream&,ContainerSfera&);

    ~ContainerSfera()override=default;

};

istream& operator>>(istream& is,ContainerSfera& n)
{
    is>>n.raza;
    return is;
}

int main()
{
    double greu=0;
    int n;
    cin>>n;
    Container *ListaContainer[300];
    for(int i=0;i<n;++i)
    {
        double densitate;
        char TipContainer[14];
        cin>>densitate;

        cin>>TipContainer;
        if(TipContainer[0]=='P') // PARALELIPIPED
        {
            ListaContainer[i]=new ContainerParalelipiped();
            ListaContainer[i]->SetD1(densitate);
            cin>>(ContainerParalelipiped&)*ListaContainer[i];
            greu=max(greu,ListaContainer[i]->Masa());
        }
        if(TipContainer[0]=='S') // SFERA
        {
            ListaContainer[i]=new ContainerSfera();
            ListaContainer[i]->SetD1(densitate);
            cin>>(ContainerSfera&)*ListaContainer[i];
            greu=max(greu,ListaContainer[i]->Masa());
        }
        if(TipContainer[0]=='C')
        {
            if(TipContainer[1]=='U') // CUB
            {
                ListaContainer[i]=new ContainerCub();
                ListaContainer[i]->SetD1(densitate);
                cin>>(ContainerCub&)*ListaContainer[i];
                greu=max(greu,ListaContainer[i]->Masa());
            }
            else                        // CILINDRU
            {
                ListaContainer[i]=new ContainerCilindru();
                ListaContainer[i]->SetD1(densitate);
                cin>>(ContainerCilindru&)*ListaContainer[i];
                greu=max(greu,ListaContainer[i]->Masa());
            }
        }
    }

    cout<<int(greu);
    greu=greu-int(greu);
    greu=greu*10000;
    if(int(greu)%10>=5)
        greu=greu+10;
    greu=int(greu)/10;
    cout<<'.'<<int(greu);

    return 0;
}