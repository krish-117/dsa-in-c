#include<stdio.h>

void main()
{
    int pqueue[100],low_front=-1,low_rear=-1;
    int medium_front=-1,medium_rear=-1;
    int high_front=-1,high_rear=-1;
    int operation=0,size,num;

    printf("enter size of an queue :- ");
    scanf("%d",&size);

    while(operation!=-1)
    {
        printf("enter 1 for insert at low\n");
        printf("enter 2 for insert at medium\n");
        printf("enter 3 for insert at high\n");
        printf("enter -1 for back\n");
        scanf("%d",&operation);

        switch (operation)
        {
            case 1:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                insert(pqueue,&low_front,&low_rear,size,num);
                
                break;

            case 2:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                
                
                break;

            case 3:
                printf("Enter element to insert :- ");
                scanf("%d",&num);
                
                
                break;
            
            default:
                printf("Invalid Input !..");
        }
    }

}

insert(int pqueue[],int* front,int *rear,int size,int num)
{

}
