#include <iostream>
#include "Students.h"
#include "HeaderGlobal.h"
int main()
{
    students s1;
    s1.nume("Miruna");
    s1.addmate(5.0f);
    s1.addeng(8.1f);
    s1.addhistory(6.1f);
    students s2;
    s2.nume("Marcel");
    s2.addmate(4.0f);
    s2.addeng(8.9f);
    s2.addhistory(7.1f);
    std::cout << s1.average()<<"=medie ";
    std::cout << cmpmate(s1, s2)<<" ";

}
