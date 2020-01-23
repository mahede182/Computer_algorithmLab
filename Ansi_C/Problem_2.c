//Write a program to implement Binary Search algorithm for ascending order input in C.
#include<stdio.h>
#include<conio.h>
void main()
{
    int Data[100], n, item, beg, mid, end,i;
    printf("Enter number of element: ");
    scanf("%d",&n);
    printf("Enter %d integer: ",n);
    for(i=1; i<=n; i++)
        scanf("%d", &Data[i]);
    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    beg = 1;
    end = n;
    mid = (beg + end)/2;
    while (beg <= end)
    {
        if(Data[mid]< item)
            beg = mid + 1;
        else if (Data[mid] == item)
        {
            printf("%d is present at the location %d", item, mid);
            break;
        }
        else
            end = mid - 1;
        mid = (beg + end)/2;
    }
    if(beg > end)
        printf("%d is not present in the array",item);
    return 0;
}
