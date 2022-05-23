#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//扑克牌13张4个花色，顺子从3--A最少五张；
//两次输入，第一次表示自己手里的牌，第二次表示场上出过的牌，输出对手手里可能有的最长的顺子;

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
        con = 0;
        for (j = 0; j < 54; j++)
        {
            if (b[i] == a[j])
            {
                con++;
            }
            if (b[i] == a2[j])
            {
                con++;
            }
            if (con == 4)
            {
                b[i] = 'x';
                break;
            }

        }
    }
}
int main()
{
    int i = 0;
    char arr[54] = { 0 };
    char arr2[54] = { 0 };
    char b[12] = { '3','4','5','6','7','8','9','0','J','Q','K','A' };
    my_getchar(arr);
    my_getchar(arr2);
    Con(arr, arr2, b);
    int count = 0;
    int con = 0;
    int flag = 0;
    for (i = 1; i <= 12; i++)
    {
        if (b[i-1] != 'x')
        {
            count++;
            if (con < count)
                con = count;
        }
        else
        {
            if (con < (12 - con) )
            flag = i; 
            count = 0;
        }
    }
    if (con >= 5)
    {
        for (i = flag; i <= flag+con-1; i++)
        {
            if (b[i] == '0')
                printf("%d", 10);
            else
                printf("%c", b[i]);
        }
    }
    else
    {
        printf("NO-CHAIN");
    }
    return 0;
}
