#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
int *M; //for merge sort

void merge(int low, int mid, int high) {
    int i, j, k;
    int *U = new int[high-low+1]; //temp array for merging
    i = low; j = mid+1; k = low;
    while(i <= mid && j <= high) {
        if(M[i] < M[j]) {
            U[k-low] = M[i];
            i++;
        }
        else {
            U[k-low] = M[j];
            j++;
        }
        k++;
    }
    if(i>mid)
        for(int s=j; s<=high; s++) {
            U[k-low]=M[s];
            k++;
        }
    else {
        for(int s=i; s<=mid; s++){
            U[k-low]=M[s];
            k++;
        }
    }
    for(int s=low; s<=high; s++){
        M[s] = U[s-low];
    }
    delete[]U;
}

void mergesort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid+1, high);
        merge(low, mid, high);
    }
}
