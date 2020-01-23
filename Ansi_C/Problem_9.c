//Write a program to implement job sequencing for one unit of time with given deadline.
#include<stdio.h>
int slot_check(int slot[], int j);
int n,i,j;
int main()
{
    int s[20], p[20], d[20], tp, temp;    //slot, profit, deadline, total profit
    printf("Enter the number of job: ");
    scanf("%d", &n);
    printf("Enter profits and deadlines: ");
    for(i=0; i<n; i++)
    {
        printf("Enter profit of job %d: ",i+1);
        scanf("%d", &p[i]);
        printf("Enter deadline of job %d: ",i+1);
        scanf("%d", &d[i]);
    }
    for(i=0; i<n; i++)

        for(j=i+1; j<n; j++)

            if(p[i] < p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }


    for(i=0; i<n; i++)
    {
        s[i] = 0;
    }
    for(i=0; i<n; i++)

        for(j=d[i]; j>0; j--)
        {
           if(slot_check(s,j)==1)
           {
               s[i] = j;
               break;
           }
        }

    printf("slot\t profit\t deadline\t slot allocation\n");
    for(i=0; i<n; i++)
    {
        if(s[i]>0)
            printf("\t\n\n %d \t %d \t %d \t [%d - %d]\n", i+1, p[i], d[i], (s[i]-1),s[i]);
        else
            printf("\t\n\n %d\t %d\t %d\t rejected", i+1, p[i], d[i]);
    }
    getch();
}
int slot_check(int slot[], int j)
{
    int flag = 0;
    for(i=0; i<n; i++)
    {
        if(slot[i] == j)
            flag++;
    }
    if(flag==0)
        return 1;
    else
        return 0;
}
