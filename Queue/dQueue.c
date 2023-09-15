#include<stdio.h>

void dqInsert_front(int dqueue[],int* front , int* rear,int size,int num);
void dqInsert_rear(int dqueue[],int* front , int* rear,int size,int num);
int dqDelete_front(int dqueue[],int* front , int* rear);
int dqDelete_rear(int dqueue[],int* front , int* rear);
void show(int queue[],int* front , int* rear);

void main()
{
    int dqueue[100],size,front=-1,rear=-1,num,operation=0;

    printf("enter size of an dqueue :- ");
    scanf("%d",&size);

    while(operation!=-1)
    {
        printf("enter 1 for insert  from front\n");
        printf("enter 2 for insert from rear\n");
        printf("enter 3 for delete from front\n");
        printf("enter 4 for delete from rear\n");
        printf("enter -1 for back\n");
        scanf("%d",&operation);

        switch (operation)
        {
            case 1:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                dqInsert_front(dqueue,&front,&rear,size,num);
                show(dqueue,&front,&rear);
                break;

            case 2:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                dqInsert_rear(dqueue,&front,&rear,size,num);
                show(dqueue,&front,&rear);
                break;

            case 3:
                num=dqDelete_front(dqueue,&front,&rear);
                if(num==0)
                    printf("Stack Underflow !.. ");
                else
                    show(dqueue,&front,&rear);
                break;
            
            case 4:
                num=dqDelete_rear(dqueue,&front,&rear);
                if(num==0)
                    printf("Stack Underflow !.. ");
                else
                    show(dqueue,&front,&rear);
                break;
            
            default:
                printf("Invalid Input !..");
        }
    }
}

void dqInsert_rear(int dqueue[],int* front , int* rear,int size,int num)
{
    if((*rear)>=size)
    {
        printf("overflow !.. ");
        return;
    }
    (*rear)++;
    dqueue[*rear]=num;
    if((*front)==-1)
        (*front)=0;
    return;
}

void dqInsert_front(int dqueue[],int* front , int* rear,int size,int num)
{
    if((*front)==-1)
    {
        printf("empty !.. ");
        return;
    }
    if((*front)==0)
    {
        printf("overflow !.. ");
        return;
    }
    (*front)--;
    dqueue[(*front)]=num;
}

int dqDelete_front(int dqueue[],int* front , int* rear)
{
    if((*front)==-1)
    {
        printf("underflow !.. ");
        return 0;
    }
    int y = dqueue[*front];
    if((*front) == (*rear))
        (*front) = (*rear) = -1;
    else
        (*front)++;
    return y;
}

int dqDelete_rear(int dqueue[],int* front , int* rear)
{
    if((*rear)==0)
    {
        printf("underflow !.. ");
        return 0;
    }
    int y = dqueue[(*rear)];
    if((*front) == (*rear))
        (*front) = (*rear) = -1;
    else
        (*rear)--;
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