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


void reverse(struct node **head_ref){


   struct node *prev=NULL;
   struct node *curr=*head_ref;
   struct node *next;

   while(curr!=NULL){
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
   }
   *head_ref=prev;

}

//Recursive Call

void reverse1(struct node *curr,struct node *prev,struct node **head){
   

  if(curr->next==NULL){
      curr->next=prev;
      *head=curr;
      return;
  }

  struct node *temp=curr->next;
  curr->next=prev;
  reverse1(temp,curr,head); 

}


int main() {

  struct node *head=NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  traverse(head);
  reverse1(head,NULL,&head);
  traverse(head);

  return 0;

}