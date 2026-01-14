#include <stdio.h>
#include <stdlib.h>

int *arr;    
int *sorted;  

void merge(int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        } else {
            sorted[k++] = arr[j++];
        }
    }

    if (i > mid) {
        for (int t = j; t <= right; t++) sorted[k++] = arr[t];
    } else {
        for (int t = i; t <= mid; t++) sorted[k++] = arr[t];
    }

    for (int t = left; t <= right; t++) {
        arr[t] = sorted[t];
    }
}

void merge_sort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);      
        merge_sort(mid + 1, right); 
        merge(left, mid, right);   
    }
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) return 1;

    
    arr = (int*)malloc(sizeof(int) * N);
    sorted = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);
    free(sorted);

    return 0;
}