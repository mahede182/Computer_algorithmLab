//Write a program to perform Strassen's Matrix multiplication on 2 by 2 matrix using c.
#include<stdio.h>
int main()
{
    int a[2][2], b[2][2], c[2][2], P, Q, R , S, T, U, V, i, j;
    printf("Enter matrix a\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter matrix b\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("b[%d][%d]: ", i, j);
            scanf("%d",&b[i][j]);
        }
    }
    P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    Q = (a[1][0] + a[1][1]) * b[0][0];
    R = a[0][0] * (b[0][1] - b[1][1]);
    S = a[1][1] * (b[1][0] - b[0][0]);
    T = (a[0][0] + a[0][1]) * b[1][1];
    U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    c[0][0] = P+S-T+V;
    c[0][1] = R+T;
    c[1][0] = Q+S;
    c[1][1] = P+R-Q+U;
    printf("\nc = \n");
    printf(" %d\t %d\t\n %d\t %d\t",c[0][0],c[0][1],c[1][0],c[1][1]);
}
