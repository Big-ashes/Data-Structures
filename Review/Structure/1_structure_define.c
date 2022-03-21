#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
}; //分号不能省略,这是一个用户自己定义的数据类型，叫做struct student

int main(void)
{
    struct Student st = {1, "bigash", 20};
    printf("%d %s %d\n", st.sid, st.name, st.age);

    st.sid = 666;
    // st.name = "Big-ashes"; //写法错误
    strcpy(st.name ,"Big-ashes"); //复制
    st.age = 66;
    printf("%d %s %d\n", st.sid, st.name, st.age);

    return 0;
}