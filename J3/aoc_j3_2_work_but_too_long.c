#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>

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
    FILE* f = fopen("input_test.txt", "r");
    if(f==NULL) {
        printf("pas de fichier\n");
        exit(1);
    }
    char* line = NULL;
    size_t nl = 0;
    unsigned long long int cpt = 0;
    unsigned long long int max;
    ssize_t len;
    while ((len=getline(&line, &nl, f))!=-1)
    {
        if(len<=0) { 
            printf("getline échoué\n");
            continue;
        }
        size_t L = (size_t)len;
        if(L>0 && line[L-1]=='\n') {
            printf("on retire le \\n \n");
            L--;
        }
        if(L<12) {
            printf("line trop petite\n");
            continue;
        }
        max = 0;
        for (size_t i = 0; i <L-11 ; i++)
        {
            for (size_t j = i+1; j < L-10; j++)
            {
                for (size_t k = j+1; k < L-9; k++)
                {
                    for (size_t l = k+1; l < L-8; l++)
                    {
                        for (size_t m = l+1; m < L-7; m++)
                        {
                            for (size_t n = m+1; n < L-6; n++)
                            {
                                for (size_t i2 = n+1; i2 <L-5 ; i2++)
                                {
                                    for (size_t j2 = i2+1; j2 < L-4; j2++)
                                    {
                                        for (size_t k2 = j2+1; k2 < L-3; k2++)
                                        {
                                            for (size_t l2 = k2+1; l2 < L-2; l2++)
                                            {
                                                for (size_t m2 = l2+1; m2 < L-1; m2++)
                                                {
                                                    for (size_t n2 = m2+1; n2 < L; n2++)
                                                    {
                                                        char entier[13]; // 12 chiffres + '\0'
                                                        entier[0] = line[i];
                                                        entier[1] = line[j];
                                                        entier[2] = line[k];
                                                        entier[3] = line[l];
                                                        entier[4] = line[m];
                                                        entier[5] = line[n];
                                                        entier[6] = line[i2];
                                                        entier[7] = line[j2];
                                                        entier[8] = line[k2];
                                                        entier[9] = line[l2];
                                                        entier[10] = line[m2];
                                                        entier[11] = line[n2];
                                                        entier[12] = '\0';

                                                        unsigned long long valeur = to_ull(entier);
                                                        printf("chaine : %s, valeur : %llu ", entier, valeur);
                                                        if(valeur>max) {
                                                            max = valeur;
                                                            printf(" max trouvé : %llu", max);
                                                        }
                                                        printf("\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }


        /*
        for(size_t i = 0; i<12;i++) {
            max_char[i] = 0;
            for (size_t j = 0; j < L-1; j++)
            {
                int integer = line[j] - '0';
                if(integer>max_char[i]) {
                    int is_great_max = 1;
                    for (size_t k = 0; k < i; k++) {
                        if(integer>max_char[k])
                            is_great_max = 0;
                    }
                    if(is_great_max==1) {
                        max_char[i] = integer;
                        i_max_char[i] = j;
                    }
                }        
            }
        }
        
        char chaine[13];
        for (size_t i = 0; i < 12; i++)
        {
            int best_j = -1;
            int best_pos = 999;
            for (size_t j = 0; j < 12; j++)
            {
                if(i_max_char[j]<best_pos)
                {
                best_pos = i_max_char[j];
                best_j = j;
                }
            }
            chaine[i] = max_char[best_j] + '0';
            i_max_char[best_j] = 999;
        }
        chaine[12] = '\0';

        max = to_ull(chaine);
        */

        printf("cpt : %llu, max : %llu\n", cpt, max);
        cpt+=max;

    }
    
    //free(line);
    printf("cpt : %llu\n", cpt);
    free(line);
    fclose(f);

    return 0;
}


