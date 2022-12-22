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

//     Katalog::Katalog(int rozmiar)
// {
    
// }
void Katalog::kolejny()
{
    int x = 1;

    if((this -> aktualny+1) <= this -> dane)
    {
        do
        {
            if (this -> produkty[aktualny+x].getStatus() != getArch())
            {
                x++;
            }

        } while (this -> produkty[aktualny+x].getStatus() != getArch());

        if ((x + this -> aktualny) >= this -> dane)
        {
            x = 0;
        }

        this -> aktualny = aktualny + x;
    }

}
void Katalog::poprzedni()
{
    int x = 1;

    if(0 <= (this -> aktualny-1))
    {
        do
        {
            if (this -> produkty[aktualny-x].getStatus() != getArch())
            {
                x++;
            }

        } while (this -> produkty[aktualny-x].getStatus() != getArch());

        if (this -> aktualny - x < 0)
        {
            x = 0;
        }
        
        this -> aktualny = aktualny - x;
    }
}
void Katalog::wyswietl()
{
    int koniecLini = 28, cyfra;
    char input = 0;
    string nazw;
    do
    {
        fflush(stdin);
        system("cls");
        if(getArch() == true){
            cout<<"----------Archiwum----------"<<endl;
        }else{
            cout<<"----------------------------"<<endl;
        }
        cout<<"|ID: "<<this -> produkty[this ->aktualny].getID();
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< this -> produkty[this ->aktualny].getNazwaProd();
        tp(3,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< this -> produkty[this ->aktualny].getCena();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< this -> produkty[this ->aktualny].getIlosc();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (this -> produkty[this ->aktualny].getRezerwacja())+(this -> produkty[this ->aktualny].getWyslane());
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< this -> produkty[this ->aktualny].getRezerwacja();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< this -> produkty[this ->aktualny].getWyslane();
        tp(8,koniecLini);cout<<"|"<<endl;
        cout<<"|akutalny: "<< this -> aktualny;
        tp(9,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|##########################|"<<endl;
        cout<<"|1. Zmien dane             |"<<endl;
        if(getArch() == true){
            cout<<"|2. Odzyskaj               |"<<endl;
        }else{
            cout<<"|2. Archiwizuj             |"<<endl;
        }
        cout<<"|                          |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ESC. Wyjdz                |"<<endl;
        cout<<"|<A                      D>|"<<endl;
        cout<<"----------------------------"<<endl;    
        
        input = getch();
        switch (input)
        {
            case '1':
                bufor.setID(this ->produkty[this -> aktualny].getID());
                cout<<"Podaj nazwe: ";
                getline( cin, nazw );
                bufor.setNazwaProd(nazw);
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
                        this -> bufor.setCena(cyfra);
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
                        this -> bufor.setIlosc(cyfra);
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
                        this -> bufor.setRezerwacja(cyfra);
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
                        this -> bufor.setWyslane(cyfra);
                    }
                    
                } while (cyfra <= 0);
                cout<<endl<<"Napewno chcesz zamienic? T/N"<<endl;
                input = getch();
                if(input == 'T' || input == 't')
                {
                    if(this -> zamienJeden(this ->produkty[this -> aktualny].getID()))
                    {
                        cout<<endl<<"Zamieniono pomyslnie"<<endl;
                        system("pause");
                    }
                }
            break;
            case '2':
                if(getArch() == true){
                    this -> produkty[this -> aktualny].odzyskaj();
                }else{
                    this -> produkty[this -> aktualny].ukryj();
                }
            break;
            case 68: case 100:
                this -> kolejny();
            break;
            case 65: case 97:
                this ->  poprzedni();
            break;            
            default:
            cout<<"zla komenda";
            break;
        }
        
    } while (input != 27);
}
void Katalog::buduj(int x)
{
    produkty = new Produkt[x];
    this -> wielkosc = x;
}
void Katalog::setNazwa(string naz)
{
    this -> nazwa = naz;
}
string Katalog::getNazwa()
{
    return this -> nazwa;
}
void Katalog::menu()
{
    int koniecLini = 26, pion = 20, cyfra, sth;
    char input = 0;
    string nazw;
    do
    {
        fflush(stdin);
        system("cls");

        cout<<"--------------------------"<<endl;
        cout<<"|Twoja nazwa:";//dodac wyswietlanie nazwy uzytkownika po zrobieniu mechanizmu
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|Obecny magazyn: "<< this -> nazwa;
        tp(3,koniecLini);cout<<"|"<<endl;
        cout<<"|Wielkosc: "<< this -> wielkosc;
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|Ilosc danych: "<< this -> dane;
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|                        |"<<endl;
        cout<<"|########################|"<<endl;
        cout<<"|1. Przegladaj jeden     |"<<endl;
        cout<<"|2. Przegladaj wszystkie |"<<endl;
        cout<<"|3. Kosz                 |"<<endl;
        cout<<"|4. Sortuj               |"<<endl;
        cout<<"|5. Filtruj              |"<<endl;
        cout<<"|6. Dodaj jeden          |"<<endl;   
        cout<<"|7. Generuj              |"<<endl;
        cout<<"|                        |"<<endl;
        cout<<"|                        |"<<endl;
        cout<<"|ESC. Wyjdz              |"<<endl;
        cout<<"--------------------------"<<endl;    
        
        input = getch();
        switch (input)
        {
            case '1':
                this -> setArch(false);
                this -> wyswietl();
            break;
            case '2':
                cout<<"  ID      Nazwa               Cena        Ilosc       Sprzedano      Rezerwacja       Wyslano"<<endl;
                for (int i = 0; i <= (this -> dane-1); i++)
                {
                    tp(pion + i,2);
                    cout<<this -> produkty[i].getID();
                    tp(pion + i,10);
                    cout<<this -> produkty[i].getNazwaProd();
                    tp(pion + i,30);
                    cout<<this -> produkty[i].getCena();
                    tp(pion + i,42);
                    cout<<this -> produkty[i].getIlosc();
                    tp(pion + i,54);
                    cout<<(this -> produkty[i].getRezerwacja())+(this -> produkty[i].getWyslane());
                    tp(pion + i,69);
                    cout<<this -> produkty[i].getRezerwacja();
                    tp(pion + i,86);
                    cout<<this -> produkty[i].getRezerwacja();
                    tp(pion + i,90);
                    if(this -> produkty[i].getStatus() == true)
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
                this -> setArch(true);
                this -> wyswietl();
            break;
            case '4':
                //kiedys
            break;
            case '5':
                //kiedys
            break;
            case '6':
                if((this -> dane + 1) <= this -> wielkosc)
                {
                    this -> bufor.setID((this -> dane + 1));
                    this -> bufor.odzyskaj();
                    cout<<"Podaj nazwe: ";
                    getline( cin, nazw );
                    bufor.setNazwaProd(nazw);
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
                            this -> bufor.setCena(cyfra);
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
                            this -> bufor.setIlosc(cyfra);
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
                            this -> bufor.setRezerwacja(cyfra);
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
                            this -> bufor.setWyslane(cyfra);
                        }
                        
                    } while (cyfra <= 0);
                    cout<<endl<<"Napewno chcesz dodac? T/N"<<endl;
                    input = getch();
                    if(input == 84 || input == 116)
                    {
                    
                        if(this -> dodajJeden((this -> dane)))
                        {
                            this -> dane = this -> dane + 1;
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
                    if(ile <= 0 || ile > this -> wielkosc)
                    {
                        cout<<"Zla wartosc"<<endl;
                    }
                } while (ile <= 0 || ile > this -> wielkosc);
                generuj(ile);
                
            break;

            default:
            cout<<"zla komenda";
            break;
        }
        
    } while (input != 27);
}
void Katalog::generuj(int x)
{
    for (int i = 0; i <= (x - 1); i++)
    {
        this -> produkty[(this -> dane + i)].losuj(this -> dane + i + 1);
    }
    this -> dane = this -> dane + x;    
}
void Katalog::setArch(bool x)
{
    this -> arch = x;
}
bool Katalog::getArch()
{
    return this -> arch;
}
bool Katalog::dodajJeden(int i)
{
    try
    {
        this -> produkty[(i)] = this -> bufor;
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
    
}
bool Katalog::zamienJeden(int id)
{
    for (int i = 0; i < this -> dane; i++)
    {
        if(id == this -> produkty[i].getID())
        {
            this -> produkty[i] = this -> bufor;
            return true;
        }
    }   
    return false;
}
//
//    ----------------------------
//    |ID:                       |
//    |nazwa:                    |
//    |cena:                     |
//    |ilosc:                    |
//    |sprzedano:                |
//    |rezerwacja:               |
//    |wyslano:                  |
//    |                          |
//    |                          |
//    |##########################|
//    |1. Zmien dane             |
//    |2. Archiwizuj             |
//    |                          |
//    |                          |
//    |ESC. Wyjdz                |
//    |<A                      D>|
//    ----------------------------
//    --------------------------
//    |twoja nazwa:            |
//    |obecny magazyn:         |
//    |wielkosc:               |
//    |ilosc danych            |
//    |                        |
//    |                        |
//    |########################|
//    |1. Przegladaj jeden     |
//    |2. Przegladaj wszystkie |
//    |3. Kosz                 |
//    |4. Sortuj               |
//    |5. Filtruj              |
//    |6. Dodaj jeden          |
//    |                        |
//    |                        |
//    |ESC. Wyjdz              |
//    --------------------------


//  ID      Nazwa               Cena        Ilosc       Sprzedano      Rezerwacja       Wyslano
//  1       Towar               123         124         543            125              5324