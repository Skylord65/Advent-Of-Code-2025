#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define NB_LINE 4
#define INPUT_NAME "input.txt"

// 2040221097
// 2415247165
// 62544789309
// 264408252221
// 67278782971709
// 6295830249262

unsigned long long int to_ull(const char *s) {
    unsigned long long int x = 0;
    while (*s>= '0' && *s <= '9'){
        x = x * 10 + ((unsigned long long)*s - '0');
        s++;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    FILE* f = fopen(INPUT_NAME, "r");
    unsigned long long int cpt=0;
    char* line = NULL;
    size_t n;
    int previous_int = 0;
    unsigned long long int op[1001][1001];
    int op_i = 0;

    for(int k = 0; k<NB_LINE; k++) {
        getline(&line, &n, f);
        op_i = 0;
        int iterator = 0;
        previous_int = 0;
        while (line[iterator]!='\n')
        {
            if(line[iterator]==' ' && previous_int > 0) {
                char chaine[previous_int+1];
                int i = 0;
                while(previous_int>0) {
                    chaine[i] = line[iterator-previous_int];
                    previous_int--;
                    i++;
                }
                chaine[i]='\0';
                op[k][op_i] = to_ull(chaine);
                printf("number added : %d at [%d][%d]\n", op[k][op_i], k, op_i);
                op_i++;
            }
            if(line[iterator]!=' ') previous_int++;
            iterator++;
        }
        if(previous_int>0) {
            char chaine[previous_int+1];
                int i = 0;
                while(previous_int>0) {
                    chaine[i] = line[iterator-previous_int];
                    previous_int--;
                    i++;
                }
                chaine[i]='\0';
                op[k][op_i] = atoi(chaine);
                printf("number added : %d at [%d][%d]\n", op[k][op_i], k, op_i);
                op_i++;
        }
    }

    getline(&line, &n, f);
    int iterator_op = 0;
    int column = 0;
    unsigned long long int sum_column = 0;
    unsigned long long int sum_geo_column;
    while (line[iterator_op]!='\n') {
        sum_column = 0;
        sum_geo_column = 1;
        if(line[iterator_op]=='+') {
            for(int j=0; j<NB_LINE;j++) {
                sum_column+=op[j][column];
                printf("summed ton arith : %d at [%d][%d]\n", op[j][column], j, column);
            }
            printf("sum arith : %d\n", sum_column);
            cpt+=sum_column;
            column++;
        } else if(line[iterator_op]=='*') {
            for(int j=0; j<NB_LINE;j++) {
                sum_geo_column*=op[j][column];
                printf("summed to geo : %d at [%d][%d]\n", op[j][column], j, column);
            }
            //printf("sum geo : %d", sum_column);
            printf("sum geo : %d\n", sum_geo_column);
            cpt+=sum_geo_column;
            column++;
        }
        iterator_op++;
    }
    
    free(line);
    fclose(f);
    printf("cpt : %llu\n", cpt);
    

    return 0;
}

