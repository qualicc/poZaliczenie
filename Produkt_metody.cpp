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


void Produkt::ukryj()
{
    this -> ukrycie = true;
}
void Produkt::odzyskaj()
{
    this -> ukrycie = false;
}
void Produkt::losuj()
{
    srand(time(NULL));
    //strcpy(this ->     nazwa,"Towar");
    this ->     nazwa = "Towar";
    this ->     ilosc = rand()%100+1;
    this ->     rezerwacja = rand()%1000+1;
    this ->     wyslane = rand()%10000+1;
    this ->     cena = (rand()%10000+1)/100;
}
bool Produkt::zarezeruj(int ile)
{
    if(this -> ilosc > ile)
    {
        this -> ilosc = this -> ilosc - ile;
        this -> rezerwacja = this -> rezerwacja + ile;
        return true;
    }
    return false;
}
bool Produkt::wyslij(int ile)
{
    if(this -> rezerwacja > ile)
    {
        this -> rezerwacja = this -> rezerwacja - ile;
        this -> wyslane = this -> wyslane + ile;
        return true;
    }
    return false;
}
bool Produkt::zwroc(int ile)
{
    if(this -> wyslane > ile)
    {
        this -> wyslane = this -> wyslane - ile;
        this -> ilosc = this -> ilosc + ile;
        return true;
    }
    return false;
}
bool Produkt::setCena(int cena)
{
    if(WOZF(cena))
    {
        this -> cena = cena;
        return true;
    }
    return false;
}
bool Produkt::setNazwaProd(string naz)
{
    this -> nazwa = naz;
    //strcpy(this -> nazwa,naz);
    return true;
}
bool Produkt::setID(int id)
{
    this -> ID = id;
    return true;
}
bool Produkt::setIlosc(int ilosc)
{
    if(WOZI(ilosc))
    {
        this -> ilosc = ilosc;
        return true;
    }
    return false;
}
bool Produkt::setRezerwacja(int rez)
{
    if(WOZI(rez))
    {
        this -> rezerwacja = rez;
        return true;
    }
    return false;
}
bool Produkt::setWyslane(int wys)
{
    if(WOZI(wys))
    {
        this -> wyslane = wys;
        return true;
    }
    return false;
}
int  Produkt::getCena()
{
    return this -> ilosc;
}
string Produkt::getNazwaProd()
{
    return this ->nazwa;
}
int  Produkt::getID()
{
    return this -> ID;
}
int  Produkt::getIlosc()
{
    return this -> ilosc;
}
int  Produkt::getRezerwacja()
{
    return this -> rezerwacja;
}
int  Produkt::getWyslane()
{
    return this -> wyslane;
}