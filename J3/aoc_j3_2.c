#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include "stack.h"

char* line = NULL;

void make_max12(const char *line, size_t L, char out[13]) {
    const size_t K = 12;
    size_t remaining = L;
    
    Stack* s = create_stack(K);

    for (size_t i = 0; i < L; i++) {
        char c = line[i];

        /* Récupérer le sommet si la pile n’est pas vide */
        while (!stack_empty(s)) {
            const char *top_ptr = stack_top(s);
            char top = *top_ptr;

            size_t current_size = stack_size(s);
            size_t space_left = K - current_size;

            if (top >= c)
                break;

            if (remaining <= space_left)
                break;

            s = stack_pop(s);
        }

        if (stack_size(s) < K) {
            char *heap_char = malloc(sizeof(char));
            *heap_char = c;
            s = stack_push(s, heap_char);
        }

        remaining--;
    }

    size_t sz = stack_size(s);
    if (sz != K) {
        fprintf(stderr, "Erreur interne : stack_size=%zu != 12\n", sz);
        exit(1);
    }

    for (int i = K - 1; i >= 0; i--) {
        const char *pc = stack_top(s);
        out[i] = *pc;
        free((void*)pc);
        s = stack_pop(s);
    }

    out[K] = '\0';
    delete_stack(&s);
}

int cmp(const void *a, const void *b) {
    int i = *(const int *)a;
    int j = *(const int *)b;

    // ordre décroissant sur la valeur
    if (line[i] != line[j]) return (line[j] - line[i]);

    // si égalité, ordre croissant sur la position
    return (i - j);
}

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
    
    size_t nl = 0;
    unsigned long long int cpt = 0;
    unsigned long long int max;
    unsigned long long int max_char[12];
    int i_max_char[12];
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
        
        char stack[13];
        make_max12(line, L, stack);
        max = to_ull(stack);
        

        /*
        size_t k = 12;
        char stack[12];
        size_t top = 0;
        size_t remaining = L;

        for(size_t i=0;i<L;i++){
            char c = line[i];
            while(top>0 && stack[top-1]<c && remaining > k - top){
                top--;
            }
            if(top<k){
                stack[top] = c;
                top++;
            }
            remaining--;
        }
        stack[k] = '\0';
        max = to_ull(stack);
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


