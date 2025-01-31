#include<stdio.h>

typedef struct stack stack;

struct stack
{
    int size;
    int top;
    int *s;
};

int isfull(stack *st)
{
    if(st->top==st->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *st,int x)
{
    if(isfull(st))
    {
        printf("stack overflow.");
        return;
    }
    else
    {
        st->s[++st->top]=x;
    }
}

int pop(stack *st)
{
    if(isEmpty(st))
    {
        printf("stack is empty.");
        return;
    }
    else
    {
        int x=-1;
        x=st->s[st->top];
        st->top--;
        return x;
    }
}

int stacktop(stack *st)
{
    if(isEmpty(st))
    {
        return -1;
    }
    else
    {
        return st->s[st->top];
    }
}

int peek(stack *st,int pos)
{
    if(st->top-pos+1<-1 || st->top-pos+1>st->size)
    {
        printf("Invalid position.");
        return;
    }
    else
    {
        int x=-1;
        x=st->s[st->top-pos+1];
        return x;
    }
}

void display(stack *st)
{
    if(isEmpty(st))
    {
        printf("stack underflow.");
        return;
    }
    else
    {
       for(int i=0;i<=st->top;i++)
      {
        printf("%d ",st->s[i]);
      }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    stack *st=(stack*)malloc(sizeof(stack));
    st->size=n;
    st->top=-1;
    st->s=(int)malloc(n*sizeof(int));
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        int element;
        scanf("%d",&element);
        push(st,element);
    }
    printf("Element store in stack are:");
    display(st);

    int x1=pop(st);
    if(x1==-1)
    {
        printf("\nElement is not popped.");
    }
    else
    {
        printf("\nElement is popped:%d",x1);
    }

    int x2=peek(st,3);
    if(x2==-1)
    {
        printf("\nElement is not found.");
    }
    else
    {
        printf("\nElement is found:%d\n",x2);
    }

    int x3=stacktop(st);
    printf("%d",x3);
    return 0;
}