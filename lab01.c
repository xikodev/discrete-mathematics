#include <stdio.h>

__uint128_t factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void print_uint128(__uint128_t n) {
    char buf[50];
    int i = 0;

    if (n == 0) {
        putchar('0'); return;
    }

    while (n > 0) {
        buf[i] = '0' + (n % 10);
        n /= 10;
        i++;
    }

    while (i--) {
        putchar(buf[i]);
    }
}

int main(void) {
    int a, b, c, d, e, L;

    do {
        printf("Insert a, b, c, d, e:\n");
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    } while ((a < 0 || b < 0 || c < 0 || d < 0 || e < 0) && (a > 10 || b > 10 || c > 10 || d > 10 || e > 10));

    do {
        printf("Insert the word length L:\n");
        scanf("%d", &L);
    } while (L <= 0 || L > 25);

    printf("Number of combinations is: ");

    if (L > (a + b + c + d + e)) {
        printf("0");
        return 0;
    }

    long double e_x_L = 0;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= d; l++) {
                    for (int m = 0; m <= e; m++) {
                        if (i + j + k + l + m == L) {
                            e_x_L += 1.0/(factorial(i) * factorial(j) * factorial(k) * factorial(l) * factorial(m));
                        }
                    }
                }
            }
        }
    }

    __uint128_t result = factorial(L) * e_x_L;

    print_uint128(result);
    return 0;
}
