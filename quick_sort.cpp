#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
int *S; //for quick sort
void partition(int low, int high, int &pivot) {
    pivot = low;
    int i = low+1;
    int j = high;

    while(i<=j) {
        while(i<=high && S[i] <= S[pivot]) {
            i++;
        }
        while(j>=(low+1) && S[j] >= S[pivot]) {
            j--;
        }
        if(i>=j){
            swap(S[j], S[pivot]);
            pivot=j;
        }
        else{
            swap(S[j], S[i]);
        }
    }
}
void quicksort(int low, int high) {
    int pivot;
    if(high > low) {
        partition(low, high,pivot);
        quicksort(low, pivot-1);
        quicksort(pivot+1, high);
    }
}
