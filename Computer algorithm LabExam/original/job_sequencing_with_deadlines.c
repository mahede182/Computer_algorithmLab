#include<conio.h>
#include<stdio.h>
int n,i,j,k,t;
int slot_check(int slot[],int j)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(slot[i]==j)
        flag++;
    }
    if(flag==0)
        return 1;
    else
        return 0;
}

int main()
{
    printf("enter the no of jobs: ");
    scanf("%d",&n);
    int slot[n],profit,p[n],d[n];
    for(i=0;i<n;i++)
    {
        printf(" enter the profit of job %d: ",i+1);
        scanf("%d",&p[i]);
        printf(" enter the deadline of job %d: ",i+1);
        scanf("%d",&d[i]);
    }

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(p[i]<p[j])
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
                t=d[i];
                d[i]=d[j];
                d[j]=t;
            }

    for(i=0;i<n;i++)
        slot[i]=0;

    for(i=0;i<n;i++)
        for(j=d[i];j>0;j--)
        {
            if(slot_check(slot,j)==1)
            {
                slot[i]=j;
                break;
            }
        }

    printf("\n\t index \t profit   deadline   slot allocated ");
    for(i=0;i<n;i++)
    {
        if(slot[i]>0)
            printf("\n\n \t %d \t %d \t %d \t [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
        else
            printf("\n\n \t %d  \t %d \t %d \t REJECTED", i+1,p[i],d[i]);
    }
    getch();
}
