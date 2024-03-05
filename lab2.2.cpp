#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;


bool expresie(char *p1)
{
    for(int i=0;i<strlen(p1);++i)
        if(p1[i]!=' ')
            return true;
    return false;
}

char spatiu(char *s)
{
    bool adv=true;
    char p[200],*a;
    a=strtok(s," ");
    while(a!=NULL)
    {
        if(adv)
        {
            strcpy(p,a);
            adv=false;
        }
        else
            strcat(p,a);
        a=strtok(NULL," ");
    }
    strcpy(s,p);
}

double conversie_semn(char a)
{
    if(a=='-')
        return (-1);
    return 1;
}
double conversie_nr(char a)
{
    if(a=='0')
        return 0;
    if(a=='1')
        return 1;
    if(a=='2')
        return 2;
    if(a=='3')
        return 3;
    if(a=='4')
        return 4;
    if(a=='5')
        return 5;
    if(a=='6')
        return 6;
    if(a=='7')
        return 7;
    if(a=='8')
        return 8;
    return 9;
}



class Vector
{
    int lungimeV;
    double *elemV=nullptr;

  public:
    Vector()=default;
    Vector(const Vector&)=default;
    Vector(Vector&&)=default;
    Vector operator+(Vector n)
    {
        /*
        Vector e;
        for(int i=0;i<n.lungimeV;++i)
            e.elemV[i]=e.elemV[i]+n.elemV[i];
        return e;
        */
        if(lungimeV==n.lungimeV)
        {
            for(int i=0;i<n.lungimeV;++i)
                elemV[i]=elemV[i]+n.elemV[i];
            return *this;
        }
    }
    Vector operator-(Vector n)
    {
        if(lungimeV==n.lungimeV)
        {
            for(int i=0;i<lungimeV;++i)
                elemV[i]=elemV[i]-n.elemV[i];
            return *this;
        }
    }
    Vector operator*(Vector n)
    {
        if(lungimeV==n.lungimeV)
        {
            for(int i=0;i<lungimeV;++i)
                elemV[i]=elemV[i]*n.elemV[i];
            return *this;
        }
    }
    Vector operator/(Vector n)
    {
        if(lungimeV==n.lungimeV)
        {
            for(int i=0;i<lungimeV;++i)
                elemV[i]=elemV[i]/n.elemV[i];
            return *this;
        }
    }
    Vector operator=(Vector n)
    {
        if(lungimeV==n.lungimeV)
        {
            for(int i=0;i<lungimeV;++i)
                elemV[i]=n.elemV[i];
            return *this;
        }
        if(lungimeV!=n.lungimeV)
        {
            delete[] elemV;
            lungimeV=n.lungimeV;
            elemV=new double[n.lungimeV];
            for(int i=0;i<n.lungimeV;++i)
                elemV[i]=n.elemV[i];
            return *this;
        }
    }


    void setlungimeV()
    {
        for(int i=0;i<lungimeV;++i)
            elemV[i]=0;
    }


    friend istream& operator>>(istream&,Vector&);
    friend ostream& operator<<(ostream&,Vector);
};

istream &operator>>(istream &is, Vector &n)
{
    n.lungimeV=0;
    char s[200],p[200],*a;
    cin.get(s,200);
    cin.get();
    strcpy(p,s);
    a=strtok(s," ");
    while(a!=NULL)
    {
    	n.lungimeV++;
        a=strtok(NULL," ");
    }
    n.elemV=new double[n.lungimeV];
    int cont=0;
    a=strtok(p," ");
    while(a!=NULL)
    {
        double aux=0,impartire=10;
        bool adv=true;
        int z=strlen(a);
        double semn=conversie_semn(a[0]);
        for(int i=0;i<z;++i)
        {
            if(a[i]=='.')
                adv=false;
            if(adv==true && a[i]!='-' && a[i]!='+' && a[i]!='.')
            {
                double f=conversie_nr(a[i]);
                aux=aux*10+f;
            }
            if(adv==false && a[i]!='-' && a[i]!='+' && a[i]!='.')
            {
                double f=conversie_nr(a[i]);
                aux=aux+f/impartire;
                impartire=10*impartire;
            }
        }
        n.elemV[cont]=aux*semn;
        cont++;
        a=strtok(NULL," ");
    }
    return is;
}
ostream& operator<<(ostream& os,Vector n)
{
    for(int i=0;i<n.lungimeV;++i)
        os<<n.elemV[i]<<" ";
    return os;
}

