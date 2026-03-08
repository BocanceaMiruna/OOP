
#include <iostream>

int main()
{
    FILE* f = NULL;
   fopen_s(&f,"in.txt","r");
   char linie[1000];
   int s=0;
   while (fgets(linie,sizeof(linie),f)!=NULL){
       int i = 0,nr=0;
       while (linie[i] >= '0' && linie[i] <= '9')
            nr = nr * 10 + (linie[i] - '0'),i++;
       s +=nr ;
    }
   std::cout << s;
   fclose(f);
}
