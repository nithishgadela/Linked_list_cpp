//Circular Linked list

#include<iostream>
using namespace std;
//Structure of CLL
struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
//printing of CLL O(n)
void print(Node *head)
{
    Node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
//insert at Begining of CLL O(1)
Node *insertBegin(Node *head,int k)
{
    Node *temp=new Node(k);
    Node *cur=head->next;
    head->next=temp;
    temp->next=cur;
    swap(head->data,temp->data);
    return head;
}
//Insert at End of CLL O(1)
Node *insertEnd(Node *head,int k)
{
    Node *temp=new Node(k);
    Node *cur=head->next;
    head->next=temp;
    temp->next=cur;
    swap(head->data,temp->data);
    return temp;;
}
//Delate head of CLL O(1)
Node *delBegin(Node *head)
{
    if(head==NULL || head->next==NULL || head->next==head )
    return NULL;
    swap(head->data,head->next->data);
    Node *temp=head->next->next;
    Node *cur=head->next;
    head->next=temp;
    delete(cur);
    return head;
}
//Delete End of CLL O(n)
Node *delEnd(Node *head)
{
    if(head==NULL || head->next==NULL || head->next==head )
    return NULL;
    Node *temp=head;
    while(temp->next->next!=head)
    temp=temp->next;
    Node *cur=temp->next;
    temp->next=head;
    delete(cur);
    return head;
}

int main()
{
    //Implementation of CLL
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=head;
    
    print(head);
    cout<<endl;
    int k=5;
    head=insertBegin(head,k);
    print(head);
    cout<<endl;
    k=50;
    head=insertEnd(head,k);
    print(head);
    cout<<endl;
    head=delBegin(head);
    print(head);
    cout<<endl;
    head=delEnd(head);
    print(head);
    cout<<endl;
}