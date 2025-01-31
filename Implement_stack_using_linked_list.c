#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct stack stack;

struct Node
{
    int data;
    Node *next;
};

struct stack
{
    int size;
    Node *top;
};

int isEmpty(stack *st)
{
    if(st->top==NULL)
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
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=st->top;
    st->top=temp;
}

int peek(stack *st,int pos)
{
    if(isEmpty(st))
    {
        printf("Stack is empty.");
        return;
    }
    else
    {
        Node *t;
        t=st->top;
        for(int i=0;i<pos-1;i++)
        {
            t=t->next;
        }
        int x=-1;
        x=t->data;
        return x;
    }
}

void display(stack *st)
{
    if(isEmpty(st))
    {
        printf("stack is empty.");
        return;
    }
    else
    {
        Node *p;
        p=st->top;
        while(p!=NULL)
        {
           printf("%d ",p->data);
           p=p->next;
        }
    }
}

int pop(stack *st)
{
    int x=-1;
    Node *temp;
    temp=st->top;
    st->top=st->top->next;
    x=temp->data;
    free(temp);
    return x;
}

int stacktop(stack *st)
{
    int x=-1;
    x=st->top->data;
    return x;
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    stack *st=(stack*)malloc(sizeof(stack));
    st->size=n;
    st->top=NULL;
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        int element;
        scanf("%d",&element);
        push(st,element);
    }
    printf("Elements store in linked list are:");
    display(st);
    int x1=peek(st,4);
    printf("\n%d ",x1);

    int x2=pop(st);
    printf("\n%d\n",x2);
    display(st);

    int x3=stacktop(st);
    printf("\n%d",x3);
    return 0;
}