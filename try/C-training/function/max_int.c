#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//变参函数

int max_int(int n, ...){
    if(n<=0) return 0;
    va_list arg;
    va_start(arg, n);
    off32_t ans = INT_MIN;
    for (int i = 0; i < n; i++){
        off32_t temp = va_arg(arg,int);   //函数的 参数传递了一个类型  （一般见到的都是传递一个参数）
        if (temp >ans) ans = temp;
    }
    return ans;
}

int main(){
    printf("%d \n",max_int(3,1,5,3));
    printf("%d \n",max_int(3,1,5,7));
    printf("%d \n",max_int(3,1,99,3));
    return 0;
}