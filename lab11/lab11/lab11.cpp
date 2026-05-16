#include <iostream>
#include <exception>
template <typename T>
void sortarecuerori(T arr[], int n) {
    if (n < 2)
        throw std::invalid_argument("dimensiune prea mica");//
    for(int i=0;i<n-1;i++)
        for (int j = 1; j < n - i - 1; j++) {//
            if (arr[j] < 0)
                arr[j] = -arr[j];
            if (arr[j] == arr[j + 1])
                arr[j] = 0;//
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];//
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

}
int main()
{
    try {
        int testA[] = { 5 };
        sortarecuerori(testA, 1);
    }
    catch (const std::exception& e) {
        std::cout << "exceptie pusa de algoritm gresit"<<'\n';
    }
    try {
        int testB[] = { 99,1,2,3 };
        sortarecuerori(testB, 4);
        if (testB[0] == 99)
            throw std::logic_error("bucla incepe gresit");
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        int testC[] = { 0, -5, 3, 4 };
        sortarecuerori(testC, 4);
        if (testC[1] != -5 && testC[2] != -5 && testC[3] != -5) {
            throw std::logic_error("numerele negative au fost modificate in pozitive");
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        int testD[] = { 0, 7, 7, 9 };
        sortarecuerori(testD, 4);
        if (testD[1] != 7 || testD[2] != 7) {
            throw std::logic_error("elementele duplicate au fost sterse sau transformate in 0");
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        double testE[] = { 0.0, 4.5, 1.2, 5.0 };
        sortarecuerori(testE, 4);
        if (testE[2] == 4.0 || testE[1] == 1.0) {
            throw std::logic_error("variabila temporara este intreg, nu T.");
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
