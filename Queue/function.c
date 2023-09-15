#include<stdio.h>

void enQueue(int queue[],int* front , int* rear,int size,int num);
int deQueue(int queue[],int* front , int* rear);
void show(int queue[],int* front , int* rear);

void main()
{
    int queue[100],size,front=-1,rear=-1,num,operation=0;

    printf("enter size of an queue :- ");
    scanf("%d",&size);

    while(operation!=-1)
    {
        printf("enter 1 for insert\n");
        printf("enter 2 for delete\n");
        printf("enter -1 for back\n");
        scanf("%d",&operation);

        switch (operation)
        {
            case 1:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                enQueue(queue,&front,&rear,size,num);
                show(queue,&front,&rear);
                break;

            case 2:
                num=deQueue(queue,&front,&rear);
                if(num==0)
                    printf("Stack Underflow !.. ");
                else
                    show(queue,&front,&rear);
                break;
            
            default:
                printf("Invalid Input !..");
        }
    }
}

void enQueue(int queue[],int* front , int* rear,int size,int num)
{
    if((*rear)>=size)
    {
        printf("overflow !.. ");
        return;
    }
    (*rear)++;
    queue[*rear]=num;
    if((*front)==-1)
        (*front)=0;
    return;
}

int deQueue(int queue[],int* front , int* rear)
{
    if((*front)==-1)
    {
        printf("underflow !.. ");
        return 0;
    }
    int y = queue[*front];
    if((*front) == (*rear))
        (*front) = (*rear) = -1;
    else
        (*front)++;
    return y;
}

void show(int queue[],int* front , int* rear)
{
    if((*front)<0)
    {
        printf("empty !.. ");
        return;
    }
    for(int i=(*front);i<=(*rear);i++)
        printf("%3d",queue[i]);
    printf("\n");
}