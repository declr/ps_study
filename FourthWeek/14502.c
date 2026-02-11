#include <stdio.h>
#include <stdlib.h>
int N, M;
int **map;
int temp[8][8];     
int result = 0;     


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void dfs_virus(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                dfs_virus(nx, ny); 
            }
        }
    }
}


int get_score() {
    int score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) {
                score++;
            }
        }
    }
    return score;
}


void dfs_wall(int count) {
   
    if (count == 3) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = map[i][j];
            }
        }

        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (temp[i][j] == 2) {
                    dfs_virus(i, j); 
                }
            }
        }

        int current_score = get_score();
        if (current_score > result) {
            result = current_score;
        }
        return;
    }

 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) { 
                map[i][j] = 1;    
                dfs_wall(count + 1); 
                map[i][j] = 0;   
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    map = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        map[i] = (int*)malloc(sizeof(int) * M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    dfs_wall(0); 

    printf("%d\n", result);


}