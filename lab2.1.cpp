#include <iostream>
#include <string.h>
using namespace std;

class Elev
{
    char Nume[20];
    char Prenume [20];
    double nAdmitere;
    double nM;
    double nR;
  public:
    Elev()=default;
    Elev(const Elev&)=default;
    Elev(Elev&&)=default;
    Elev operator=(const Elev& n)
    {
        strcpy(Nume,n.Nume);
        strcpy(Prenume,n.Prenume);
        nAdmitere=n.nAdmitere;
        nM=n.nM;
        nR=n.nR;
        return *this;
    }
    bool operator<(Elev n)
    {
        bool adv=false;
        if(nAdmitere<n.nAdmitere)
        {
            adv=true;
        }
        else if(nAdmitere>n.nAdmitere)
        {
            adv=false;
        }
        else if(nAdmitere=n.nAdmitere)
        {
            if(nM<n.nM)
            {
                adv=true;
            }
            else if(nM>n.nM)
            {
                adv=false;
            }
            else if(nM=n.nM)
            {
                if(nR<n.nR)
                {
                    adv=true;
                }
                else if(nR>n.nR)
                {
                    adv=false;
                }
            }
        }
        return adv;
    }
    bool operator==(Elev n)
    {
        bool adv;
        if(nAdmitere==n.nAdmitere && nM==n.nM && nR==n.nR)
        {
            adv=true;
        }
        else
        {
            adv=false;
        }
        return adv;
    }
    friend istream& operator>>(istream&,Elev&);
    friend ostream& operator<<(ostream&,Elev);
};
istream& operator>>(istream& is,Elev& n)
{
    is>>n.Nume;
    is>>n.Prenume;
    is>>n.nAdmitere;
    is>>n.nM;
    is>>n.nR;
    return is;
}
ostream& operator<<(ostream& os, Elev n)
{
    os<<n.Nume<<" "<<n.Prenume;
    return os;
}



int main()
{
    int n;
    cin>>n;
    Elev *e=new Elev[n];
    for(int i=0;i<n;++i)
    {
        cin>>e[i];
    }
    Elev aux;
    int ord;
    do{
        ord=1;
        for(int i=0;i<n;++i)
        {
            if(e[i]<e[i+1])
            {
                ord=0;
                aux=e[i];
                e[i]=e[i+1];
                e[i+1]=aux;
            }
        }
    }while(ord==0);
    ord=1;
    cout<<"Locul 1:"<<endl;
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            cout<<e[i]<<endl;
        }
        else
        {
            if(e[i]==e[i-1] && ord<4)
            {
                cout<<e[i]<<endl;
            }
            else
            {
                ord++;
                if(ord<4)
                {
                    cout<<"Locul "<<ord<<":"<<endl;
                    cout<<e[i]<<endl;
                }
            }
        }
    }
    delete []e;
    e=NULL;
    return 0;
}