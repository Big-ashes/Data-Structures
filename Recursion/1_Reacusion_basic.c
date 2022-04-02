#include <stdio.h>

void f();
void g();
void k();

void f()
{
    printf("FFFFFF\n");
    g();   //这种就是间接调用
    printf("111111\n"); 
}

void g()
{
    printf("GGGGGG\n");
    k();
    printf("222222\n");  //先调用后返回，返回结果可以自行推导
}

void k()
{
    printf("KKKKKK\n");
    // f();  //死递归,最终在调取一定数量后终止，找不到出口
}


int main (void)
{
    f();
    return 0;
}