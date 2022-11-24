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
    public:
        char nazwa[20];//1
        int ilosc, dostawca, rezerwacja, wyslane, ID;
        float cena;
        bool ukrycie = false;//1
        //metody
        void ukryj();
        void odzyskaj();
        void losuj();
        bool zarezeruj(int ile);
        bool wyslij(int ile);
        bool zwroc(int ile);
        //set i get
        bool setCena(int cena);
        bool setNazwa(char naz);
        bool setDostawca(int dost);
        bool setID(int id);
        bool setIlosc(int ilosc);
        bool setRezerwacja(int rez);
        bool setWyslane(int wys);
        int  getCena();
        int  getDostawca();
        char getNazwa();
        int  getID();
        int  getIlosc();
        int  getRezerwacja();
        int  getWyslane();

};
#include "funkcje.cpp"
#include "Produkt_metody.cpp"
#include "Magazyn_metody.cpp"

main()
{
    srand(time(NULL));
}