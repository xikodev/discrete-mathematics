#include <stdio.h>
#include <string.h>

#define MAX_FILENAME        25

int main() {
    char filename[MAX_FILENAME];
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME, stdin);

    filename[strcspn(filename, "\n")] = '\0';

    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error: cannot open file '%s'\n", filename);
        return 1;
    }

    int n;
    fscanf(f, "%d", &n);

    int A[n][n];

    for (int i = 0; i < n; i++) {
        char buffer[n];
        fscanf(f, "%s", buffer);

        for (int j = 0; j < n; j++) {
            A[i][j] = buffer[j] - '0';
        }
    }

    fclose(f);

    printf("Loaded adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    int count = 0;

    /*
    For a subraph to be isomorphic to C3 we need to check these:
    A[i][j] == 1
    A[j][k] == 1
    A[i][k] == 1
     */

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!A[i][j]) {
                continue;
            }
            for (int k = j + 1; k < n; k++) {
                if (A[i][k] && A[j][k]) {
                    count++;
                }
            }
        }
    }

    printf("\nSolution: %d", count);

    return 0;
}
