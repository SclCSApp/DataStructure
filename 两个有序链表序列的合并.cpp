#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}*List;

List create()
{
    List L=(List)malloc(sizeof(struct node));
    L->next=NULL;
    List p=L;

    int data;
    cin>>data;
    while(data!=-1)
    {
        List t=(List)malloc(sizeof(struct node));
        t->data=data;
        t->next=NULL;
        p->next=t;
        p=p->next;
        cin>>data;
    }

    return L;
}

List mergeL(List L1,List L2)
{
    List p=L1->next;
    List q=L2->next;
    List head=L1;
    List r=head;
    while(p&&q)
    {
        if(p->data<=q->data)
        {
            r->next=p;
            r=r->next;
            p=p->next;
        }else
        {
            r->next=q;
            r=r->next;
            q=q->next;
        }
    }
    if(p) r->next=p;
    if(q) r->next=q;

    return head;
}

void print(List L)
{
    List t=L;
    if(L->next==NULL) cout<<"NULL";
    while(t)
    {
        t=t->next;
        if(t==NULL) break;
        if(t->next)
            cout<<t->data<<" ";
        if(t->next==NULL)
            cout<<t->data;
    }

    return ;

}

int main()
{
    List L1=create();
    List L2=create();
    List L3=mergeL(L1,L2);
    print(L3);
    return 0;
}











