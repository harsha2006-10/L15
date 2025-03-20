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
// from here this program is for dynamic value
//

#include<stdio.h>
int  main(void)
{
    int x ,i ;
    printf("enter the length of the array:-");
    scanf("%d",&x);
    int a[x],b[x],c[x];
    printf("enter the array a");
    for (i=0;i<x;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the array b");
    for (i=0;i<x;i++)
    {
        scanf("%d",&b[i]);
    }
    for (i=0;i<x;i++)
    {
        c[i]=a[i]*b[i];
    }
    for (i=0;i<x;i++)
    {
        printf("the mul of array c[%d]=%d\n",i,c[i]);
    }

}
