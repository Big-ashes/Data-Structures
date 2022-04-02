#include <stdio.h>

// void hanoi(int n, char A,char B,char C);

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        printf("move num %d:  %C --> %c\n", n, A, C);
    else
    {
        hanoi(n-1, A, C, B); //从A借助C到B
        printf("move num %d:  %C --> %c\n", n, A, C);
        hanoi(n-1, B, A, C); //从B借助A到C
    }
}
//输入数字不可以太大，若为n 则需要执行2^n-1,比如三个盘子要移动8-1=7次
int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int n;
    printf("please type hanoi num: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}