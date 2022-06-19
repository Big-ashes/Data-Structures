//<bits/stdc++.h>包含了目前c++的所有头文件
#include<bits/stdc++.h>
using namespace std;
#define Max 50
struct SqList{
    int a[Max]={1,4,5,7,1,3};
    int length=6;
};
bool listdelete(SqList &s,int &ele)
{
    if(s.length==0)
        return false;
    int minn=s.a[0];
    int flag=0;
    for(int i=1;i<s.length;i++)
    {
        if(s.a[i]<minn)
        {
            minn=s.a[i];flag=i;
        }
    }
    ele=s.a[flag];
    s.a[flag]=s.a[s.length-1];
    return true;
}
int main()
{
   SqList s;
   cout<<"SqList is :"<<endl;
   for(int i=0;i<s.length;i++) cout<<s.a[i]<<" ";
   cout<<endl;
   int k=0;
   if(listdelete(s,k))
   {
       cout<<"min element k is ="<<k<<endl;
       cout<<"SqList is :"<<endl;
       for(int i=0;i<s.length;i++)
       {
           cout<<s.a[i]<<" ";
       }
       cout<<endl;
   }
   else{
       cout<<"error"<<endl;
   }
    return 0;
}