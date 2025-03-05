#include<stdio.h>
void add(int X[])
{
    for(int i=0;i<5;i++)
    printf("a[%d]=%d\n",i,X[i]);
}
int main(void)
{
    int a[5]={2,3,4,5,7};
    add(a);

}
