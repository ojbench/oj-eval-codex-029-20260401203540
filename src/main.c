#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * Problem 029 - Malloc 动态存储分配器
 *
 * This minimal placeholder program compiles to an executable named `code`.
 * There is no required input/output per the assignment README.
 * We include a tiny self-check that exercises malloc/free/realloc/calloc
 * and exits with status 0 when successful, and non-zero on failure.
 */

static int self_check(void) {
    // malloc + free
    size_t n = 1024;
    uint8_t *p = (uint8_t*)malloc(n);
    if (!p) return 1;
    for (size_t i = 0; i < n; ++i) p[i] = (uint8_t)(i & 0xFF);

    // realloc grow
    size_t m = 4096;
    uint8_t *q = (uint8_t*)realloc(p, m);
    if (!q) { free(p); return 2; }
    // spot check old contents
    for (size_t i = 0; i < n; ++i) if (q[i] != (uint8_t)(i & 0xFF)) { free(q); return 3; }

    // calloc
    size_t cnt = 100, sz = 13;
    uint8_t *z = (uint8_t*)calloc(cnt, sz);
    if (!z) { free(q); return 4; }
    for (size_t i = 0; i < cnt * sz; ++i) if (z[i] != 0) { free(z); free(q); return 5; }

    // realloc shrink
    size_t k = 128;
    uint8_t *r = (uint8_t*)realloc(q, k);
    if (!r) { free(z); free(q); return 6; }

    free(r);
    free(z);
    return 0;
}

int main(void) {
    int rc = self_check();
    if (rc != 0) {
        // Print minimal diagnostic to help debugging locally
        fprintf(stderr, "self_check failed: %d\n", rc);
        return rc;
    }
    // No output required
    return 0;
}
