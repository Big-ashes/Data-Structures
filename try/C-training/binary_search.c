#include <stdio.h>

// 二分思想，二分查找，类似于数学中求函数的零点，采用二分法逼近


int Triangle(int n){
    return n*(1+n)/2;
}

//给定一个数字，判断它是否是三角形数  
int binary_search(int x){
    int head =1, tail=x, mid;
    while (head<=tail){
        mid = (head +tail) >>1;
        if(Triangle(mid) == x) return mid;
        if(Triangle(mid) < x) head = mid + 1;
        else tail = mid -1;
    }
    return -1;
}//其实这个函数用于求解所有单调函数，F（x）=y，给定y值求解x，但注意前提需要单调



int main(){
    int n;
    while(~scanf("%d",&n)){  //按位取反，等价于 while(scanf("%d",&n) != EOF)
        printf("%d \n",binary_search(n));
    }
    // binary_search(10);
    return 0;
}