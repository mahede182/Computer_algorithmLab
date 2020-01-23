//Write a program to implement minimax algorithm.
#include<stdio.h>
int data[20], min, max;
int MaxMin(int i, int j);
int main()
{
    int n, i;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    printf("Enter %d elements: ",n);
    for(i=0; i<n; i++)
        scanf("%d",&data[i]);
    max = min = data[0];
    MaxMin(0, n-1);
    printf("Maximum number is %d\n",max);
    printf("Minimum number is %d\n",min);
}
int MaxMin(int i, int j)
{
    int mid, max1, min1;
    if(i==j)
        max = min = data[i];
    else
    {
        if(i == j-1)
        {
            if (data[i] < data[j])
            {
                max = data[j];
                min = data[i];
            }
            else
            {
                max = data[i];
                min = data[j];
            }
        }
        else
        {
            mid = (i+j)/2;
            MaxMin(i, mid);
            max1 = max;
            min1 = min;
            MaxMin(mid+1,j);
            if(max < max1)
                max = max1;
            if(min > min1)
                min = min1;
        }
    }
}
