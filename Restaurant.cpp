/* Code written and tested by Md Aaquil Nasim*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string foodname;
    int quantity;
    float price;
    int data;
    Node *next;
};

//Global struct pointers used throughout the program to create and maintain the linked list
Node *headc=NULL, *newnode=NULL;
Node *heada=NULL, *taila=NULL;
Node *head_s;

//Methods which print the options available for admin to shoose
void adminmenu()
{
    cout<<"\n1. View total Sales\n";
    cout<<"2. Add new items in the order menu\n";
    cout<<"3. Delete items from the order menu\n";
    cout<<"4. Display order menu\n";
    cout<<"5. Back to Main Menu\n\n";
    cout<<"Enter the choice :";
}

//Function prints the options available for customer to choose
void customermenu()
{
    cout<<"\n1. Place Your Order\n";
    cout<<"2. View Ordered Items\n";
    cout<<"3. Delete items from the order\n";
    cout<<"4. Display final bill\n";
    cout<<"5. Back to Main Menu\n\n";
    cout<<"Enter the choice :";
}

//Function creates a node for admin's Linked list
Node *createadmin(Node *head, int data, string foodname, float price)
{
    Node *newnode= new Node();
    newnode->data= data;
    newnode->price= price;
    newnode->quantity = 0;
    newnode->foodname = foodname;
    newnode->next= NULL;
    
    Node *temp=head;

    if(temp==NULL){
        heada= taila= newnode;
    }
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        taila=newnode;
    }
    return heada;
}

//Function creates a node for customer's linked list
Node createcustomer(Node *head, int data, int quantity)
{
    Node *newnode= new Node();
    Node *temp1=heada;
    int flag=0;
    while(temp1!=NULL)
    {   
        if(temp1->data==data)
        {
            flag = 1;
            break;
        }
        temp1=temp1->next;

    }
    if(flag==1)
    {
        newnode->data=data;
        newnode->price=quantity*(temp1->price);
        newnode->foodname=temp1->foodname;
        newnode->next=NULL;
        Node *temp=head;
        if(temp==NULL)
            headc=tailc=newnode;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            
            temp->next=newnode;
            tailc=newnode;
        }
    }
    else
    {
        cout<<"\n This Item is not present in the menu\n";

    }
    return headc;
}

//Function displays the respective enr=tire linked list whose head pointer is passed to it
void displayList(Node *head)
{
    Node *temp1=head;
    if(temp1==NULL)
        cout<<"\n List is Empty..\n";
    else
    {
        cout<<"\n";
        while(temp1!=NULL)
        {
            if(temp1->quantity==0)
                cout<<temp1->data<<"\t"<<temp1->foodname<<"\t"<<temp1->price;
            else 
                cout<<cout<<temp1->data<<"\t"<<temp1->foodname<<"\t"<<temp1->quantity<<"\t"<<temp1->price;
        temp1=temp1->next;
        }
        cout<<"\n";
    }
}



