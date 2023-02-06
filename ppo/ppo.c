#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int N = 0;
int LENGHT = 1028;

bool lenght_check(char* p){
    if(strlen(p) >= 8 && strlen(p) < 17)
        return true;

    return false; 
}

bool uppercase(char l){
    if(l >= 'A' && l <= 'Z')
        return true;
    return false;
}


bool lowercase(char l){
    if(l >= 'a' && l <= 'z')
        return true;
    return false;
}

bool specialcase(char l){
    if((l >= ' ' && l <= '@') || (l >= '{' && l <= '~') )
        return true;
    return false;
}


bool letter_check(char* p){
    bool up = false;
    bool low = false;
    bool special = false;

    for(int i = 0; i<strlen(p); i++){
        if(!up)
            up = uppercase(p[i]);
        if(!low)
            low = lowercase(p[i]);
        if(!special)
            special = specialcase(p[i]);
    }

    if(up && low && special)
        return true;
    return false; 
}

bool consecutive_check(char *p){
    for(int i=0; i<strlen(p)-1; i++){
        if(p[i] == p[i+1])
            return false;
    }

    return true;
}

bool old_pswd_check(char *new, char* old){
    if(strcmp(new, old) == 0)
        return false;

    int diff = strlen(new) - strlen(old);
    if(diff > 2 || diff < -2)
        return true;

    int nChanges = 0;
    
    if(strlen(new) == strlen(old)){
        //same lenght
        for(int i=0; i<strlen(new); i++){
            if(new[i] != old[i])
                nChanges++;
        }
    }
    else if(strlen(new) == strlen(old) + 1){
        // |new| == |old| + 1
        for(int i=0; i<strlen(old); i++){
            if(new[i] != old[i])
                nChanges++;
            }
    }

     else if(strlen(new) == strlen(old) - 1){
        // |new| == |old| - 1
        for(int i=0; i<strlen(new); i++){
            if(new[i] != old[i])
                nChanges++;
        }
    }

    if(nChanges >=2 )
        return true;
    
    return false;
}

int main(){

    scanf("%d", &N);
    printf("N: %d\n", N);

    for(int i=0; i<N; i++){
        char new[LENGHT];
        char old[LENGHT];
        scanf("%s", new);
        scanf("%s", old);
        
        // printf("%s\t\t\t\t", new);
        // printf("%s\t\t\t\t", old);    

        bool r1, r2, r3, r4, result;
        r1 = lenght_check(new);
        r2 = letter_check(new);
        r3 = consecutive_check(new);
        r4 = old_pswd_check(new, old);

        result = r1 && r2 && r3 && r4;

        printf("i:%d\t%d\t%s\t%s\n", i+1, result, old, new);
        printf("\tr1: %d\n", r1);
        printf("\tr2: %d\n", r2);
        printf("\tr3: %d\n", r3);
        printf("\tr4: %d\n", r4);
    }

    return 0;
}