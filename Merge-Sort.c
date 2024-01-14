#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 200000

void InsertionSort(int A[]);
void Merge(int A[], int p, int q, int r);
void MergeSort(int A[],int p, int r);

int main()
{
    int A1[ARRAYSIZE];
    int A2[ARRAYSIZE];
    int i;
    int num;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        num = rand();
        A1[i] = num;
        A2[i] = num;
    }

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }

    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    InsertionSort(A1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Eklemeli Siralama): %f saniyedir.\n", cpu_time_used);

    start_t = clock();
    MergeSort(A2,0,ARRAYSIZE-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Birlestirmeli Siralama): %f saniyedir.\n", cpu_time_used);

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }

    return 0;
}

void InsertionSort(int A[])
{
    int i,j,key;
    for(j = 1; j < ARRAYSIZE; j++)
    {
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void Merge(int A[], int p, int q, int r)
{
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];

    for(i = 0;i<n1;i++){
        L[i] = A[p+i];
    }
    for(j = 0;j<n2;j++){
        R[j] = A[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(int k = p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i = i+1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void MergeSort(int A[],int p, int r)
{
    if(p<r){
        int q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
