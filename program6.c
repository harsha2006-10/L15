#include<stdio.h>
void main()
{
    int mark;
    printf("enter you marks :- ");
    scanf("%d",&mark);
    if(mark>90)
    {
        printf("your passed with A grad");
    }
    else if(mark<=90 && mark<80){
        printf("your passed with B graed");
    }
    else if(mark<=80 && mark<70){
        printf("your passed with C graed");
    }
    else if(mark<=70 && mark<60){
        printf("your just passed");
    }
    else{
        printf("your failed");
    }
}
