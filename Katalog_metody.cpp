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
    if(minMaxI(0,this -> wielkosc, x))
    {
        //if nie ukryte
        cout<<"ID: ";
        //wyswielt id
        cout<<"Nazwa: ";
        //wyswielt nazwe
        cout<<"Cena: ";
        //wyswielt nazwe
        cout<<"Ilosc: ";
        //wyswielt Ilosc
        cout<<"Dostawca: ";
        //wyswielt Dostawca
        cout<<"Zarezerowane: ";
        //wyswielt Zarezerowane
        cout<<"Wyslane: ";
        //wyswielt Wyslane
    }
}
void Katalog::buduj(int x)
{
    produkty = new Produkt[x];
}
void Katalog::setNazwa(string naz)
{
    this -> nazwa = naz;
}
string Katalog::getNazwa()
{
    return this -> nazwa;
}