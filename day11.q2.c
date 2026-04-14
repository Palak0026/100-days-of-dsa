#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[1000][1000];
    int transpose[1000][1000];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = matrix[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    return 0;
}