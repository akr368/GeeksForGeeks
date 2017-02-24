#include <iostream>

using namespace std;

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

void reverse(struct node *node){
   
   if(node==NULL)
    return;

  reverse(node->next);
  cout<<node->data<<" ";

}


int main() {
  
  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  traverse(head);
  reverse(head);
  


  return 0;

}