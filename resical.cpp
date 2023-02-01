#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tab {
long double wartosc;
string nazwa;
bool operator<(const tab &x)const
{
    return wartosc<x.wartosc;
}

};


long double tablica2[100000] = {10,100,220,470,1000,2200,4700,10000,22000,47000,100000,220000,1000000,10000000};
long double liczba, a;
int b;
string stablica[100000] = {"10","100","220","470","1000","2200","4700","10000","22000","47000","100000","220000","1000000","10000000"};
tab tablica[100000];



void megatablica ()
{
    int k=14;
    for(int i = 0; i<=13;i++)
    {
        for(int j = 0;j<=13;j++)
        {
            tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc)/(tablica[i].wartosc+tablica[j].wartosc);
            tablica[k].nazwa=tablica[i].nazwa+ "+" + tablica[j].nazwa;
           k++;
        }
    }
    for(int l=0;l<=13;l++)
    {
        for(int i = 0; i<=13;i++)
        {
            for(int j = 0;j<=13;j++)
            {
                tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc);
                tablica[k].nazwa=tablica[i].nazwa+ "+" + tablica[j].nazwa+ "+" + tablica[l].nazwa;
               k++;
            }
        }
    }
    for(int m=0;m<=13;m++)
    {
        for(int l=0;l<=13;l++)
        {
            for(int i = 0; i<=13;i++)
            {
                for(int j = 0;j<=13;j++)
                {
                    tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc*tablica[m].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc+tablica[m].wartosc);
                    tablica[k].nazwa=tablica[i].nazwa+ "+" + tablica[j].nazwa+ "+" + tablica[l].nazwa+ "+" + tablica[m].nazwa;
                   k++;
                }
            }
        }
    }

}
int main() {
    for(int i=0; i<=13;i++)
    {
        tablica[i].wartosc=tablica2[i];
        tablica[i].nazwa=stablica[i];
    }


    megatablica();
    sort(tablica,tablica+41370);
    cin >> liczba;
    a=liczba;
    while(tablica[0].wartosc<=a)
    {
        for(int i = 0;tablica[i].wartosc<=a;i++)
        {
            b=i;

        }
        a-=tablica[b].wartosc;
        cout << tablica[b].wartosc << ": ";
        cout << tablica[b].nazwa << " + ";
    }
    cout << endl << liczba-a;

    return 0;
}
