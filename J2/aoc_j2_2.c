#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    FILE* f = fopen("input.txt", "r");
    unsigned long long int a1;
    unsigned long long int a2;
    unsigned long long int invalid_value = 0;
    int invalid = 0;

    while (fscanf(f, "%llu-%llu", &a1, &a2) == 2) {

        for (unsigned long long int i = a1; i <= a2; i++) {
            char chaine[100000];
            sprintf(chaine, "%llu", i);
            invalid = 0;
            for(int k = 2; k<1000; k++) {
                size_t len = strlen(chaine);

                if (len % k == 0) {

                    char* moitie_chaine1 = malloc(len/k + 1);
                    char* moitie_chaine2 = malloc(len/k + 1);

                    strncpy(moitie_chaine1, chaine, len/k);
                    moitie_chaine1[len/k] = '\0';

                    strncpy(moitie_chaine2, chaine + len/k, len/k);
                    moitie_chaine2[len/k] = '\0';
                
                    printf("a1: %llu, a2:%llu, chaine : %s, valeur : %llu, %s <--> %s", a1, a2, chaine, i, moitie_chaine1, moitie_chaine2);

                    if (strcmp(moitie_chaine1, moitie_chaine2) == 0) {
                        int test = 0;
                        for(int l = 2; l<k; l++){

                            strncpy(moitie_chaine2, chaine + l*(len/k), len/k);
                            moitie_chaine2[len/k] = '\0';

                            if(strcmp(moitie_chaine1, moitie_chaine2) != 0) {
                                test =1;
                            }
                        }
                        if(test==0 && invalid==0) {
                            invalid_value += i;
                            printf(" is invalid in %llu\n", invalid_value);
                            invalid = 1;
                        } else {
                            printf("\n");
                        }                   
                    } else {
                        printf("\n");
                    }

                    free(moitie_chaine1);
                    free(moitie_chaine2);
                }
            }
        }

        fgetc(f); // Pour lire le '\n' si nécessaire
    }   

    fclose(f);
    printf("invalid value : %llu\n", invalid_value);
    

    return 0;
}

