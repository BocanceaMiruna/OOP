#include <iostream>//.cpp
#include "header.h"
int main()
{
    NumberList listamea;
    listamea.Init();
    listamea.Add(11);
    listamea.Add(1);
    listamea.Add(100);
    listamea.Add(3);
    listamea.Add(22);
   // listamea.Print();
    listamea.Sort();
    listamea.Print();

}
