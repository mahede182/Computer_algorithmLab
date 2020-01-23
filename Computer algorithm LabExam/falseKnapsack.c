
#include<stdio.h>
void knapsack(int n,float weight[], float profit[], float capacity);
int main()
{

    int n, i, j;
    float p[20], w[20],ratio[20],m,temp;
    printf("Enter the name of the elements: ");
    scanf("%d",&n);
    printf("Enter %d profits: ",n);
    for(i=0;i<n;i++){
        scanf("%f",&p[i]);
    }
    printf("Enter %d weights: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
    }
    for(i=0;i<n;i++)
    {

        ratio [i] = p[i]/w[i];
    }
    printf("Enter the capcity of knapsack:");
    scanf("%f",&m);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
             temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = w[j];
                w[j] = w[i];
                w[i] = temp;

                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    knapsack(n,w,p,m);
}
void knapsack(int n,float weight[],float profit[],float capacity)
{
    float x[20],tempp;
    int i,u;
    u=capacity;
    tempp = 0;
    for(i=0;i<n;i++ )
        x[i] = 0.0;
    for(i=0;i<n;i++){
        if(weight[i]>u)
            break;
        else
        {
            x[i] = 1.0;
            tempp += profit[i];
            u -= weight[i];

        }
        if(i<n)
            x[i] = u/weight[i];
        tempp = tempp + (x[i] * profit[i]);
        for(i=0;i<n;i++)
        {

            printf("x[%d]: %f\n",i,x[i]);
        }
        printf("The maximum profit is %f",tempp);
    }
}
