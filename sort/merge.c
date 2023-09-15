#include<stdio.h>

void main()
{
    int arr[10];
    int n;

    printf("enter size of array :- ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("enter %d element :--> ",i+1);
        scanf("%d",&arr[i]);
    }

    

    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
}

