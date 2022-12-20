#include <iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Produkt
{
    protected:
        string nazwa;//1
        int ilosc, dostawca, rezerwacja, wyslane, ID;
        float cena;
        bool ukrycie = false;//1

    public:
        //metody
        void ukryj();
        void odzyskaj();
        void losuj();
        bool zarezeruj(int ile);
        bool wyslij(int ile);
        bool zwroc(int ile);
        //set i get
        bool setCena(int cena);
        bool setNazwaProd(string naz);
        bool setDostawca(int dost);
        bool setID(int id);
        bool setIlosc(int ilosc);
        bool setRezerwacja(int rez);
        bool setWyslane(int wys);
        int  getCena();
        int  getDostawca();
        string getNazwaProd();
        int  getID();
        int  getIlosc();
        int  getRezerwacja();
        int  getWyslane();

};

class Katalog:public Produkt
{
    protected:
        int wielkosc,ID, aktualny = 0, dane = 0;
        string nazwa = "";
        Produkt bufor, *produkty;

    public:
        //Katalog(int rozmiar);
        bool import();
        bool save();
        void buduj(int x);
        void kolejny();
        void poprzedni();
        void wyswietl();
        void setNazwa(string naz);
        void menu();
        string getNazwa();
        void generuj(int x);

        


        // generowanie wielkości katalogu w konstrukcie poprzez wartość przekazywaną do konstrukta
        //
};

class User
{
    protected:
        string nazwa, haslo;

    public:
        bool zaloguj(string login, string haslo);
        bool wyloguj();
};
#include "funkcje.cpp"
#include "Produkt_metody.cpp"
#include "Katalog_metody.cpp"

main()
{
    int wielkosc= 0,utworzone = 0,wybrany;
    string nazw;
    Katalog *kat;
    kat = new Katalog[10];
    char input;
    srand(time(NULL));
    do
    {
        fflush(stdin);
        system("cls");
        
        //lista instrukcji
        cout<<"Magazyn"<<endl<<endl;
        cout<<"1. Lista magazynow"<<endl;
        cout<<"2. Dodaj magazyn"<<endl;

        cout<<"ESC. Wyjscie"<<endl;
        input = getch();
        switch (input)
        {
            case '1':
                for (int i = 0; i < 9; i++)
                {
                    cout<<(i+1)<<". "<<kat[i].getNazwa()<<endl;
                }
                do
                {
                    cout<<"wybierz magazyn(1-10) lub ESC aby wyjsc";
                    input = getch();
                    switch (input)
                    {
                    case 48 ... 57:
                        //wyberanie magazynu
                        wybrany = input-49;
                        kat[wybrany].menu();
                        break;
                    case 27:
                        break;
                    default:
                        cout<<"zla komenda";
                        break;
                    }                    
                } while (input != 27);
                


            break;
            case '2':
                do
                {
                    cout<<"Podaj wielkosc katalogu:"<<endl<<"  ";
                    cin>>wielkosc;
                    if (wielkosc > 0)
                    {
                        cout<<"podaj nazwe katalogu:"<<endl<<"  ";
                        cin>>nazw;
                        kat[utworzone].buduj(wielkosc);
                        kat[utworzone].setNazwa(nazw);
                        utworzone++;
                    }
                    else
                    {
                        cout<<"Zła wartość"<<endl;
                    }
                    
                } while (wielkosc < 0);
                
            break;
            case 27:
                char info;
                cout<<"napewno wylogowac?"<<endl;
                cout<<"T/N"<<endl;
                info = getch();
                if (info == 'T' || info == 't')
                {
                    input = '0';
                }
                
                break;
            
            default:
                cout<<"zla komenda";
                break;
        }
        
        
    } while (input != '0');
    
}


