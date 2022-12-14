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
#include <vector>
using namespace std;

class Produkt
{
    protected:
        string nazwa;//1
        int ilosc, rezerwacja, wyslane, ID;
        float cena;
        bool ukrycie = false;//1

    public:
        //metody
        void ukryj();
        void odzyskaj();
        void losuj(int id);
        bool zarezeruj(int ile);
        bool wyslij(int ile);
        bool zwroc(int ile);
        //set i get
        bool setCena(int cena);
        bool setNazwaProd(string naz);
        bool setID(int id);
        bool setIlosc(int ilosc);
        bool setRezerwacja(int rez);
        bool setWyslane(int wys);
        bool getStatus();
        int  getCena();
        string getNazwaProd();
        int  getID();
        int  getIlosc();
        int  getRezerwacja();
        int  getWyslane();
        void setStatus(bool status);
        

};

class Katalog:public Produkt
{
    protected:
        int wielkosc,ID, aktualny = 0, dane = 0, counterWyszukane = 0;
        string nazwa = "";
        bool arch = false;
        Produkt bufor, *produkty, *wyszukane;

    public:
        bool import();
        bool save();
        void buduj(int x);
        void kolejny();
        void poprzedni();
        void wyswietl();
        void setNazwa(string naz);
        void setDataCount(int x);
        void setArch(bool x);
        bool getArch();
        void menu();
        string getNazwa();
        void generuj(int x);
        bool zamienJeden(int);
        bool dodajJeden(int i);
        void poNazwie(string text);
        void wyswietlaniePoWyszukaniu();
        bool archiwizujWyszuakne();
        void nextWysz();
        void prevWysz();
        void wyszukniePrzedzialCena(float min, float max);
        void sortNazwa(bool kierunek);
        void sortCena(bool kierunek);
        void sortId(bool kierunek);
        bool print(bool mode);
        bool zapisz(bool mode, string nazwaPliku);
        void wczytaj(string naz);
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
    // Katalog *kat;
    // kat = new Katalog[10];
    vector <Katalog> kat;

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
        cout<<"3. Wczytaj magazyn"<<endl;

        cout<<"ESC. Wyjscie"<<endl;
        input = getch();
        switch (input)
        {
            case '1':
                for (int i = 0; i < kat.size(); i++)
                {
                    cout<<(i+1)<<". "<<kat[i].getNazwa()<<endl;
                }
                do
                {
                    cout<<"wybierz magazyn(1-"<<kat.size()<<") lub ESC aby wyjsc";
                    input = getch();
                    switch (input)
                    {
                    case 48 ... 57:
                        //wyberanie magazynu
                        wybrany = input-49;
                        kat[wybrany].menu();
                        input = 27;
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
                        kat.push_back(Katalog());
                        kat[utworzone].buduj(wielkosc);
                        kat[utworzone].setNazwa(nazw);
                        utworzone++;
                    }
                    else
                    {
                        cout<<"Z??a warto????"<<endl;
                    }
                    
                } while (wielkosc < 0);
                
            break;
            case '3':
                cout<<"Podaj nazwe pliku (bez rozszerzenia):"<<endl;
                cin>>nazw;
                try
                {
                    kat.push_back(Katalog());
                    kat[utworzone].wczytaj(nazw);
                    utworzone++;
                }
                catch(const std::exception& e)
                {
                    cout<<"Wystapil blad"<<endl;
                    std::cerr << e.what() << '\n';
                    system("pause");
                }
                
                
            break;
            case 27:
                cout<<"napewno wylogowac?"<<endl;
                cout<<"T/N"<<endl;
                input = getch();
                if (input == 'T' || input == 't')
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


