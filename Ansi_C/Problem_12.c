//Write a program to implement multistage graph problem using dynamic programming.
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define loop(a, b, c) for(a=b; a<c; a++)    //user-defined macros
#define aloop(a, b, c) for(a=b; a>=c; a--)

int g[50][50];
int stage[50][50];
int distance[50];
int n;
int get_min(int a, int b)
{
    return a>b? b: a;
}

int main()
{
    int i, j, x, y, c, l, k, s;
    printf("Enter number of stages: ");
    scanf("%d", &l);

    c = 1;
    n = 1;
    stage[0][0] = 0;
    stage[0][1] = -1;

    loop(i, 1, l-1){
        printf("Enter number of nodes in stage %d: ", i+1);
        scanf("%d", &x);
        n += x;
        loop(j, 0, x){
            stage[i][j] = c;
            c++;
        }
        stage[i][j] = -1;
    }

    stage[l-1][0] = n, stage[l-1][1] = -1;
    n+=1;

    loop(i, 0, n){
        distance[i] = INT_MAX;
        loop(j, 0, n)
        g[i][j] = INT_MAX;
    }

    printf("Enter edges:\n");

    loop(i, 0, l-1){
        printf("Enter edges between stages %d and %d\nEnter -1 to stop\n", i, i+1);
        printf("Nodes are\n");
        j = 0;
        printf("Layer\tNodes\n");
        printf("%d\t",i);
        while(stage[i][j]!=-1){
            printf("%d ", stage[i][j]);
            ++j;
        }
        j = 0;
        printf("\n%d\t", i+1);
        while(stage[i+1][j]!=-1){
            printf("%d ", stage[i+1][j]);
            ++j;
        }

        printf("\n");
        while(1)
        {
            scanf("%d %d %d", &x, &y, &c);
            if(x == -1 || y == -1)
                break;
            g[x][y] = c;
        }
    }

    j = 0;
    while(stage[l-1][j] != -1){
        distance[stage[l-1][j]] = 0;
        j++;
    }

    aloop(i, l-2, 0){
        j = 0;
        while(stage[i][j] != -1){
            s = stage[i][j];

            loop(k, 0, n){
                if(g[s][k] != INT_MAX){
                    distance[s] = get_min(distance[s], g[s][k] + distance[k]);
                }
            }
            j++;
        }
    }
    printf("Shortest path is: %d", distance[0]);
    return 0;
}

