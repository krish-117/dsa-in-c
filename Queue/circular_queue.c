#include<stdio.h>

void cqInsert(int cqueue[],int* front , int* rear,int size,int num);
int cqDelete(int cqueue[],int* front , int* rear,int size);
void show(int queue[],int* front , int* rear,int size);

void main()
{
    int cqueue[100],size,front=-1,rear=-1,num,operation=0;

    printf("enter size of an cqueue :- ");
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
                cqInsert(cqueue,&front,&rear,size,num);
                show(cqueue,&front,&rear,size);
                break;

            case 2:
                num=cqDelete(cqueue,&front,&rear,size);
                if(num==0)
                    printf(" Underflow !.. ");
                else
                    show(cqueue,&front,&rear,size);
                break;
            
            default:
                printf("Invalid Input !..");
        }
    }
}

void cqInsert(int cqueue[],int* front , int* rear,int size,int num)
{
    if((*rear)==size-1)
        (*rear)=0;
    else    
        (*rear)++;

    if((*rear)==(*front))
    {
        printf("overflow !.. ");
        return;
    }
    cqueue[(*rear)]=num;
    if((*front)==-1)
        (*front)=0;
    return;
}

int cqDelete(int cqueue[],int* front , int* rear,int size)
{
    if((*front)==-1)
    {
        printf("underflow !.. ");
        return 0;
    }
    int y = cqueue[*front];
    if((*front) == (*rear))
        (*front) = (*rear) = -1;
    if((*front)==size)
        (*front=0);
    else    
        (*front)++;
    return y;
}

void show(int queue[],int* front , int* rear,int size)
{
    if((*front)<=(*rear))
    {
        for(int i=(*front);i<=(*rear);i++)
            printf("%3d",queue[i]);
    }
    else{
        for(int i=(*front);i<=size;i++)
            printf("%3d",queue[i]);
        for(int i=0;i<=(*rear);i++)
            printf("%3d",queue[i]);
    }
}