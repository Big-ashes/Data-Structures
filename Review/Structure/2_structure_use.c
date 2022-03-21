#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
}; 

int main(void)
{
    struct Student st = {1, "bigash", 20};
    // st.sid = 99; //第一种方式
    struct Student *pst = &st; //struct Student占208个字节（理论上），pst占16个字节，16G运存
    
    // pst = &st;      
    pst->sid = 99;  //第二种方式 
    //pst->sid 等价于(*pst).sid = st.sid  pst指向st,*pst等于st
    //pst->sid 表示pst所指的结构体变量中的sid这个成员，最终表示的是sid这个成员
    
    return 0;
}