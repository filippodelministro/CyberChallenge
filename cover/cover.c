#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long int conta(int N, int K, long long int **ranges) {
    
    int min = ranges[0][0];
    int max = ranges[0][1];
    long long int result = 0;

    //find min and max of all ranges
    for(long long int i=1; i<N; i++){
        printf("\tCONTA> loading: %d\n", N-i);
        system("clear");

        if(ranges[i][0] < min)
            min = ranges[i][0];
        if(ranges[i][1] > max)
            max = ranges[i][1];
    }

    //for each number between min and max chechk in wich range is contained
    for(long long int i=min; i<=max; i++){
        long long int c = 0; 
        for(long long int j=0; j<N; j++){
            if(i>=ranges[j][0] && i<=ranges[j][1])
                c++;
        }
        if(c == K)
            result++;
    }

    return result;
}

int main() {

    freopen("cover-input-3.txt", "r", stdin); 

    int N, K;
    assert(2 == scanf("%d %d\n", &N, &K));

    long long int **ranges = (long long int **) malloc(N * sizeof(long long int *));

    for(long long int i=0; i<N; i++) {
        printf("\tMAIN>reading: %d\n", N-i);
        system("clear");

        ranges[i] = (long long int *) malloc(2 * sizeof(long long int));
        assert(2 == scanf("%lld %lld\n", &ranges[i][0], &ranges[i][1]));
    }

    long long int res = conta(N, K, ranges);
    printf("\tresult: %d", res);
    //freopen("output.txt", "w", stdout);

    for(int i=0; i<N; i++) {
        free(ranges[i]);
    }
    free(ranges);

    return 0;
}
