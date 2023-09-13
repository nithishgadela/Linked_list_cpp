//Doubly Linked List 
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};
//printing operation O(n)
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
//insert at begining of DLL O(1)
Node *insertBegin(Node *head,int k)
{
    Node *temp=new Node(k);
    if(head!=NULL)
    {
        temp->next=head;
        head->prev=temp;
    }
    return temp;
}
//insert at the end of DLL O(n)
Node *insertEnd(Node *head,int k)
{
    Node *temp=new Node(k);
    if(head==NULL)
    return temp;
    Node *cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return head;
}
//reversing DLL O(n)
Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node *temp=head;
    Node *back;
    while(temp!=NULL)
    {
        back=temp->prev;
        temp->prev=temp->next;
        temp->next=back;
        temp=temp->prev;
    }
    return back->prev;
}
//deleting head of DLL O(1)
Node *delHead(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node *temp=head->next;
    temp->prev=NULL;
    delete(head);
    return temp;
}
//Delete last element of DLL O(n)
Node *delTail(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node *cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    Node *temp=cur->prev;
    temp->next=NULL;
    delete(cur);
    return head;
}
int main()
{
  //construction of DLL
  Node *head=new Node(10);
  Node *temp1=new Node(20);
  Node *temp2=new Node(30);
  head->next=temp1;
  temp1->prev=head;
  temp1->next=temp2;
  temp2->prev=temp1;
  
  print(head);
  cout<<endl;
  head=insertBegin(head,5);
  print(head);
  cout<<endl;
  head=insertEnd(head,35);
  print(head);
  cout<<endl;
  head=reverse(head);
  print(head);
  cout<<endl;
  head=delHead(head);
  print(head);
  cout<<endl;
  head=delTail(head);
  print(head);
  cout<<endl;
}