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