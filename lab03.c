#include <stdio.h>

#define MAXN 60
#define MAXM (MAXN*(MAXN-1)/2)

typedef struct {
    int a;
    int b;
} Edge;

static unsigned char adj[MAXN][MAXN];
static Edge edges[MAXM];
static int edge_color[MAXM];
static unsigned used_mask[MAXN];

static int n;
static int m;
static int delta;
static unsigned FULL_MASK;

static int dfs(int k) {
    if (k == m) {
        return 1;
    }

    int a = edges[k].a;
    int b = edges[k].b;

    unsigned avail = FULL_MASK & ~(used_mask[a] | used_mask[b]);

    while (avail != 0) {
        unsigned bit = avail & (~avail + 1u);

        used_mask[a] |= bit;
        used_mask[b] |= bit;

        if (dfs(k + 1)) {
            return 1;
        }

        used_mask[a] ^= bit;
        used_mask[b] ^= bit;

        avail -= bit;
    }

    return 0;
}

int main(void) {
    char filename[256];
    char line[MAXN + 5];

    printf("Enter file name: ");
    if (scanf("%255s", filename) != 1) {
        return 0;
    }

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return 0;
    }

    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(f, "%s", line);
        for (int j = 0; j < n; j++) {
            if (line[j] == '1') {
                adj[i][j] = 1;
            } else {
                adj[i][j] = 0;
            }
        }
    }
    fclose(f);

    int degree[MAXN];
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
    }

    m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] == 1) {
                edges[m].a = i;
                edges[m].b = j;
                m++;

                degree[i]++;
                degree[j]++;
            }
        }
    }

    delta = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] > delta) {
            delta = degree[i];
        }
    }

    int ok;

    if (m == 0 || delta == 0) {
        ok = 1;
    } else if (delta > 31) {
        ok = 0;
    } else {
        for (int i = 0; i < n; i++) {
            used_mask[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            edge_color[i] = -1;
        }

        FULL_MASK = (1u << delta) - 1u;
        ok = dfs(0);
    }

    printf("%d\n", delta);
    printf("%d\n", ok);

    return 0;
}
