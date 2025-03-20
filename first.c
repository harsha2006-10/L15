#include<stdio.h>
int  main(void)
{
    int a[4]={1,5,8,5};
    int b[4]={2,4,5,6};
    int c[4] ,i ;
    for (i=0;i<4;i++)
    {
        c[i]=a[i]*b[i];
    }
    for (i=0;i<4;i++)
    {
        printf("the mul of array c[%d]=%d\n",i,c[i]);
    }

}

