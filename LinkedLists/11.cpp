#include <iostream>
using namespace std;

struct node {
 int data;
 struct node *next;
};

void push(struct node **head_ref,int data_item){

   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
   *head_ref=newnode;
}

void getNth(struct node *node,int n){
      
     if(node==NULL)
      return;
      
     for(int i=0;node!=NULL && i<n;i++) 
      node=node->next;
     
     if(node!=NULL)
     cout<<"Data at Nth Node: "<<node->data<<endl;
     else
      cout<<"Nth Node doesn't exist."<<endl;

}

int main(){

  struct node *head=NULL;
  push(&head,10);
  push(&head,20);
  push(&head,30);
  getNth(head,10);

  return 0;
}