#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>
///#define PI 3.14159265358979323846
using namespace std;


class Container
{
protected:

    double D1=0;
    double D2=0;
    double grosime=1;

public:

    Container(){}

    Container(const double &x,const double &y):D1(x),D2(y){}

    virtual double MasaProprie()=0;

    virtual double VolumContainer()=0;

    virtual double MasaLichid()=0;

    virtual void ThicknessCheck()=0;

    virtual double MasaTotala()=0;

    friend istream& operator>>(istream&,Container&);

    virtual ~Container()=default;

    void SetD1(const double &z)
    {
        D1=z;
    }

    void SetD2(const double &p)
    {
        D2=p;
    }

};


class ContainerParalelipiped: public Container
{
    double a=0;     // lungime
    double b=0;     // latime
    double c=0;     // inaltime

public:

    ContainerParalelipiped():Container(){}

    ContainerParalelipiped(const double &q, const double &w, const double &e, const double &r, const double &t):Container(q,w),a(e),b(r),c(t){}

    double MasaProprie() override
    {
        return 2*(a*b+a*c+b*c)*grosime*D1;
    }

    double VolumContainer() override
    {
        return a*b*c;
    }

    double MasaLichid() override
    {
        return VolumContainer()*D2;
    }

    void ThicknessCheck() override
    {
        if(MasaProprie()<(0.2*MasaLichid()))
        {
            grosime=MasaLichid()*0.2;
            double x=2*(a*b+a*c+b*c)*D1;
            grosime=grosime/x;
        }
    }

    double MasaTotala() override
    {
        return (MasaProprie()+MasaLichid());
    }

    friend istream& operator>>(istream&,ContainerParalelipiped&);

    ~ContainerParalelipiped()override=default;

};

istream& operator>>(istream& is,ContainerParalelipiped& n)
{
    is>>n.a;
    is>>n.b;
    is>>n.c;
    return is;
}

class ContainerCub: public Container /// problema
{
    double a=0;    // latura

public:

    ContainerCub():Container(){}

    ContainerCub(const double &x, const double &y, const double &z):Container(x,y),a(z){}

    double MasaProprie() override
    {
        return 6*a*a*D1*grosime;
    }

    double VolumContainer() override
    {
        return a*a*a;
    }

    double MasaLichid() override
    {
        return VolumContainer()*D2;
    }

    void ThicknessCheck() override
    {
        if(MasaProprie()<0.2*MasaLichid())
        {
            grosime=0.2*MasaLichid();
            double o=6*a*a*D1;
            grosime=grosime/o;
        }
    }

    double MasaTotala() override
    {
        return (MasaProprie()+MasaLichid());
    }

    friend istream& operator>>(istream&,ContainerCub&);

    ~ContainerCub()override=default;

};

istream& operator>>(istream& is,ContainerCub& n)
{
    is>>n.a;
    return is;
}

class ContainerCilindru:public Container
{
    double r=0;             // raza
    double h=0;             // inaltimea

public:

    ContainerCilindru():Container(){}

    ContainerCilindru(const double &a, const double &x, const double &b,const double &c):Container(a,x),r(b),h(c){}

    double MasaProprie() override
    {
        return 2*M_PI*r*(r+h)*grosime*D1;
    }

    double VolumContainer() override
    {
        return M_PI*r*r*h;
    }

    double MasaLichid() override
    {
        return VolumContainer()*D2;
    }

    void ThicknessCheck() override
    {
        if(MasaProprie()<(0.2*MasaLichid()))
        {
            grosime=MasaLichid()*0.2;
            double x=2*M_PI*r*(r+h)*D1;
            grosime=grosime/x;
        }
    }

    double MasaTotala() override
    {
        return (MasaProprie()+MasaLichid());
    }

    friend istream& operator>>(istream&,ContainerCilindru&);

    ~ContainerCilindru()override=default;
};

istream& operator>>(istream& is,ContainerCilindru& n)
{
    is>>n.r;
    is>>n.h;
    return is;
}

class ContainerSfera: public Container
{
    double r=0;     // raza

public:

    ContainerSfera():Container(){}

    ContainerSfera(const double &a, const double &x, const double &b):Container(a,x),r(b){}

    double MasaProprie() override
    {
        return 4*M_PI*r*r*grosime*D1;
    }

    double VolumContainer() override
    {
        return (4*M_PI*r*r*r)/3;
    }

    double MasaLichid() override
    {
        return VolumContainer()*D2;
    }

    void ThicknessCheck() override
    {
        if(MasaProprie()<(0.2*MasaLichid()))
        {
            grosime=MasaLichid()*0.2;
            double x=4*M_PI*r*r*D1;
            grosime=grosime/x;
        }
    }

    double MasaTotala() override
    {
        return (MasaProprie()+MasaLichid());
    }

    friend istream& operator>>(istream&,ContainerSfera&);

    ~ContainerSfera()override=default;

};

