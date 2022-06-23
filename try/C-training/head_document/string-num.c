#include <stdio.h>

// 读入一个行字符串，（可能包含空格），输出这个字符串中字符的数量

int main(){
    char str[100];
    while(scanf(" %[^\n]s",str) != EOF){
        printf("str has %d digtis" ,printf("%s",str));
    }
    return 0;
}

//正则表达式，读入到\n字符为止 