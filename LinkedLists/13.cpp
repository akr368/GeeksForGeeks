#include <iostream>
using namespace std;

struct node {
 int data;
 struct node *next;
};

void traverse(struct node *node){
  
   while(node!=NULL){
    cout<<node->data<<" ";
    node=node->next;
   }
   cout<<endl;

}
void push(struct node **head_ref,int data_item){

   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
   *head_ref=newnode;
}


void function1(struct node *node,int n){

   struct node *temp=node;
   int length=0;
   while(temp!=NULL){
    length++;
    temp=temp->next;
   }

   if(n>length)
    return;
   int c=length-n;
   while(node!=NULL && c>0){
     node=node->next;
     c--;
   }
   
   if(node!=NULL)
    cout<<"Nth Node from end: "<<node->data<<endl;

}

//recursive version of function 1

void function2(struct node *node,int n){
    
    static int i=0;
    if(node==NULL)
      return;
    function2(node->next,n);
    cout<<"Test: "<<node->data<<endl;
    if(++i==n)
      cout<<"Nth Node from end: "<<node->data<<endl;

}


void function3(struct node *node,int n){
  
  struct node *pointer1=node;
  struct node *pointer2=node;
  int count=n;

  if(node!=NULL){
 
  while(pointer1!=NULL && count>0){
    pointer1=pointer1->next;
    count--;
   
   }
   
   while(pointer1!=NULL){
       pointer1=pointer1->next;
       pointer2=pointer2->next;
   }

   cout<<"Nth Element from end:"<<pointer2->data<<endl;

  }

}



int main(){

  struct node *head=NULL;
  push(&head,1);
  push(&head,121);
  push(&head,3);
  push(&head,14);
  push(&head,5);
  
  traverse(head);
  function3(head,4);

  return 0;
}