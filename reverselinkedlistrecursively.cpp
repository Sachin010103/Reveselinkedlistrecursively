#include<bits/stdc++.h>
using namespace std;

//creating class

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};





void deletenode(node* &prev){
        node* temp=prev->next;
        prev->next=prev->next->next;
        temp->next=NULL;
        delete temp;
}




void insertathead(node* &head,int element){


       node* temp=new node(element);
       temp->next=head;
       head=temp;
      
}

void operation(node* &head,node* curr,node* prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    node* forward=curr->next;
    operation(head,forward,curr);
    curr->next=prev;
}

void reverse(node* &head){
    node* curr=head;
    node* prev=NULL;
    operation(head,curr,prev);
}
 
 
void printlist(node* &head){
    node* temp=head;
    while (temp!=NULL)
    {
         cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}

int  lengthoflist(node* &head){
    node* temp=head;
    auto count=0;
    while (temp!=NULL)
    {
          count++;
         temp=temp->next;
    }
    return count;
}

 
  
int main(){
     node* x=new node(100);
     insertathead(x,200);
     insertathead(x,300);
      
     printlist(x);
      
 
   reverse(x);
   printlist(x); 
 
 
}