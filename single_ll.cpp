#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head!=NULL)
    temp->next=head;
    return temp;
}
Node *insertEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    Node *cur=head;
    if(head!=NULL)
    {
        while(cur->next!=NULL)
        cur=cur->next;
        cur->next=temp;
        return head;
    }
    return temp;
}
Node *delBegin(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node *temp=head->next;
    delete(head);
    return temp;
}
Node *delEnd(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node *cur=head;
    while(cur->next->next!=NULL)
    {
        cur=cur->next;
    }
    delete(cur->next);
    cur->next=NULL;
    return head;
}
Node *insertPos(Node *head,int k,int p)
{
    if(p<=0)
    return head;
    if(p==1)
    {
        head=insertBegin(head,k);
        return head;
    }
    Node *temp=new Node(k);
    Node *cur=head;
    for(int i=2;cur!=NULL && i<p;i++)
    {
        cur=cur->next;
    }
    if(cur==NULL)
    return head;
    temp->next=cur->next;
    cur->next=temp;
    return head;
}
int searchI(Node *head,int k)
{
    int i=1;
    while(head!=NULL)
    {
        if(head->data==k)
        return i;
        i++;
        head=head->next;
    }
    return -1;
}
int searchR(Node *head,int k,int i)
{
    if(head==NULL)
    return -1;
    if(head->data==k)
    return i;
    else
    return searchR(head->next,k,i+1);
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    print(head);
    cout<<endl;
    int k=50;
    head=insertBegin(head,k);
    print(head);
    cout<<endl;
    k=70;
    head=insertEnd(head,k);
    print(head);
    cout<<endl;
    head=delBegin(head);
    print(head);
    cout<<endl;
    head=delEnd(head);
    print(head);
    cout<<endl;
    k=25;
    int p=3;
    head=insertPos(head,k,p);
    print(head);
    cout<<endl;
    k=30;
    cout<<searchI(head,k)<<endl;
    k=60;
    cout<<searchR(head,k,1)<<endl;
}





