#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w; 
} Edge;

Edge *arr;     
Edge *sorted;  

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].w <= arr[j].w) {
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
    int N, M;

    if (scanf("%d %d", &N, &M) != 2) return 1;

    arr = (Edge*)malloc(sizeof(Edge) * M);
    sorted = (Edge*)malloc(sizeof(Edge) * M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
    }

    merge_sort(0, M - 1);

    int cost = 0;

    for (int i = 0; i < M; i++) {
       
        if () {
            
            cost += arr[i].w; 
             
        }
    }

    free(arr);
    free(sorted);

    return 0;
}