#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define NB_LINE 192
#define INPUT_NAME "input.txt"

int main(int argc, char const *argv[])
{
    FILE* f = fopen(INPUT_NAME, "r");
    unsigned long long int a[NB_LINE][2];
    int a_checked[NB_LINE] = {0};
    unsigned long long int cpt_fresh = 0;
    unsigned long long int id = 0;
    int check = 0;
    for(int i = 0; i<NB_LINE; i++) {
        fscanf(f, "%llu-%llu", &(a[i][0]), &(a[i][1]));
    }
    fgetc(f);
    for (int i = 0; i < NB_LINE; i++) {
        if(a_checked[i]!=1) {
            for (unsigned long long int j = a[i][0]; j<=a[i][1];j++) {
                check = 0;
                for(int k = 0; k < NB_LINE; k++) {
                    if(a_checked[k]==1 && a[k][0]<=j && a[k][1]>=j) {
                        printf("%llu déjà compté\n", j);
                        check = 1;
                        break;
                    }
                }
                printf("%llu à %llu\n", j, cpt_fresh);
                if(check==0) cpt_fresh++;
            }
            printf("ligne %d fini et checké\n", i);
            a_checked[i]=1;
        }
    }

    fclose(f);
    printf("nb id fresh : %llu\n", cpt_fresh);
    

    return 0;
}

