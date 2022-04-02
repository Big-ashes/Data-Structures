#include <stdio.h>
#include <string.h>

void move(char x ,char y);
void hanoi(int n,char one ,char two,char three);


void hanoi(int n,char one ,char two,char three)
{
    if(n==1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);  //放n-1---从A借助C到B
        move(one,three);//搬空A---最后一个到C
        hanoi(n-1,two,one,three); //放n-1---从B借助A到C
    }
}

void move(char x ,char y)
{
    printf("%c----->%c \n",x,y);
}

int main(void)
{
    int n;
    printf("please type your hanoi num : ");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}