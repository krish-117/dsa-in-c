#include<stdio.h>

void push (int stack[],int* top,int size,int num);
int pop(int stack[],int *top , int size);
int peep(int stack[],int *top,int size,int i);
void change(int stack[],int *top,int num,int i);
void show(int stack[],int *top);

void main()
{
    int stack[100],size,top=-1,num,operation=0,index;

    printf("enter size of an stack :- ");
    scanf("%d",&size);

    while(operation!=-1)
    {
        printf("enter 1 for push\n");
        printf("enter 2 for pop\n");
        printf("enter 3 for peep\n");
        printf("enter 4 for change\n");
        printf("enter -1 for back\n");
        scanf("%d",&operation);

        switch (operation)
        {
        case 1:
            printf("Enter element to insert :- ");
            scanf("%d",&num);
            push(stack,&top,size,num);
            show(stack,&top);
            break;

        case 2:
            num=pop(stack,&top,size);
            if(num==-1)
                printf("Stack Underflow !.. ");
            else
                show(stack,&top);
            break;

        case 3:
            printf("Enter index from top :- ");
            scanf("%d",&index);
            num = peep(stack,&top,size,index);
            if(num==-1)
                printf("Stack Underflow !.. ");
            else
                printf("%d",num);
            break;

        case 4:
            printf("Enter index from top :- ");
            scanf("%d",&index);
            printf("Enter element :- ");
            scanf("%d",&num);
            change(stack,&top,num,index);
            show(stack,&top);
            break;
        
        default:
            printf("Invalid Input !..");
        }
    }
}

void push (int stack[],int* top,int size,int num)
{
    if((*top)>=size)
    {
        printf("Stack Overflow !..");
        return;
    }
    *top += 1;
    stack[*top] = num;
    return;
}

int pop(int stack[],int *top , int size)
{
    if(*top<0)
        return -1;
    *top -= 1;
    return stack[(*top)+1];
}

int peep(int stack[],int *top,int size,int i)
{
    if((*top)-i+1<0)
        return -1;
    return stack[(*top)-i+1];
}

void change(int stack[],int *top,int num,int i)
{
    if((*top)-i+1<0)
    {
        printf("Stack Underflow !..");
        return;
    }
    stack[(*top)-i+1] = num ;
}

void show(int stack[],int *top)
{
    if((*top)<0)
    {
        printf("Empty Stack !..");
        return;
    }
    for(int i=0;i<=(*top);i++)
    {
        printf("%3d",stack[i]);
    }
    printf("\n");
}