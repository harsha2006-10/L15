#include<stdio.h>
void add(char const*name,int X[],int size)
{
    for(int i=0;i<size ;i++)
   { printf("%s[%d]=%d\n",name,i,X[i]);} printf("\n");
}
int main(void)
{
    int a[5]={2,3,4,5,7};
    int b[10]={02,154,454,4,64,454,4564,416,4,45};
    add("a",a,5);
    add("b",b,10);
} 
