#include <iostream>
using namespace std;

class Vagon
{
    double Distanta;
public:
    Vagon():Distanta(0){}
    Vagon(double d):Distanta(d){}
    Vagon(const Vagon& n):Distanta(n.Distanta){}

    friend istream& operator>>(istream&, Vagon&);

    virtual double Cost()=0;

    double TrimiteDistanta()
    {
        return Distanta;
    }

    virtual ~Vagon(){}
};

istream& operator>>(istream &is, Vagon &n)
{
    is>>n.Distanta;
    return is;
}

class VagonMarfa: virtual public Vagon
{
    double Greutate;
public:
    VagonMarfa():Vagon(0),Greutate(0){}
    VagonMarfa(double d, double g):Vagon(d),Greutate(g){}
    VagonMarfa(const VagonMarfa &n):Vagon(n),Greutate(n.Greutate){}

    friend istream& operator>>(istream&, VagonMarfa&);

    double Cost()
    {
        double CalculCost,x;
        x=TrimiteDistanta();
        CalculCost=Greutate*x;
      //  cout<<"Costul vagonului este: "<<CalculCost<<endl;
        return CalculCost;
    }

    virtual ~VagonMarfa(){}

};

istream& operator>>(istream &is, VagonMarfa &n)
{
    is>>(Vagon&)n;
    is>>n.Greutate;
    return is;
}

class VagonCalatori: virtual public Vagon
{
    int NrPasageri;
public:
    VagonCalatori():Vagon(0),NrPasageri(0){}
    VagonCalatori(double d, int n):Vagon(d),NrPasageri(n){}
    VagonCalatori(const VagonCalatori &n):Vagon(n),NrPasageri(n.NrPasageri){}

    int TrimiteNrPasageri()
    {
        return NrPasageri;
    }

    friend istream& operator>>(istream&, VagonCalatori&);

    double Cost()
    {
        double CalculCost,x;
        x=TrimiteDistanta();
        CalculCost=NrPasageri*x;
       // cout<<"Costul vagonului este: "<<CalculCost<<endl;
        return CalculCost;
    }

    virtual ~VagonCalatori(){}
};

istream& operator>>(istream &is, VagonCalatori &n)
{
    is>>(Vagon&)n;
    is>>n.NrPasageri;
    return is;
}

class VagonDormit: public VagonCalatori
{
    double SporVD;
public:
    VagonDormit():VagonCalatori(0,0),SporVD(0){}
    VagonDormit(double d, int n, double s):VagonCalatori(d,n),SporVD(s){}
    VagonDormit(const VagonDormit &n):VagonCalatori(n),SporVD(n.SporVD){}

    friend istream& operator>>(istream&, VagonDormit&);

    int TrimiteNrPasageri()
    {
        int x=VagonCalatori::TrimiteDistanta();
        return x;
    }

    double Cost()
    {
        double CalculCost,x,y;
        x=TrimiteDistanta();
        y=TrimiteNrPasageri();
        CalculCost=SporVD*x*y;
     //   cout<<"Costul vagonului este: "<<CalculCost<<endl;
        return CalculCost;
    }

    virtual ~VagonDormit(){}
};

istream& operator>>(istream &is, VagonDormit &n)
{
    is>>(VagonCalatori&)n;
    is>>n.SporVD;
    return is;
}

double CalculTipVagon(int Tip)
{
    if(Tip==1)
    {
        VagonMarfa a;
        cin>>a;
        return a.Cost();
    }
    if(Tip==2)
    {
        VagonCalatori b;
        cin>>b;
        return b.Cost();
    }
    if(Tip==3)
    {
        VagonDormit c;
        cin>>c;
        return c.Cost();
    }
//    return Cost();
}

int main()
{
    int NrVagoane,Tip;

    double Tren=0;

    cin>>NrVagoane;

    for(int i=0;i<NrVagoane;++i)
    {
        cin>>Tip;
        double z;
        z=CalculTipVagon(Tip);
        Tren=Tren+z;
    }
    cout<<"Costul trenului este: "<<Tren<<endl;
    return 0;
}
