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
    unsigned long long int max, max_i,min, min_i;

    for(int i = 0; i<NB_LINE; i++) {
        fscanf(f, "%llu-%llu", &(a[i][0]), &(a[i][1]));
    }

    for(int h = 0; h<NB_LINE; h++){

        for(int i = 0; i<NB_LINE; i++) {
            if(a_checked[i]==0) {
                max_i = i;
                max = a[i][0];
                min_i = i;
                min = a[i][0];
            }
        }

        for(int i = 0; i < NB_LINE; i++) {
            if(a_checked[i]==0 && a[i][0]<min) {
                min = a[i][0];
                min_i = i;
                printf("min : %llu ligne %llu\n", min, min_i);
            }
            if(a_checked[i]==0 && a[i][1]>max) {
                max = a[i][1];
                max_i = i;
                printf("max : %llu ligne %llu\n", max, max_i);
            }
        }

        for(int i = 0; i<NB_LINE; i++) {
            if(a_checked[i] == 0 && a[min_i][1]>=a[i][0]) {
                if(a[min_i][1]>=a[i][1]) {
                    a_checked[i] = 2;
                } else {
                    a[i][0] = a[min_i][1]+1;
                }
            }
        }
        a_checked[min_i] = 1;
        printf("check de %llu à %llu\n", a[min_i][0], a[min_i][0]);
    }

    for(int i = 0; i<NB_LINE;i++) {
        if(a_checked[i]==1) {
            cpt_fresh+=(a[i][1]-(a[i][0]-1));
            printf("cpt_fresh : %llu, ajout : %llu\n", cpt_fresh, (a[i][1]-(a[i][0]-1)));
        }
    }

    fclose(f);
    printf("nb id fresh : %llu\n", cpt_fresh);
    

    return 0;
}

