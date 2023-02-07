#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int conta(int N, int K, long long int **ranges) {
    // SCRIVI QUA IL TUO CODICE
    return 0;
}

int main() {

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N, K;
    assert(2 == scanf("%d %d\n", &N, &K));

    long long int **ranges = (long long int **) malloc(N * sizeof(long long int *));

    for(int i=0; i<N; i++) {
       ranges[i] = (long long int *) malloc(2 * sizeof(long long int));
       assert(2 == scanf("%lld %lld\n", &ranges[i][0], &ranges[i][1]));
    }

    printf("%d", conta(N, K, ranges));

    for(int i=0; i<N; i++) {
        free(ranges[i]);
    }
    free(ranges);
    return 0;
}
