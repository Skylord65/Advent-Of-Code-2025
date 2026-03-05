#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define NB_LINE 4
#define INPUT_NAME "input_test.txt"

int main(int argc, char const *argv[])
{
    FILE* f = fopen(INPUT_NAME, "r");
    unsigned long long int a[NB_LINE][2];
    unsigned long long int cpt_fresh = 0;
    unsigned long long int id = 0;
    int fresh = 0;
    for(int i = 0; i<NB_LINE; i++) {
        fscanf(f, "%llu-%llu", &(a[i][0]), &(a[i][1]));
    }
    fgetc(f);
    while (fscanf(f, "%llu", &id)==1) {
        printf("id : %llu\n", id);
        fresh = 0;
        for (int i = 0; i < NB_LINE; i++)
        {
            printf("%llu<=%llu<=%llu ?\n", a[i][0], id, a[i][1]);
            if (id >= a[i][0] && id <= a[i][1]) {
                printf("id : %llu is fresh\n", id);
                fresh = 1;
                break;
            }
        }

        if(fresh == 1) {
            cpt_fresh++;
            printf("cpt_fresh : %llu\n", cpt_fresh);
        }
    }
    

    fclose(f);
    printf("nb id fresh : %llu\n", cpt_fresh);
    

    return 0;
}

