#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};


void push(struct node **head_ref,int data_item){
   
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data_item;
   newnode->next=*head_ref;
      *head_ref=newnode;

}


int length(struct node *node){
  
   int count=0;
   if(node==NULL)
    return 0;

   while(node!=NULL){
      count++;
      node=node->next;
   }

   return count;

}



int main(){

	struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    cout<<"Length: "<<length(head)<<endl;


    return 0;

}