#include <iostream>
#include <windows.h>
#include "Canva.h"

int main() {
    Canvas c(60, 30);
    c.Clear(); 
    c.DrawCircle(30, 15, 10, 'X');
    c.Print();
    Sleep(1000);        
    system("cls");
    c.Clear();
    c.DrawRect(10, 10, 55, 20, 'X');
    c.Print();
    Sleep(2000);
    system("cls");
    c.Clear();
    c.FillCircle(40, 15, 10, 'X');
    c.Print();

    return 0;
}