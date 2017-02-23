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


void deleteList(struct node **head_ref){   
  
    struct node *cur=*head_ref;
    struct node *temp=cur;

    while(cur!=NULL){ 
         cur=cur->next;
         free(temp);
         temp=cur;
    }

    *head_ref=NULL;
}

int main(){

  struct node *head=NULL;
  push(&head,1);
  push(&head,121);
  push(&head,3);
  push(&head,14);
  push(&head,5);
  
  traverse(head);
  deleteList(&head);
  traverse(head);

  return 0;
}