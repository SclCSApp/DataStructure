#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int n,data;
    scanf("%d",&n);

    List head=(List)malloc (sizeof(struct Node));
    scanf("%d",&data);
    head->Data=data;

    List p=head;

    for(int i=1;i<n;i++)
    {
        scanf("%d",&data);
        List t=(List)malloc (sizeof(struct Node));
        t->Data=data;
        t->Next=NULL;
        p->Next=t;
        p=p->Next;
    }

    return head;
}

void Print(List L)
{
    List t=L;
    while(t)
    {
        printf("%d ",t->Data);
        t=t->Next;
    }
}

List Reverse( List L )
{

    if(L==NULL) return L;
    List p,q,s;
    p=NULL;
    q=L;
    s=q->Next;
    while(s)
    {
        q->Next=p;
        p=q;
        q=s;
        s=s->Next;
    }
    q->Next=p;
    return q;

}











