#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 1000 
void merge(int a[MAX], int low, int mid, int high) 
{ 
    int i, j, k, b[MAX]; 
    i = low; 
    j = mid + 1; 
    k = low; 
    while (i <= mid && j <= high) 
    { 
        if (a[i] < a[j]) 
        { 
            b[k++] = a[i++]; 
        } 
        else 
        { 
            b[k++] = a[j++]; 
        } 
    } 
    while (i <= mid) 
    { 
        b[k++] = a[i++]; 
    } 
    while (j <= high) 
    { 
        b[k++] = a[j++]; 
    } 
    for (i = low; i <= high; i++) 
    { 
        a[i] = b[i]; 
    } 
} 
void mergesort(int a[MAX], int low, int high) 
{ 
    int mid; 
    if (low < high) 
    { 
        mid = (low + high) / 2; 
        mergesort(a, low, mid); 
        mergesort(a, mid + 1, high); 
        merge(a, low, mid, high); 
    } 
} 

void presort(int n,int a[]){
    for(int i =0;i<=n-2;i++){
        if(a[i]==a[i+1]){
            printf("the element in the array is not unique \n");
            return;
        }
    }
    printf("the element in the array is unique \n");


}

int main() 
{ 
    int i, j, n, a[MAX];
    printf("\nEnter n: "); 
    scanf("%d", &n); 
    printf("\nEnter elements: "); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%d", &a[i]); 
    } 
    mergesort(a, 0, n - 1); 
    printf("\nSorted elements: \n"); 
    for (i = 0; i < n; i++) 
    { 
        printf("%d ", a[i]); 
    } 
    presort(n,a);
    return 0;}


    