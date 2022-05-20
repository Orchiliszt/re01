#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


void my_getchar(char a[])
{
    int i = 0;
    for (i = 0;; i++)
    {
        scanf("%c", &a[i]);
        if (a[i] == '\n')
            break;
    }
}
void Con(char a[], char a2[], char b[])
{
    int i = 0;
    int con = 0;
    for (i = 0; i < 12; i++)
    {
        int j = 0;
        for (j = 0; j < 54; j++)
        {
            if (b[i] == a[j] || b[i] == a2[j])
            {
                con++;
            }
            if (con == 4)
                b[i] = 0;

        }
    }
}
int main()
{
    int i = 0;
    char arr[54] = { 0 };
    char arr2[54] = { 0 };
    char b[12] = { '3','4','5','6','7','8','9','10','J','Q','K','A' };
    my_getchar(arr);
    my_getchar(arr2);
    Con(arr, arr2, b);
    int count = 0;
    int con = 0;
    int flag = 0;
    for (i = 0; i < 12; i++)
    {
        if (b[i] != 0)
        {
            count++;
            con = count;
        }
        else
            flag = i - count; count = 0;
    }
    if (con > 5)
    {
        for (i = flag; i <= con; i++)
        {
            printf("%c", b[i]);
        }
    }
    else
    {
        printf("NO-CHAIN");
    }
    return 0;
}