#include<stdio.h>
void add(int X[],int size)
{
    for(int i=0;i<size;i++)
   { printf("a[%d]=%d\n",i,X[i]);} printf("\n");
}
int main(void)
{
    int a[5]={2,3,4,5,7};
    int b[10]={02,154,454,4,64,454,4564,416,4,45};
    add(a,5);
    add(b,10);
}
