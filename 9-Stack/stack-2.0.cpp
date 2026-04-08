#include <iostream> 
using namespace std;
int size=5;
int arr[size];
int top=-1;

void push(int value){
    if(top==size-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    top++;
    arr[top]=value;
}
void pop(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
        return;
    }
    top--;
}
void peek(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<"top element is "<<arr[top]<<endl;
}
void display(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
        return;
    }
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" -> ";
    }
    cout<<"NULL"<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    peek();
    return 0;
}