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
        int wielkosc,ID;
        string nazwa;

    public:
        Katalog(int rozmiar);
        bool import();
        bool save();
        float wartoscKatalogu(); //all                  warosc
        float wartoscProduktu(int id); //jeden      
        int iloscProduktow(); //all                     ilosc
        int iloscProduktu(int id); //jeden
        int iloscZarezerowanychProd(); //all            rezerwacja
        int iloscZarezerowanegoProd(int id); //jeden
        int iloscWyslanychProd(); //all                 wysylka
        int iloscWyslanegoProd(int id); //jeden
        int ktoDostarcza(int id); //                     dostawca



        // generowanie wielkości katalogu w konstrukcie poprzez wartość przekazywaną do konstrukta
        //
};
#include "funkcje.cpp"
#include "Produkt_metody.cpp"
#include "Katalog_metody.cpp"

main()
{
    srand(time(NULL));
}