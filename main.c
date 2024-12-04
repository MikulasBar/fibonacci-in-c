#include <stdio.h>

typedef unsigned long long number;

typedef struct {
    number x; // the whole number part
    number y; // the sqrt5 part 
} z_r5;

z_r5 z_r5_init(number x, number y) {
    z_r5 res = {x, y};
    return res;
}

z_r5 z_r5_sub(z_r5 a, z_r5 b) {
    return z_r5_init(
        a.x - b.x,
        a.y - b.y
    );
}

z_r5 z_r5_mul(z_r5 a, z_r5 b) {
    return z_r5_init(
        a.x * b.x + 5 * a.y * b.y,
        a.x * b.y + a.y * b.x
    );
}

z_r5 z_r5_pow(z_r5 base, size_t exp) {
    size_t i = 0;
    z_r5 res = z_r5_init(1, 0);

    while (i < exp) {
        res = z_r5_mul(res, base);
        i++;
    }

    return res;
}

// these are only the numerators
#define PHI_A z_r5_init(1, 1)
#define PHI_B z_r5_init(1, -1)

number fibonacci(size_t n) {
    z_r5 phi_a = z_r5_pow(PHI_A, n);
    z_r5 phi_b = z_r5_pow(PHI_B, n);
    z_r5 diff = z_r5_sub(phi_a, phi_b);

    return diff.y >> n;
}


int main(void) {
    size_t n = 50;

    for (size_t i = 0; i < n; i++) {
        number res = fibonacci(i);
        printf("%llu\n", res);
    }
    
    return 0;
}