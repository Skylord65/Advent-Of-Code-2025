#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    FILE* f = fopen("input_test.txt", "r");
    char* line = NULL;
    size_t n;
    int cpt = 0;
    int l = 0;
    char tab_line[140][140];
    char last_line[140];
    int number_col[140] = {0};
    int proxy = 0;
    int cpt_proxy = 0;
    //int number_l;
    while (getline(&line, &n, f)!=EOF)
    {
        strcpy(tab_line[l], line);
        l++;
    }
    n = strlen(tab_line[0])-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++) {
            proxy = 0;
            cpt_proxy = 0;
            if(proxy == 0 && i == 0 && j == 0 && tab_line[i][j]=='@') proxy++;
            if(proxy == 0 && i == n-1 && j == n-1 && tab_line[i][j] == '@') proxy++;
            if(proxy == 0 && i == 0 && j == n-1 && tab_line[i][j]=='@') proxy++;
            if(proxy == 0 && i == 0 && j == n-1 && tab_line[i][j] == '@') proxy++;
            if(proxy == 0 && i == n-1 && j != n-1 && tab_line[i][j] == '@') {
                if (tab_line[i][j-1]=='@') cpt_proxy++;
                if (tab_line[i][j+1]=='@') cpt_proxy++;
                if (tab_line[i-1][j]=='@') cpt_proxy++;
                if (tab_line[i-1][j+1]=='@') cpt_proxy++;
                if (tab_line[i-1][j-1]=='@') cpt_proxy++;
                proxy=1;
            }
            if(proxy == 0 && i != n-1 && j == n-1 && tab_line[i][j] == '@') {
                if (tab_line[i-1][j]=='@') cpt_proxy++;
                if (tab_line[i-1][j-1]=='@') cpt_proxy++;
                if (tab_line[i][j-1]=='@') cpt_proxy++;
                if (tab_line[i+1][j]=='@') cpt_proxy++;
                if (tab_line[i+1][j-1]=='@') cpt_proxy++;
                proxy=1;
            }
            if(proxy == 0 && i == 0 && j != 0 && tab_line[i][j]=='@') {
                if (tab_line[i][j-1]=='@') cpt_proxy++;
                if (tab_line[i+1][j]=='@') cpt_proxy++;
                if (tab_line[i+1][j+1]=='@') cpt_proxy++;
                if (tab_line[i][j+1]=='@') cpt_proxy++;
                if (tab_line[i+1][j-1]=='@') cpt_proxy++;
                proxy=1;
            }
            if(proxy == 0 && i != 0 && j == 0 && tab_line[i][j]=='@') {
                if (tab_line[i-1][j]=='@') cpt_proxy++;
                if (tab_line[i+1][j]=='@') cpt_proxy++;
                if (tab_line[i+1][j+1]=='@') cpt_proxy++;
                if (tab_line[i][j+1]=='@') cpt_proxy++;
                if (tab_line[i-1][j+1]=='@') cpt_proxy++;
                proxy=1;
            }
            if (proxy == 0 && i != 0 && j!= 0 && i != n-1 && j != n-1 && tab_line[i][j]=='@') {
                if (tab_line[i-1][j]=='@') cpt_proxy++;
                if (tab_line[i-1][j-1]=='@') cpt_proxy++;
                if (tab_line[i][j-1]=='@') cpt_proxy++;
                if (tab_line[i+1][j]=='@') cpt_proxy++;
                if (tab_line[i+1][j+1]=='@') cpt_proxy++;
                if (tab_line[i][j+1]=='@') cpt_proxy++;
                if (tab_line[i-1][j+1]=='@') cpt_proxy++;
                if (tab_line[i+1][j-1]=='@') cpt_proxy++;
                proxy=1;
            }
            if(tab_line[i][j]=='@' && proxy==1 && cpt_proxy<4) cpt++;

        }
    }
    

    //free(line);
    printf("cpt : %d\n", cpt);
    free(line);
    fclose(f);

    return 0;
}
