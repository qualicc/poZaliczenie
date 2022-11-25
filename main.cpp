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
        bool setNazwa(string naz);
        bool setDostawca(int dost);
        bool setID(int id);
        bool setIlosc(int ilosc);
        bool setRezerwacja(int rez);
        bool setWyslane(int wys);
        int  getCena();
        int  getDostawca();
        string getNazwa();
        int  getID();
        int  getIlosc();
        int  getRezerwacja();
        int  getWyslane();

};

class Katalog:public Produkt
{
    protected:
        int wielkosc,ID, aktualny;
        string nazwa;
        Produkt bufor;

    public:
        Katalog(int rozmiar);
        bool import();
        bool save();
        void kolejny(int x);
        void poprzedni(int x);
        void wyswietl(int x);

        


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


            break;
            case '2';
            
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