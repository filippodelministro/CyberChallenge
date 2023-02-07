#include <stdio.h>
#include <assert.h>

#define MAXN 301
#define MAXM 301
#define MAXS 50001
#define MAX_FLAG_LENGTH 11

typedef struct {   
    int task_id;
    char task_flag[MAX_FLAG_LENGTH];
    int task_points;

} task;

typedef struct {
    int player_id;
    int task_id;
    char flag[MAX_FLAG_LENGTH];
    int timestamp;
} submission;

void calcola_classifica(int M, int N, int S, task tasks[], submission submissions[]) {
    // SCRIVI QUA IL TUO CODICE
    return;
}

int main() {

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int M, N, S;
    task tasks[MAXN];
    submission submissions[MAXS];

    assert(3 == scanf("%d %d %d", &M, &N, &S));

    for(int i=0; i<N; i++) 
        assert(3 == scanf("%d %s %d", &tasks[i].task_id, tasks[i].task_flag, &tasks[i].task_points));
    
    for(int i=0; i<S; i++)
        assert(4 == scanf("%d %d %s %d", &submissions[i].player_id, &submissions[i].task_id, submissions[i].flag, &submissions[i].timestamp));

    calcola_classifica(M, N, S, tasks, submissions);

    return 0;
}