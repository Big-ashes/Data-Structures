#include <stdio.h>

//stuct类型-把好几个属性合起来统一定义成一个新的类型，方便调用
//struct {  xxx }；   也可以不放名称，称之为匿名的结构体类型
/* 
struct person{
    char name[20];  20B
    int age;        4B
    char gender;    1B
    float height;   4B   应该占用29个B，但是占用的时候实际为32B，申请空间的时候注意边界对齐
};
调用的时候需要用到（直接引用运算符）其实就是一个.  类似如下
struct person p1;
p1.age   间接引用   p1->age
*/
int main(){

    return 0;
}