#include <stdio.h>
typedef int BigAsh;//用BigAsh代替int这个数字类型，可以直接用


// struct Student
// {
//     int sid;
//     char name[100];
//     char sex;
// };//定义的时候要写全部的struct Student，太麻烦了


// typedef struct Student
// {
//     int sid;
//     char name[100];
//     char sex;
// }ST; //这样写就更加方便，可以直接用ST来代替这个数据结构 struct Student

typedef struct Student
{
    int sid;
    char name[100];
    char sex;
}* PST; //加了星号 * 后就不一样了  代表了一个指针   等价于struct Student *
//也就是说PST是一个struct Student *类型的指针

int main(void)
{
    // BigAsh i = 10; //等价于int i=10
    // printf("%d\n",i);
    // struct Student st ; //等价于ST st;
    // struct Student *ps = &st ;//等价于ST * ps;
    
    // ST st2;
    // st2.sid =200;
    // printf("%d\n",st2.sid);
    struct Student st;
    PST ps = &st;
    ps->sid = 99;
    printf("%d\n",ps->sid);

    return 0;
}