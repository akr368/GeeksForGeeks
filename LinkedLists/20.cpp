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

void insert(struct node **head_ref,struct node *newnode){

   struct node *node=*head_ref;
   struct node *prev=NULL;
   
   if(*head_ref==NULL || (*head_ref)->data>=newnode->data){
     
     newnode->next=*head_ref;
     *head_ref=newnode;

   }

   else{

   while(node!=NULL){

       if(node->data<=newnode->data){
          prev=node;
          node=node->next;
       }
       else
        break;  
   }

   struct node *temp=prev->next;
   prev->next=newnode;
   newnode->next=temp;

  } 

}

int main() {
  
  struct node *head=NULL;
  push(&head,10);
  //push(&head,5);
  //push(&head,2);
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=7;
  newnode->next=NULL;
  traverse(head);
  insert(&head,newnode);
  traverse(head);





  return 0;

}