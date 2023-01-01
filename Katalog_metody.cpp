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
    this -> aktualny = 0;   
    
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
    int koniecLini = 26, pion = 20, cyfra, sth, l1, l2, kierunek;
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
        cout<<"|5. Wyszukaj             |"<<endl;
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
                cout<<" ID      Nazwa               Cena        Ilosc       Sprzedano      Rezerwacja       Wyslano"<<endl;
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
                        
                        break;
                    case '2':
                        
                        break;
                    case '3':
                        
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
                        this -> poNazwie(nazw);
                        break;
                    case '2':
                        cout<<"Podaj przedzial min, max. (alby wybrac na podstawie jednej wartosci wprowadz 2 razy ta sama wartosc)"<<endl;
                        cin>>l1;
                        cout<<"-------------------"<<endl;
                        cin>> l2;
                        if (l1 <= l2 && l1 > 0)
                        {
                            wyszukniePrzedzialCena(l1, l2);
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
void Katalog::poNazwie(string text)
{
    this -> counterWyszukane = 0;
    this -> wyszukane =  new Produkt[this -> dane];
    int textLen = text.length(), checker;
    string nazwa;
    for (int i = 0; i <= this -> dane; i++)
    {
        checker = 0;
        nazwa = this -> produkty[i].getNazwaProd();
        for (int k = 0; k <= textLen; k++)
        {
            if (nazwa[k] == text[k] || (nazwa[k] + 32) == text[k] || (nazwa[k] - 32) == text[k])
            {
                checker++;
            }                

        }
        if (checker == textLen)
        {
            this -> wyszukane[this -> counterWyszukane] = this -> produkty[i];
            (this -> counterWyszukane)++;
        }
    }
    if(this -> counterWyszukane > 0)
    {
        this -> wyswietlaniePoWyszukaniu();
    }
    else
    {
        cout<<"nie znleziono";
        system("pause");
    }
    
}
void Katalog::wyswietlaniePoWyszukaniu()
{
    int koniecLini = 28, cyfra;
    char input = 0;
    string nazw;

    this -> aktualny = 0;

    do
    {
        fflush(stdin);
        system("cls");
        cout<<"----------Wyszukane---------"<<endl;
        cout<<"|Ilosc wyszukanych: "<<this -> counterWyszukane;
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ID: "<<this -> wyszukane[this ->aktualny].getID();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< this -> wyszukane[this ->aktualny].getNazwaProd();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< this -> wyszukane[this ->aktualny].getCena();
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< this -> wyszukane[this ->aktualny].getIlosc();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (this -> wyszukane[this ->aktualny].getRezerwacja())+(this -> wyszukane[this ->aktualny].getWyslane());
        tp(8,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< this -> wyszukane[this ->aktualny].getRezerwacja();
        tp(9,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< this -> wyszukane[this ->aktualny].getWyslane();
        tp(10,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|##########################|"<<endl;
        cout<<"|1. Zmien dane             |"<<endl;
        cout<<"|2. Archiwizuj wyszystkie  |"<<endl;
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
            if(archiwizujWyszuakne())
            {
                cout<<"zarchiwizowano prawidlowo";
            }
        break;

        case 'a':
        case 'A':
            this -> prevWysz();
        break;
    
        case 'd':
        case 'D':
            this -> nextWysz();
        break;
        
        default:
            cout<<"zla komenda";
        break;
        }
    } while (input != 27);
    input = 0;
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
        return true;
    }
    catch(const std::exception& e)
    {
        cout<<"blad masowego usuwania";
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
void Katalog::wyszukniePrzedzialCena(float min, float max)
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
        this -> wyswietlaniePoWyszukaniu();
    }
    else
    {
        cout<<"nie znleziono";
        system("pause");
    }
}
void Katalog::sortNazwa(bool kierunek)
{
    string t1,t2;
    int l, t1L,t2L;
    for(int i = 0; i < this -> dane; i++)
    {
        for(int k = 1; k < (this -> dane - i); k++)
        {           
            t1 = this -> produkty[k - 1].getNazwaProd();
            t2 = this -> produkty[k].getNazwaProd();
            switch (kierunek)
            {
            case 0:
                {
                    if (t1.length() >= t2.length())
                    {
                        do
                        {
                            if(t1[l] > t2[l])
                            {
                                this -> bufor = this -> produkty[k - 1];
                                this -> produkty[k - 1] = this -> produkty[k];
                                this -> produkty[k] = this -> bufor;
                                break;
                            }
                            else if (t1[l] == t2[l])
                            {
                                l++;
                            }
                            else
                            {
                                break;
                            }    
                        } while (t1[l] == t2[l] || t1.length() >= l);
                    }
                    else
                    {
                        do
                        {
                            if(t1[l] > t2[l])
                            {
                                this -> bufor = this -> produkty[k - 1];
                                this -> produkty[k - 1] = this -> produkty[k];
                                this -> produkty[k] = this -> bufor;
                                break;
                            }
                            else if (t1[l] == t2[l])
                            {
                                l++;
                            }
                            else
                            {
                                break;
                            }    
                        } while (t1[l] == t2[l] || t2.length() >= l);                
                    }
                }
                break;
            
            case 1:
                {
                    if (t1.length() >= t2.length())
                    {
                        do
                        {
                            if(t1[l] < t2[l])
                            {
                                this -> bufor = this -> produkty[k - 1];
                                this -> produkty[k - 1] = this -> produkty[k];
                                this -> produkty[k] = this -> bufor;
                                break;
                            }
                            else if (t1[l] == t2[l])
                            {
                                l++;
                            }
                            else
                            {
                                break;
                            }    
                        } while (t1[l] == t2[l] || t1.length() >= l);
                    }
                    else
                    {
                        do
                        {
                            if(t1[l] < t2[l])
                            {
                                this -> bufor = this -> produkty[k - 1];
                                this -> produkty[k - 1] = this -> produkty[k];
                                this -> produkty[k] = this -> bufor;
                                break;
                            }
                            else if (t1[l] == t2[l])
                            {
                                l++;
                            }
                            else
                            {
                                break;
                            }    
                        } while (t1[l] == t2[l] || t2.length() >= l);                
                    }
                }
                break;
            }
            
        }
    }
		
}
void Katalog::sortCena(bool kierunek)
{

}
void Katalog::sortId(bool kierunek)
{

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