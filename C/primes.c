#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

void printPrimes(uint32_t limit) {
    uint32_t sqrt_limit = sqrt(limit);
    uint8_t *sieve = (uint8_t*) malloc((limit / 2 + 1) * sizeof(uint8_t));

    for (uint32_t i = 1; i <= sqrt_limit; i++) {
        if ((sieve[i / 8] & (1 << (i % 8))) == 0) {
            for (uint32_t j = i * (i + 1) * 2; j <= limit; j += (i * 2) + 1) {
                sieve[j / 16] |= (1 << ((j / 2) % 8));
            }
        }
    }

    printf("2\n");
    for (uint32_t i = 1; i <= limit / 2; i++) {
        if ((sieve[i / 8] & (1 << (i % 8))) == 0) {
            printf("%d\n", i * 2 + 1);
        }
    }

    free(sieve);
}

int main() {
    printPrimes(100000000);
    return 0;
}
