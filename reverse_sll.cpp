#include<iostream>
using namespace std;
//Structure of SLL
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
//Tc=O(n) Sc=O(1).     Iterative
Node *rev_it(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node *temp=head;
    Node *prev=NULL;
    Node *cur=head;
    while(cur!=NULL)
    {
        cur=temp->next;
        temp->next=prev;
        prev=temp;
        temp=cur;
    }
    return prev;
}
//Tc=O(n) Sc=O(n).     Recurssion 1
Node *rev_rec1(Node *cur,Node *prev)
{
    if(cur==NULL)
    return prev;
    Node *temp=cur->next;
    cur->next=prev;
    return rev_rec1(temp,cur);
}
//Tc=O(n) Sc=O(n).      Recurssion 2
Node *rev_rec2(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node *fhead=rev_rec2(head->next);
    Node *ftail=head->next;
    ftail->next=head;
    head->next=NULL;
    return fhead;
}
int main()
{
    //construction of LL
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    print(head);
    cout<<endl;
    head=rev_it(head);
    print(head);
    cout<<endl;
    head=rev_rec1(head,NULL);
    print(head);
    cout<<endl;
    head=rev_rec2(head);
    print(head);
    cout<<endl;
}