istream& operator>>(istream& is,ContainerSfera& n)
{
    is>>n.r;
    return is;
}

/*
void AfisareVector(double *c, const int &n)
{
    for(int i=0; i<n;++i)
    {
        cout<<int(c[i]);
        c[i]=c[i]-int(c[i]);
        c[i]=c[i]*10000;
        if(int(c[i])%10>4)
            c[i]=c[i]+10;
        c[i]=int(c[i])/10;
        cout<<'.'<<int(c[i])<<" ";
    }
}
*/
void BubbleSort(double *c, const int &n)
{
    bool ordonat;
    do
    {
        ordonat=true;
        for(int i=0;i<n;++i)
        {
            if(c[i]<c[i+1])
            {
                ordonat=false;
                double aux=c[i];
                c[i]=c[i+1];
                c[i+1]=aux;
            }
        }
    }while(ordonat==false);
}

void Sortare1(double *c, const int &n)
{
    if(n%4==0)
    {
        for(int i=1;i<n/2;++i)
        {
            if(i%2==0)
                continue;
            double temp=c[i];
            c[i]=c[n-i];
            c[n-i]=temp;
        }
    }
    else if(n%4==2)
    {
        for(int i=1;i<n/2-1;++i)
        {
            if(i%2==0)
                continue;
            double temp=c[i];
            c[i]=c[n-i];
            c[n-i]=temp;
        }
    }
}
/*
void Sortare2(double *c, const int &n)
{

    double *a=new double[n],*z=new double[n];
    for(int i=0;i<n;++i)
    {
        a[i]=0;
        z[i]=0;
    }
    int contorA=0,contorZ=0;
    for(int i=0;i<n/2;++i)
    {
        if(i==0 || i%2==0)
        {
            a[contorA]=c[i];
            c[i]=0;
            contorA++;
            a[contorA]=c[n-i-1];
            c[n-i-1]=0;
            contorA++;
        }
        if(i%2==1)
        {
            z[contorZ]=c[i];
            c[i]=0;
            contorZ++;
            z[contorZ]=c[n-i-1];
            c[n-i-1]=0;
            contorZ++;
        }
    }

    for(int i=0;i<n/2;++i)
    {
        double aux=z[i];
        z[i]=z[n-i-1];
        z[n-i-1]=aux;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            i=j;
            if(a[j]==0)
                break;
            c[i]=a[j];
        }
        for(int j=0;j<n;++j)
        {
            if(z[j]==0)
                continue;
            c[i]=z[j];
            i++;
        }
    }
}
*/
void afisare(double *c,const int &n)
{
    for(int i=0;i<n;++i)
    {
         cout << fixed << setprecision(3) << c[i] << " ";
    }
}

int main()
{
    int n1;
    cin>>n1;
    const int n=n1;
    double *c=new double[n];
    Container *ListaContainer[300];
    for(int i=0;i<n;++i)
    {
        double densitate1,densitate2;
        char TipContainer[15];
        cin>>densitate1>>densitate2;
        cin>>TipContainer;
        if(TipContainer[0]=='P') /// PARALELIPIPED
        {
            ListaContainer[i]=new ContainerParalelipiped();
            ListaContainer[i]->SetD1(densitate1);
            ListaContainer[i]->SetD2(densitate2);
            cin>>(ContainerParalelipiped&)*ListaContainer[i];
            ListaContainer[i]->ThicknessCheck();
            c[i]=ListaContainer[i]->MasaTotala();
        }
        else if(TipContainer[2]=='B')    /// CUB
        {
            ListaContainer[i]=new ContainerCub();
            ListaContainer[i]->SetD1(densitate1);
            ListaContainer[i]->SetD2(densitate2);
            cin>>(ContainerCub&)*ListaContainer[i];
            ListaContainer[i]->ThicknessCheck();
            c[i]=ListaContainer[i]->MasaTotala();
        }
        else if(TipContainer[1]=='I')       /// CILINDRU
        {
            ListaContainer[i]=new ContainerCilindru();
            ListaContainer[i]->SetD1(densitate1);
            ListaContainer[i]->SetD2(densitate2);
            cin>>(ContainerCilindru&)*ListaContainer[i];
            ListaContainer[i]->ThicknessCheck();
            c[i]=ListaContainer[i]->MasaTotala();
        }
        else if(TipContainer[0]=='S')    /// SFERA
        {
            ListaContainer[i]=new ContainerSfera();
            ListaContainer[i]->SetD1(densitate1);
            ListaContainer[i]->SetD2(densitate2);
            cin>>(ContainerSfera&)*ListaContainer[i];
            ListaContainer[i]->ThicknessCheck();
            c[i]=ListaContainer[i]->MasaTotala();
        }


    }

    BubbleSort(c,n);

    Sortare1(c,n);

    //Sortare2(c,n);

   // AfisareVector(c,n);

    afisare(c,n);

    delete[] c;
    return 0;
}