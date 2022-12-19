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
    if(0 <= (this -> aktualny+1) || (this -> aktualny+1) <= this -> dane)
    {
        aktualny++;
    }
}
void Katalog::poprzedni()
{
    if(0 <= (this -> aktualny-1) || (this -> aktualny-1) <= this -> dane)
    {
        aktualny--;
    }
}
void Katalog::wyswietl(int x)
{
    this -> aktualny = x;
    int koniecLini = 28,cyfra;
    char input = 0;
    string nazw;
    do
    {
        fflush(stdin);
        system("cls");

        cout<<"----------------------------"<<endl;
        cout<<"|ID: "<<this -> produkty[this -> aktualny].getID();
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< this -> produkty[this -> aktualny].getNazwaProd();
        tp(3,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< this -> produkty[this -> aktualny].getCena();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< this -> produkty[this -> aktualny].getIlosc();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (this -> produkty[this -> aktualny].getRezerwacja())+(this -> produkty[x].getWyslane());
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< this -> produkty[this -> aktualny].getRezerwacja();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< this -> produkty[this -> aktualny].getWyslane();
        tp(8,koniecLini);cout<<"|"<<endl;
        cout<<"|aktualny: "<< this -> aktualny;
        tp(9,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|##########################|"<<endl;
        cout<<"|1. Zmien dane             |"<<endl;
        cout<<"|2. Archiwizuj             |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ESC. Wyjdz                |"<<endl;
        cout<<"|<A                      D>|"<<endl;
        cout<<"----------------------------"<<endl;    
        
        input = getch();
        switch (input)
        {
            case '1':
                bufor.setID(produkty[this -> aktualny].getID());
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
                        bufor.setCena(cyfra);
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
                        bufor.setIlosc(cyfra);
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
                        bufor.setRezerwacja(cyfra);
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
                        bufor.setWyslane(cyfra);
                    }
                    
                } while (cyfra <= 0);

            break;
            case '2':
                produkty[this -> aktualny].ukryj();
            break;
            case 65: case 97:
                kolejny();
            break;
            case 68: case 100:
                poprzedni();
            break;

            default:
            cout<<"zla komenda";
            break;
        }
        
    } while (input != 27);
}
void Katalog::generuj(int x)
{
    for (int i = 0; i <= x; i++)
    {
        this -> produkty[(this -> dane + i)].losuj();
    }
    this -> dane = this -> dane + x;    
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
    int koniecLini = 26;
    char input = 0;
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
                this -> wyswietl(this -> aktualny);
            break;
            case '2':
                //kiedys
            break;
            case '3':
                //kiedys
            break;
            case '4':
                //kiedys
            break;
            case '5':
                //kiedys
            break;
            case '6':
                //kiedys
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
//    |ilosc danych:           |
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


