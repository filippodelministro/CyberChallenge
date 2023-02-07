#include <stdio.h>
#include <assert.h>
#include <string.h>

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


void InsertionSort(int x[], int n) {
    int i, j, app;
    for (i = 1; i < n; i++){
        app = x[i];
        for (j = i - 1; (j >= 0) && (x[j] > app); j--){
            x[j+1] = x[j];
            j--;
        }
        x[j + 1] = app;
    }
}

void calcola_classifica(int M, int N, int S, task tasks[], submission submissions[]) {
    
    int player[M][N];       //save task submitted by each player
    int scores[M];
    int time[M];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            player[i][j] = 0;
        }
        scores[i] = 0;
        time[i] = 0;
    }

   // printf("player\ttask\t\tflag\ttime\n");
    for(int i=0; i<S; i++){
        int pl = submissions[i].player_id;
        int ts = submissions[i].task_id;

        printf("%d\t%d\t%s\t%d\n", pl, ts, submissions[i].flag, submissions[i].timestamp);

        if(player[pl][ts] == 0){
            printf("\t%s\n", tasks[ts].task_flag);

            if(strcmp(submissions[i].flag, tasks[ts].task_flag) == 0){
            printf("diocane\n");
                scores[pl] += tasks[ts].task_points;

                if(submissions[i].timestamp > time[pl])
                    time[pl] = submissions[i].timestamp;

              //  printf("\t%d\t%d\n", scores[i], time[i]);
            }
            player[pl][ts] = 1;     //task submitted now
        }
    }    

    // printf("\n---------------\n\tscores\ttime\n");
    // for(int i=0; i<M; i++){
    //     printf("\t%d\t%d\n", scores[i], time[i]);
    // }

    return;
}

int main() {

    freopen("winner-input-1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

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