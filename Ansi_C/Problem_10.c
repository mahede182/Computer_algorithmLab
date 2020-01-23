//Write a program to implement Prim's Algorithm.
#include<stdio.h>
#include<conio.h>
int main()
{
    int n, i, j, cost[20][20], visited[20]={0}, node1, node2, u, v, edge=1, min, Tcost=0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j] = 99;
            }
        }
    }
    visited[1] = 1;
    while(edge<n)
    {
        for(min=99,i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j]<min)
                    if(visited[i]!=0)
                    {
                        min = cost[i][j];
                        node1 = u = i;
                        node2 = v = j;
                    }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("Edge %d: (%d - %d) = %d\n", edge++, node1, node2, min);
            Tcost += min;
            visited[node2] = 1;
        }
        cost[node1][node2] = cost[node2][node1] = 99;
    }
    printf("The minimum cost is %d", Tcost);
}
