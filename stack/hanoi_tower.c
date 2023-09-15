#include<stdio.h>

void towerofhanoi(int n , char from,char to,char left);

void main()
{
    int n;
    char from='A',to='B',left='C';

    printf("enter number of disk :- ");
    scanf("%d",&n);

    towerofhanoi(n,from,to,left);
}

void towerofhanoi(int n , char from,char to,char left)
{
    if(n==1)
    {
        printf("change disk 1 from %c to %c \n",from,to);
        return;
    }
    towerofhanoi(n-1,from,left,to);
    printf("change disk %d from %c to %c \n",n,from,to);
    towerofhanoi(n-1,left,to,from);
}