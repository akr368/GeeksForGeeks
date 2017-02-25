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


void swap(int *a,int *b){

  int t=*a;
  *a=*b;
  *b=t;
}

void pairswap(struct node *node){

    if(node==NULL)
      return;
    struct node *temp=node;
    
    while(temp!=NULL && temp->next!=NULL){
       swap(&temp->data,&(temp->next->data));
       temp=temp->next->next;

    }

}



int main() {
  
  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  
  traverse(head);
  pairswap(head);
  traverse(head);
 
  
  return 0;

}