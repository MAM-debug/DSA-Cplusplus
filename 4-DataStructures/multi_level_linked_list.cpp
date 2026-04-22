#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* child;
    Node(int value){
        data=value;
        next=nullptr;
        child=nullptr;
    }
};
void insert(Node* head,int value,int position){
    Node* newNode=new Node(value);
    if(position==0){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* temp=head;
    int idx=0;
    while(temp!=nullptr && idx<position-1){
        temp=temp->next;
        idx++;
    }
    if(temp==nullptr){
        cout<<"Position out of bounds"<<endl;
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void insertchild(int parentvalue,int childvalue,Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==parentvalue){
            break;
        }
        temp=temp->next;

    }
    if (temp==nullptr){
        cout<<"Parent value not found"<<endl;
        return;
    }
    Node* newNode=new Node(childvalue);
    if(temp->child==nullptr){
        temp->child=newNode;
    }
    else{
        Node* childtemp=temp->child;
        while(childtemp->next!=nullptr){
            childtemp=childtemp->next;
        }
        childtemp->next=newNode;

    }
}
void display(Node* head){
    Node* temp=head;
    stack<Node*> st;
    while(temp!=nullptr || !st.empty()){
        if(temp==nullptr){
            temp=st.top();
            st.pop();
        }
        cout<<temp->data<<" -> ";
        if(temp->child!=nullptr){
            st.push(temp->next);
            temp=temp->child;
        }
        else{
            temp=temp->next;
        }
    }
}



































