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

    for(int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
}