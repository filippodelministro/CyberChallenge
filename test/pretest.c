#include <stdio.h>
#include <assert.h>
#define MAXN 1001


int calcola_punteggio(int Q, char correct[], char candidate[]) {
    // SCRIVI QUA IL TUO CODICE
    return 0;
}

int main() {

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N, Q;
    char correct[MAXN];
    char candidate[MAXN];

    assert(2 == scanf("%d %d", &Q, &N));
    assert(1 == scanf("%s", correct));

    for(int i=0; i<N; i++) {
        assert(1 == scanf("%s", candidate));
        printf("%d\n", calcola_punteggio(Q, correct, candidate));
    }

    return 0;
}