#include<stdio.h>

void quick(int arr[],int start,int end);
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

    quick(arr,0,n-1);
   
    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
}

void quick(int arr[],int start,int end)
{
    if(start<end)
    {
        int i = start;
        int j = end+1 ;
        int temp = arr[start];
        int flag = 0;

        while(flag == 0)
        {
            i++;
            while(arr[i]<temp )
                i++;
            j--;
            while(arr[j]>temp )
                j--;
            if(i<j)
            {
                int swap = arr[i];
                arr[i]= arr[j];
                arr[j]= swap;
            }
            else
                flag ==1;
        }
        int swap = arr[start];
        arr[start] = arr[j];
        arr[j]= swap;

            quick(arr,start,j-1);
            quick(arr,j+1,end);
    }
}