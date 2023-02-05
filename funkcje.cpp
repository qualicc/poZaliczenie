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

bool WOZI(int x)
{
    if(x >0)
    {
        return true;
    }
    return false;
}
bool WOZF(float x)
{
    if(x >0)
    {
        return true;
    }
    return false;
}
bool minMaxI(int min, int max, int z)
{
    if(min < z && z < max)
    {
        return true;
    }
    return false;
}
bool minMaxF(float min, float max, float z)
{
    if(min < z && z < max)
    {
        return true;
    }
    return false;
}
void tp(int x, int y)
{
     COORD c;
     c.Y = x-1;
     c.X = y-1;
     SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}
void wyswietl(Katalog aktualyKatalog)
{
    int koniecLini = 28, cyfra;
    char input = 0;
    string nazw;
    aktualyKatalog.aktualny = 0;   
    
    do
    {
        fflush(stdin);
        system("cls");
        if(aktualyKatalog.getArch() == true){
            cout<<"----------Archiwum----------"<<endl;
        }else{
            cout<<"----------------------------"<<endl;
        }
        cout<<"|ID: "<<aktualyKatalog.produkty[aktualyKatalog.aktualny].getID();
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< aktualyKatalog.produkty[aktualyKatalog.aktualny].getNazwaProd();
        tp(3,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< aktualyKatalog.produkty[aktualyKatalog.aktualny].getCena();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< aktualyKatalog.produkty[aktualyKatalog.aktualny].getIlosc();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (aktualyKatalog.produkty[aktualyKatalog.aktualny].getRezerwacja())+(aktualyKatalog.produkty[aktualyKatalog.aktualny].getWyslane());
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< aktualyKatalog.produkty[aktualyKatalog.aktualny].getRezerwacja();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< aktualyKatalog.produkty[aktualyKatalog.aktualny].getWyslane();
        tp(8,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|##########################|"<<endl;
        cout<<"|1. Zmien dane             |"<<endl;
        if(aktualyKatalog.getArch() == true){
            cout<<"|2. Odzyskaj               |"<<endl;
        }else{
            cout<<"|2. Archiwizuj             |"<<endl;
        }
        cout<<"|3. Usuń                   |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ESC. Wyjdz                |"<<endl;
        cout<<"|<A                      D>|"<<endl;
        cout<<"----------------------------"<<endl;    
        
        input = getch();
        switch (input)
        {
            case '1':
                aktualyKatalog.bufor.setID(aktualyKatalog.produkty[aktualyKatalog.aktualny].getID());
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
                        aktualyKatalog.bufor.setIlosc(cyfra);
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
                        aktualyKatalog.bufor.setRezerwacja(cyfra);
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
                        aktualyKatalog.bufor.setWyslane(cyfra);
                    }
                    
                } while (cyfra <= 0);
                cout<<endl<<"Napewno chcesz zamienic? T/N"<<endl;
                input = getch();
                if(input == 'T' || input == 't')
                {
                    if(aktualyKatalog.zamienJeden(aktualyKatalog.produkty[aktualyKatalog.aktualny].getID()))
                    {
                        cout<<endl<<"Zamieniono pomyslnie"<<endl;
                        system("pause");
                    }
                }
            break;
            case '2':
                if(aktualyKatalog.getArch() == true){
                    aktualyKatalog.produkty[aktualyKatalog.aktualny].odzyskaj();
                    aktualyKatalog.archCount--;
                }else{
                    aktualyKatalog.produkty[aktualyKatalog.aktualny].ukryj();
                    aktualyKatalog.archCount++;
                }
            break;
            case 68: case 100:
                aktualyKatalog.kolejny();
            break;
            case 65: case 97:
                aktualyKatalog.poprzedni();
            break; 
            case '3':
                aktualyKatalog.usun(aktualyKatalog.aktualny);
            break;          
            default:
            cout<<"zla komenda";
            break;
        }
        
    } while (input != 27);
}
void wyswietlaniePoWyszukaniu(Katalog aktualyKatalog)
{
    int koniecLini = 28, cyfra;
    char input = 0;
    string nazw;

    aktualyKatalog.aktualny = 0;

    do
    {
        fflush(stdin);
        system("cls");
        cout<<"----------Wyszukane---------"<<endl;
        cout<<"|Ilosc wyszukanych: "<<aktualyKatalog.counterWyszukane;
        tp(2,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ID: "<<aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getID();
        tp(4,koniecLini);cout<<"|"<<endl;
        cout<<"|nazwa: "<< aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getNazwaProd();
        tp(5,koniecLini);cout<<"|"<<endl;
        cout<<"|cena: "<< aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getCena();
        tp(6,koniecLini);cout<<"|"<<endl;
        cout<<"|ilosc: "<< aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getIlosc();
        tp(7,koniecLini);cout<<"|"<<endl;
        cout<<"|sprzedano: "<< (aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getRezerwacja())+(aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getWyslane());
        tp(8,koniecLini);cout<<"|"<<endl;
        cout<<"|rezerwacja: "<< aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getRezerwacja();
        tp(9,koniecLini);cout<<"|"<<endl;
        cout<<"|wyslano: "<< aktualyKatalog.wyszukane[aktualyKatalog.aktualny].getWyslane();
        tp(10,koniecLini);cout<<"|"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|##########################|"<<endl;
        cout<<"|1. Zmien dane             |"<<endl;
        cout<<"|2. Archiwizuj wyszystkie  |"<<endl;
        cout<<"|3. Zapisz wyszukane       |"<<endl;
        cout<<"|4. Wydrukuj wyszukane     |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|                          |"<<endl;
        cout<<"|ESC. Wyjdz                |"<<endl;
        cout<<"|<A                      D>|"<<endl;
        cout<<"----------------------------"<<endl;   

        input = getch();
        switch (input)
        {
        case '1':
            aktualyKatalog.bufor.setID(aktualyKatalog.produkty[aktualyKatalog.aktualny].getID());
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
                    aktualyKatalog.bufor.setIlosc(cyfra);
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
                    aktualyKatalog.bufor.setRezerwacja(cyfra);
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
                    aktualyKatalog.bufor.setWyslane(cyfra);
                }
                
            } while (cyfra <= 0);
            cout<<endl<<"Napewno chcesz zamienic? T/N"<<endl;
            input = getch();
            if(input == 'T' || input == 't')
            {
                if(aktualyKatalog.zamienJeden(aktualyKatalog.produkty[aktualyKatalog.aktualny].getID()))
                {
                    cout<<endl<<"Zamieniono pomyslnie"<<endl;
                    system("pause");
                }
            }
        break;
        
        case '2':
            if(aktualyKatalog.archiwizujWyszuakne())
            {
                cout<<"zarchiwizowano prawidlowo";
            }
            else
            {
                cout<<"blad masowego usuwania";
            }
        break;
        case '3':
            if (aktualyKatalog.zapisz(1,""))
            {
                cout<<"Zapisano poprawnie";
            }
            else
            {
                cout<<"Wystapil blad";  
            }
            system("pause");
        break;
        case '4':
            if (aktualyKatalog.print(1))
            {
                cout<<"Wydrukowano poprawnie";
            }
            else
            {
                cout<<"Wystapil blad";  
            }
            system("pause");
        break;
        case 'a':
        case 'A':
            aktualyKatalog.prevWysz();
        break;
    
        case 'd':
        case 'D':
            aktualyKatalog.nextWysz();
        break;
        
        default:
            cout<<"zla komenda";
        break;
        }
    } while (input != 27);
    input = 0;
}