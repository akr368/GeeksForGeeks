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


void isLoop(struct node *node){

   struct node *slow=node;
   struct node *fast=node;
   
   while(slow && fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      cout<<"Loop exists"<<endl;
      return;
    }
   }
  
   cout<<"No Loop Detected."<<endl;
   

}



int main() {

  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  
  //traverse(head);
  isLoop(head);
  return 0;

}