#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct tab {
long double wartosc;
string nazwa;
};

vector<long double> resistors={10,100,220,470,1000,2200,4700,10000,22000,47000,100000,220000,1000000,10000000};
long double liczba, a;
int b, startres=resistors.size();
vector<tab> tablica;

void megatablica ()
{
    for(int i = 0; i<startres;i++)
    {
        for(int j = 0;j<startres;j++)
        {
            tablica.push_back({(tablica[i].wartosc*tablica[j].wartosc)/(tablica[i].wartosc+tablica[j].wartosc),tablica[i].nazwa+ " & " + tablica[j].nazwa});
        }
    }
    for(int l=0;l<startres;l++)
    {
        for(int i = 0; i<startres;i++)
        {
            for(int j = 0;j<startres;j++)
            {
                tablica.push_back({(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc),tablica[i].nazwa+ " & " + tablica[j].nazwa+ " & " + tablica[l].nazwa});
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
                    tablica.push_back({(tablica[i].wartosc*tablica[j].wartosc*tablica[l].wartosc*tablica[m].wartosc)/(tablica[i].wartosc+tablica[j].wartosc+tablica[l].wartosc+tablica[m].wartosc),tablica[i].nazwa+ " & " + tablica[j].nazwa+ " & " + tablica[l].nazwa+ " & " + tablica[m].nazwa});
                }
            }
        }
    }
}

int main() {
    for(int i=0; i<resistors.size();i++)
    {
        tablica.push_back({resistors[i],to_string((int)resistors[i])});
    }
    megatablica();
    sort(tablica.begin(), tablica.end(), [](const tab &x, const tab &y) {
    return x.wartosc < y.wartosc;
  });

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
