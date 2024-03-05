#include <iostream>
#include <vector>
using namespace std;

template<class T>
ostream& operator<<(ostream& os, vector<T> vt)
{
    for(auto e:vt)
        os<<e<<" ";
    os<<endl;
    return os;
}

int main()
{
    uint32_t i;
    vector<int> vt;

    cout<<vt.size()<<endl;
    cout<<vt.capacity()<<endl;

    /*
///    vt[0]=5;
    try
    {
        vt.at(0)=5;
    }
    catch(std::out_of_range)
    {
        cerr<<"Eroare"<<endl;
        vt.resize(1);
        cout<<vt.size()<<endl;
        cout<<vt.capacity()<<endl;
    }
    cout<<"Linia urmatoare executata dupa catch"<<endl;
    */

    for(i=0;i<10;++i)
        vt.push_back(10*i);

    cout<<vt;

    vector<int>::reverse_iterator it; /// it este iterator

    for(it=vt.rbegin();it!=vt.rend();++it)
        cout<<*it<<" ";
    cout<<endl;

    cout<<endl<<endl<<"Vector de float:"<<endl;

    vector<float> vt1(10,3);
    cout<<vt1.size()<<endl;
    cout<<vt1.capacity()<<endl;

    cout<<vt1;
    i=1;
    for(auto &e:vt1)
        e=i++;
    cout<<vt1;

/*
    vt1[0]=11;
    vt1[2]=20;
    vt1.at(9)=51;
    vt1.at(8)=520;
*/

    vt1.push_back(100);

    cout<<vt1.size()<<endl;
    cout<<vt1.capacity()<<endl;

    cout<<vt1;

    cout<<vt1.size()<<endl;
    cout<<vt1.capacity()<<endl;

    float a=vt1[vt1.size()-1];
    cout<<a<<endl;
    vt1.pop_back();

    a=*vt1.rbegin();
    cout<<a<<endl;

    //cout<<vt.max_size()<<endl;

    vt1.pop_back();

    a=vt1.back();
    cout<<a<<endl;
    cout<<vt1<<endl;

    vector<float>::iterator it1=vt1.begin(); /// actualizam iteratorul la zona respectiva

//    vt1.insert(it1+2,20,325);

    //vt1.insert(it1+2, vt.begin(), vt.begin()+3);

//    vt1.insert(it1+2, {100,200,300} );

    vt1.insert(vt1.begin(),100);

    cout<<vt1;


    it1=vt1.begin();
   // vt1.erase(it1+3);

    vt1.erase(it1+2, it1+5);
    cout<<vt1;
    cout<<endl<<"Verificare swap"<<endl;

    vector<float> vt2(10,3);
    cout<<vt1;
    cout<<vt2;
    vt1.swap(vt2);
    cout<<"Dupa swap"<<endl;
    cout<<vt1;
    cout<<vt2;

    vector<vector<int>> av; /// un fel de matrice cu nr de elemente pe linii diferite, practic un vector de vectori
    /// care poate fi uniformizat in asa fel incat sa avem o matrice patratica sau oarecare
    for(i=2;i<6;++i)
        av.push_back(vector<int>(vt.begin(),vt.begin()+i));
    cout<<av;




    return 0;
}
