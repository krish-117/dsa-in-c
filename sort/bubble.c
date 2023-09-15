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

    for(int i=0;i<n-1;i++)
    {
        int flag = 0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[i])
            {
                int swap = arr[i];
                arr[i]=arr[j];
                arr[j]=swap;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }

    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
}