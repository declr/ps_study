#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000

int N, M, K, X;

typedef struct NODE {
    int index;
    struct NODE* next;
} node;
node* graph[MAX_N];

int dist[MAX_N];

int queue[MAX_N];
int front = 0, rear = 0;

void add_edge(int u, int v) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->index = v;
    new_node->next = graph[u]; 
    graph[u] = new_node;       
}

void bfs(int start) {

    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }

    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        node* curr_node = graph[current];
        while (curr_node != NULL) {
            int next_city = curr_node->index;

            if (dist[next_city] == -1) {
                dist[next_city] = dist[current] + 1; 
                queue[rear++] = next_city;           
            }
            curr_node = curr_node->next;
        }
    }
}

int main() {

    if (scanf("%d %d %d %d", &N, &M, &K, &X) != 4) return 1;

    for (int i = 0; i < M; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) break;
        add_edge(u, v);
    }

    bfs(X);

    int found = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            printf("%d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1\n");
    }

    return 0;
}