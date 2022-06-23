#include <stdio.h>

// 分段函数，调用一个函数指针，然后作为参数传入函数

int f1(int n){
    if(n==0) return 1;
    return n*f1(n-1);
}

int f2(int n){
    return n*(n+1)/2;
}

int f3(int n){
    return n+n+1;
}

void g(int (*f)(int),int x){
    printf("g(%d) = %d\n",x,f(x));
}
//这是一个分段函数，规定自变量不同范围返回不同值，并不关心具体的f1（x）如何实现，
//只需要传递指向函数的指针就可以
//int 类型的参数（*f1）指针类型，which 指向一个（int）类型的函数指针

// int g(int (*f1)(int),int (*f2)(int),int (*f3)(int)){
//     if (x<0){
//         return f1(x);
//     }
//     if (x<100){
//         return f2(x);
//     }
//     return f3(x);    
// }

int main(){
    g(f1,5);
    g(f2,5);

    return 0;
}