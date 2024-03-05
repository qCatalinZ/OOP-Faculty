#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

template<class T>

class Vector
{
    T* data=nullptr;
    uint32_t dim=0;

public:
    Vector()=default;
    Vector(uint32_t d)
    {
        dim=d;
        data=new T[dim];
    }
    Vector(const Vector& v)
    {
        dim=v.data;
        data=new T[dim];
        for(uint32_t i=0;i<dim;++i)
        {
            data[i]=v.data[i];
        }
    }
    Vector& operator=(const Vector& v)
    {
        if(this==&v)
            return *this;
        if(dim!=v.dim)
        {
            if(dim)
                delete[] data;
            dim=v.dim;
            data=new T[dim];
        }
        for(uint32_t i=0;i<dim;++i)
        {
            data[i]=v.data[i];
        }
        return *this;
    }
    ~Vector()
    {
        if(data)
            delete[] data;
    }
    T& operator[](uint32_t i)
    {
        return data[i];
    }

    T* Find(const T& val)
    {
        for(uint32_t i=0;i<dim;++i)
        {
            if(data[i]==val)
                return &data[i];
        }
        return nullptr;
    }

    template<class DT>
    friend ostream& operator<<(ostream&,const Vector<DT>&);
};

template<class DT>
ostream& operator<<(ostream& os, const Vector<DT>& v)
{
    for(uint32_t i=0; i<v.dim;++i)
    {
        os<<v.data[i]<<endl;
    }
    return os;
}

class Student
{
    char Nume[20];
    char Prenume[20];
    int Varsta=0;
    long CNP=0;
    char Facultate[40];
public:
    Student()=default;
    Student(char N[],char P[], int V, long C,char F[]):Varsta(V),CNP(C)
    {
        strcpy(Nume,N);
        strcpy(Prenume,P);
        strcpy(Facultate,F);
    }
    Student(const Student &n):Varsta(n.Varsta),CNP(n.CNP)
    {
        strcpy(Nume,n.Nume);
        strcpy(Prenume,n.Prenume);
        strcpy(Facultate,n.Facultate);
    }
    friend istream& operator>>(istream&,Student&);
    friend ostream& operator<<(ostream&, const Student&);
    ~Student()=default;
};

istream& operator>>(istream& is,Student& n)
{
    is>>n.Nume;
    is>>n.Prenume;
    is>>n.Varsta;
    is>>n.CNP;
    is>>n.Facultate;
    return is;
}

ostream& operator<<(ostream& os, const Student& n)
{
    os<<n.Nume;
    cout<<endl;
    os<<n.Prenume;
    cout<<endl<<"Varsta: ";
    os<<n.Varsta;
    cout<<endl<<"CNP: ";
    os<<n.CNP;
    cout<<endl;
    os<<n.Facultate;
    cout<<endl;
    return os;
}

int main()
{
    ///ifstream cin("data.in");
/*
    uint32_t i,n=10;
    Vector<int> v(n);
    for(i=0;i<n;++i)
    {
        cin>>v[i];
    }

 //   cout<<v;

    int* p;
    int val=23;
    p=v.Find(val);
    if(p)
        cout<<"Valoarea "<<val<<" se afla pe pozitia "<<(p-&v[0]+1)<<endl;
    else
        cout<<"Valoarea "<<val<<" NU se afla pe pozitia "<<endl;
        */
    int n;
    cin>>n;
    Student *s=new Student[n];
    for(int i=0;i<n;++i)
        cin>>s[i];
    for(int i=0;i<n;++i)
        cout<<s[i];
 //   Student Mari("Zarcan","Marian",18,5454,"Pizz");
   // cout<<Mari;


    return 0;
}
