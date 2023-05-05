#include <iostream>
#include <chrono>
#include "realize.h"
#include "sorts.h"
using namespace std;

double BubbleSortTime(int sizeT){
    int size = sizeT;
    int arr[size];
    FillArray(arr, size);
    auto start=std::chrono::high_resolution_clock::now();
    BubbleSorts(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>diff = end - start;
    return diff.count();
}

double SelectionSortTime(int sizeT){
    int size = sizeT;
    int arr[size];
    FillArray(arr, size);
    auto start=std::chrono::high_resolution_clock::now();
    SelectionSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>diff = end - start;
    return diff.count();
}

double InsertionSortTime(int sizeT){
    int size = sizeT;
    int arr[size];
    FillArray(arr, size);
    auto start=std::chrono::high_resolution_clock::now();
    InsertionSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>diff = end - start;
    return diff.count();
}

double CountingSortTime(int sizeT){
    int size = sizeT;
    int arr[size];
    FillArray(arr, size);
    auto start=std::chrono::high_resolution_clock::now();
    CountingSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>diff = end - start;
    return diff.count();
}

double MergeSortTime(int sizeT){
    int size = sizeT;
    int arr[size];
    FillArray(arr, size);
    auto start=std::chrono::high_resolution_clock::now();
    mergeSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>diff = end - start;
    return diff.count();
}
