#include <stdio.h>
#include <assert.h>
#define MAXN 1001


int calcola_punteggio(int Q, char correct[], char candidate[]) {
    int result = 0;

    for(int i=0; i<Q; i++){
        if(correct[i] == candidate[i])
            result++;
    }

    return result;
}

int main() {

    freopen("pretest-input-1.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

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