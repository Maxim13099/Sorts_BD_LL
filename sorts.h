#ifndef SORTS_H
#define SORTS_H
#include <iostream>
using namespace std;
    void FillArray(int arr[], const int N);
    void ShowArray(int arr[], const int N);
    void BubbleSorts(int arr[], const int size);
    void SelectionSort(int arr[], const int size);
    void InsertionSort(int arr[], const int size);
    void CountingSort(int arr[], const int size);
    void mergeSort(int ar[], int size);
    static void merge(int ar[], int size, int central);
#endif // SORTS_H
