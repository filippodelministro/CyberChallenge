#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 100001


bool check(int W, int N, int T, int Ti[]){
    int worker[W];   
    for(int i=0; i<W; i++)
        worker[i] = T;          //time at begin

    // printf("firt iter: %d worker\n", W);
    // printf("\tid\ttime\n");
    // for(int i=0; i<W; i++)
    //     printf("\t%d\t%d\n", i, worker[i]);

    //printf("\tid\ttime\n");
    for(int j=0; j<N; j += W){
        for(int i=0; i<W; i++){
        worker[i] -= Ti[i+W];
        
        // for(int i=0; i<W; i++)
        //     printf("\t%d\t%d\n", i, worker[i]);
        // printf("j left: %d\n", N-j);
        
        if(worker[i] <= 0)
            return false;
        }
    }

   
    return true;
}

int min_workers(int N, int T, int Ti[]) {
    
    int number = 2;
    
    while(!check(number, N, T, Ti))
        number++;

    return number;
}

int main() {

    freopen("workers-input-3.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N, T;
    int Ti[MAXN];

    assert(2 == scanf("%d %d", &N, &T));

    for(int i=0; i<N; i++) 
        assert(1 == scanf("%d", &Ti[i]));

    printf("%d\n", min_workers(N, T, Ti));

    return 0;
}