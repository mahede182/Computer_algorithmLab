//Write a program to implement Longest Common Subsequence in C.
#include<stdio.h>
#include<string.h>
int LCS(char *s1, char *s2, int i, int j);
int max(int x, int y);
int main()
{
    char s1[30], s2[30];
    int l1, l2, length;
    printf("Enter first string: ");
    scanf("%s",&s1);
    printf("Enter second string: ");
    scanf("%s",&s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    length = LCS(s1, s2, l1, l2);
    printf("The Longest Common Subsequence is %d",length);
}
int LCS(char *s1, char *s2, int i, int j)
{
    if(i == 0 || j == 0)
        return 0;
    else if(s1[i-1] == s2 [j-1])
        return 1 + LCS (s1, s2, i-1, j-1);
    else
        return max(LCS(s1, s2, i,j-1), LCS(s1, s2, i-1,j));
}
int max(int x, int y)
{
        return (x>y)? x: y;
}