int main()
{
    bool adv=true;
    int n;
    cin>>n;
    cin.get();
    Vector *v=new Vector[n];
    for(int i=0;i<n;++i)
        cin>>v[i];
    Vector e,h,paranteza[200];
    int contorParanteza=1;

    char s[200],p[200],*a,p1[200];
    cin.get(s,200);
    cin.get();

    for(int i=0;i<strlen(s);++i)
        if(s[i]=='V')
            s[i]=' ';
    a=strtok(s," ");
    while(a!=NULL)
    {
        if(adv)
        {
            strcpy(p,a);
            adv=false;
        }
        else
            strcat(p,a);
        a=strtok(NULL," ");
    }

    strcpy(s,p);
    for(int i=0;i<strlen(s);++i)
        if(s[i]!='(' && s[i]!=')')
            s[i]=' ';
    a=strtok(s," ");
    while(a!=NULL)
    {
        if(adv==false)
        {
            strcpy(p1,a);
            adv=true;
        }
        else
            strcat(p1,a);
        a=strtok(NULL," ");
    }
    int indice[200]={0},contor=0,semn[200],contorsemn=0;
    adv=true;
    while(expresie(p))  // trebuie sa facem vector de paranteze pe care l atribuim in p ul nostru cu indicele propriu
    {
        while(expresie(p1))
        {
            for(int i=0;i<strlen(p);++i)
            {
                if(p[i]=='(')
                {
                    contorParanteza++;
                    for(int j=(i+1);j<strlen(p);++j)
                    {
                        if(p[j]==')')
                        {
                            for(int l=i;l<=j;++l)
                                p[l]=' ';
                            p[j]='p';
                            spatiu(p);
                            if(adv)
                            {
                                e=v[indice[contor]];
                                e.setlungimeV();
                                paranteza[contorParanteza-1]=e;
                                adv=false;
                            }
                            for(int z=0;z<contorsemn;++z)
                            {
                                if(semn[z]=='*' || semn[z]=='/')
                                {
                                    if(semn[z]=='*')
                                    {
                                        h=v[indice[z]]*v[indice[z+1]];
                                        paranteza[contorParanteza-1]=h+paranteza[contorParanteza-1];
                                    }
                                    if(semn[z]=='/')
                                    {
                                        h=v[indice[z]]/v[indice[z+1]];
                                        paranteza[contorParanteza-1]=h+paranteza[contorParanteza-1];
                                    }
                                }
                                if((semn[z]=='+' || semn[z]=='-') && ((semn[z+1]=='+' || semn[z+1]=='-') || (semn[z+1]!='*' && semn[z+1]!='/')))
                                {
                                    if(semn[z]=='+')
                                    {
                                        paranteza[contorParanteza-1]=paranteza[contorParanteza-1]+v[indice[z]];
                                        paranteza[contorParanteza-1]=paranteza[contorParanteza-1]+v[indice[z+1]];
                                    }
                                    if(semn[z]=='-')
                                    {
                                        paranteza[contorParanteza-1]=paranteza[contorParanteza-1]-v[indice[z]];
                                        paranteza[contorParanteza-1]=paranteza[contorParanteza-1]-v[indice[z+1]];
                                    }
                                }

                                if((semn[z]=='+' || semn[z]=='-') && (semn[z+1]=='*' || semn[z+1]=='/'))
                                {
                                    if(semn[z+1]=='*')
                                    {
                                        h=v[indice[z+1]]*v[indice[z+2]];
                                        if(semn[z]=='+')
                                            h=v[indice[z]]+h;
                                        if(semn[z]=='-')
                                            h=v[indice[z]]-h;
                                        z++;
                                        paranteza[contorParanteza-1]=h+paranteza[contorParanteza-1];
                                    }
                                    if(semn[z+1]=='/')
                                    {
                                        h=v[indice[z+1]]/v[indice[z+2]];
                                        if(semn[z]=='+')
                                            h=v[indice[z]]+h;
                                        if(semn[z]=='-')
                                            h=v[indice[z]]-h;
                                        z++;
                                        paranteza[contorParanteza-1]=h+paranteza[contorParanteza-1];
                                    }
                                }
                            }
                            indice[200]={0};
                            contor=0;
                            semn[200]={0};
                            contorsemn=0;
                            break;
                        }
                        if(isdigit(p[j]))
                        {
                            indice[contor]=indice[contor]*10+(int)conversie_nr(p[j]);
                        }
                        else
                        {
                            contor++;
                            semn[contorsemn]=p[j];
                            contorsemn++;
                        }
                    }
                }
            }
        }

        if(expresie(p))
        {
            for(int i=0;i<strlen(p);++i)
            {
                if(isalnum(p[i]))
                {
                    if(p[i]!='p')
                        indice[contor]=indice[contor]*10+(int)conversie_nr(p[i]);
                }
                else
                {
                    indice[contor]=-indice[contor];
                    contor++;
                    semn[contorsemn]=p[i];
                    contorsemn++;
                }
            }
            for(int i=0;i<contorsemn;++i)
            {
                if(semn[i]=='*' || semn[i]=='/')
                {
                    if(semn[i]=='*')
                    {
                        if(indice[i]>=0 && indice[i+1]>=0)
                        {
                            h=v[indice[i]]*v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]>=0 && indice[i]<0)
                        {
                            h=v[indice[i]]*paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]>=0)
                        {
                            h=paranteza[abs(indice[i])]*v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]<0)
                        {
                            h=paranteza[abs(indice[i])]*paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                    }
                    if(semn[i]=='/')
                    {
                        if(indice[i]>=0 && indice[i+1]>=0)
                        {
                            h=v[indice[i]]/v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]>=0 && indice[i]<0)
                        {
                            h=v[indice[i]]/paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]>=0)
                        {
                            h=paranteza[abs(indice[i])]/v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]<0)
                        {
                            h=paranteza[abs(indice[i])]/paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                    }
                }
                if((semn[i]=='+' || semn[i]=='-') && ((semn[i+1]=='+' || semn[i+1]=='-') || (semn[i+1]!='*' && semn[i+1]!='/')))
                {
                    if(semn[i]=='+')
                    {
                        if(indice[i]>=0 && indice[i+1]>=0)
                        {
                            h=v[indice[i]]+v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]>=0 && indice[i]<0)
                        {
                            h=v[indice[i]]+paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]>=0)
                        {
                            h=paranteza[abs(indice[i])]+v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]<0)
                        {
                            h=paranteza[abs(indice[i])]+paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                    }
                    if(semn[i]=='-')
                    {
                        if(indice[i]>=0 && indice[i+1]>=0)
                        {
                            h=v[indice[i]]-v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]>=0 && indice[i]<0)
                        {
                            h=v[indice[i]]-paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]>=0)
                        {
                            h=paranteza[abs(indice[i])]-v[indice[i+1]];
                            e=h+e;
                        }
                        if(indice[i]<0 && indice[i+1]<0)
                        {
                            h=paranteza[abs(indice[i])]-paranteza[abs(indice[i+1])];
                            e=h+e;
                        }
                    }
                }
                if((semn[i]=='+' || semn[i]=='-') && (semn[i+1]=='*' || semn[i+1]=='/'))
                {
                    if(semn[i+1]=='*')
                    {
                        if(indice[i+1]>=0 && indice[i+2]>=0)
                        {
                            h=v[indice[i+1]]*v[indice[i+2]];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]>=0 && indice[i+2]<0)
                        {
                            h=v[indice[i+1]]*paranteza[abs(indice[i+2])];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]<0 && indice[i+2]>=0)
                        {
                            h=paranteza[abs(indice[i+1])]*v[indice[i+2]];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]<0 && indice[i+2]<0)
                        {
                            h=paranteza[abs(indice[i+1])]*paranteza[abs(indice[i+2])];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                    }
                    if(semn[i+1]=='/')
                    {
                        if(indice[i+1]>=0 && indice[i+2]>=0)
                        {
                            h=v[indice[i+1]]/v[indice[i+2]];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]>=0 && indice[i+2]<0)
                        {
                            h=v[indice[i+1]]/paranteza[abs(indice[i+2])];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]<0 && indice[i+2]>=0)
                        {
                            h=paranteza[abs(indice[i+1])]/v[indice[i+2]];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                        if(indice[i+1]<0 && indice[i+2]<0)
                        {
                            h=paranteza[abs(indice[i+1])]/paranteza[abs(indice[i+2])];
                            if(semn[i]=='+')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]+h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]+h;
                            }
                            if(semn[i]=='-')
                            {
                                if(indice[i]>=0)
                                    h=v[indice[i]]-h;
                                if(indice[i]<0)
                                    h=paranteza[abs(indice[i])]-h;
                            }
                            i++;
                            e=h+e;
                        }
                    }
                }
            }

        }
    }
    cout<<e;
    delete[] v;
    v=NULL;
    return 0;
}