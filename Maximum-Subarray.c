#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 365

typedef struct subArray
{
    int maxBasla;
    int maxSon;
    int maxToplam;
}subArray;

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high);
subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);
subArray BruteForce(int A[]);

int main()
{
    int i;
    int fiyatlar[ARRAYSIZE];
    int degisim[ARRAYSIZE];
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        fiyatlar[i] = (rand() % 120) + 1;
    }
    for(i = 1; i < ARRAYSIZE; i++)
    {
        degisim[i] = fiyatlar[i] - fiyatlar[i-1];
    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i, fiyatlar[i]);
    }
    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    subArray res = FIND_MAXIMUM_SUBARRAY(degisim,1,ARRAYSIZE-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Bol ve yonet yontemi): %f saniyedir.\n", cpu_time_used);

    printf("Al: %d\n", res.maxBasla - 1);
    printf("Sat: %d\n", res.maxSon);
    printf("Kar: %d\n", res.maxToplam);

    start_t = clock();
    subArray res2 = BruteForce(fiyatlar);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Kaba kuvvet): %f saniyedir.\n", cpu_time_used);
    printf("Al: %d\n", res2.maxBasla);
    printf("Sat: %d\n", res2.maxSon);
    printf("Kar: %d\n", res2.maxToplam);
	return 0;
}

subArray BruteForce(int A[])
{
    int i,j;
    subArray res;
    res.maxToplam = 0;
    for(int i = 0; i < ARRAYSIZE; i++) {
        for(int j = i+1; j < ARRAYSIZE; j++) {
            if(A[j]-A[i] > res.maxToplam){
                res.maxBasla = i;
                res.maxSon = j;
                res.maxToplam = A[j] - A[i];
            }
        }
    }

    return res;
}

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
    subArray res;
    int left_sum = INT_MIN;
    int max_left;
    int max_right;
    int sum = 0;
    for(int i = mid;i > low; i--) {
        sum = sum + A[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;

    for(int j = mid + 1;j < high; j++) {
        sum = sum + A[j];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    res.maxToplam = left_sum + right_sum;

    return res;
}

subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
    subArray res;
    subArray left_res;
    subArray right_res;
    subArray cross_res;
    int mid;

    if(high == low) {
        res.maxBasla = low;
        res.maxSon = high;
        res.maxToplam = A[low];
        return res;
    } else {
        int mid = (low + high) / 2;
        left_res = FIND_MAXIMUM_SUBARRAY(A,low,mid);
        right_res = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
        cross_res = FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);
        if(left_res.maxToplam >= right_res.maxToplam && left_res.maxToplam >= cross_res.maxToplam)
            return left_res;
        else if(right_res.maxToplam >= left_res.maxToplam && right_res.maxToplam >= cross_res.maxToplam)
            return right_res;
        else
            return cross_res;
    }
}
