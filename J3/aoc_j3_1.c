#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    FILE* f = fopen("input.txt", "r");
    char* line = NULL;
    size_t n;
    int cpt = 0;
    int max;
    while (getline(&line, &n, f)!=EOF)
    {
        max = 0;
        for (size_t i = 0; i <n-1 ; i++)
        {
            for (size_t j = i+1; j < n-1; j++)
            {
                char entier[4];
                sprintf(entier, "%c%c", line[i], line[j]);
                int valeur = atoi(entier);
                printf("i : %d, j : %d, chaine : %s, valeur : %d ", i, j, entier, valeur);
                if(valeur>max) {
                    max = valeur;
                    printf(" max trouvé : %d", max);
                }
                printf("\n");
            }
            
        }
        cpt+=max;

    }
    
    //free(line);
    printf("cpt : %d\n", cpt);
    free(line);
    fclose(f);

    return 0;
}
