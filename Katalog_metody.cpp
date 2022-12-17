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
void Katalog::kolejny(int x)
{
    if(minMaxI(0,this -> wielkosc, x))
    {
        aktualny++;
    }
}
void Katalog::poprzedni(int x)
{
    if(minMaxI(0,this -> wielkosc, x))
    {
        aktualny--;
    }
}
void Katalog::wyswietl(int x)
{
    int koniecLini = 28;
    char input = 0;
    do
    {
        fflush(stdin);
        system("cls");

        cout<<"----------------------------"<<endl;
        cout<<"|ID: "<<this -> produkty[x].getID();
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< this -> produkty[x].getNazwaProd();
        tp(3,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< this -> produkty[x].getCena();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< this -> produkty[x].getIlosc();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (this -> produkty[x].getRezerwacja())+(this -> produkty[x].getWyslane());
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< this -> produkty[x].getRezerwacja();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< this -> produkty[x].getWyslane();
        tp(8,koniecLini);cout<<"|"<<endl;
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
        cout<<"|                        |"<<endl;
        cout<<"|########################|"<<endl;
        cout<<"|1. Przegladaj jeden     |"<<endl;
        cout<<"|2. Przegladaj wszystkie |"<<endl;
        cout<<"|3. Kosz                 |"<<endl;
        cout<<"|4. Sortuj               |"<<endl;
        cout<<"|5. Filtruj              |"<<endl;
        cout<<"|6. Dodaj jeden          |"<<endl;   
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


