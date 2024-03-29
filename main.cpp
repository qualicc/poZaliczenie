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
    public:
        string nazwa ;//1
        int ilosc, rezerwacja, wyslane, ID;
        float cena;
        bool ukrycie = false;//1

    
        //metody
        void ukryj();
        void odzyskaj();
        void losuj(int x);
        bool zarezeruj(int ile);
        bool wyslij(int ile);
        bool zwroc(int ile);
        //set i get
        bool setCena(int cena);
        bool setNazwaProd(string naz);
        void setID(int id);
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
    public:
        int wielkosc,ID, aktualny = 0, dane = 0, counterWyszukane = 0,archCount = 0;
        string nazwa = "";
        bool arch = false;
        Produkt bufor, *produkty, *wyszukane;

    
        bool import();
        bool save();
        void buduj(int x);
        void kolejny();
        void poprzedni();
        void setNazwa(string naz);
        void setDataCount(int x);
        void setArch(bool x);
        bool getArch();
        string getNazwa();
        void generuj(int x);
        bool zamienJeden(int);
        bool dodajJeden(int i);
        bool poNazwie(string text);
        bool archiwizujWyszuakne();
        void nextWysz();
        void prevWysz();
        void setWielkosc(int x);
        bool wyszukniePrzedzialCena(float min, float max);
        void sortNazwa(bool kierunek);
        void sortCena(bool kierunek);
        void sortId(bool kierunek);
        bool print(bool mode);
        bool zapisz(bool mode, string nazwaPliku);
        void wczytaj(string naz);
        void setAktualny();
        void setAktualny(int x);
        int getWielkosc();
        int getIloscDanych();
        void usun();
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
    int wielkosc= 0,utworzone = 0,wybrany, intINPUT;
    string nazw, strINPUT;
    Katalog aktualyKatalog;
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
                    cout<<"wybierz magazyn(1-"<<kat.size()<<") lub 0 aby wyjsc"<<endl;
                    cin>>intINPUT;
                    switch (intINPUT)
                    {
                    case 0:
                        break;
                    default:
                        if (intINPUT > 0 && intINPUT <= kat.size())
                        {
                            aktualyKatalog = kat[(intINPUT-1)];
                            int koniecLini = 26, pion = 22, cyfra, sth, l1, l2, kierunek;
                            char input = 0;
                            string nazw;
                            do
                            {
                                fflush(stdin);
                                system("cls");

                                cout<<"--------------------------"<<endl;
                                cout<<"|Twoja nazwa:";//dodac wyswietlanie nazwy uzytkownika po zrobieniu mechanizmu
                                tp(2,koniecLini);cout<<"|"<<endl;
                                cout<<"|Obecny magazyn: "<< aktualyKatalog.getNazwa();
                                tp(3,koniecLini);cout<<"|"<<endl;
                                cout<<"|Wielkosc: "<< aktualyKatalog.getWielkosc();
                                tp(4,koniecLini);cout<<"|"<<endl;
                                cout<<"|Ilosc danych: "<< aktualyKatalog.getIloscDanych();
                                tp(5,koniecLini);cout<<"|"<<endl;
                                cout<<"|                        |"<<endl;
                                cout<<"|########################|"<<endl;
                                cout<<"|1. Przegladaj jeden     |"<<endl;
                                cout<<"|2. Przegladaj wszystkie |"<<endl;
                                cout<<"|3. Kosz                 |"<<endl;
                                cout<<"|4. Sortuj               |"<<endl;
                                cout<<"|5. Wyszukaj             |"<<endl;
                                cout<<"|6. Dodaj jeden          |"<<endl;   
                                cout<<"|7. Generuj              |"<<endl;
                                cout<<"|8. Zapisz               |"<<endl;
                                cout<<"|9. Drukuj               |"<<endl;
                                cout<<"|                        |"<<endl;
                                cout<<"|                        |"<<endl;
                                cout<<"|ESC. Wyjdz              |"<<endl;
                                cout<<"--------------------------"<<endl;    
                                
                                input = getch();
                                switch (input)
                                {
                                    case '1':
                                        aktualyKatalog.setArch(false);
                                        wyswietl(aktualyKatalog);
                                    break;
                                    case '2':
                                        cout<<" ID      Nazwa               Cena        Ilosc       Sprzedano      Rezerwacja       Wyslano"<<endl;
                                        for (int i = 0; i <= (aktualyKatalog.getIloscDanych()-1); i++)
                                        {
                                            tp(pion + i,2);
                                            cout<<aktualyKatalog.produkty[i].getID();
                                            tp(pion + i,10);
                                            cout<<aktualyKatalog.produkty[i].getNazwaProd();
                                            tp(pion + i,30);
                                            cout<<aktualyKatalog.produkty[i].getCena();
                                            tp(pion + i,42);
                                            cout<<aktualyKatalog.produkty[i].getIlosc();
                                            tp(pion + i,54);
                                            cout<<(aktualyKatalog.produkty[i].getRezerwacja())+(aktualyKatalog.produkty[i].getWyslane());
                                            tp(pion + i,69);
                                            cout<<aktualyKatalog.produkty[i].getRezerwacja();
                                            tp(pion + i,86);
                                            cout<<aktualyKatalog.produkty[i].getRezerwacja();
                                            tp(pion + i,90);
                                            if(aktualyKatalog.produkty[i].getStatus() == true)
                                            {
                                                cout<<"ukryty";
                                            }
                                            else
                                            {
                                                cout<<"odkryty";
                                            }
                                        }
                                        cout<<endl;
                                        system("pause");
                                    break;
                                    case '3':
                                        if(aktualyKatalog.archCount > 0)
                                        {
                                            aktualyKatalog.setArch(true);
                                            wyswietl(aktualyKatalog);
                                        }
                                        else
                                        {
                                            cout<<"brak danych w koszu"<<endl;
                                            system("pause");
                                        }
                                        
                                    break;
                                    case '4':
                                        do
                                        {
                                            fflush(stdin);
                                            system("cls");
                                            cout<<"0 - rosnaco, 1 - malejaco";
                                            do
                                            {
                                                cin >> kierunek;
                                                if(kierunek != 1 && kierunek != 0)
                                                {
                                                    cout<<"zla komenda";
                                                }
                                            } while ((kierunek != 1 && kierunek != 0));

                                            cout<<"Sortuj"<<endl<<"Wybierz kryterium:"<<endl<<"1. Nazwa"<<endl<<"2. Cena"<<endl<<"3. ID";
                                            cout<<endl<<"ESC. wyjscie"<<endl;
                                            input = getch();
                                            switch (input)
                                            {
                                            case '1':
                                                aktualyKatalog.sortNazwa(kierunek);
                                                input = 0;
                                                break;
                                            case '2':
                                                aktualyKatalog.sortCena(kierunek);
                                                input = 0;
                                                break;
                                            case '3':
                                                aktualyKatalog.sortId(kierunek);
                                                input = 0;
                                                break;
                                            case 27:
                                                input = 0;
                                            break;
                                            default:
                                                cout<<"zla opcja";
                                                break;
                                            }

                                        } while (input != 0);
                                    break;
                                    case '5':
                                        do
                                        {
                                            fflush(stdin);
                                            system("cls");
                                            cout<<"Wyszukaj"<<endl<<"Wybierz kryterium:"<<endl<<"1. Nazwa"<<endl<<"2. Cena";
                                            cout<<endl<<"ESC. wyjscie"<<endl;
                                            input = getch();
                                            switch (input)
                                            {
                                            case '1':
                                                cout<<"Podaj calosc lub fragment nazwy: "<<endl;
                                                getline( cin, nazw );
                                                if(aktualyKatalog.poNazwie(nazw))
                                                {
                                                    aktualyKatalog.poNazwie(nazw);
                                                    wyswietlaniePoWyszukaniu(aktualyKatalog);
                                                }
                                                else
                                                {
                                                    cout<<"brak takich rekordow";
                                                    system("pause");
                                                }
                                                break;
                                            case '2':
                                                cout<<"Podaj przedzial min, max. (alby wybrac na podstawie jednej wartosci wprowadz 2 razy ta sama wartosc)"<<endl;
                                                cin>>l1;
                                                cout<<"-------------------"<<endl;
                                                cin>> l2;
                                                if (l1 <= l2 && l1 > 0)
                                                {
                                                    if(aktualyKatalog.wyszukniePrzedzialCena(l1, l2))
                                                    {
                                                        aktualyKatalog.wyszukniePrzedzialCena(l1, l2);
                                                        wyswietlaniePoWyszukaniu(aktualyKatalog);
                                                    }
                                                    else
                                                    {
                                                        cout<<"brak takich rekordow";
                                                        system("pause");
                                                    }
                                                }
                                                else
                                                {
                                                    cout<<"blad";
                                                }
                                                break;
                                            case 27:
                                                input = 0;
                                            break;
                                            default:
                                                cout<<"zla opcja";
                                                break;
                                            }

                                        } while (input != 0);
                                        
                                    break;
                                    case '6':
                                        if((aktualyKatalog.getIloscDanych()+ 1) <= aktualyKatalog.getWielkosc())
                                        {
                                            aktualyKatalog.bufor.setID((aktualyKatalog.getIloscDanych()+ 1));
                                            aktualyKatalog.bufor.odzyskaj();
                                            cout<<"Podaj nazwe: ";
                                            getline( cin, nazw );
                                            aktualyKatalog.bufor.setNazwaProd(nazw);
                                            do
                                            {
                                                cout<<endl<<"Podaj cene: ";
                                                cin>>cyfra;
                                                if (cyfra <= 0)
                                                {
                                                    cout<<"zla wartosc";
                                                }
                                                else
                                                {
                                                    aktualyKatalog.bufor.setCena(cyfra);
                                                }
                                                
                                            } while (cyfra <= 0);
                                            cyfra = 0;
                                            do
                                            {
                                                cout<<endl<<"Podaj ilosc: ";
                                                cin>>cyfra;
                                                if (cyfra <= 0)
                                                {
                                                    cout<<"zla wartosc";
                                                }
                                                else
                                                {
                                                    aktualyKatalog.setIlosc(cyfra);
                                                }
                                                
                                            } while (cyfra <= 0);
                                            cyfra = 0;
                                            do
                                            {
                                                cout<<endl<<"Podaj ilosc zarezerwowanych: ";
                                                cin>>cyfra;
                                                if (cyfra <= 0)
                                                {
                                                    cout<<"zla wartosc";
                                                }
                                                else
                                                {
                                                    aktualyKatalog.setRezerwacja(cyfra);
                                                }
                                                
                                            } while (cyfra <= 0);
                                            cyfra = 0;
                                            do
                                            {
                                                cout<<endl<<"Podaj ilosc wyslanych: ";
                                                cin>>cyfra;
                                                if (cyfra <= 0)
                                                {
                                                    cout<<"zla wartosc";
                                                }
                                                else
                                                {
                                                    aktualyKatalog.setWyslane(cyfra);
                                                }
                                                
                                            } while (cyfra <= 0);
                                            cout<<endl<<"Napewno chcesz dodac? T/N"<<endl;
                                            input = getch();
                                            if(input == 84 || input == 116)
                                            {
                                            
                                                if(aktualyKatalog.dodajJeden((aktualyKatalog.getIloscDanych())))
                                                {
                                                    aktualyKatalog.dane = aktualyKatalog.getIloscDanych()+ 1;
                                                    cout<<endl<<"Dodano pomyslnie"<<endl;
                                                    system("pause");
                                                }
                                            } 
                                        }

                                    break;
                                    case '7':
                                        int ile;
                                        do
                                        {
                                            cout<<endl<<"Ile generowac?";
                                            cin>>ile;
                                            if(ile <= 0 || ile > aktualyKatalog.getWielkosc())
                                            {
                                                cout<<"Zla wartosc"<<endl;
                                            }
                                        } while (ile <= 0 || ile > aktualyKatalog.getWielkosc());
                                        aktualyKatalog.generuj(ile);
                                        
                                    break;
                                    case '8':
                                        do
                                        {
                                            cout<<"Zapisz: 0, Zapisz jako: 1, Anuluj: ESC"<<endl;
                                            cin>>input;
                                            switch (input)
                                            {
                                            case '0':
                                                if (aktualyKatalog.zapisz(0, ""))
                                                {
                                                    cout<<"Zapisano poprawnie"<<endl;
                                                }
                                                else
                                                {
                                                    cout<<"Wystapil blad"<<endl;  
                                                }
                                                system("pause"); 
                                                input = 0;
                                                break;
                                            case '1':
                                                cout<<"Podaj Nazwe: "<<endl;
                                                cin>>nazw;
                                                if (aktualyKatalog.zapisz(0, nazw))
                                                {
                                                    cout<<"Zapisano poprawnie"<<endl;
                                                }
                                                else
                                                {
                                                    cout<<"Wystapil blad"<<endl;  
                                                }
                                                system("pause");
                                                input = 0;
                                                break;
                                            case 27:
                                                input = 0;
                                                break;
                                            default:
                                                cout<<"Zla wartosc"<<endl;
                                                break;
                                            }
                                        } while (input != 0);
                                        
                                        
                                    break;
                                    case '9': 
                                        if (aktualyKatalog.print(0))
                                        {
                                            cout<<"Wydrukowano poprawnie"<<endl;
                                        }
                                        else
                                        {
                                            cout<<"Wystapil blad"<<endl;  
                                        }
                                        system("pause");
                                    break;
                                    default:
                                    cout<<"zla komenda";
                                    break;
                                }
                                
                            } while (input != 27);
                        }
                        
                        cout<<"zla komenda";
                        break;
                    }                    
                } while (intINPUT != 0);
                


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
                        kat[utworzone].setNazwa(nazw);
                        kat[utworzone].setWielkosc(wielkosc);
                        utworzone++;
                    }
                    else
                    {
                        cout<<"Zła wartość"<<endl;
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


