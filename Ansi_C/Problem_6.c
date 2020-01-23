//Write a program to perform Merge Sort using divide and conquer approach.
#include<stdio.h>
int arr[30], temp[30];
void sort(int low, int high);

int main()
{
    int n, i;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(0,n-1);
    printf("Sorted array: \n");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
}

void sort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        sort(low,mid);
        sort(mid+1, high);
        merge(low,mid,high);
    }
    else
        return ;
}
void merge(int low, int mid, int high)
{
    int h, i,j;
    for(h=low, j=mid+1, i=low; h<=mid && j<=high; i++)
    {
        if(arr[h] <= arr[j])
            temp[i] = arr[h++];
        else
            temp[i] = arr[j++];
    }
    while(h<=mid)
        temp[i++] = arr[h++];
    while(j<=high)
        temp[i++] = arr[j++];
    for(i=low; i<=high; i++)
        arr[i] = temp[i];
}
