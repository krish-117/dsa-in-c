#include<stdio.h>

void push (char stack[],int* top,int num);
char pop(char stack[],int *top );
void show(int stack[],int *top);
int f(char ch);
int g(char ch);
int r(char ch);

void main()
{
    char infix[100];
    printf("Enter infix expression ");
    scanf("%s",infix);

    int count_next=0,count_polish=0;

    int top=0;
    char s[100];
    s[top]='(';

    char polish[100];
    int rank = 0;

    char next = infix[count_next++];

    while(next!=' ')
    {
        if(top<0)
        {
            printf("invalid !..");
            break;
        }
        while (g(s[top]) > f(next))
        {
            char temp = pop(s,&top);
            polish[count_polish++] = temp;
            rank = rank+r(temp);

            if(rank<1)
            {
                printf("invalid");
                break;
            }
        }

        if(g(s[top]) != f(next))
            push(s,&top,next);
        else
            pop(s,&top);
        next = infix[count_next++];
        
    }
    if(top!=-1 || rank!=1)
        printf("invalid !");
    else
        printf("%s",polish);
}

void push (char stack[],int* top,int num)
{
    *top += 1;
    stack[*top] = num;
    return;
}

char pop(char stack[],int *top )
{
    if(*top<0)
        return -1;
    *top -= 1;
    return stack[(*top)+1];
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

int f(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 3;
    else  if(ch=='^')
        return 6;
    else  if(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z')
        return 7;
    else  if(ch=='(')
        return 9;
    else  if(ch==')')
        return 0;
}

int g(char ch)
{
    if(ch=='+' || ch=='-')
        return 2;
    else if(ch=='*' || ch=='/')
        return 4;
    else  if(ch=='^')
        return 5;
    else  if(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z')
        return 8;
    else  if(ch=='(')
        return 0;
}

int r(char ch)
{
    if(ch=='+' || ch=='-')
        return -1;
    else if(ch=='*' || ch=='/')
        return -1;
    else  if(ch=='^')
        return -1;
    else  if(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z')
        return 1;
}