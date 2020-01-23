//Write a program to implement Bubble Sort algorithm for integer input in C.
#include<stdio.h>
#include<conio.h>
void main()
{
    int Data[100], ptr, n, k, temp=0;
    printf("Enter number of element: ");
    scanf("%d",&n);
    printf("Enter %d integer: ",n);
    for(k=1; k<=n; k++)
        scanf("%d", &Data[k]);
    for(k=1; k<=n-1; k++)
    {
        ptr = 1;
        while(ptr <= n-k)
        {
            if(Data[ptr]>Data[ptr+1])
            {
                temp = Data[ptr];
                Data[ptr] = Data[ptr+1];
                Data[ptr+1] = temp;
            }
            ptr++;
        }
    }
    printf("Output after bubble sorting:\n");
    for(k=1; k<=n; k++)
        printf("%d\t",Data[k]);
    return 0;
}
