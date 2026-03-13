#pragma once
#include <initializer_list>
class Sort
{
    int* elem;
    int cnt;
    int Partition(int mic,int mare,bool ascendent);
    void Quickrecursie(int mic, int mare, bool ascendent);
public:
    Sort(int min, int max, int cnt);
    Sort(std::initializer_list<int> list);
    Sort(int* vector, int cnt);
    Sort(int cnt, ...);
    Sort(const char* str);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
