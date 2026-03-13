#include <iostream>
#include "Sort.h"

int main() {
    Sort s1(5, 30, 10);
    s1.BubbleSort(true);
    s1.Print();
    Sort s2 = { 12, 4, 89, 43, 21 };
    s2.InsertSort(false);
    s2.Print();
    int arr[] = { 100, 23, 4, 1, 78, 30 };
    Sort s3(arr, 6);
    s3.QuickSort(true);
    s3.Print();
    Sort s4(6, 50, 20, 90, 10, 60, 30);
    s4.BubbleSort(false);
    s4.Print();
    Sort s5("10,40,100,5,70");
    s5.QuickSort(true);
    s5.Print();
    return 0;
}