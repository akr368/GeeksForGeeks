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

void delete1(struct node *node){

   struct node *temp=node->next;
   node->data=temp->data;
   node->next=temp->next;
   free(temp);

}


int main() {
  
  struct node *head=NULL;
  push(&head,10);
  push(&head,5);
  push(&head,12);
  traverse(head);
  struct node *temp=head;
  while(temp->data!=5){
    temp=temp->next;
  }
  delete1(temp);
  
  traverse(head);





  return 0;

}