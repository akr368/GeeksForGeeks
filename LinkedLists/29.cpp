#include <iostream>

using namespace std;

void swap_elements(int *,int *);

struct node{
  int data;
  struct node *next;
};

void push(struct node **head_ref,int data_item){

  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data_item;
  newnode->next=*head_ref;
  *head_ref=newnode;

}

void traverse(struct node *node){

   while(node!=NULL){
      cout<<node->data<<" ";
      node=node->next;
   }
   cout<<endl;
}


void move(struct node **head_ref){
   
   struct node *node=*head_ref; 
   if(node==NULL || node->next==NULL)
    return;

   struct node *secLast=NULL;
   struct node *last=*head_ref;
    
   while(last->next!=NULL){
       secLast=last;
       last=last->next;
   } 

   secLast->next=NULL;
   last->next=*head_ref;
   *head_ref=last;
}


int main() {
  
  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  
  traverse(head);
  move(&head);
  traverse(head);
  
  
  return 0;

}