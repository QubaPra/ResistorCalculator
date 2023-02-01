#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct tab {
long double wartosc;
string nazwa;
bool operator<(const tab &x)const
{
    return wartosc<x.wartosc;
}

};

vector<long double> resistors={10,100,220,470,1000,2200,4700,10000,22000,47000,100000,220000,1000000,10000000};
long double liczba, a;
int b, startres=resistors.size();
tab tablica[100000];



void megatablica ()
{
    int k=startres;
    for(int i = 0; i<startres;i++)
    {
        for(int j = 0;j<startres;j++)
        {
            tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc)/(tablica[i].wartosc+tablica[j].wartosc);
            tablica[k].nazwa=tablica[i].nazwa+ " & " + tablica[j].nazwa;
           k++;
        }
    }
    for(int l=0;l<startres;l++)
    {
        for(int i = 0; i<startres;i++)
        {
            for(int j = 0;j<startres;j++)
            {
                tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc);
                tablica[k].nazwa=tablica[i].nazwa+ " & " + tablica[j].nazwa+ " & " + tablica[l].nazwa;
               k++;
            }
        }
    }
    for(int m=0;m<startres;m++)
    {
        for(int l=0;l<startres;l++)
        {
            for(int i = 0; i<startres;i++)
            {
                for(int j = 0;j<startres;j++)
                {
                    tablica[k].wartosc=(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc*tablica[m].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc+tablica[m].wartosc);
                    tablica[k].nazwa=tablica[i].nazwa+ " & " + tablica[j].nazwa+ " & " + tablica[l].nazwa+ " & " + tablica[m].nazwa;
                   k++;
                }
            }
        }
    }

}
int main() {
    for(int i=0; i<resistors.size();i++)
    {
        tablica[i].wartosc=resistors[i];
        tablica[i].nazwa=to_string((int)resistors[i]);
    }
    megatablica();
    sort(tablica,tablica+41370);

    cout << "Enter resistance that you want to get: ";
    cin >> liczba;
    cout << endl << "You'll need:" << endl;
    a=liczba;
    while(tablica[0].wartosc<=a)
    {
        for(int i = 0;tablica[i].wartosc<=a;i++)
        {
            b=i;
        }
        a-=tablica[b].wartosc;
        cout << tablica[b].wartosc << ": ";
        cout << tablica[b].nazwa << endl;
    }
    cout << endl << endl << "Overall you can make:";
    cout << endl << liczba-a << endl;

    return 0;
}
