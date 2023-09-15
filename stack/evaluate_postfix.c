#include<stdio.h>
#include<math.h>

void push (char stack[],int* top,int num);
char pop(char stack[],int *top );

void main()
{
    char postfix[100];
    char ans[100];
    int count_next=0,top=-1;
    int op1,op2;

    printf("enter postfix :- ");
    scanf("%s",postfix);

    char next = postfix[count_next++];

    while(next != ' ' && next != '\0')
    {
        if(next>='0'&&next<='9')
        {
            push(ans,&top,next);
        }
        else if(next == '+' || next == '-' || next == '*' || next == '/' || next == '^')
        {
            op2 =(pop(ans,&top)-'0');
            op1 =(pop(ans,&top)-'0');
            int temp;

            switch (next)
            {
            case '+':
                temp = op1 + op2;
                push(ans,&top,temp);
                break;
            
            case '-':
                temp = op1 - op2;
                push(ans,&top,temp);
                break;            

            case '*':
                temp = op1 * op2;
                push(ans,&top,temp);
                break;
            
            case '/':
                temp = op1 / op2;
                push(ans,&top,temp);
                break;
            
            case '^':
                temp=1;
                for(int i=0;i<op2;i++)
                    temp*=op1;
                push(ans,&top,temp);
                break;
            
            default:
                break;
            }   
        }
        next = postfix[count_next++];
    }
    printf("ans :- %d",ans[0]);
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
    char temp = stack[(*top)];
    *top -= 1;
    return temp;
}
