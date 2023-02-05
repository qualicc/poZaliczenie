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
void Katalog::buduj(int x)
{
    produkty = new Produkt[x];
    this -> wielkosc = x;
}
void Katalog::setWielkosc(int x)
{
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
void Katalog::setDataCount(int x)
{
    this -> dane = x; 
}

void Katalog::generuj(int x)
{
    for (int i = 0; i <= (x - 1); i++)
    {
        this -> produkty[(this -> dane + i)].losuj((this -> dane + i + 1));
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
bool Katalog::poNazwie(string text)
{
    this -> counterWyszukane = 0;
    this -> wyszukane =  new Produkt[this -> dane];
    string nazwa;
    for (int i = 0; i < this -> dane; i++)
    {

        nazwa = this -> produkty[i].getNazwaProd();
        size_t found = nazwa.find(text);
        
        if (found != string::npos)
        {
            this -> counterWyszukane++;
            this -> wyszukane[this -> counterWyszukane] = this -> produkty[i];
        }
    }
    if(this -> counterWyszukane > 0)
    {

        return true;
    }
    else
    {
        return false;
    }
    
}
bool Katalog::archiwizujWyszuakne()
{
    try
    {
        for (int i = 0; i < (this -> counterWyszukane - 1); i++)
        {
            for (int k = 0; k < this -> dane; k++)
            {
                if(this -> produkty[k].getID() == this -> wyszukane[i].getID())
                {
                    this -> produkty[k].ukryj();
                }
            }
        }
        this -> arch = this -> arch + this -> counterWyszukane;
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
}
void Katalog::nextWysz()
{
    int x = 1;

    if((this -> aktualny+1) <= this -> counterWyszukane)
    {
        do
        {
            if (this -> produkty[aktualny+x].getStatus() != getArch())
            {
                x++;
            }

        } while (this -> produkty[aktualny+x].getStatus() != getArch());

        if ((x + this -> aktualny) >= this -> counterWyszukane)
        {
            x = 0;
        }

        this -> aktualny = aktualny + x;
    }
}
void Katalog::prevWysz()
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
bool Katalog::wyszukniePrzedzialCena(float min, float max)
{
    this -> counterWyszukane = 0;
    this -> wyszukane =  new Produkt[this -> dane];
    if(min != max)
    {
        for (int i = 0; i <= this -> dane; i++)
        {
            if(this -> produkty[i].getCena() >= min && this -> produkty[i].getCena() <= max)
            {
                this -> wyszukane[this -> counterWyszukane] = this ->produkty[i];
                (this -> counterWyszukane)++;
            }
        }
    }
    else
    {
        for (int i = 0; i <= this -> dane; i++)
        {
            if(this -> produkty[i].getCena() == min)
            {
                this -> wyszukane[this -> counterWyszukane] = this ->produkty[i];
                (this -> counterWyszukane)++;
            }
        }
    }
    if(this -> counterWyszukane > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Katalog::sortNazwa(bool kierunek)
{
    for(int i = 0; i < this -> dane; i++)
    {
        for(int k = 1; k < (this -> dane - i); k++)
        {           
            switch (kierunek)
            {
            case 0:
                if(this -> produkty[k - 1].getNazwaProd() > this -> produkty[k].getNazwaProd())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }
                break;
            
            case 1:
                if(this -> produkty[k - 1].getNazwaProd() < this -> produkty[k].getNazwaProd())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }                
                break;
            }
            
        }
    }
		
}
void Katalog::sortCena(bool kierunek)
{
    for(int i = 0; i < this -> dane; i++)
    {
        for(int k = 1; k < (this -> dane - i); k++)
        {           
            switch (kierunek)
            {
            case 0:
                if(this -> produkty[k - 1].getCena() > this -> produkty[k].getCena())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }
                break;
            
            case 1:
                if(this -> produkty[k - 1].getCena() < this -> produkty[k].getCena())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }                
                break;
            }
            
        }
    }
}
void Katalog::sortId(bool kierunek)
{
    for(int i = 0; i < this -> dane; i++)
    {
        for(int k = 1; k < (this -> dane - i); k++)
        {           
            switch (kierunek)
            {
            case 0:
                if(this -> produkty[k - 1].getID() > this -> produkty[k].getID())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }
                break;
            
            case 1:
                if(this -> produkty[k - 1].getID() < this -> produkty[k].getID())
                {
                    this -> bufor = this -> produkty[k - 1];
                    this -> produkty[k - 1] = this -> produkty[k];
                    this -> produkty[k] = this -> bufor;
                }                
                break;
            }
            
        }
    }
}
bool Katalog::print(bool mode)
{
    try
    {
        long X;
        string strN = this -> nazwa;
        int dl;
        strN.append(".txt");
        char* nazwaPliku = new char[this -> nazwa.length()];
        strcpy(nazwaPliku, strN.c_str());
        ofstream file(nazwaPliku);
        Produkt *tab; 
        file<<" ID      Nazwa               Cena        Ilosc       Sprzedano      Rezerwacja       Wyslano"<<endl;
        
        switch (!mode)
        {
        case 1:
            tab = this -> produkty;
            dl = this -> dane;
            break;
        case 0:
            tab = this -> wyszukane; 
            dl = this -> counterWyszukane;
            break;        
        } 

        for (int i = 0; i < dl; i++)
        {
            if (tab[i].getStatus() == false)
            {
                X = file.tellp();
                file.seekp (X + 1);
                file<< tab[i].getID();
                file.seekp (X + 9);
                file<< tab[i].getNazwaProd();
                file.seekp (X + 29);
                file<< tab[i].getCena();
                file.seekp (X + 41);
                file<< tab[i].getIlosc();
                file.seekp (X + 53);
                file<< (tab[i].getWyslane() + tab[i].getRezerwacja());
                file.seekp (X + 68);
                file<< tab[i].getRezerwacja();
                file.seekp (X + 85);
                file<< tab[i].getWyslane()<<endl;
            }    
        }
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return false;
}
bool Katalog::zapisz(bool mode, string nazwaPliku)
{
    try
    {
        long X;
        string strN;
        
        if (nazwaPliku == "")
        {
            strN = this -> nazwa;
        }
        else
        {
            strN = nazwaPliku;
        }
        
        int dl;
        strN.append(".save");
        char* nazwaKoncowa = new char[strN.length()];
        strcpy(nazwaKoncowa, strN.c_str());
        ofstream file(nazwaKoncowa);
        Produkt *tab;
        
        switch (!mode)
        {
        case 1:
            tab = this -> produkty;
            dl = this -> dane;
            break;
        case 0:
            tab = this -> wyszukane; 
            dl = this -> counterWyszukane;
            break;        
        } 
        //zapis
        file<<this -> nazwa<<endl;
        file<<this -> wielkosc<<endl;
        file<<this -> dane<<endl;
        for (int i = 0; i < dl; i++)
        {
            file<<tab[i].getID()<<endl;
            file<<tab[i].getNazwaProd()<<endl;
            file<<tab[i].getCena()<<endl;
            file<<tab[i].getIlosc()<<endl;
            file<<tab[i].getWyslane()<<endl;
            file<<tab[i].getRezerwacja()<<endl;
            file<<tab[i].getStatus()<<endl;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return false;
}
void Katalog::wczytaj(string nazw)
{
    nazw.append(".save");
    char* nazwaKoncowa = new char[nazw.length()];
    strcpy(nazwaKoncowa, nazw.c_str());
    string buff;


    ifstream file;
    file.open(nazwaKoncowa);
    getline(file,buff);
    this -> setNazwa(buff);
    getline(file,buff);
    this -> buduj(stoi(buff));
    getline(file,buff);
    this -> setDataCount(stoi(buff));
    for (int i = 0; i < this -> dane; i++)
    {
        //ID
        getline(file,buff);
        this -> produkty[i].setID(stoi(buff));

        //nazwa
        getline(file,buff);
        this -> produkty[i].setNazwaProd(buff);
        
        //cena
        getline(file,buff);
        this -> produkty[i].setCena(stof(buff));
        
        //ilosc
        getline(file,buff);
        this -> produkty[i].setIlosc(stoi(buff));
        
        //wyslane
        getline(file,buff);
        this -> produkty[i].setWyslane(stoi(buff));
        
        //rezerwacja
        getline(file,buff);
        this -> produkty[i].setRezerwacja(stoi(buff));
        
        //ukrycie
        getline(file,buff);
        this -> produkty[i].setStatus(stoi(buff));
        
    }
    
    file.close();

}
void Katalog::setAktualny()
{
    this -> aktualny = 0;
}
void Katalog::setAktualny(int x)
{
    this -> aktualny = x;
}
int Katalog::getWielkosc()
{
    return this -> wielkosc;
}
int Katalog::getIloscDanych()
{
    return this -> dane;
}
void Katalog::usun()
{
    for (int i = this -> aktualny; i < this -> dane; i++)
    {
        this -> bufor = this -> produkty[i+1];
        this -> produkty[i] = this -> bufor;
    }
    (this -> dane)--;
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



//zapis budowa
// [nazwa]
// [wielkosc]
// [ilosc danych]
// [id]
// [nazwa]
// [cena]
// [ilosc]
// [wyslane]
// [rezerwacja]
// [ukrycie]
// [...]
