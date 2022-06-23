#include <stdio.h>

/*
任何指针类型占用的大小是一样的，与最大寻址空间有关
指针存储的位置就是每个变量的头一个地址

int a；
int *p = &a;
*p = 5
*/

struct Data{
    int x,y;
};


int main(){
    struct Data a[2] , *p=a;
    
    return 0;
}