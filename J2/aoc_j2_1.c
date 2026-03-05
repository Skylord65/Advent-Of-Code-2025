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

    while (fscanf(f, "%llu-%llu", &a1, &a2) == 2) {

        for (unsigned long long int i = a1; i <= a2; i++) {
            char chaine[100000];
            sprintf(chaine, "%llu", i);

            size_t len = strlen(chaine);

            if (len % 2 == 0) {

                char* moitie_chaine1 = malloc(len/2 + 1);
                char* moitie_chaine2 = malloc(len/2 + 1);

                strncpy(moitie_chaine1, chaine, len/2);
                moitie_chaine1[len/2] = '\0';

                strncpy(moitie_chaine2, chaine + len/2, len/2);
                moitie_chaine2[len/2] = '\0';
                
                printf("a1: %llu, a2:%llu, chaine : %s, valeur : %llu, %s <--> %s", a1, a2, chaine, i, moitie_chaine1, moitie_chaine2);

                if (strcmp(moitie_chaine1, moitie_chaine2) == 0) {
                    invalid_value += i;
                    printf(" is invalid in %llu\n", invalid_value);
                } else {
                    printf("\n");
                }

                free(moitie_chaine1);
                free(moitie_chaine2);
            }
        }

        fgetc(f); // Pour lire le '\n' si nécessaire
    }   

    fclose(f);
    printf("invalid value : %llu\n", invalid_value);
    

    return 0;
}

