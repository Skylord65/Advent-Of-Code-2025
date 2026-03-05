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
    size_t n = 0;
    int cpt = 0;
    int current_number = 50;
    char* text_number = malloc(sizeof(char)*10);
    while (getline(&line, &n, f)!=EOF)
    {
        char* text_number = malloc(sizeof(char)*n+1);
        if(line[0] == 'L') {
            int i = 1;
            while (line[i]!='\n')
            {
                text_number[i-1] = line[i];
                i++;
            }
            text_number[i] = '\0';
            current_number = (current_number-atoi(text_number))%100;      
        }
        if(line[0] == 'R') {
            
            int i = 1;
            while (line[i]!='\n')
            {
                text_number[i-1] = line[i];
                i++;
            }
            text_number[i] = '\0';
            current_number = (current_number+atoi(text_number))%100;           
        }
        if (current_number==0) {
                cpt++;
        }
        free(text_number);
    }
    
    //free(line);
    printf("cpt : %d\n", cpt);
    fclose(f);

    return 0;
}
