#include<iostream>
using namespace std;
#include<string>
#define N 10
#define M 100
void swap(int a, int b);
void selectSort(int* a);
void print(int* a);
void insertSort(int* a);
void shellSort(int* a);
void quickSort(int* a,int left,int right);
int partition(int* a, int left, int right);
void qsort(int* a, int low, int high);