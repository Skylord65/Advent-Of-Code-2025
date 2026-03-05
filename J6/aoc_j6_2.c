#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define NB_LINE 5
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
    char* line_get;
    char line[NB_LINE][3800];
    size_t n;
    int previous_int = 0;
    unsigned long long int op[1001][1001];
    int op_i = 0;

    for(int k = 0; k<NB_LINE; k++) {
        getline(&line_get, &n, f);
        strcpy(line[k], line_get);
    }

    int i = 0;
    unsigned long long int cpt_temp = 0;
    while (line[NB_LINE-1][i]!='\n') {
        if(line[NB_LINE-1][i]=='+') {
            cpt_temp = 0;
            char chaine[5];
            do {
                int chaine_i = 0;
                for(int g = 0; g<NB_LINE-1; g++) {
                    if(line[g][i]!=' ') {
                        chaine[chaine_i] = line[g][i];
                        chaine_i++;
                    }
                }
                chaine[chaine_i]='\0';
                unsigned long long int num = to_ull(chaine);
                cpt_temp += num;
                printf("added to sum arithm temp : %llu\n", num);
                i++;
            } while(line[NB_LINE-1][i]==' ' && line[NB_LINE-1][i+1]==' ');

            cpt+=cpt_temp;
        } else if(line[NB_LINE-1][i]=='*') {
            cpt_temp = 1;
            char chaine[5];
            do {
                int chaine_i = 0;
                for(int g = 0; g<NB_LINE-1; g++) {
                    if(line[g][i]!=' ') {
                        chaine[chaine_i] = line[g][i];
                        chaine_i++;
                    }
                }
                chaine[chaine_i]='\0';
                unsigned long long int num = to_ull(chaine);
                cpt_temp *= num;
                printf("added to sum geo temp : %llu\n", num);
                i++;
            } while(line[NB_LINE-1][i]==' ' && line[NB_LINE-1][i+1]==' ');

            cpt+=cpt_temp;
            printf("added to cpt : %llu\n", cpt_temp);
        } else i++;
    }
    
    free(line_get);
    fclose(f);
    printf("cpt : %llu\n", cpt);
    

    return 0;
}

